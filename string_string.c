#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void primeira_tarefa(){
//   char *texto;
//   char *busca;
//   int ocorrencias = 0, cont = 0;
//   char *p;
//
//   texto = (char *) calloc(100, sizeof(char));
//   busca = (char *) calloc(50, sizeof(char));
//
//   printf("Digite um texto\n");
//   gets(texto);
//
//   printf("O que desejas procurar?\n");
//   gets(busca);
//
//   p = strstr(texto, busca);
//   printf("Position %d\n", p - texto);
//   ocorrencias++;
//
//   do{
//     if(strstr(p, busca) != NULL){
//       ocorrencias++;
//       p = strstr(p + strlen(busca), busca);
//       printf("Achei %d\n", p - texto);
//     }
//     cont++;
//   }while(strstr(p + strlen(busca), busca) != NULL);
//
//   printf("ocorrencias %d\n", ocorrencias);
//
//   free(texto);
//   free(busca);
//   texto = NULL;
//   busca = NULL;
// }

int crtlf(char *texto, char *busca){
  char *p;
  int ocorrencias = 0, cont = 0;
  p = strstr(texto, busca);
  if(p != NULL){
    ocorrencias++;
  }
  do{
    if(strstr(p, busca) != NULL){
      ocorrencias++;
      p = strstr(p + strlen(busca), busca);
    }
    cont++;
  }while(strstr(p + strlen(busca), busca) != NULL);

  return ocorrencias;
}

int main() {
  char *texto;
  char *busca;
  char *palavra;
  int tam_texto = 100, tam_busca = 50, qtd = 0, last_pos = 0, index;
  texto = (char *) calloc(100, sizeof(char));
  busca = (char *) calloc(50, sizeof(char));

  printf("Digite um texto\n");
  gets(texto);

  printf("O que desejas procurar?\n");
  gets(busca);

  for (int i = 0; i < strlen(busca); i++) {
    if(busca[i] == ' ' || busca[i] == '!' || busca[i] == '.' || busca[i] == ';' || busca[i] == '?' || busca[i] == ':' || i == strlen(busca) - 1){
      if(i == strlen(busca) - 1){
        i++;
      }
      palavra = (char *) calloc(i+1, sizeof(char));
      index = 0;
      for (int j = last_pos; j < i; j++) {
        palavra[index] = busca[j];
        index++;
      }
      qtd = crtlf(texto, palavra);

      printf("%s - %d\n", palavra, qtd);
      free(palavra);
      palavra = NULL;
      last_pos = i+1;
    }
  }

  free(texto);
  free(busca);
  texto = NULL;
  busca = NULL;
  return 0;
}
