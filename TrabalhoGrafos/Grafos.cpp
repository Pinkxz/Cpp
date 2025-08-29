#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <fstream>
#include <ctime>
using namespace std;

// Função para gerar arquivo DOT com o caminho destacado em vermelho
void generateGraphvizFile(const std::string& filename, 
                          const vector<vector<int>>& matrizC, 
                          const vector<int>& caminho) {
    ofstream file(filename);
    file << "graph G {\n";
    int vertices = matrizC.size();

    // Guardar pares de arestas do caminho
    vector<pair<int,int>> pathEdges;
    for (int i = 0; i + 1 < (int)caminho.size(); i++) {
        pathEdges.push_back({caminho[i], caminho[i+1]});
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = i+1; j < vertices; j++) {
            if (matrizC[i][j] < 100000) {
                bool isPathEdge = false;
                for (auto &p : pathEdges) {
                    if ((p.first == i && p.second == j) || 
                        (p.first == j && p.second == i)) {
                        isPathEdge = true;
                        break;
                    }
                }
                file << "  " << i << " -- " << j
                     << " [label=\"" << matrizC[i][j] << "\"";
                if (isPathEdge) file << ", color=red, penwidth=2";
                file << "];\n";
            }
        }
    }

    for (int i = 0; i < vertices; i++) {
        file << "  " << i << " [shape=circle];\n";
    }

    file << "}\n";
    file.close();
}

// Reconstrói caminho mínimo usando matriz "next"
vector<int> reconstruirCaminho(int u, int v, const vector<vector<int>>& next) {
    if (next[u][v] == -1) return {};
    vector<int> path = {u};
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}

int main() {
    int vertices;
    srand(time(NULL));

    cout << "Digite o número de vertices: ";
    cin >> vertices;

    vector<vector<int>> matrizAdj(vertices, vector<int>(vertices, 0));
    vector<vector<int>> matrizC(vertices, vector<int>(vertices, 100000));
    vector<vector<int>> next(vertices, vector<int>(vertices, -1));

    // Inserir na mão
    /*
    cout << "Digite os elementos da matriz de adjacencia:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrizAdj[i][j];
        }
    }
    */

    
    // Gerar grafo aleatoriamente
    // Garante conexidade ligando cada vértice ao próximo
    for (int i = 0; i < vertices - 1; i++) {
        matrizAdj[i][i+1] = matrizAdj[i+1][i] = 1;
    }

    // Adiciona arestas extras
    int extraEdges = vertices; 
    for (int k = 0; k < extraEdges; k++) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        if (u != v) {
            matrizAdj[u][v] = matrizAdj[v][u] = 1;
        }
    }

    cout << "\nMatriz Adjacencia:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrizAdj[i][j] << "\t";
        }
        cout << endl;
    }

    // Preenche matriz de custos
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                matrizC[i][j] = 0;
                next[i][j] = i;
            } else if (matrizAdj[i][j]) {
                matrizC[i][j] = rand() % 5 + 1; // custo aleatório
                next[i][j] = j;
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
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                if (matrizC[i][k] + matrizC[k][j] < matrizC[i][j]) {
                    matrizC[i][j] = matrizC[i][k] + matrizC[k][j];
                    next[i][j] = next[i][k];
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

    // Usuário escolhe origem e destino
    int src, dst;
    cout << "\nDigite o vértice de origem: ";
    cin >> src;
    cout << "Digite o vértice de destino: ";
    cin >> dst;

    vector<int> caminho = reconstruirCaminho(src, dst, next);

    if (caminho.empty()) {
        cout << "Nao existe caminho entre " << src << " e " << dst << endl;
    } else {
        cout << "Caminho minimo de " << src << " para " << dst << ": ";
        for (int i = 0; i < (int)caminho.size(); i++) {
            cout << caminho[i];
            if (i != (int)caminho.size() - 1) cout << " -> ";
        }
        cout << "\nCusto total: " << matrizC[src][dst] << endl;
    }

    // Gera imagem com caminho destacado
    generateGraphvizFile("graph.dot", matrizC, caminho);

    int ret = system("dot -Tpng graph.dot -o graph.png");

    if(ret == 0) {
        cout << "Arquivo 'graph.png' gerado com sucesso! Caminho destacado em vermelho.\n";
    } else {
        cout << "Erro ao gerar o arquivo PNG. Verifique se o Graphviz está instalado.\n";
    }

    return 0;
}
