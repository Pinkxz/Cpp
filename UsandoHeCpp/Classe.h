#ifndef CLASSE_H
#define CLASSE_H

#include <iostream>

namespace teste{
    class Classe
    {
    private:
        int valor;
    public:
        Classe(int valor);
        ~Classe();
        void exibir() const;

        int getTeste();
        void setTeste(int nValor);
    };
   
}

#endif
    