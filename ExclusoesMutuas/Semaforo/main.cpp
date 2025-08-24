#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class Semaforo{
public:
    int S;
    mutex mtx;

    Semaforo(int valor){
        S = valor;
    }

    void down(){
        while (true){
            mtx.lock();
            if(S > 0){
                S--;
                mtx.unlock();
                break;
            }
            mtx.unlock();
            this_thread::sleep_for(chrono::milliseconds(20));
        }
    }

    void up(){
        mtx.lock();
        S++;
        mtx.unlock();
    }
};

Semaforo sem(1);

void critica1(vector<int>& v){
    sem.down();
    // Area critica 1
    cout << "critico 1" << endl;
    for(int i = 10; i < 20; i++){
        v.push_back(i);
        cout << i << endl;
    }
    sem.up();

}

void critica2(vector<int>& v){
    // Area critica 2
    sem.down();
    cout << "critico 2" << endl;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
        cout << i << endl;
    }
    sem.up();
}

void critica3(vector<int>& v){
    // Area critica 3
    sem.down();
    cout << "critico 3" << endl;
    for(int i = 20; i < 30; i++){
        v.push_back(i);
        cout << i << endl;
    }
    sem.up();
}


// Main
int main(){
    vector<int> vetorCompartilhado;


    thread t1(critica1,  ref(vetorCompartilhado));
    thread t2(critica2,  ref(vetorCompartilhado));
    thread t3(critica3,  ref(vetorCompartilhado));
    t1.join();
    t2.join();
    t3.join();
    
    cout << "Tamanho final do vetor: " << vetorCompartilhado.size() << endl;
    cout.flush();

    this_thread::sleep_for(chrono::milliseconds(100));
    cerr << "Terminou as threads\n";


    return 0;
}