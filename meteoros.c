#include <stdio.h>
#include <stdlib.h>
#include <string.h> //funções de string
//#include <conio.h> //biblioteca que contem o kbhit ---------- funciona apenas no Windows

//bibliotecas necessárias para funcionamento no linux
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
//bibliotecas

int ptns = 10; //pontuação do jogo
int linhas = 16; //quantidade de linhas usadas para as matrizes do jogo
int colunas = 60; //quantidade de colunas usadas para as matrizes do jogo

int kbhit(void) //necessário para funcionamento no Linux
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

void pontos() { //exibe apenas a pontuação
  printf("Pontuacao: %d\n", ptns);
}

void clrscr(){ //limpa a tela em ambos os sistemas operacionais
  system("@cls||clear");
}

void check_colision(char eixos_meteoros[linhas][colunas], char eixos_disparos[linhas][colunas]){
  for (int i = 0; i < linhas; i++) {
    for(int j = 0; j < colunas; j++){
      if (eixos_disparos[i][j] == '|' && eixos_meteoros[i][j] == '*'){ //verifica a existencia de disparos
          eixos_disparos[i][j] = ' ';  //se sim, limpa ambos os espaços da matriz
          eixos_meteoros[i][j] = ' ';
          ptns += 2;
      }
    }
  }
}

void move_meteoros_disparos(char eixos_meteoros[linhas][colunas], char eixos_disparos[linhas][colunas]){ //separar as funçõesa
  char aux1[colunas];
  char aux2[colunas];

  if (strchr(eixos_disparos[0], '|') != NULL) {
    for (int j = 0; j < colunas; j++) {
      eixos_disparos[0][j] = ' ';
    }
  }
  if (strchr(eixos_meteoros[linhas - 1], '*') != NULL) {
    for (int k = 0; k < colunas; k++) {
      eixos_meteoros[linhas - 1][k] = ' ';
    }
    ptns -= 5;
  }
  for (int z = 0; z < linhas; z++) { //subida dos disparos
    strncpy(aux1, eixos_disparos[z+1], colunas);
    strncpy(eixos_disparos[z+1], eixos_disparos[z], colunas);
    strncpy(eixos_disparos[z], aux1, colunas);
  }
  check_colision(eixos_meteoros, eixos_disparos);
  for (int i = linhas-1; i > 0; i--){ //queda dos meteoros
    strncpy(aux2, eixos_meteoros[i-1], colunas);
    strncpy(eixos_meteoros[i-1], eixos_meteoros[i], colunas);
    strncpy(eixos_meteoros[i], aux2, colunas);
  }
  check_colision(eixos_meteoros, eixos_disparos);
}

///////////////////////////////////FUNÇÕES PARA METEOROS///////////////////////////////////
void init_meteoros(char eixos_meteoros[linhas][colunas]){ //inicializa as posições da matriz com espaços em branco
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      eixos_meteoros[i][j] = ' ';
    }
  }
}

void new_meteoro(char eixos_meteoros[linhas][colunas]){ //define a posição (coluna) de um novo meteoro
  int position = rand() % 400;
  if (position < colunas){
      eixos_meteoros[0][position] = '*';
  }
}

void render_meteoros_disparos(char eixos_meteoros[linhas][colunas], char eixos_disparos[linhas][colunas]){ //renderiza os meteoros em conjunto com os disparos
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if(eixos_disparos[i][j] == '|'){
        printf("%c", eixos_disparos[i][j]);
      }else{
        printf("%c", eixos_meteoros[i][j]);
      }
    }
    printf("\n");
  }
}

///////////////////////////////////FUNÇÕES PARA NAVE/////////////////////////////////////
void set_nave_posi(char eixo_nave[colunas], int nave_posi){ //define a posição inicial da nave
  for (int i = 0; i < colunas; i++) {
    eixo_nave[i] = ' ';
  }
  eixo_nave[nave_posi] = '_';
}

void render_nave(char eixo_nave[colunas]){ //renderiza o vetor da nave
  for (int i = 0; i < colunas; i++) {
    printf("%c", eixo_nave[i]);
  }
}

////////////////////////////////CONTROLE DE DISPAROS///////////////////////////////////////////
void init_disparos(char eixos_disparos[linhas][colunas]){ //inicia toda a matriz que contém os disparos
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      eixos_disparos[i][j] = ' ';
    }
  }
}

void set_disparo(char eixos_disparos[linhas][colunas], int nave_posi){ //define um novo disparo
  eixos_disparos[linhas - 1][nave_posi] = '|';
}

void disparo(char eixos_disparos[linhas][colunas], int nave_posi){ //função de disparo
    set_disparo(eixos_disparos, nave_posi);
    ptns -= 2;
}

//////////////////////////////////GRAFICOS DO JOGO/////////////////////////////////////////////
void load_graphics(char eixos_meteoros[linhas][colunas], char eixo_nave[colunas], int nave_posi, char eixos_disparos[linhas][colunas]){ //carrega todas as funções de inicialização
  init_disparos(eixos_disparos);
  init_meteoros(eixos_meteoros);
  set_nave_posi (eixo_nave, nave_posi);
}

void render_graphics(char eixos_meteoros[linhas][colunas], char eixos_disparos[linhas][colunas], char eixo_nave[colunas]){ //renderiza todos os gráficos
  clrscr();//limpa o console
  pontos();
  render_meteoros_disparos(eixos_meteoros, eixos_disparos);
  render_nave(eixo_nave);
}

int main() {
  char eixos_meteoros[linhas][colunas], eixos_disparos[linhas][colunas], eixo_nave[colunas]; //matries e vetor usado para a lógica do jogo
  int nave_posi = (colunas / 2)-1;

  //primeiro carregamento do jogo
  load_graphics(eixos_meteoros, eixo_nave, nave_posi, eixos_disparos);
  render_graphics(eixos_meteoros, eixos_disparos, eixo_nave);
  do {
    if(kbhit()){ //chamada toda vez que uma tecla é acionada no teclado
      char tecla = getchar(); //no Linux é utilizado getchar
      switch (tecla) {
        case 'd': //movimenta para a esquerda
        case 'D':
          if(nave_posi < colunas){
            nave_posi++;
          }
          break;
        case 'a': //movimenta para a direita
        case 'A':
          if(nave_posi > 0){
            nave_posi--;
          }
          break;
        case 32: //atira (utilizando espaço)
            disparo(eixos_disparos, nave_posi);
            break;
        default:
          break;
      }
      set_nave_posi(eixo_nave, nave_posi);
      move_meteoros_disparos(eixos_meteoros, eixos_disparos);
      render_graphics(eixos_meteoros, eixos_disparos, eixo_nave); //ver o que seria melhor para o jogo
      new_meteoro(eixos_meteoros);
    }
} while(ptns > 0);
  return 0;
}
