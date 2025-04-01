#include "character.h"

Character::Character(){

}

Character::Character(std::string nome, int vida, int ataque, int defesa) : nome(nome), vida(vida), ataque(ataque), defesa(defesa){

}

Character::~Character(){

}

std::string Character::getNome(){
    return nome;
}

int Character::getVida(){
    return vida;
} 

int Character::getAtaque(){
    return ataque;
}

int Character::getDefesa(){
    return defesa;
}

void Character::setNome(std::string novoNome){
    nome = novoNome;
}

void Character::setVida(int novaVida){
    vida = novaVida;
}

void Character::setAtaque(int novoAtaque){
    ataque = novoAtaque;
}

void Character::setDefesa(int novaDefesa){
    defesa = novaDefesa;
}

void Character::attack(Character& target){
    int dano = ataque - target.getDefesa();
    if(dano < 0)
        dano = 0;
    target.takeDamage(dano);
    std::cout << nome << " atacou " << target.getNome() << " e causou " << dano << " de dano." << std::endl;
}

bool Character::isAlive() const{
    return vida > 0;
}

void Character::takeDamage(int dano){
     vida -= dano;
     if(vida < 0){
        vida = 0;
     }
}

void Character::showStatus() const{
    std::cout << nome << " - Vida: " << vida << std::endl;
}
