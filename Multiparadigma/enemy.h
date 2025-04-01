#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "utils.h"

class Enemy : public Character {
public:
    Enemy();
    void attack(Character& target) override;
};

#endif
