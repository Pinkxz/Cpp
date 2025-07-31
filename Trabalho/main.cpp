// g++ main.cpp -o main.exe
#include <iostream>
#include <thread>



int main(){

    int N, MThreads;
    std::cout << "Quantos numeros primos deseja calcular?" << std::endl;
    std::cin >> N;

    std::cout << "Digite quantas threads devem ser criadas (Digite 0 para sair):\n--> ";
	std::cin >> MThreads;
    
	if (MThreads == 0) {
		return 0;
	}

    return 0;
}