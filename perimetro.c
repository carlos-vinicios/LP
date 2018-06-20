#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int *vetor;
  int lados;
  int x, y;
  int indice = 0;
  float perimetro = 0;

  printf("Digite a quantidade de elementos:\n");
  scanf("%d", &lados);

  vetor = (int *) malloc( 2*lados * sizeof(int));

  for(int i = 0; i < lados; i++){
    printf("Ponto %d: (1 - x 2 -y)\n", i);
    scanf("%d", &x);
    scanf("%d", &y);
    vetor[indice] = x;
    indice++;
    vetor[indice] = y;
    indice++;
  }

  for (int j = 0; j < sizeof(vetor); j+=3) {
    perimetro += sqrt((vetor[j+2] - vetor[j]) * (vetor[j+2] - vetor[j]) + (vetor[j+3] - vetor[j+1]) * (vetor[j+3] - vetor[j+1]));
  }

  //perimetro += sqrt((vetor[0] - vetor[sizeof(vetor)-1]) * (vetor[0] - vetor[sizeof(vetor)-1]) + (vetor[1] - vetor[sizeof(vetor)-2]) * (vetor[1] - vetor[sizeof(vetor)-2]));

  printf("%f\n", perimetro );
  0 0
  2 0
  2 2
  0 2
  return 0;
}
