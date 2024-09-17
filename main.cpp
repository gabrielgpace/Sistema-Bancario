//TODO:
    // Orçamento por categoria: Representa o teto, Lazer pode ser gasto até R$ 500.00 reais etc...

//SUGESTAO DE COMO FAZER

// struct TipoTransacao {
//     string nome;
//     double valor;
//     TipoTransacao(string nome, double valor) : nome(nome), valor(valor) {}
// };

// class Conta {
// private:
//     double saldo;
//     vector<TipoTransacao> transacoes;

//int main() {
// int opcao;
// Conta conta;

// vector<string> tiposEntrada = {"Salario", "Bico", "Emprestimo"};
// vector<string> tiposSaida = {"Lazer", "Mercado", "Aluguel", "Agua", "Internet"};


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tipos
{
    vector <string> tiposEntrada = {"Salario", "Bico", "Emprestimo"};
    vector <string> tiposSaida = {"Lazer", "Mercado", "Aluguel", "Agua", "Internet"};

    vector <string> registroEntrada;
    vector <string> registroSaida;

    void Registrar(int indice)
    {
        if(indice < 0 || indice > tiposEntrada.size())
        {
            cout<< "Digite valores inteiros!" << endl;
        }
        else
        {
            registroEntrada.push_back(tiposEntrada[indice]);
        }
    }

    void RegistrarSaida(int indice)
    {
        if(indice < 0 || indice > tiposEntrada.size())
        {
            cout<< "Digite valores inteiros!" << endl;
        }
        else
        {
            registroSaida.push_back(tiposSaida[indice]);
        }

    }
};


class Conta
{
public:
    double saldo;
    vector<double> listaSaque;
    vector<double> listaDeposito;

    Conta() : saldo(0) {}

    void sacar(double valor)
    {
        if (valor <= 0)
        {
            cout << "Digite um valor maior que zero!" << endl;
        }
        else if (valor > saldo)
        {
            cout << "Não é possível realizar o saque. Saldo insuficiente!" << endl;
        }
        else
        {
            saldo -= valor;
            listaSaque.push_back(valor);
            cout << "Saque realizado com sucesso!" << endl;
        }
    }

    void depositar(double valor)
    {
        if (valor <= 0)
        {
            cout << "Não é possível realizar depósito com valores abaixo ou iguais a zero!" << endl;
        }
        else
        {
            saldo += valor;
            listaDeposito.push_back(valor);
            cout << "Depósito realizado com sucesso!" << endl;
        }
    }

    void mostrarExtrato()
    {
        Tipos tipo;

        // SAQUE
        cout << "SAQUES:" << endl;
        for (size_t i = 0; i < listaSaque.size(); i++)
        {
            cout << "Saque [" << i << "] valor = " << listaSaque[i] << "|| Tipo da saida: "<<tipo.tiposSaida[i] << endl;
        }

        // DEPOSITO
        cout << "DEPÓSITOS:" << endl;
        for (size_t i = 0; i < listaDeposito.size(); i++)
        {
            cout << "Depósito [" << i << "] valor = " << listaDeposito[i] <<"|| Tipo da entrada: "<<tipo.tiposEntrada[i] << endl;
        }
        cout << "Saldo atual: " << saldo << endl;
    }
};

int main()
{
    int opcao;
    Conta conta;
    Tipos tipo;

    int reg;

    cout << "Bem-vindo ao sistema financeiro!" << endl;

    while (true)
    {
        cout << "O que deseja fazer? \n[1] Sacar dinheiro \t[2] Depositar dinheiro \t[3] Ver o extrato \t[4] Sair" << endl;
        cin >> opcao;

        double valor;
        switch (opcao)
        {
        case 1:
            cout << "Digite o valor que deseja sacar: " << endl;
            cin >> valor;

            cout << "Qual foi o tipo de saída? 0- Lazer  1- Mercado  2- Aluguel  3- Internet" << endl;
            cin >> reg; 
            
            conta.sacar(valor);
            tipo.RegistrarSaida(reg);
            break;

        case 2:
            cout << "Digite a quantidade que deseja depositar: ";
            cin >> valor;
            conta.depositar(valor);

            cout << "Qual foi o tipo de entrada? 0- Salario  1- Bico  2- Emprestimo" << endl;
            cin >> reg; 
            tipo.RegistrarSaida(reg);
            break;

        case 3:
            conta.mostrarExtrato();
            break;

        case 4:
            cout << "Saindo do sistema. Até mais!" << endl;
            return 0;

        default:
            cout << "Opção inválida. Por favor, digite um valor válido!" << endl;
            break;
        }
    }
}
