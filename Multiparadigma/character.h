#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>


class Character{
    public:
        Character();
        Character(std::string nome, int vida, int ataque, int defesa);
        ~Character();
        std::string getNome();
        int getVida();
        int getAtaque();
        int getDefesa();
        void setNome(std::string novoNome);
        void setVida(int novaVida);
        void setAtaque(int novoAtaque);
        void setDefesa(int novaDefesa);
        virtual void attack(Character& target) = 0;
        bool isAlive() const;
        void takeDamage(int damage);
        void showStatus() const;
    protected:
        std::string nome;
        int vida;
        int ataque;
        int defesa;
    private:

    };


#endif