#include <iostream>
using namespace std;

#define N 6
#define M 2

void k_means(double x[][M], int k){
    //Primeiramente, vamos definir k clusters de maneira
    //aleatória. Para isso, criaremos um algoritmo que possa
    //espaçar essa definição de acordo com a ordem
    //das informações.

    //array de clusters:
    float cluster[k];

    if (N % 0 != 2){
        for(int i=0; i<k; i++){
        
        }

    }else{
        int p = N/k;
        //o número p que vamos pular na definição das
        //clusters é definido por N/k, garantindo
        //um espaçamento igual, começando do primeiro ponto.
        for(int i=0; i<k-1; i++){
            for(int j=0; j<N-1; j+=p){
                cluster[i] = x[j][M];
            }
        }
    }

    //agora veremos a proximidade de cada um
    //dos outros pontos em relação a cada centróide.
    //Assim, vamos atribuir o ponto ao centróide mais próximo.
}

int main()
{
    double x[N][M] = {{1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    //dados que serão organizados em k grupos pelo algoritmo.
    int k = 2;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
            cout << x[i][j] << ' ';
        cout << endl;
    }
            
    k_means(x, k);
    
    return 0;
}