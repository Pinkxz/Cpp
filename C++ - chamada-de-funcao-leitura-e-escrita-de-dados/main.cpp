#include <iostream>
using namespace std;

int hello(int cpp) {
  cout << "Hello World!\n Escreva algum numero para mim: ";
  cin >> cpp;
  return cpp;
}
void tabuada(int i, int j){
  int resut;
  for(j = 1;j < 11; j++){
    cout << "\n\n";
    i = 0;
    for(i = 1;i < 11;i++){
      resut = i * j;
      cout << "\n" << i << " x " << j << " = " << resut;
    }
  }
}

int main() {
  int cpp = 0;
  int i , j;
  cpp = hello(cpp);
  cout << "Isso o codigo que voce escreveu: " << cpp;
  tabuada(i, j);
  cout << "\nFinalizando o programa...";
}