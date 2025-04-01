#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character {
public:
    Player(std::string nome);
    void attack(Character& target) override;
};

#endif
