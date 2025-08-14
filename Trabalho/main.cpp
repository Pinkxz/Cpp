/* Comandos para execução em ./readme.md */
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <fstream>
#include <algorithm>

std::vector<int> primos;
std::mutex mutex;
std::atomic<int> primo(3);
int total_primos;
int contador_arquivos = 0;

bool ePrimo(int n){
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

void multiThread() {
    while (true) {
        int numero = primo.fetch_add(2);

        if (ePrimo(numero)) {
            std::lock_guard<std::mutex> lock(mutex);
            primos.push_back(numero);
            if ((int)primos.size() >= total_primos) {return;}
        }
        
    }
}

void salvarArquivo(int qtThreads, double tempo) {
    std::sort(primos.begin(), primos.end());
    primos.resize(total_primos);
    std::ofstream arquivo("resultado_" + std::to_string(contador_arquivos++) + ".txt");
    arquivo << "Threads: " << qtThreads << ".\n";
    arquivo << "Tempo de execução: " << tempo << " segundos.\n";
    for (int p : primos) arquivo << p << "\n";
    arquivo.close();

    std::cout << "Threads: " << qtThreads << ".\n";
    std::cout << "Tempo de execucao: " << tempo << " segundos.\n";
    std::cout << "O resultado do processamento foi gravado em ./resultado_" 
        << contador_arquivos-1 << ".txt" << std::endl;
}

int main() {
    int MThreads;
    std::cout << "Quantos numeros primos deseja calcular? " << std::endl;
    std::cin >> total_primos;

    while (true) {
        std::cout << "Digite quantas threads devem ser criadas (Digite 0 para sair): ";
        std::cin >> MThreads;
        if (MThreads == 0) break;

        primos.clear();
        primo = 3;
        primos.push_back(2);

        auto inicio = std::chrono::high_resolution_clock::now();

        std::vector<std::thread> threads;
        threads.reserve(MThreads);
        for (int i = 0; i < MThreads; ++i)
            threads.emplace_back(multiThread);

        for (auto &t : threads)
            t.join();

        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duracao = fim - inicio;

        salvarArquivo(MThreads, duracao.count());
    }

    std::cout << "Programa encerrado.\n";
    return 0;
}
