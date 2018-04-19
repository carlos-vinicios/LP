#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char numero[100];

  printf("Digite o numero que deseja formatar\n");
  scanf("%s", numero);

  for(int i = 0; i < strlen(numero); i++){
    if(numero[i] == ','){
      numero[i] = '.';
    }else if(numero[i] == '.'){
      numero[i] = ',';
    }
  }

  printf("%s", numero);

  return 0;
}
