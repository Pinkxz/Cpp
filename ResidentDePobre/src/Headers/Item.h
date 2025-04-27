#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    private:
        int ID;
        std::string nome;
    public:
        Item();
        Item(int ID, std::string nome);
        ~Item();
        int getID();
        std::string getNome();
        void setID(int ID);
        void setNome(std::string Nome);


};

#endif