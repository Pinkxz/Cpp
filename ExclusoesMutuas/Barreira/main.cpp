#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex Mcount;
bool espera = false;
int contador;
int total_threads = 3;
int fase = 0;
condition_variable cv;

bool barreira() {
    unique_lock<mutex> lock(Mcount);
    int fase_atual = fase;
    contador++;

    if (contador == total_threads) {
        contador = 0;
        fase++;
        cv.notify_all();
        cout << "EXECUCAO FINALIZADA\n";
        return true;
    } else {
        cv.wait(lock, [&]{ return fase != fase_atual; });
        return false;
    }
}


void critica1(vector<int>& v){
    // Area critica 1
    cout << "critico 1" << endl;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
        cout << i << endl;
    }
    barreira();
}


void critica2(vector<int>& v){

    // Area critica 2
    cout << "critico 2" << endl;
    for(int i = 10; i < 20; i++){
        v.push_back(i);
        cout << i << endl;
    }

    barreira();
}

void critica3(vector<int>& v){

    // Area critica 3
    cout << "critico 3" << endl;
    for(int i = 20; i < 30; i++){
        v.push_back(i);
        cout << i << endl;
    }
    barreira();
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