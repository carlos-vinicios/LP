#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void divisores(int num){
  int i, j, maior_primo, cont;
  printf("Divisores:\n");
  for(i = 1; i <= num; i++){
    if(num % i == 0){
      printf("%d\n", i);
      cont = 0;
      for (j = 1; j <= i; j++) {
        if(i % j == 0){
          cont++;
        }
      }
      if(cont == 2){
        maior_primo = i;
      }
    }
  }
  printf("Maior primo: %d\n", maior_primo);
  return;
}

void primeira(){
  int n;

  printf("Digite o numero que deseja achar os divisores\n");
  scanf("%d", &n);
  if(n >= 100 && n <= 1000000){
    divisores(n);
  }else{
    printf("Digite um numero no intervalo fechado 100 a 1000000 \n");
  }
  return;
}

int randomDezena(int x, int t){ //x = quantidade de dezenas, t repetições máxima de uma dezena
  FILE *arq;
  int num, dez, print = 0, exec = 0;
  int rept[] = {0, 0, 0, 0, 0, 0};

  if(t * 6 < x){
    return 0; //erro a quantidade de vezes que uma dezena pode se repetir não será suficiente para gerar a quantidade desejada
  }

  arq = fopen("Sequencia.txt", "w");

  if(arq == NULL){
    return 0; //não foi possivel criar o arquivo
  }

  do {
    if(exec == 5 && rept[5] == 0 && x == 6){ //para que o programa não demore, gerando varios números enquanto a dezena que falta é o 6
      num = 60;
    }else{
      num = rand() % 60;
    }
    dez = floor(num / 10);
    switch (dez) {
      case 1:
        if(rept[0] < t){
          print = 1;
          rept[0]++;
          exec++;
        }
        break;
      case 2:
        if(rept[1] < t){
          print = 1;
          rept[1]++;
          exec++;
        }
        break;
      case 3:
        if(rept[2] < t){
          print = 1;
          rept[2]++;
          exec++;
        }
        break;
      case 4:
        if(rept[3] < t){
          print = 1;
          rept[3]++;
          exec++;
        }
        break;
      case 5:
        if(rept[4] < t){
          print = 1;
          rept[4]++;
          exec++;
        }
        break;
      case 6:
        if(rept[5] < t){
          print = 1;
          rept[5]++;
          exec++;
        }
        break;
    }
    if(print){
      fprintf(arq, "%d - %d\n", exec, num);
    }
    print = 0;
  } while(exec < x);
  fclose(arq);
  return 1; //execução realizada com sucesso
}

void segunda(){
  int t, x;
  srand( (unsigned)time(NULL) );

  printf("Digite a quantidade de dezenas desejadas:\n");
  scanf("%d", &x);
  printf("Digite a quantidade de vezes que uma dezena pode se repetir:\n");
  scanf("%d", &t);

  if(randomDezena(x, t)){
    printf("Sequencia gerada com sucesso\n");
  }else{
    printf("Nao foi possivel gerar a sequencia, quantidade de dezenas é maior que as repeticoes permitidas\n");
  }
  return;
}

int main() {
  int opc;

  printf("Digite a questao desejada:\n1) - 1\n2) - 2\n");
  scanf("%d", &opc);

  switch (opc) {
    case 1:
      primeira();
      break;
    case 2:
      segunda();
      break;
    default:
      printf("Questao indisponivel\n");
      break;
  }

  return 0;
}
