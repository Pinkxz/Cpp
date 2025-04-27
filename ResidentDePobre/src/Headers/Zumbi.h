#ifndef ZUMBI_H
#define ZUMBI_H

class Zumbi{

    private:
        int vida, ataque;
    public:
        Zumbi();
        Zumbi(int vida, int ataque) : vida(vida), ataque(ataque) {};
        ~Zumbi();
        int getVida();
        int getAtaque();
        void setVida(int novaVida);
        void setAtaque(int novoAtaque);
        void attack(Zumbi& targert);
        bool isAlive() const;
        void takeDamage(int dano);
        void showStatus() const;
};

#endif