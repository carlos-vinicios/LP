#include <iostream>
#include <string.h>

using namespace std;

int killEquals(){
  FILE *data;
  char *linha, *musica;
  int size, cont;
  data = fopen("musicas.txt", "r");
  if(data == NULL)
    return 0; //erro

  fseek(data, 0, SEEK_END);
  size = ftell(data);
  rewind(data);

  linha = new char[size];

  while(fgets(linha, size, data) != NULL){
    for(int i = 0; i < strlen(size); i++){
      if(linha[i] === "/")
        cont++

      if(cont >= 4){
        musica = char[strlen(size) - i]
      }
    }
  }
  return 1;
}

int main(){
  int result;

  result = killEquals();

  if(result)
    cout << "Sucesso";
  else
    cout << "Erro";

  return 0;
}
