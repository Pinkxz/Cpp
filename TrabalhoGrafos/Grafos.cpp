#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <fstream>
#include <ctime>
using namespace std;

void generateGraphvizFile(const std::string& filename, const vector<vector<int>>& matrizC) {
    std::ofstream file(filename);

    file << "graph G {\n";
    int vertices = matrizC.size();

    for (int i = 0; i < vertices; i++) {
        for (int j = i+1; j < vertices; j++) { // j > i evita duplicar
            if (matrizC[i][j] < 100000) { // existe aresta
                file << "  " << i << " -- " << j 
                     << " [label=\"" << matrizC[i][j] << "\"];\n";
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        file << "  " << i << " [shape=circle];\n";
    }

    file << "}\n";
    file.close();
}

int main() {
    int vertices;
    srand(time(NULL));

    cout << "Digite o número de vertices: ";
    cin >> vertices;


    // Declarando uma matriz de inteiros com vetor de vetor
    vector<vector<int>> matrizI(vertices, vector<int>(vertices));
    vector<vector<int>> matrizC(vertices, vector<int>(vertices));

    // Preenchendo a matriz
    cout << "Digite os elementos da matriz:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrizI[i][j];

        }
    }

    // Exibindo a matriz
    cout << "\nMatriz Incidencia:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrizI[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            if(matrizI[i][j] == 0){
                matrizC[i][j] = 100000;
            }else{
                matrizC[i][j] = rand() % 5 + 1;
            }
        }
    }
    cout << "\nMatriz Custo:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
             cout << matrizC[i][j] << "\t";
         }
         cout << endl;
    }


    // Floyd-Warshall
    for(int k = 0; k < vertices; k++){
     //   cout << "Loop K" << k << endl;
        for(int i = 0; i < vertices; i++){
          //  cout << "Loop I" << i << endl;
            for(int j = 0; j < vertices; j++){
           //     cout << "Loop J" << j << endl;
           if(i == j){
            continue;
           }
                if(matrizC[i][k] + matrizC[k][j] < matrizC[i][j]){
            //       cout << "comparando" << endl;
                    matrizC[i][j] = matrizC[i][k] + matrizC[k][j];
                }
            }
        }
    }

    cout << "\nMatriz CustoFinal:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrizC[i][j] << "\t";
        }
        cout << endl;
    }

    generateGraphvizFile("graph.dot", matrizC);

    int ret = system("dot -Tpng graph.dot -o graph.png");

    if(ret == 0) {
        cout << "Arquivo 'graph.png' gerado com sucesso!\n";
    } else {
        cout << "Erro ao gerar o arquivo PNG. Verifique se o Graphviz está instalado.\n";
    }
    return 0;

}