/*
    Sistema Financeiro de registro de entrada e saída. 3 Pontos

    Registro de Entrada.

    Registro de Saída.

    Total.

    Categorias e Orçamento por categoria.
*/

//PRECISA CORRIGIR
//Quando escolhe a opção de sacar ele da "erro"


#include <iostream>

using namespace std;


int main()
{
    int opcao;
    double quantidade_Saque, saldo = 0, quantidade_Deposito;
    double quantidade_Saque_Atualizado = 0, quantidade_Deposito_Atualizado = 0;

    cout << "Bem-vindo ao sistema financeiro!!";
    cout << "O que deseja fazer? \n[1]Sacar dinheiro \t[2]Depositar dinheiro \t[3]Ver o saldo: \t[>4]Sair" ;
    cin >> opcao;
    while(true)
    {
        if (!NULL)
        {
            if(opcao == 1)
            {
                if (saldo < 0)
                {
                    //ARRUMAR ISSO
                    //PRECISA VOLTAR PARA A OPCAO DE DEPOSITAR OU VER O SALDO ATUAL
                    cout << "Digite a quantidade que deseja sacar: ";
                    cin >> quantidade_Saque;
                    saldo -= quantidade_Saque;
                    quantidade_Saque_Atualizado = quantidade_Saque_Atualizado + quantidade_Saque;
                    break;
                }
                else
                {
                    //ARRUMAR ISSO
                    //PRECISA VOLTAR PARA A OPCAO DE DEPOSITAR OU VER O SALDO ATUAL
                    cout << "Não é possivel fazer o saque! Motivo -> Sem saldo!" << endl;
                    cout << "O que deseja fazer? \n[2]Depositar dinheiro \t[3]Ver o saldo: \t[>4]Sair" ;
                    cin >> opcao;
                    break;
                }
            }
            else if(opcao == 2)
            {
                cout << "Digite a quantidade que deseja depositar: ";
                cin >> quantidade_Deposito;
                saldo += quantidade_Deposito;
                quantidade_Deposito_Atualizado = quantidade_Deposito_Atualizado + quantidade_Saque;
                break;
            }
            else if(opcao == 3)
            {
                cout << "Foi retirado " << quantidade_Saque_Atualizado << "RS da conta!" << endl;
                cout << "Foi acrescentado " << quantidade_Deposito_Atualizado << "RS na conta!"<< endl;
                cout << "Seu saldo atual e de " << saldo << endl;
                break;
            }
            else
            {
                return 0;
            }
        }

        else
        {
            cout << "Nao foi possivel completar a acao, digite valores validos!";
        }
    }
}