#include <iostream>
#include <thread>
#include <vector>


int lock = 0;


void critica1(std::vector<int>& v){
    while(lock == 1);
    lock = 1;
    // Area critica 1
    for(int i = 0; i < 10000; i++){
        v.push_back(i);
    }
    lock = 0;

}



void critica2(std::vector<int>& v){
    while(lock == 0);
    // Area critica 2
    lock = 0;
    for(int i = 0; i < 1000; i++){
        v.push_back(i);
    }
    lock = 1;
}


// Main
int main(){
    std::vector<int> vetorCompartilhado;


    std::thread t1(critica1,  std::ref(vetorCompartilhado));
    std::thread t2(critica2,  std::ref(vetorCompartilhado));
    t1.join();
    t2.join();

    std::cout << "Tamanho final do vetor: " << vetorCompartilhado.size() << std::endl;
    std::cout.flush();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cerr << "Terminou as threads\n";


    return 0;
}