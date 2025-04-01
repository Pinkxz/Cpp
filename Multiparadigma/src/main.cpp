#include "player.h"
#include "enemy.h"
#include "utils.h"

void gameLoop() {
    srand(time(0));

    Player player("Herói");
    Enemy enemy;

    while (player.isAlive() && enemy.isAlive()) {
        player.showStatus();
        enemy.showStatus();

        std::cout << "\n1. Atacar\n2. Fugir\nEscolha: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            player.attack(enemy);
            if (enemy.isAlive()) {
                enemy.attack(player);
            }
        } else {
            std::cout << "Você fugiu!\n";
            break;
        }
    }

    if (!player.isAlive()) {
        std::cout << "Game Over! Você perdeu.\n";
    } else if (!enemy.isAlive()) {
        std::cout << "Parabéns! Você venceu.\n";
    }
}

int main() {
    gameLoop();
    return 0;
}
