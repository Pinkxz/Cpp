#include <iostream>
#include <thread>
#include <mutex>

// Area critica 1

std::mutex mutex;



void critica1(){
    mutex.lock();
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop1: " << i << std::endl;
    }
    mutex.unlock();
}

// Area critica 2
void critica2(){
    mutex.lock();
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop2: " << i << std::endl;
    }
    mutex.unlock();

}

// Main
int main(){
    std::thread t1(critica1);
    std::thread t2(critica2);
    t1.join();
    t2.join();
    return 0;
}