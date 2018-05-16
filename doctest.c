#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User{
  char nome[6];
  int idade;
};

int main(int argc, char const *argv[]) {
    struct User usuario;
    FILE *arq;;
    char *linha;
    int id, size;
    char pos[] = "5";


    arq = fopen("ArqGrav.txt", "r+");  // Cria um arquivo texto para gravação
    if (arq == NULL) // Se não conseguiu criar
    {
       printf("Problemas na CRIACAO do arquivo\n");
       return 0;
    }

    fseek (arq, 0, SEEK_END);   // non-portable
    size = ftell (arq);
    rewind(arq);

    printf("%d\n", size);

    linha = (char *) malloc(size * sizeof(char *));

    id = 0;
    while(!feof(arq)){
      fgets(linha, size * sizeof(char), arq);
      id++;
    }
    id--;
    rewind(arq);

    int x = 0;
    while(!feof(arq)){
      fgets(linha, size * sizeof(char), arq);
      if(x == id){
        break;
      }
      x++;
    }

    // printf("%s\n", linha);

    free(linha);
    linha = NULL;
    fclose(arq);
    return 0;
}
