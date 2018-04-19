#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void unidade(char unidade){
  switch (unidade) {
    case '1':
      printf("Um");
      break;
    case '2':
      printf("Dois");
      break;
    case '3':
      printf("Tres");
      break;
    case '4':
      printf("Quatro");
      break;
    case '5':
      printf("Cinco");
      break;
    case '6':
      printf("Seis");
      break;
    case '7':
      printf("Sete");
      break;
    case '8':
      printf("Oito");
      break;
    case '9':
      printf("Nove");
      break;
  }
}

switch (numero[1]) {
  case '0':
    printf("Dez");
    break;
  case '1':
    printf("Onze");
    break;
  case '2':
    printf("Doze");
    break;
  case '3':
    printf("Treze");
    break;
  case '4':
    printf("Quatorze");
    break;
  case '5':
    printf("Quinze");
    break;
  case '6':
    printf("Dezeseis");
    break;
  case '7':
    printf("Dezesete");
    break;
  case '8':
    printf("Dezoito");
    break;
  case '9':
    printf("Dezenove");
    break;
}


void dezena(char dezena){
  switch(dezena){
    case '2':
      printf("Vinte e ");
      break;
    case '3':
        printf("Trinta e ");
      break;
    case '4':
        printf("Quarenta e ");
      break;
    case '5':
        printf("Cinquenta e ");
      break;
    case '6':
        printf("Sessenta e ");
      break;
    case '7':
        printf("Setenta e ");
      break;
    case '8':
        printf("Oitenta e ");
      break;
    case '9':
        printf("Noventa e ");
      break;
  }
}

void centena(char centena){
  switch (centena) {
    case '1':
      printf("Cem");
      break;
    case '2':
      printf("Duzentos");
      break;
    case '3':
      printf("Tressentos");
      break;
    case '4':
      printf("Quatrocentos");
      break;
    case '5':
      printf("Quinhentos");
      break;
    case '6':
      printf("Seiscentos");
      break;
    case '7':
      printf("Setecentos");
      break;
    case '8':
      printf("Oitocentos");
      break;
    case '9':
      printf("Novecentos");
      break;
  }
}

int main() {
  char numero[7];
  //char extenso[10000000];
  int tamanho;

  printf("Digite o numero que deseja:\n");
  scanf("%s", numero);
  tamanho = strlen(numero);

  switch (tamanho) {
    case 1:
      unidade(numero[0]);
      break;
    case 2:
      dezena(numero[0]);
      unidade(numero[1]);
      break;
    case 3:
      centena(numero[0]);
      dezena(numero[1]);
      unidade(numero[2]);
      break;
    case 4:
      //milhar(numero);
      break;
  }
  printf(" reais");
  return 0;
}
