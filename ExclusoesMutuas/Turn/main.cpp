#include <iostream>
#include <thread>

// Area critica 1

void critica1(){
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop1: " << i << std::endl;
    }

}




// Area critica 2
void critica2(){
    for(int i = 0; i < 10000; i++){
        std::cout << "Loop2: " << i << std::endl;
    }
}


// Main
int main(){
    std::thread t1(critica1);
    std::thread t2(critica2);
    t1.join();
    t2.join();
    return 0;
}