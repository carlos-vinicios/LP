#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
=======
int entrada, saida, poslinha, poscoluna, preso, exec;

>>>>>>> master
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

<<<<<<< HEAD
void setarMatriz(char **matrix, char **lasts_pos, int linhas, int colunas){
=======
void setarMatriz(char **matrix, char **mind, int linhas, int colunas){
>>>>>>> master
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        if(i == 0 || i == linhas-1){
          matrix[i][j] = '*';
        }else if((j == 0 && i > 0) || (j == colunas-1 && i > 0)){
          matrix[i][j] = '*';
        }else{
          matrix[i][j] = ' ';
        }
<<<<<<< HEAD
        lasts_pos[i][j] = ' ';
=======
        mind[i][j] = ' ';
>>>>>>> master
      }
    }
}

void make_wall(char **matrix, int linhas, int colunas){
    int paredeLinha, paredeColuna;
    for(int i = 1; i < linhas-1; i++){
      for(int j = 1; j < colunas-1; j++){
<<<<<<< HEAD
        paredeLinha = rand() % linhas * 2;
        paredeColuna = rand() % colunas * 2;
=======
        paredeLinha = rand() % 50;
        paredeColuna = rand() % 50;
>>>>>>> master
        if(paredeLinha < linhas-1 && paredeColuna < colunas-1){
          matrix[paredeLinha][paredeColuna] = '*';
        }
      }
    }
}

<<<<<<< HEAD
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
=======
void in_out(char **matrix, char **mind, int linhas, int colunas){
  entrada = rand() % linhas - 1;
  saida = rand() % linhas - 1;

  matrix[entrada][0] = 'i';
  mind[entrada][0] = '.';
  poslinha = entrada;
  poscoluna = 0;
  matrix[saida][colunas - 1] = ' ';
}

void direita(char **matrix, char **mind, char marker){
  matrix[poslinha][poscoluna] = ' ';
  mind[poslinha][poscoluna] = marker;
  poscoluna++;
  matrix[poslinha][poscoluna] = 'i';
}

void esquerda(char **matrix, char **mind, char marker){
  matrix[poslinha][poscoluna] = ' ';
  mind[poslinha][poscoluna] = marker;
  poscoluna--;
  matrix[poslinha][poscoluna] = 'i';
}

void cima(char **matrix, char **mind, char marker){
  matrix[poslinha][poscoluna] = ' ';
  mind[poslinha][poscoluna] = marker;
  poslinha++;
  matrix[poslinha][poscoluna] = 'i';
}

void baixo(char **matrix, char **mind, char marker){
  matrix[poslinha][poscoluna] = ' ';
  mind[poslinha][poscoluna] = marker;
  poslinha--;
  matrix[poslinha][poscoluna] = 'i';
}

int escape(char **matrix, char **mind, int colunas){
  if(matrix[poslinha][poscoluna] == matrix[saida][colunas - 1]){
      return 0;
  }else{
      if(matrix[poslinha][poscoluna + 1] != '*' && mind[poslinha][poscoluna + 1] != '.'){
        direita(matrix, mind, '.');
      }else if(matrix[poslinha + 1][poscoluna] != '*' && mind[poslinha + 1][poscoluna] != '.'){
        cima(matrix, mind, '.');
      }else if(matrix[poslinha][poscoluna - 1] != '*' && mind[poslinha][poscoluna - 1] != '.'){
        esquerda(matrix, mind, '.');
      }else if(matrix[poslinha - 1][poscoluna] != '*' && mind[poslinha - 1][poscoluna] != '.'){
        baixo(matrix, mind, '.');
      }else{
        preso = 1;
      }
>>>>>>> master
  }
  return 1;
}

int main() {
<<<<<<< HEAD
  int linhas, colunas, entrada, saida, pos[2];
  char **matrix, **lasts_pos;
=======
  int linhas, colunas;
  char **matrix;
  char **mind;
>>>>>>> master
  srand( (unsigned)time(NULL) );

  // printf("Digite a quantidade de linhas do labirinto\n");
  // scanf("%d", &linhas);
  // printf("Digite a quantidade de colunas do labirinto\n");
  // scanf("%d", &colunas);

<<<<<<< HEAD
  linhas = 20;
  colunas = 40;
=======
  matrix = (char**) calloc(linhas, sizeof(char *)); //cria um vetor de ponteiros para char
  mind = (char**) calloc(linhas, sizeof(char *)); //cria um vetor de ponteiros para char
>>>>>>> master

  matrix = (char**) calloc(linhas, sizeof(char *)); //cria um vetor de ponteiros para char
  lasts_pos = (char**) calloc(linhas, sizeof(char *));
  for (int i = 0; i < linhas; i++) {
    matrix[i] = (char*) calloc(colunas, sizeof(char)); //cria espaço char para a matriz
<<<<<<< HEAD
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
=======
    mind[i] = (char*) calloc(colunas, sizeof(char)); //cria espaço char para a matriz
  }

  setarMatriz(matrix, mind, linhas, colunas); //cria a matriz com os espaços vazios e bordas
  make_wall(matrix, linhas, colunas); //cria as paredes do labirinto
  in_out(matrix, mind, linhas, colunas); //define a entrada e a saida do labirinto
>>>>>>> master

  printarMatriz(matrix, linhas, colunas); //imprime a matriz na tela

  do{
    clrscr();
    make_move(matrix, pos, last_pos);
    printarMatriz(matrix, linhas, colunas);
<<<<<<< HEAD
    printf("%d -- %d\n", last_pos[0], lasts_pos);
    getchar();
  }while (escape(matrix, linhas, colunas, saida));
  printf("Saiu\n");
=======
    if(preso){
      do{
        if(matrix[poslinha][poscoluna + 1] != '*' && mind[poslinha][poscoluna + 1] != '0'){
          direita(matrix, mind, '0');
        }else if(matrix[poslinha + 1][poscoluna] != '*' && mind[poslinha + 1][poscoluna] != '0'){
          cima(matrix, mind, '0');
        }else if(matrix[poslinha][poscoluna - 1] != '*' && mind[poslinha][poscoluna - 1] != '0'){
          esquerda(matrix, mind, '0');
        }else if(matrix[poslinha - 1][poscoluna] != '*' && mind[poslinha - 1][poscoluna] != '0'){
          baixo(matrix, mind, '0');
        }
        clrscr();
        printarMatriz(matrix, linhas, colunas);
      }while(matrix[poslinha][poscoluna + 1] == ' ' || matrix[poslinha + 1][poscoluna] == ' ' || matrix[poslinha][poscoluna - 1] == ' ' || matrix[poslinha - 1][poscoluna] == ' ');
      exec = 1;
    }else{
      exec = escape(matrix, mind, colunas);
    }
  }while (exec);

>>>>>>> master
  return 0;
}
