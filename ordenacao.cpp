<<<<<<< HEAD
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

using namespace std;

int numIn(int num){
  int res, divi;
  divi = 10;
  do{
    res = floor(num / divi);
    divi = divi * 10;
  }while(res < 1 || res > 9);
  divi = divi / 10;

  return res;
}

int **ordenacao(int *nums, int qtd){
  int **ordered, *index, i, j, k, z, cont, base, newBase;

  ordered = new int *[qtd];
  index = new int[qtd];

  cont = 0;
  for(i = 0; i < qtd; i++){
    newBase = 1;
    if(cont > 0){
      for(z = 0; z < cont; z++){
        cout << z << '\n';
        cout << "Num na posição " << ordered[z][0] << "\n\n";
        if(numIn(ordered[z][0]) == numIn(nums[i])){
          newBase = 0;
          break;
        }
      }
    }
    if(newBase){
      k = 0;
      base = numIn(nums[i]);
      cout << "A base é: " << base << "\n\n";
      cout << nums[i] << '\n';
      index[k] = nums[i];
      k++;
      for(j=i+1; j < qtd; j++){
        if(base == numIn(nums[j])){
          cout << nums[j] << "\n\n";
          index[k] = nums[j];
          k++;
        }
      }
      *ordered = index;
      cont++;
    }
  }

  return ordered;
}

int main() {

  int *nums, **ordenado, i, j, qtd;

  cout << "Digite a quantidade desejada:\n";
  cin >> qtd;

  nums = new int[qtd];

  cout << "Digite os numeros da sequencia\n";
  for(i = 0; i < qtd; i++){
    cin >> nums[i];
  }

  ordenado = ordenacao(nums, qtd);

  return 0;
}
=======
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
>>>>>>> master
