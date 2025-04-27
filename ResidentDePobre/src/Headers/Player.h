#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"

class Player : public Person {
public:
    Player(); 
    Player(std::string nome, int vida, int defesa);
    ~Player(); 

    
    void interagir();
    void correr();
    void verInvetario(std::vector<Item*> Item);
};

#endif
