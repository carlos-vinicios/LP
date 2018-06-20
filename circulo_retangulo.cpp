#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

using namespace std;

typedef struct _ponto2d_{
  float x;
  float y;
}ponto2d;

typedef struct _circulo_{
  float raio;
  ponto2d centro;
}circulo;

void retangulo(circulo *circulos, int qtd_circ){
  ponto2d ponto, origem, h, l;
  float ma_x, ma_y, me_x, me_y, cma_x, cma_y, cme_x, cme_y, raio, altura, largura;
  int i;
  for(i = 0; i < qtd_circ; i++){
    ponto = circulos[i].centro;
    raio = circulos[i].raio;
    cma_x = ponto.x + raio;
    cma_y = ponto.y + raio;
    cme_x = ponto.x - raio;
    cme_y = ponto.y - raio;
    if(i == 0){
      ma_x = cma_x;
      ma_y = cma_y;
      me_x = cme_x;
      me_y = cme_y;
    }else{
      if(cma_x > ma_x)
        ma_x = cma_x;
      else if(cme_x > ma_x)
        ma_x = cme_x;
      if(cma_y > ma_y)
        ma_y = cma_y;
      else if(cme_y > ma_y)
        ma_y = cme_y;
      if(cme_x < me_x)
        me_x = cme_x;
      else if(cma_x < me_x)
        me_x = cma_x;
      if(cme_y < me_y)
        me_y = cme_y;
      else if(cma_y < me_y)
        me_y = cma_y;
    }
  }
  origem.x = me_x;
  origem.y = me_y;
  h.x = me_x;
  h.y = ma_y;
  l.x = ma_x;
  l.y = me_y;
  altura = sqrt(pow(h.x - origem.x, 2) + pow(h.y - origem.y, 2));
  largura = sqrt(pow(l.x - origem.x, 2) + pow(l.y - origem.y, 2));
  system("clear");
  cout << "Origem: x=" << origem.x << " y=" << origem.y << '\n';
  cout << "Largura: " << largura << '\n';
  cout << "Altura: " << altura << '\n';
}

int main() {
  int qtd_circ, i;
  circulo *circulos;
  cout << "Quantidade de circulos\n";
  cin >> qtd_circ;
  circulos = new circulo[qtd_circ];
  for(i = 0; i < qtd_circ; i++){
    cout << "Ciruclo " << i+1 << '\n';
    cout << "Centro do circunferência\n";
    cout << "X:\n";
    cin >> circulos[i].centro.x;
    cout << "Y:\n";
    cin >> circulos[i].centro.y;
    cout << "Raio da circunferência:\n";
    cin >> circulos[i].raio;
    system("clear");
  }
  retangulo(circulos, qtd_circ);
  return 0;
}
