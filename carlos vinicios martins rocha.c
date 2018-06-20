#include <stdio.h>

int main() {
  char caracter;

  do {
    printf("Digite a letra\n");
    scanf(" %c", &caracter);

    switch(caracter){
        case 'E':
        case 'e':
          for (int i = 0; i < 5; i++) {
            if (i % 2 == 0) {
              for (int j = 0; j < 7; j++) {
                printf("*");
              }
            }else{
              printf("*");
            }
            printf("\n");
          }
          break;
        case 'O':
        case 'o':
          for (int i = 0; i < 5; i++) {
            if (i == 0 || i == 4) {
              for (int j = 0; j < 6; j++) {
                printf("*");
              }
            }else{
              for (int z = 0; z < 2; z++) {
                printf("*");
              }
              for (int x = 0; x < 2; x++) {
                printf(" ");
              }
              for (int y = 0; y < 2; y++) {
                printf("*");
              }
            }
            printf("\n");
          }
          break;
        case 'Z':
        case 'z':
          for (int i = 0; i < 5; i++) {
            if (i == 0 || i == 4) {
              for (int j = 0; j < 5; j++) {
                printf("*");
              }
            }else{
              for (int k = 1; k < espaco_z; k++) {
                printf(" ");
              }
              printf("*");
            }
            espaco_z--;
            printf("\n");
          }
          break;
        default:
          printf("Desculpa essa letra ainda não está disponivel");
          break;
      }

      printf("\n\nDeseja executar novamente?\n1 - yes\n2 - no");
      scanf("%d", &exec);

  } while(exec == 1);
  return 0;
}
