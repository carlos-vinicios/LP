#include <iostream>

using namespace std;

struct Celulas {
  int conteudo;
  struct Celulas *prox;
};

typedef struct Celulas Celula;
typedef Celula *ptrcelula;

Celula *novaCelula(int n){
  Celula *c;
  c = new Celula();
  c->conteudo = n;
  c->prox = NULL;
  return c;
}

void freeCelula(Celula *c){
  delete(c);
  return;
}

Celula *printCelula(Celula *c){
  if(c != NULL) {
    cout << c->conteudo;
  }
}

typedef struct {
  string nome;
  Celula *prox;
  Celula *ant;
} Lista;

Lista *newLista(string s){
  Lista *l;
  l = new Lista();
  l->nome = s;
  l->prox = NULL;
  l->ant = NULL;
  return l;
}

Celula *proxCelula(Celula *c){
  return c->prox;
}

Lista *limpaLista(Lista *l){
  Celula *c1, *c2;
  c1 = l->prox;
  while (c1 != NULL) {
    c2 = proxCelula(c1);
    freeCelula(c1);
    c1 = c2;
  }
  l->prox = NULL;
  l->ant = NULL;

  return l;
}

void deleteLista(Lista *l){
  limpaLista(l); //cada celula
  delete(l); //a estrutura
  return;
}

int listaVazia(Lista *l){
  if(l->prox == NULL)
    return 1;
  else
    return 0;
}

Lista *printList(Lista *l) {
    Celula *c;
    cout << endl << l->nome;
    if (listaVazia(l)) {
        cout << "A lista está vazia!";
        return l;
    }
    c = l->prox;
    while (c != NULL) {
        cout << endl;
        printCelula(c);
        c = proxCelula(c);
    }
    return l;
}

Lista *insertAtFront(Lista *l, int n) {
    Celula *c;
    c = novaCelula(n);
    c->prox = l->prox;
    l->prox = c;
    if (l->ant == NULL)
        l->ant = c;
    return l;
}

Lista *insertAfter(Lista *l, Celula *w, int n) {
    Celula *c;
    if (w == NULL || l->prox == NULL)
        return insertAtFront(l, n);
    c = novaCelula(n);
    c->prox = w->prox;
    w->prox = c;
    if (w == l->ant)
        l->ant = c;
    return l;
}

Lista *insertAtRear(Lista *l, int n) {
    Celula *c;
    c = l->ant;
    return insertAfter(l, c, n);
}

int removeFromFront(Lista *l) {
    int n;
    Celula *c;
    if (listaVazia(l)) {
        cout << endl << "Underflow na lista";
        exit(EXIT_FAILURE);
    }
    n = l->prox->conteudo;
    c = l->prox;
    l->prox = l->prox->prox;
    freeCelula(c);
    if (l->prox == NULL)
        l->prox = NULL;
    return n;
}

Celula *findInList(Lista *l, int n) {
    Celula *c;
    c = l->prox;
    while (c != NULL) {
        if (c->conteudo == n)
            break;
        c = proxCelula(c);
    }
    // retorna NULL se não for encontrado.
    return c;
}

int main(int argc, char const *argv[]) {
  Lista *l;
  int elem;
  string nome;

  // Criando uma nova lista
  cout << "Digite o nome da lista: ";
  cin >> nome;
  l = newLista(nome);

  // Inserindo dados na lista
  cin >> elem;
  while (elem != 0) {
      // Inserindo no final da lista (fila)
      insertAtRear(l, elem);

      /*
       // Inserindo no início da lista (pilha)
       insertAtFront(p, elem);
       */

      cin >> elem;
  }

  // Exibindo a lista
  printList(l);

  return 0;
}
