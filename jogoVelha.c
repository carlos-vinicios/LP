#include <stdio.h>

int main() {
  char jogoVelha[9];
  int j1, j2, v1, v2;
  int cont = 1;
  int condicao, condicao2, condicao3;

  for (int z = 0; z < 9; z++) {
    jogoVelha[z] = '_';
  }

  for (int i = 0; i < 9; i++) {
    do {
      printf("Jogador 1(x):\n");
      scanf("%d", &j1 );
      if( jogoVelha[j1] == 'x'|| jogoVelha[j1] == 'o')
      {
        printf("Jogada invalida, jogue novamente\n");
        v1 = 0;
      }else{
        jogoVelha[j1] = 'x';
        v1 = 1;
      }
    } while(v1 != 1);

    do {
      printf("Jogador 2(o):\n");
      scanf("%d", &j2 );
      if( jogoVelha[j2] == 'o' || jogoVelha[j2] == 'x'){
        printf("Joga invalida, jogue novamente\n");
        v2 = 0;
      }else{
        jogoVelha[j2] = 'o';
        v2 = 1;
      }
    } while(v2 != 1);

    for ( int j = 0; j < 9; j++) {
      printf("%c ", jogoVelha[j]);
      if(cont == 3){
        printf("\n");
        cont = 0;
      }
      cont++;
    }

    condicao = 0;
    for (int i = 0; i < 3; i++) {
      if(jogoVelha[condicao] == 'x' && jogoVelha[condicao+1] == 'x' && jogoVelha[condicao+2] == 'x'){
        printf("Jogador 1 ganhou");
        return 0;
      }else if(jogoVelha[condicao] == 'o' && jogoVelha[condicao+1] == 'o' && jogoVelha[condicao+2] == 'o'){
        printf("Jogador 2 ganhou");
        return 0;
      }
      condicao += 3;
    }
    condicao2 = 0;
    if(jogoVelha[condicao2] == 'x' && jogoVelha[condicao2+4] == 'x' && jogoVelha[condicao2+8] == 'x'){
      printf("Jogador 1 ganhou");
      return 0;
    }else if(jogoVelha[condicao2] == 'o' && jogoVelha[condicao2+4] == 'o' && jogoVelha[condicao2+8] == 'o'){
      printf("Jogador 2 ganhou");
      return 0;
    }

    condicao3 = 2;
    if(jogoVelha[condicao3] == 'x' && jogoVelha[condicao3+2] == 'x' && jogoVelha[condicao3+4] == 'x'){
      printf("Jogador 1 ganhou");
      return 0;
    }else if(jogoVelha[condicao3] == 'o' && jogoVelha[condicao3+2] == 'o' && jogoVelha[condicao3+4] == 'o'){
      printf("Jogador 2 ganhou");
      return 0;
    }
  }
  printf("Deu velha");
  return 0;
}
