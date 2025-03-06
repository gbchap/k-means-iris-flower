#include <iostream>
#include <iomanip>
#include <cmath>

#include <cstdlib> //para ler irisData
#include <string> //para ler irisData
#include <fstream> //para ler irisData
#include <sstream>  //para ler irisData
using namespace std;

#define N 150 //pois há 150 linhas de pontos
#define M 4 //número de atributos por ponto
#define k 3 //pois existem 3 tipos de flores iris


//função para ler o arquivo:
void lerArquivo(const string& irisData, double x[N][M], int att[N]) {
    ifstream arquivo(irisData.c_str());
    string linha;
    int i = 0;

    while (getline(arquivo, linha) && i < N) {
        stringstream ss(linha);
        string valor;
        int j = 0;

        while (getline(ss, valor, ',')) {  
            // Separa os valores por vírgula
            if (j < M) {
                x[i][j] = atof(valor.c_str());
                // Converte para double e armazena no array x
            } else {
                // Converte a classe para um número inteiro
                if (valor == "Iris-setosa")
                    att[i] = 0;
                else if (valor == "Iris-versicolor")
                    att[i] = 1;
                else if (valor == "Iris-virginica")
                    att[i] = 2;
            }
            j++;
        }
        i++;
    }

    arquivo.close();  // Fecha o arquivo
}

//agora vamos atribuir as clusters utilizando att, como no exemplo inicial.
void atribuicao(float dist[N][k], int att[N], double x[N][M], float cluster[k][M], int var1, int var2){

    for (int c = 0; c < k; c++) {
        for (int i = 0; i < N; i++) {
            float x1 = x[i][var1];
            float y1 = x[i][var2];
            float x2 = cluster[c][var1];
            float y2 = cluster[c][var2];
            dist[i][c] = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        }
    }

    for (int i=0; i< N; i++){
        float minDist = dist[i][0];
        int clusterprox = 0;
        for(int c=0; c< k; c++){
            if (dist[i][c] < minDist){
                minDist = dist[i][c];
                clusterprox = c;
            }
        }
        att[i] = clusterprox;
    }
}

void atualizarCentroides(float cluster[k][M], double x[N][M], int att[N], int var1, int var2){
    //calculo da media da cluster:
    float soma[k][M] = {0};
    float media[k][M] = {0};

    for(int c=0; c<k; c++){
        int num = 0;
        for (int i = 0; i < N; i++) {
            if (att[i] == c) {
                soma[c][var1] += x[i][var1];
                soma[c][var2] += x[i][var2];
                num++;
            }
        }
        for (int j = 0; j < M; j++) {
            media[c][j] = soma[c][j] / num;
        }
    }

    for (int c = 0; c < k; c++) {
        cluster[c][var1] = media[c][var1];
        cluster[c][var2] = media[c][var2];
    }
}

void k_means(double x[][M], int att[N], int var1, int var2){
    cout << fixed << setprecision(2);
    
    //Primeiramente, vamos definir 3 clusters (pois k=3)
    //aleatoriamente.
    float cluster[k][M];
    for (int i = 0; i < k; i++) {
        cluster[i][var1] = x[i][var1];
        cluster[i][var2] = x[i][var2];
    }

    float dist[N][k];

    for(int iter = 0; iter < 1000; iter++){
        atribuicao(dist, att, x, cluster, var1, var2);
        atualizarCentroides(cluster, x, att, var1, var2);
    }

    for(int i=0; i<N; i++){
        cout<< fixed << setprecision(0);
        cout << "Ponto (" << x[i][var1] << ", " << x[i][var2] << "): Classe ";
        if(att[i] == 0){
            cout << "Iris-setosa";
        }
        else if(att[i] == 1){
            cout << "Iris-versicolor";
        }
        else{
            cout << "Iris-virginica";
        }
        cout<< endl;
    }
}

int main()
{
    double x[N][M]; 
    int att[N];

    // Lê os dados do arquivo "irisData.txt"
    lerArquivo("irisData.txt", x, att);

    // Exibindo os dados lidos
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << x[i][j] << ' ';
        cout << endl;
    }
    
    int var1 = 0; 
    // Índice da primeira variável (ex: Sepal Length)
    int var2 = 1; 
    // Índice da segunda variável (ex: Sepal Width)
    
    k_means(x, att, var1, var2);

    return 0;
}
