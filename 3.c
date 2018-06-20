#include <stdio.h>

void printar_jogo_velha(char matrix[3][3]){
  printf("\n");
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if(matrix[i][j] == 'x' || matrix[i][j] == 'o'){
        printf("%c   ", matrix[i][j]);
      } else {
        printf("_   ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int finalizar_jogo(char matrix[3][3]){
  if(matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]){
    return 1;
  }else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]){
    return 1;
  }else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]){
    return 1;
  }else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]){
    return 1;
  }else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]){
    return 1;
  }else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]){
    return 1;
  }else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
    return 1;
  }else if(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix[0][2]){
    return 1;
  }
  return 0;
}

void jogada(char matrix[3][3], int jogador, char letra_jogador, char letra_oponente){
  int jogada_valida = 0;
  int linha, coluna;

  do {
    printf("Jogador %d (%c):\nlinha\n", jogador, letra_jogador);
    scanf("%d", &linha);
    printf("Coluna:\n");
    scanf("%d", &coluna);

    if(!(matrix[linha][coluna] == letra_jogador || matrix[linha][coluna] == letra_oponente)){
      matrix[linha][coluna] = letra_jogador;
      jogada_valida = 1;
      printar_jogo_velha(matrix);
    }else{
      printf("Jogada invalida\n");
    }
  } while( jogada_valida == 0);
}

void zerar_matriz(char matrix[3][3]){
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      matrix[i][j] = NULL;
    }
  }
}

int main(void) {
  int jogador;
  int jogar;
  int cont;
  char letra_jogador;
  char letra_oponente;

  do{
    char jg_velha[3][3];
    jogador = 1;
    jogar = 1;
    cont = 0;
    letra_jogador = 'x';
    letra_oponente = 'o';
    do {
      jogada(jg_velha, jogador, letra_jogador, letra_oponente); //chamada da jogada do jogador 1
      if(finalizar_jogo(jg_velha) == 1){
        printf("Jogador %d ganhou\n", jogador);
        cont = 9;
      }
      if (jogador == 1) {
        jogador = 2;
        letra_jogador = 'o';
        letra_oponente = 'x';
      }else{
        jogador = 1;
        letra_jogador = 'x';
        letra_oponente = 'o';
      }
      cont++;
    } while(cont < 9);
    if (cont == 8) {
      printf("Deu velha!\n");
    }
    printf("Deseja jogar novamente? 1 | 0\n");
    scanf("%d", &jogar );
  } while(jogar == 1);

  return 0;
}
