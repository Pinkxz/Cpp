#include "enemy.h"
#include "utils.h"

Enemy::Enemy() : Character("Inimigo", generateRandomNumber(30, 60), generateRandomNumber(5, 15), generateRandomNumber(5, 30)) {}

void Enemy::attack(Character& target) {
    std::cout << nome << " atacou e causou " << ataque << " de dano!\n";
    target.takeDamage(ataque);
}
