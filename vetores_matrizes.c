#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void primeira(){
  int a[10];
  int b[10];
  int *c;
  int index_a = 0, index_b = 0;
  int tamanho = sizeof(b)/sizeof(b[0]) + sizeof(a)/sizeof(a[0]);

  c = (int *) malloc(tamanho * sizeof(int));

  for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
    printf("Digite o valor %d inteiro para o vetor 1\n", i+1);
    scanf("%d", &a[i]);
  }

  for (int j = 0; j < sizeof(b)/sizeof(b[0]); j++) {
    printf("Digite o valor %d inteiro para o vetor 2\n", j+1);
    scanf("%d", &b[j]);
  }

  for (int k = 0; k < sizeof(b)/sizeof(b[0]) + sizeof(a)/sizeof(a[0]); k++) {
    if(k % 2 == 0){
      c[k] = a[index_a];
      index_a++;
    }else{
      c[k] = b[index_b];
      index_b++;
    }
  }

  for (int l = 0; l < sizeof(b)/sizeof(b[0]) + sizeof(a)/sizeof(a[0]); l++) {
    printf("%d - ", c[l]);
  }

  free(c); //limpa o ponteiro
  c = NULL; //evita brechas no sistema, atribuindo null ao ponteiro
}

void segunda(){
  int a[10], b[10], c[10], srch, cont;

  cont = 0;
  for(int i = 0; i < 10; i++){
    printf("Digite o valor %d, do vetor a\n", i+1);
    scanf("%d", &a[i]);
  }

  for(int j = 0; j < 10; j++){
    printf("Digite o valor %d, do vetor b\n", j+1);
    scanf("%d", &b[j]);
  }

  for(int k = 0; k < 10; k++){
    printf("Digite o valor %d, do vetor c\n", k+1);
    scanf("%d", &c[k]);
  }

  printf("Qual o valor que está procurando?\n");
  scanf("%d", &srch);

  for (int z = 0; z < 10; z++) {
    if(a[z] == srch){
      printf("vetor a - %d\n", a[z]);
      cont++;
    }
    if(b[z] == srch){
      printf("vetor b - %d\n", b[z]);
      cont++;
    }
    if(c[z] == srch){
      printf("vetor c - %d\n", c[z]);
      cont++;
    }
  }

  printf("Aparece %d vezes\n", cont);
}

void terceira(){
  int a[10], b[10], c[10];

  for(int i = 0; i < 10; i++){
    printf("Digite o valor %d, do vetor a\n", i+1);
    scanf("%d", &a[i]);
  }

  for(int j = 0; j < 10; j++){
    printf("Digite o valor %d, do vetor b\n", j+1);
    scanf("%d", &b[j]);
  }

  for(int k = 0; k < 10; k++){
    printf("Digite o valor %d, do vetor c\n", k+1);
    scanf("%d", &c[k]);
  }

  printf("\nUniao: \n");
  for (int z = 0; z < 10; z++) {
    printf("%d - %d - %d - ", a[z], b[z], c[z]);
  }

  printf("\nIntersecao\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if(a[i] == b[j] && b[j] == c[k]){
          printf("%d ", a[i]);
        }
      }
    }
  }

}

void quarta(){
  int **matrix, tamanho, simetrica;
  simetrica = 1;

  printf("Digite o tamanho da matriz: \n");
  scanf("%d", &tamanho);

  matrix = (int **) malloc(tamanho * sizeof(int *));

  for (int i = 0; i < tamanho; i++) {
      matrix[i] = (int *) malloc(tamanho * sizeof(int));
  }

  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("Linha: %d Coluna: %d\n", i+1, j+1);
      scanf("%d", &matrix[i][j]);
    }
  }

  for (int i = 0; i < tamanho; i++) {
      for (int j = 0; j < tamanho; j++) {
          if(i != j){
              if(!(matrix[i][j] == matrix[j][i])){
                simetrica = 0;
                break;
              }
          }
      }
      if(!simetrica){
        break;
      }
  }

  if(simetrica){
    printf("E simetrica");
  }else{
    printf("Nao e simetrica");
  }

}

void quinta(){
  int **matrix, tamanho, determinante, p1, p2, p3, s1, s2, s3, col;

  printf("Digite o tamanho da matriz: \n");
  scanf("%d", &tamanho);

  matrix = (int **) malloc(tamanho * sizeof(int *));

  for (int i = 0; i < tamanho; i++) {
      matrix[i] = (int *) malloc(tamanho * sizeof(int));
  }

  srand((int)time(NULL));
  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      matrix[i][j] = rand() % 100;
    }
  }

  for (int i = 0; i < tamanho; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  p1 = 1;
  p2 = 1;
  p3 = 1;
  s1 = 1;
  s2 = 1;
  s3 = 1;

  for (int i = 0; i < tamanho; i++) {
      p1 = p1 * matrix[i][i];
      if(i+1 < tamanho){
        p2 = p2 * matrix[i][i+1];
        p3 = p3 * matrix[i+1][i];
      }else{
        p2 = p2 * matrix[i][0];
        p3 = p3 * matrix[0][i];
      }
  }

  col = tamanho - 2;
  for (int i = 0; i < tamanho; i++) {
    s1 = s1 * matrix[col][i];
    col--;
    if(col < 0){
      col = tamanho - 1;
    }
  }

  col++;
  for (int i = 0; i < tamanho; i++) {
    s2 = s2 * matrix[col][i];
    col--;
    if(col < 0){
      col = tamanho - 1;
    }
  }

  col = 0;
  for (int i = 0; i < tamanho; i++) {
    s3 = s3 * matrix[col][i];
    col--;
    if(col < 0){
      col = tamanho - 1;
    }
  }

  determinante = (p1 + p2 + p3) - (s1 + s2 + s3);

  printf("Determinante e: %d\n", determinante);
}

int main() {
  int qst;

  printf("Digite o numero da questao:\n");
  scanf("%d", &qst);

  switch (qst) {
    case 1:
      primeira();
      break;
    case 2:
      segunda();
      break;
    case 3:
      terceira();
      break;
    case 4:
      quarta();
      break;
    case 5:
      quinta();
      break;
  }


  return 0;
}
