#include <iostream>

using namespace std;

float **alocamatriz(int l, int c){
    float **matriz;
    int i,j;

    matriz = new float *[l];
    if (matriz == NULL) return NULL;

    for (i=0; i<l; i++) {
        matriz[i] = new float[c];
        if (matriz[i] == NULL) {
            for (j=i-1; j>=0; j--)
                delete []matriz[j];
            delete []matriz;
            return NULL;
        }
    }
    return matriz;
}

void freeMatriz(float **matriz, int l) {
    int j;
    for (j=0; j<l; j++)
        delete []matriz[j];
    delete []matriz;
}

int multiplica(float **A, int la, int ca,
           float **B, int lb, int cb,
           float **C)
{
    int i,j,k;
    if (ca != lb) return 0;

    for (i=0; i<la; i++)
        for (j=0; j<cb; j++) {
            C[i][j] = 0;
            for (k=0; k<la; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    return 1;

}

