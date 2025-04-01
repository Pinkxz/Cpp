#include "player.h"

Player::Player(std::string nome) : Character(nome, 100, 20, 20) {}

void Player::attack(Character& target) {
    std::cout << nome << " atacou e causou " << ataque << " de dano!\n";
    target.takeDamage(ataque);
}
