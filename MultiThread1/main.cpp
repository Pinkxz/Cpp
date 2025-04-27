#include <iostream>
#include <thread>


void loop1(){
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop1: " << i << std::endl;
    }
}

void loop2(){
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop2: " << i << std::endl;
    }
}

int main(){
    std::thread t1(loop1);
    std::thread t2(loop2);
    t1.join();
    t2.join();
    return 0;
}