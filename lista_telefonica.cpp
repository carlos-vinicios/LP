#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

using namespace std;

struct Contato{
  char nome[100];
  char tel[12];
};

struct Contatos{
  Contato contato;
  Contatos *next;
};

typedef Contatos ListaTelefonica;

Contato dataStruct(char *linha){
  int i, j, k, nome = 1;
  Contato novoContato;
  for(i = 0; i < strlen(linha); i++){
      if(linha[i] == '='){
        k = 0;
        for(j = i+1; j < strlen(linha); j++){;
          if(linha[j] != ';'){
            if(nome){
              novoContato.nome[k] = linha[j];
            }else{
              novoContato.tel[k] = linha[j];
            }
            k++;
          }else{
            break;
          }
        }
        nome= 0;
      }
  }
  return novoContato;
}

ListaTelefonica *loadAll(){
  FILE *arq;
  char *linha;
  int size, first = 1;
  ListaTelefonica *novaLista, *novo, *old;
  Contato contato;
  arq = fopen("lista_contato.txt", "r");
  if(arq == NULL){
      return NULL;
  }
  fseek(arq, 0, SEEK_END);
  size = ftell(arq);
  rewind(arq);
  linha = new char[size];
  novaLista = new ListaTelefonica();
  novaLista->next = NULL;
  while(!feof(arq)){
    fgets(linha, size, arq);
    contato = dataStruct(linha);
    novo = new ListaTelefonica();
    novo->contato = contato;
    novo->next = NULL;
    if(first){
      novaLista->next = novo;
      first = 0;
    }else{
      old = novaLista->next;
      while(old->next != NULL)
  			old = old->next;

  		old->next = novo;
    }
  }
  return novaLista;
}

int store(Contato contato){
  FILE *arq;
  if(strlen(contato.nome) <= 0){
    return 7;
  }
  if(strlen(contato.tel) <= 0){
    return 8;
  }
  arq = fopen("lista_contato.txt", "a+");
  if(arq == NULL){
    return 9;
  }
  fprintf(arq, "nome=%s;", contato.nome);
  fprintf(arq, "tel=%s;", contato.tel);
  fputc('\n', arq);
  fclose(arq);
  return 1;
}

void cadastro(){
  int result;
  Contato contato;
  cout << "Nome do contato:\n";
  cin.getline(contato.nome, 100);
  cout << "Telefone:\n";
  cin >> contato.tel;
  result = store(contato);
  switch (result) {
    case 1:
      cout << "Sucesso";
      break;
    case 7:
      cout << "Erro na quantidade de caractres de nome";
      break;
    case 8:
      cout << "Erro na quantidade de caractres do telefone";
      break;
    case 9:
      cout << "O sistema não conseguiu acessar o arquivo";
      break;
  }
}

void pesquisa(ListaTelefonica *contatos){
  char search[100];
  cout << "Digite um nome ou número para pesquisa:\n";
  cin.getline(search, 100);
  while(contatos != NULL){
    if((strstr(contatos->contato.nome, search) != NULL) || (strstr(contatos->contato.tel, search) != NULL)){
      cout << "Nome: " << contatos->contato.nome << '\n';
      cout << "Telefone: " << contatos->contato.tel << '\n';
    }
    contatos = contatos->next;
  }
  cin.ignore(1);
}

int main(int argc, char const *argv[]) {
  int opcao, exec = 1;
  ListaTelefonica *contatos;
  contatos = loadAll();
  if(contatos == NULL){
    cout << "Erro ao carregar a lista\n";
    return 0;
  }
  cout << "Digite a opcao que desejas:\n1- cadastro\n2- pesquisa\n3-sair\n";
  cin >> opcao;
  cin.ignore(1);
  do{
    switch (opcao) {
      case 1:
        cadastro();
        break;
      case 2:
        pesquisa(contatos);
        break;
      case 3:
        return 0;
        break;
    }
    cout << "Digite a opcao que desejas:\n1- cadastro\n2- pesquisa\n3-sair\n";
    cin >> opcao;
    cin.ignore(1);
  }while(exec);
  return 0;
}
