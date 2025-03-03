#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define N 6
#define M 2
int main(){
    cout << fixed << setprecision(2);
    int k = 2;
    double x[N][M] = {{1, 2}, {2, 3}, {3, 4}, {6, 5}, {7, 6}, {8, 7}};
    float cluster[k][M];
    int p = N/k;

    for(int i=0; i<k; i++){
        //cout << endl;
        for(int l=0; l<M; l++){
            cluster[i][l] = x[i*p][l];
            //cout << cluster[i][l] << " ";
        }
    }

    float dist[N][k];

    for(int c=0; c<k; c++){
        cout<< endl;
        for(int i=0; i<N; i++){
            float x1 = x[i][0];
            float y1 = x[i][1];
            float x2 = cluster[c][0];
            float y2 = cluster[c][1];
            dist[i][c] = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
            cout << dist[i][c] << " ";
        }
    }

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
    //for(int i=0; i<N; i++){
       //cout << att[i] << " ";
    //}
}
