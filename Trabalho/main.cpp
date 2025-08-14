// g++ main.cpp -o main.exe
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <fstream>


std::vector<int> primos;
std::mutex mutex;


// Verificando se o número é primo
bool ePrimo(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


void salvarArquivo(int qtThreads, int tempo) {
	std::ofstream arquivo;
	arquivo.open("Arquivo_" + std::to_string(qtThreads) + ".txt");
    arquivo << "Threads: " << qtThreads << "." << std::endl;
    std::cout << "Tempo de execução: " << tempo << " segundos." << std::endl;

	for(int p : primos){
        arquivo << p << "\n";
    }
    
	arquivo.close();    
}

int main(){

    int N, MThreads;
    std::cout << "Quantos numeros primos deseja calcular?" << std::endl;
    std::cin >> N;

    while(true){
        std::cout << "Digite quantas threads devem ser criadas (Digite 0 para sair):\n--> ";
	    std::cin >> MThreads;

        if (MThreads == 0) break;

        std::vector<std::thread> threads;
        threads.reserve(MThreads);

        auto inicio = std::chrono::high_resolution_clock::now();
        
        for (size_t i = 0; i < N; i++){
            ePrimo(N);
        }
        
        
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;


        salvarArquivo(MThreads, duracao.count());
    }
    
    std::cout << "Programa encerrado.";
    return 0;
}   