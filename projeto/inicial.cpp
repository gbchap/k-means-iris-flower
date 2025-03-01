#include <iostream>
using namespace std;

#define N 6
#define M 2

void k_means(double x[][M], int k){
    //Utilizando o exemplo abaixo, 
    //e 2 = k, vamos definir 2 clusters, 
    //escolhendo o primeiro e o último
    //ponto como centróides iniciais.

    //se k for maior que 2, vamos escolher
    //o número de centróides separadamente.

    cout << "Centróides iniciais escolhidos: " << endl;

    //array de clusters:
    float cluster[k];
    cluster[0] = x[0][0];

    if (k >= 2){
        cluster[k-1] = x[N-1][M-1];
    }
    if(k>2){
        if (k % 0 != 2){
            for(int i=0; i<k; i++){
                
            }


        }else{

        }
    }


    //agora veremos a proximidade de cada um
    //dos outros pontos em relação a cada centróide.

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