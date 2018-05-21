#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char numero[7];

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

void dezena_especial(char numero){
  switch (numero) {
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
}


void dezena(char dezena){
  switch(dezena){
    case '2':
      printf("Vinte");
      break;
    case '3':
        printf("Trinta");
      break;
    case '4':
        printf("Quarenta");
      break;
    case '5':
        printf("Cinquenta");
      break;
    case '6':
        printf("Sessenta");
      break;
    case '7':
        printf("Setenta");
      break;
    case '8':
        printf("Oitenta");
      break;
    case '9':
        printf("Noventa");
      break;
  }
}

void centena(char centena){
  switch (centena) {
    case '1':
      printf("Cento");
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

void chamada_dezena(){
  if(numero[0] != '1'){
    dezena(numero[0]);
    printf(" e ");
    unidade(numero[1]);
  }else{
    dezena_especial(numero[1]);
  }
}

void chamada_centena(){
  if(numero[0] == '1' && numero[1] == '0' && numero[2] == '0'){
    printf("Cem");
  }else{
    centena(numero[0]);
    printf(" e ");
    if(numero[1] != '1'){
      dezena(numero[1]);
      printf(" e ");
      unidade(numero[2]);
    }else{
      dezena_especial(numero[2]);
    }
  }
}

void milhar(int type){
  switch (type) {
    case 1:
      unidade(numero[0]);
      break;
    case 2:
      chamada_dezena();
      break;
    case 3:
      chamada_centena();
      break;
  }
}

int main() {
  int tamanho;

  printf("Digite o numero que deseja:\n");
  scanf("%s", numero);
  tamanho = strlen(numero);

  switch (tamanho) {
    case 1:
      unidade(numero[0]);
      break;
    case 2:
      chamada_dezena();
      break;
    case 3:
      chamada_centena();
      break;
    case 4:
      milhar(1); //apenas unidade
      printf(" mil");
      break;
    case 5:
      milhar(2); //apenas dezena
      printf(" mil");
      break;
    case 6:
      milhar(3); //apenas centena
      printf(" mil");
      break;
  }
  printf(" reais");
  return 0;
}
