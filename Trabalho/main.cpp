// g++ main.cpp -o main.exe
#include <iostream>
#include <thread>
#include <vector>

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
        

        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;

    }
    return 0;
}   