#include <stdio.h>

int main() {
  int n1, n2, divisor, maior, qtd, resto;//variaveis do sistema s==s )

  printf("Quantos numeros deseja?\n");
  scanf("%d", &qtd);

  for(int i = 0; i < qtd; i++){
    printf("Digite o %d numero:\n", i + 1);
    scanf("%d", &n1);

    if(i == 0){
      resto = n1;
    }

    if(n1 > resto){
      maior = n1;
    }else{
      maior = resto;
    }

    divisor = maior;

    do {
      if (n1 % divisor == 0 && resto % divisor == 0) {
        break;
      }else{
        divisor--;
      }
    } while(divisor > 0);

    resto = divisor;
  }

  printf("O M.D.C é: %d", resto);
  return 0;
}
