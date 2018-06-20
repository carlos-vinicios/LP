#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void grava(int **mat, int linhas, int colunas){
  FILE *arq;

  arq = fopen("matriz.txt", "w");

  if(arq == NULL){
    printf("Erro na gravação\n");
    return;
  }

  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      fprintf(arq, "%d ", mat[i][j]);
    }
    fputc('\n', arq);
  }

  fclose(arq);
}

void ler(int colunas){
  FILE *arq;
  char *text;

  text = (char *) malloc(colunas * sizeof(char));
  arq = fopen("matriz.txt", "r");
  while(!feof(arq)){
    fread(text, colunas * sizeof(char), 1, arq);
  }

  printf("%s", text);
  
  free(text);
  fclose(arq);
}

int main() {
  int **mat, linhas, colunas;

  scanf("%d\n", &linhas);
  scanf("%d\n", &colunas);

  mat = (int **) malloc(linhas * sizeof(int *));

  for (int i = 0; i < colunas; i++) {
      mat[i] = (int *) malloc(colunas * sizeof(int));
  }

  printf("Digite os valores da matriz\n");
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      scanf("%d\n", &mat[i][j]);
    }
  }

  grava(mat, linhas, colunas);

  free(mat);

  ler(colunas);

  return 0;
}
