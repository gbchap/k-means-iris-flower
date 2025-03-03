#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define N 6
#define M 2

void k_means(double x[][M], int k){
    cout << fixed << setprecision(2);
    //Primeiramente, vamos definir k clusters de maneira
    //aleatória. Para isso, criaremos um algoritmo que possa
    //espaçar essa definição de acordo com a ordem
    //das informações.
    //array de clusters:
    
    float cluster[k][M];

    int p = N/k;

    //o número p que vamos "pular" na definição das
    //clusters é definido por N/k, garantindo
    //um espaçamento igual, começando do primeiro ponto.

    for(int i=0; i<k; i++){
        //cout << endl;
        for(int l=0; l<M; l++){
            cluster[i][l] = x[i*p][l];
            //cout << cluster[i][l] << " ";
        }
    }

    //agora veremos a proximidade de cada um
    //dos outros pontos em relação a cada centróide.
    //Assim, vamos atribuir o ponto ao centróide mais próximo
    //utilizando dist. Euclidiana.

    float dist[N][k];
    //comparar N de cada k depois;

    float dist[N][k];

    for(int c=0; c<k; c++){
        //cout << endl;
        for(int i=0; i<N; i++){
            float x1 = x[i][0];
            float y1 = x[i][1];
            float x2 = cluster[c][0];
            float y2 = cluster[c][1];
            dist[i][c] = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
            //cout << dist[i][c] << " ";
        }
    }
    //atribuição de cada dado ao cluster mais proximo
    //(comparar com as outras distancias).
    int att[k];

    for(int c=0; c<k; c+=2){
        for(int i=0; i<N; i++){
            if(dist[i][c] < dist[i][c+1]){
                att[i] = c;
            }else{
                att[i] = c+1;
            }
        }
    }
    // assim, se att[i] = 0, indica que o ponto
    // está mais próximo da cluster 1. Se at[i] = 2,
    // o ponto está mais próximo da segunda cluster.
}

int main()
{
    double x[N][M] = {{1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    int k = 2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << x[i][j] << ' ';
        cout << endl;
    }
            
    k_means(x, k);
    
    return 0;
}