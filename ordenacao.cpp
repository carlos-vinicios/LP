#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

using namespace std;

int initAlga(int num){
  int divisor = 10, res;
  do{
    res = floor(num / divisor);
    divisor = divisor * 10;
  }while(res < 1 || res > 9);

  return res;
}

int ordenacao(int *nums, int qtd){
  int **ordenado, i, j, k, z, index, rest;

  ordenado = new int *[qtd];

  rest = qtd;
  k = 0;
  for(i = 0; i < qtd; i++){
    if(rest > 0){
      z = 0;
      ordenado[k] = new int[rest];
      if(nums[i] > 9){
        index = initAlga(nums[i]);
      }else{
        index = nums[i];
      }
      ordenado[k][z] = nums[i];
      z++;
      rest--;
      for(j=i+1; j < qtd; j++){
        if(initAlga(nums[j]) == index){
          ordenado[k][z] = nums[i];
          rest--;
          z++;
        }
      }
      k++;
    }
  }
  cout << "\n\n\n";
  cout << sizeof(ordenado) << '\n';
  cout << sizeof(int) << '\n';

  for(i = 0; i < k; i++){
    for(j = 0; j < sizeof(ordenado[i]) / sizeof(int); j++){
      cout << ordenado[i][j] << " | ";
    }
    cout << '\n';
  }

  return 0;
}

int main() {
  int ordenado, *nums, qtd, i, j;

  cout << "Quantidade de elementos:\n";
  cin >> qtd;

  nums = new int[qtd];


  for(i = 0; i < qtd; i++){
    cin >> nums[i];
  }

  ordenado = ordenacao(nums, qtd);

  return 0;
}
