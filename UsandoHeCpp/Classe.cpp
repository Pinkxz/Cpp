#include "Classe.h"

namespace teste{

            Classe::Classe(int valor) : valor(valor) {}

            Classe::~Classe(){
                std::cout << "Produto " << valor << " foi destruído." << std::endl;
            }

            int Classe::getTeste(){
                return valor;
            }
            void Classe::setTeste(int nValor){
                valor = nValor;
            }

            void Classe::exibir() const { 
                std::cout << "ID: " << valor << std::endl;
            }
}