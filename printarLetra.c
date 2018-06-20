#include <stdio.h>
#include <math.h>

int main() {
  char caracter;
  int exec = 1;

  do {
    int fonte;
    int execusoes, espaco_meio_a, espaco_borda_a, meio_a;
    int meio_b, espaco_meio_b;
    int bordas_c;
    int espaco_d, bordas_d;
    int meio_e, meio_f, meio_h, meio_v, borda_v, meio_x, lado_1_x;
    int espaco_k, espaco_r = 3;
    int espaco_z = 5;

    printf("Digite a letra\n");
    scanf(" %c", &caracter);
    printf("Digite o tamanho da letra:\n");
    scanf(" %d", &fonte);

    switch (caracter) {
      case 'A':
      case 'a':
        execusoes = 5*fonte;
        if (fonte != 1) {
          meio_a = execusoes + fonte;
          if (fonte % 2 != 0) {
            meio_a--;
          }
        }else{
          meio_a = 5;
        }
        printf("%d\n", meio_a );
        espaco_meio_a = 1*fonte;
        espaco_borda_a = 8*fonte;
        for (int i = 0; i < execusoes; i++) {
          for (int w = 0; w < espaco_borda_a; w++) {
            printf(" ");
          }
          if (i == 0) {
            for (int w = 0; w < espaco_meio_a; w++) {
              printf("*");
            }
          }else if(i == floor(execusoes/2)){
            for (int j = 0; j < meio_a; j++) {
              printf("*");
            }
            espaco_meio_a += 2;
          }else{
            printf("*");
            for (int k = 0; k < espaco_meio_a; k++) {
              printf(" ");
            }
            printf("*");
            espaco_meio_a += 2;
          }
          printf("\n");
          espaco_borda_a--;
        }
        break;
      case 'B':
      case 'b':
        execusoes = 7 * fonte;
        meio_b = 6*fonte;
        for (int i = 0; i < execusoes; i++) {
          if (i == 0 || i == (execusoes / 2 - 1) || i == execusoes - 1) { //seria melhor apenas para tamanhos impares, pois a divisão ficaria correta
            for (int j = 0; j < meio_b; j++) {
              printf("*");
            }
          } else {
            printf("*");
            for (int k = 0; k < meio_b - 1; k++) {
              printf(" ");
            }
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'C':
      case 'c':
        execusoes = 4 * fonte;
        bordas_c = 6 * fonte;
        for (int j = 0; j < execusoes; j++) {
          if (j == 0 || j == execusoes - 1) {
            for (int i = 0; i < bordas_c; i++) {
              printf("*");
            }
          }else{
              printf("*");
          }
          printf("\n");
        }
        break;
      case 'D':
      case 'd':
        execusoes = 5 * fonte;
        espaco_d =  6 * fonte + fonte - 1;
        bordas_d = 7 * fonte;
        for (int i = 0; i < execusoes; i++) {
          if (i == 0 || i == execusoes - 1) {
            for (int j = 0; j < bordas_d; j++) {
              printf("*");
            }
          }else{
            printf("*");
            for (int k = 0; k < espaco_d; k++) {
              printf(" ");
            }
            printf("*");
            if(i < (execusoes / 2)){
              espaco_d++;
            }else{
              espaco_d--;
            }
          }
          printf("\n");
        }
        break;
      case 'E':
      case 'e':
        execusoes = 5 * fonte;
        meio_e = 7 * fonte;
        if(execusoes % 2 == 0){
          execusoes++;
        }
        for (int i = 0; i < execusoes; i++) {
          if (i == 0 || i == floor(execusoes/2) || i == execusoes - 1) {
            for (int j = 0; j < meio_e; j++) {
              printf("*");
            }
          }else{
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'F':
      case 'f':
        execusoes = 7 * fonte;
        meio_f = 7 * fonte;
        if(execusoes % 2 == 0){
          execusoes++;
        }
        for (int i = 0; i < execusoes; i++) {
          if (i == 0 || i == floor(execusoes/2) - 1) {
            for (int j = 0; j < meio_f; j++) {
              printf("*");
            }
          }else{
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'G':
      case 'g':
        break;
      case 'H':
      case 'h':
        execusoes = 5 * fonte;
        meio_h = 4 * fonte;
        if(execusoes % 2 == 0){
          execusoes--;
        }
        for (int i = 0; i < execusoes; i++) {
          printf("*");
          for (int j = 0; j < meio_h; j++) {
            if (i == execusoes/2) {
              printf("*");
            }else{
              printf(" ");
            }
          }
          printf("*\n");
        }
        break;
      case 'I':
      case 'i':
        execusoes = 4 * fonte;
        for (int i = 0; i < execusoes; i++) {
          printf("*\n");
        }
        break;
      case 'J':
      case 'j':
        execusoes = 5 * fonte;
        for(int i = 0; i < execusoes; i++){
          if (i == 0) {
            for(int j = 0; j < execusoes; j++){
              printf("*");
            }
          }else if(i == execusoes - 1){
            for(int j = 0; j < execusoes / 2; j++){
              printf("*");
            }
          }else{
            for(int j = 0; j < execusoes / 2; j++){
              printf(" ");
            }
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'K':
      case 'k':
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 4; j++) {
            printf("*");
            for (int k = 0; k < espaco_k; k++) {
              printf(" ");
            }
            printf("*");
            printf("\n");
            if (i == 1) {
              espaco_k++;
            }else{
              espaco_k--;
            }
          }
          espaco_k++;
        }
        break;
      case 'L':
      case 'l':
        execusoes = 5 * fonte;
        for(int i = 0; i < execusoes; i++){
          if(i == execusoes - 1){
            for(int j = 0; j < execusoes - 1; j++){
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
      case 'P':
      case 'p':
        execusoes = 5 * fonte;
        for(int i = 0; i < execusoes; i++){
          if(i == 0 || i == execusoes / 2){
            for(int j = 0; j < execusoes-1; j++){
              printf("*");
            }
          }else if(i > 0 && i < execusoes / 2){
            printf("*");
            for(int k = 0; k < execusoes-2; k++){
              printf(" ");
            }
            printf("*");
          } else{
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'R':
      case 'r':
        for (int i = 0; i < 6; i++) {
          if (i == 0 || i == 2) {
            for (int j = 0; j < 6; j++) {
              printf("*");
            }
          }else{
            if (i == 1) {
              printf("*");
              for (int k = 0; k < espaco_r + 1; k++) {
                printf(" ");
              }
              printf("*");
            }
            if (i >= 3) {
              printf("*");
              for (int z = 0; z < espaco_r; z++) {
                printf(" ");
              }
              printf("*");
              espaco_r++;
            }
          }
          printf("\n");
        }
        break;
      case 'S':
      case 's':
        execusoes = 5 * fonte;
        for(int i = 0; i < execusoes; i++){
          if(i == 0 || i == ceil(execusoes/2) || i == execusoes - 1){
            for(int j = 0; j < execusoes -1; j++){
              printf("*");
            }
          }else if( i < ceil(execusoes/2)){
            printf("*");
          }else{
            for(int k = 0; k < execusoes - 2; k++){
              printf(" ");
            }
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'T':
      case 't':
        execusoes = 5 * fonte;
        if(fonte > 1){
          execusoes = execusoes / 2;
        }
        for(int i = 0; i < execusoes - 1; i++){
          if(i == 0){
            for(int j = 0; j < execusoes; j++){
              printf("*");
            }
          }else{
            for(int j = 0; j < execusoes/2; j++){
              printf(" ");
            }
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'U':
      case 'u':
        execusoes = 5 * fonte;
        for (int i = 0; i < execusoes; i++) {
          if(i == execusoes - 1){
            for(int k = 0; k < execusoes; k++){
              printf("*");
            }
          } else{
            printf("*");
            for (int j = 0; j < execusoes - 2; j++) {
              printf(" ");
            }
            printf("*");
          }
          printf("\n");
        }
        break;
      case 'V':
      case 'v':
        execusoes = 5 * fonte;
        meio_v = (execusoes - 1) + (execusoes - 2);
        borda_v = 0;
        for (int i = 0; i < execusoes; i++) {
          for(int k = 0; k < borda_v; k++){
            printf(" ");
          }
          if(i == execusoes - 1){
            printf("*");
          }else{
            printf("*");
            for (int j = 0; j < meio_v; j++) {
              printf(" ");
            }
            printf("*\n");
          }
          borda_v++;
          meio_v -= 2;
        }
        break;
      case 'X':
      case 'x':
        execusoes = 5 * fonte;
        meio_x =  ceil(execusoes/2) * 2 - 1;
        lado_1_x = 0;
        for (int i = 0; i < execusoes; i++) {
          if(i <= ceil(execusoes/2)){
            for(int j = 0; j < lado_1_x; j++){
              printf(" ");
            }
            if( i != ceil(execusoes/2) ){
              printf("*");
              for(int k = 0; k < meio_x; k++){
                printf(" ");
              }
              printf("*");
              printf("\n");
              meio_x -= 2;
              lado_1_x++;
            }else{
              printf("*");
              printf("\n");
            }
          }else{
            meio_x += 2;
            lado_1_x--;
            for(int j = 0; j < lado_1_x; j++){
              printf(" ");
            }
            printf("*");
            for(int k = 0; k < meio_x; k++){
              printf(" ");
            }
            printf("*");
            printf("\n");
          }
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
