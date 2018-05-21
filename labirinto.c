#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clrscr(){ //limpa a tela em ambos os sistemas operacionais
  system("clear");
}

void printarMatriz(char **matrix, int linhas, int colunas){
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        printf("%c", matrix[i][j]);
      }
      printf("\n");
    }
}

void setarMatriz(char **matrix, char **lasts_pos, int linhas, int colunas){
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        if(i == 0 || i == linhas-1){
          matrix[i][j] = '*';
        }else if((j == 0 && i > 0) || (j == colunas-1 && i > 0)){
          matrix[i][j] = '*';
        }else{
          matrix[i][j] = ' ';
        }
        lasts_pos[i][j] = ' ';
      }
    }
}

void make_wall(char **matrix, int linhas, int colunas){
    int paredeLinha, paredeColuna;
    for(int i = 1; i < linhas-1; i++){
      for(int j = 1; j < colunas-1; j++){
        paredeLinha = rand() % linhas * 2;
        paredeColuna = rand() % colunas * 2;
        if(paredeLinha < linhas-1 && paredeColuna < colunas-1){
          matrix[paredeLinha][paredeColuna] = '*';
        }
      }
    }
}

void make_move(char **matrix, int *pos, int **last_pos){
  if(matrix[pos[0]][pos[1]+1] == ' ' && last_pos[pos[0]][pos[1]+1] != '.'){
    matrix[pos[0]][pos[1]+1] = 'P';
    matrix[pos[0]][pos[1]] = ' ';
    last_pos[pos[0]][pos[1]] = '.';
    printf("Direita\n");
    pos[1]++;
  }else if(matrix[pos[0]+1][pos[1]] == ' ' && last_pos[pos[0]+1][pos[1]] != '.'){
    matrix[pos[0]+1][pos[1]] = 'P';
    matrix[pos[0]][pos[1]] = ' ';
    last_pos[pos[0]][pos[1]] = '.';
    printf("Baixo\n");
    pos[0]++;
  }else if(matrix[pos[0]][pos[1]-1] == ' ' && last_pos[pos[0]][pos[1]-1] == '.'){
    matrix[pos[0]][pos[1]-1] = 'P';
    matrix[pos[0]][pos[1]] = ' ';
    last_pos[pos[0]][pos[1]] = '.';
    printf("Esquerda\n");
    pos[1]--;
  }else if(matrix[pos[0]-1][pos[1]] == ' ' && last_pos[pos[0]-1][pos[1]] == '.'){
    matrix[pos[0]-1][pos[1]] = 'P';
    matrix[pos[0]][pos[1]] = ' ';
    last_pos[pos[0]][pos[1]] = '.';
    printf("Cima\n");
    pos[0]--;
  }
}

int escape(char **matrix, int linhas, int colunas, int saida){
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if(matrix[i][j] == 'P' && i == saida && j == colunas - 1){
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int linhas, colunas, entrada, saida, pos[2];
  char **matrix, **lasts_pos;
  srand( (unsigned)time(NULL) );

  // printf("Digite a quantidade de linhas do labirinto\n");
  // scanf("%d", &linhas);
  // printf("Digite a quantidade de colunas do labirinto\n");
  // scanf("%d", &colunas);

  linhas = 20;
  colunas = 40;

  matrix = (char**) calloc(linhas, sizeof(char *)); //cria um vetor de ponteiros para char
  lasts_pos = (char**) calloc(linhas, sizeof(char *));
  for (int i = 0; i < linhas; i++) {
    matrix[i] = (char*) calloc(colunas, sizeof(char)); //cria espaço char para a matriz
    lasts_pos[i] = (char*) calloc(colunas, sizeof(char));
  }

  setarMatriz(matrix, lasts_pos, linhas, colunas); //cria a matriz com os espaços vazios e bordas
  make_wall(matrix, linhas, colunas); //cria as paredes do labirinto

  entrada = rand() % linhas - 1;
  saida = rand() % linhas - 1;
  matrix[entrada][0] = 'P';
  matrix[saida][colunas - 1] = ' ';
  pos[0] = entrada;
  pos[1] = 0;
  last_pos[pos[0]][pos[1]] = '.';

  printarMatriz(matrix, linhas, colunas); //imprime a matriz na tela

  do{
    clrscr();
    make_move(matrix, pos, last_pos);
    printarMatriz(matrix, linhas, colunas);
    printf("%d -- %d\n", last_pos[0], lasts_pos);
    getchar();
  }while (escape(matrix, linhas, colunas, saida));
  printf("Saiu\n");
  return 0;
}
