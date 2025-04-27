#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include "Item.h"

class Person{
    private:
        std::string nome;
        int vida, ataque, defesa;
        std::vector<Item*> inventario;
    public:
        Person();
        Person(std::string nome, int vida, int defesa)  : nome(nome), vida(vida), defesa(defesa){}
        ~Person();
        bool estaVivo() const;
        void tomouDano(int dano);
        void mostrarStatus() const;
        void Atirar(Person& target);
        void getNome();
        void getVida();
        void getDefesa();
        std::string setNome(std::string nome);
        int setVida(int vida);
        void adicionarItem(std::vector<Item*> Item);
        void removerItem(std::vector<Item*> Item);
        
};



#endif