#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int entrada, int saida;

void clrscr(){ //limpa a tela em ambos os sistemas operacionais
  system("@cls||clear");
}

void printarMatriz(char **matrix, int linhas, int colunas){
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("%c", matrix[i][j]);
      }
      printf("\n");
    }
}

void setarMatriz(char **matrix, int linhas, int colunas){
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        if(i == 0 || i == linhas-1){
          matrix[i][j] = '*';
        }else if((j == 0 && i > 0) || (j == colunas-1 && i > 0)){
          matrix[i][j] = '*';
        }else{
          matrix[i][j] = ' ';
        }
      }
    }
}

void make_wall(char **matrix, int linhas, int colunas){
    int paredeLinha, paredeColuna;
    for(int i = 1; i < linhas-1; i++){
      for(int j = 1; j < colunas-1; j++){
        paredeLinha = rand() % 30;
        paredeColuna = rand() % 30;
        if(paredeLinha < linhas-1 && paredeColuna < colunas-1){
          matrix[paredeLinha][paredeColuna] = '*';
        }
      }
    }
}

void in_out(char **matrix, int linhas, int colunas){
  entrada = rand() % linhas - 1;
  saida = rand() % linhas - 1;

  matrix[entrada][0] = 'P';
  matrix[saida][colunas - 1] = ' ';
}

void escape(char **matrix, int linhas, int colunas){
    
}

int main() {
  int linhas, colunas;
  char **matrix;
  srand( (unsigned)time(NULL) );

  printf("Digite a quantidade de linhas do labirinto\n");
  scanf("%d", &linhas);
  printf("Digite a quantidade de colunas do labirinto\n");
  scanf("%d", &colunas);

  matrix = (char**) calloc(linhas, sizeof(char *)); //cria um vetor de ponteiros para char

  for (int i = 0; i < linhas; i++) {
    matrix[i] = (char*) calloc(colunas, sizeof(char)); //cria espaço char para a matriz
  }

  setarMatriz(matrix, linhas, colunas); //cria a matriz com os espaços vazios e bordas
  make_wall(matrix, linhas, colunas); //cria as paredes do labirinto
  in_out(matrix, linhas, colunas); //define a entrada e a saida do labirinto

  printarMatriz(matrix, linhas, colunas); //imprime a matriz na tela

  do{
    clrscr();
    printarMatriz(matrix, linhas, colunas);
  }while (escape(matrix, linhas, colunas));

  return 0;
}
