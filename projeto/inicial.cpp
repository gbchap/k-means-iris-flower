#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define N 6
#define M 2
#define k 2


void atribuicao(float dist[N][k], int att[N], double x[N][M], float cluster[k][M]){
    //agora veremos a proximidade de cada um
    //dos outros pontos em relação a cada centróide.
    //Assim, vamos atribuir o ponto ao centróide mais próximo
    //utilizando dist. Euclidiana.

    for(int c=0; c<k; c++){
        for(int i=0; i<N; i++){
            float x1 = x[i][0];
            float y1 = x[i][1];
            float x2 = cluster[c][0];
            float y2 = cluster[c][1];
            dist[i][c] = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        }
    }
    
    //atribuição de cada dado ao cluster mais proximo
    //(comparar com as outras distancias).

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
    // está mais próximo da cluster 1. Se att[i] = 1,
    // o ponto está mais próximo da segunda cluster.
}

void atualizarCentroides(float cluster[k][M], double x[N][M], int att[N]){
    //calculo da media da cluster:
    float soma[k][M] = {0};
    float media[k][M] = {0};
    for(int c=0; c<k; c++){
        int num = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if (att[i] == c){
                    soma[c][j] += x[i][j];
                    num++;
                }
            }
        }
        for(int j=0; j<M; j++){
            media[c][j] = soma[c][j]/(num/M);
        }
    }
    
    for(int c=0; c<k; c++){
        for(int i=0; i<M; i++){
            cluster[c][i] = media[c][i];
            //cout << cluster[c][i] << " ";
        }
    }
}

void k_means(double x[][M]){
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

    //As clusters serão atualizadas para a média.
    //O que nos resta fazer é repetir os passos 2 e 3
    //durante um número de iterações aleatório, como,
    //por exemplo, 1000.

    //Temos como passo 2 a função atribuicao e 
    //como passo 3 a função atualizarCentroides.

    float dist[N][k];
    int att[k];

    for(int iter = 0; iter < 1000; iter++){
        atribuicao(dist, att, x, cluster);
        atualizarCentroides(cluster, x, att);
    }
    for(int i=0; i<N; i++){
        cout<< fixed << setprecision(0);
        cout << "Ponto (" << x[i][0] << ", " << x[i][1] << "): " << att[i];
        cout<< endl;
    }
}

int main()
{
    double x[N][M] = {{1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << x[i][j] << ' ';
        cout << endl;
    }
            
    k_means(x);
    
    return 0;
}