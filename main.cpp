#include <iostream>
#include <vector>

using namespace std;

class Conta
{
private:
    double saldo;
    vector<double> listaSaque;
    vector<double> listaDeposito;

public:
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
        // SAQUE
        cout << "SAQUES:" << endl;
        for (size_t i = 0; i < listaSaque.size(); i++)
        {
            cout << "Saque [" << i << "] valor = " << listaSaque[i] << endl;
        }

        // DEPOSITO
        cout << "DEPÓSITOS:" << endl;
        for (size_t i = 0; i < listaDeposito.size(); i++)
        {
            cout << "Depósito [" << i << "] valor = " << listaDeposito[i] << endl;
        }
        cout << "Saldo atual: " << saldo << endl;
    }
};

int main()
{
    int opcao;
    Conta conta;

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
            conta.sacar(valor);
            break;

        case 2:
            cout << "Digite a quantidade que deseja depositar: ";
            cin >> valor;
            conta.depositar(valor);
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
