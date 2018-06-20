#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int linhade(char **matriz, int tamanho, char *palavra, int *coluna){//direita esquerda
  int i, j, k, col;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  for(i = 0; i < tamanho; i++){
    k = 0;
    for(j = tamanho-2; j >= 0; j--){
      word[k] = matriz[i][j];
      k++;
    }
    word[k] = '\0';
    filter = strstr(word, palavra);
    col = (tamanho - 1) - (filter - word);
    if(filter != NULL){
      *coluna = col;
      delete filter;
      delete word;
      return i;
    }
  }

  delete filter;
  delete word;
  return -1;
}

int linhaed(char **matriz, int tamanho, char *palavra, int *coluna){//esquerda direita
  int i;
  char *filter, *word;

  filter = new char[tamanho];
  word = new char[tamanho];

  for (i = 0; i < tamanho; i++) {
    strcpy(word, matriz[i]);

    filter = strstr(word, palavra);
    if(filter != NULL){
      *coluna = filter - word;
      delete filter;
      return i;
    }
  }

  delete filter;
  return -1;
}

int colunacb(char **matriz, int tamanho, char *palavra, int *coluna){//cima baixo
  int i, j, k, linha;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  for (i = 0; i < tamanho; i++) {
    k = 0;
    for (j = 0; j < tamanho; j++) {
      word[k] = matriz[j][i];
      k++;
    }

    word[k] = '\0';

    filter = strstr(word, palavra);
    if(filter != NULL){
      *coluna = i;
      linha = filter - word;
      return linha;
    }
  }

  delete filter;
  delete word;
  return -1;
}

int colunabc(char **matriz, int tamanho, char *palavra, int *coluna){//baixo cima
  int i, j, k;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  for (i = 0; i < tamanho; i++) {
    k = 0;
    for (j = tamanho - 1; j >= 0; j--) {
      word[k] = matriz[j][i];
      k++;
    }
    word[k] = '\0';

    filter = strstr(word, palavra);
    if(filter != NULL){
      *coluna = i;
      return (tamanho - 1) - (filter - word) + 1;
    }
  }

  delete filter;
  delete word;
  return -1;
}

int diagonalPrin(char **matriz, int tamanho, char *palavra, int *coluna){
  int i, j, k = 0;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  for (i = 0; i < tamanho; i++) {
    for (j = 0; j < tamanho; j++) {
      if(i == j){
        word[k] = matriz[i][j];
        k++;
      }
    }
  }
  word[k] = '\0';
  filter = strstr(word, palavra);
  if(filter != NULL){
    *coluna = filter - word;
    return filter - word;
  }
  delete filter;
  delete word;
  return -1;
}

int diagonalPrinInv(char **matriz, int tamanho, char *palavra, int *coluna){
  int i, j, k = 0;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  for (i = tamanho - 1; i >= 0; i--) {
    for (j = tamanho - 1; j >= 0; j--) {
      if(i == j){
        word[k] = matriz[i][j];
        k++;
      }
    }
  }
  word[k] = '\0';
  filter = strstr(word, palavra);
  if(filter != NULL){
    *coluna = (tamanho - 1) - (filter - word);
    return (tamanho - 1) - (filter - word);
  }
  delete filter;
  delete word;
  return -1;
}

int diagonalSecun(char **matriz, int tamanho, char *palavra, int *coluna){
  int i, j, k, c;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  k = 0;
  i = 0;
  j = tamanho - 1;

  for (c = 0; c < tamanho; c++) {
    word[k] = matriz[i][j];
    i++;
    j--;
    k++;
  }
  word[k] = '\0';
  filter = strstr(word, palavra);
  if(filter != NULL){
    *coluna = (tamanho - 1) - (filter - word);
    return filter - word;
  }

  delete filter;
  delete word;
  return -1;
}

int diagonalSecunInv(char **matriz, int tamanho, char *palavra, int *coluna){
  int i, j, k, c;
  char *word, *filter;

  filter = new char[tamanho];
  word = new char[tamanho];

  k = 0;
  i = tamanho-1;
  j = 0;

  for (c = 0; c < tamanho; c++) {
    word[k] = matriz[i][j];
    i--;
    j++;
    k++;
  }
  word[k] = '\0';
  filter = strstr(word, palavra);
  if(filter != NULL){
    *coluna = filter - word;
    delete filter;
    delete word;
    return (tamanho - 1) - (filter - word);
  }
  delete filter;
  delete word;
  return -1;
}

int main() {
  char **jogo, *busca;
  int linha, coluna, tamanho, i;

  cout << "Digite o tamanho da matriz\n";
  cin >> tamanho;

  busca = new char[tamanho];

  jogo = new char *[tamanho+1];
  for(i = 0; i < tamanho; i++) {
    jogo[i] = new char[tamanho];
  }

  cout << "Entre com a matriz:\n";
  for (i = 0; i < tamanho; i++){
    cin >> jogo[i];
  }

  cout << "Entre com a palavra que deseja buscar:\n";
  cin >> busca;

  linha = -1;
  coluna = -1;
  linha = linhade(jogo, tamanho, busca, &coluna);

  if(linha >= 0 && coluna >= 0){
    cout << "Achou direita para esquerda\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = linhaed(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou esquerda para direita\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = colunacb(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou coluna de cima para baixo\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = colunabc(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou coluna de baixo para cima\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = diagonalPrin(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou na diagonal principal da esquerda para direita\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = diagonalPrinInv(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou na diagonal principal da direita para esquerda\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = diagonalSecun(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou na diagonal secundaria da direita para esquerda\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  linha = -1;
  coluna = -1;
  linha = diagonalSecunInv(jogo, tamanho, busca, &coluna);
  if(linha >= 0 && coluna >= 0){
    cout << "Achou na diagonal secundaria da esquerda para esquerda\n";
    cout << "Linha: " << linha + 1 << '\n';
    cout << "Coluna: " << coluna << '\n';
  }

  cout << "Busca finalizada com sucesso";

  delete jogo;
  delete busca;
  return 0;
}
