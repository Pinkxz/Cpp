#include <iostream>

namespace loja{
    class Produto
    {
    private:
        int id;
        std::string nome;
        float preco;
        int quantidade;
    public:

        Produto(int id, const std::string& nome, float preco, int quantidade);
        ~Produto();

        // Métodos de Acesso
        int getId()
        {
            return id;
        }
        std::string getNome()
        {
            return nome;
        }
        float getPreco()
        {
            return preco;
        }
        int getQuantidade()
        {
            return quantidade;
        }
        void setId(int novoId)
        {
            id = novoId;
        }
        void setNome(const std::string& novoNome)
        {
            nome = novoNome;
        }
        void setPreco(float novoPreco)
        {
            preco = novoPreco;
        }
        void setQuantidade(int novaQuantidade)
        {
            quantidade = novaQuantidade;
        }
    
        void exibirInfo() const;
    };

    
    Produto::Produto(int id, const std::string& nome, float preco, int quantidade) : id(id), nome(nome), preco(preco), quantidade(quantidade){
    }

    // Destrutor
    Produto::~Produto() {
        std::cout << "Produto " << nome << " foi destruído." << std::endl;
    }
        // Implementação do Método de Exibição
        void Produto::exibirInfo() const {
            std::cout << "ID: " << id << "\nNome: " << nome
                      << "\nPreço: R$ " << preco
                      << "\nQuantidade: " << quantidade << std::endl;

        }

}


int main(){
    loja::Produto p(1, "Teclado", 120.00, 10);
    p.exibirInfo();
    return 0;
}