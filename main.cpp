/*
    Sistema Financeiro de registro de entrada e saída. 3 Pontos

    Registro de Entrada.

    Registro de Saída.

    Total.

    Categorias e Orçamento por categoria.
*/
//MELHORIAS:
//REGISTRO DA ORDEM DA AÇÃO POR EXEMPLO, 
//    SAQUE 1 VALOR:142R$, 
//    DEPOSITO 1 VALOR 123R$
//PODE SER FEITO UTILIZANDO LISTA

#include <iostream>

using namespace std;

int main()
{
    int opcao;
    double quantidade_Saque=0, saldo = 0, quantidade_Deposito =0;
    double quantidade_Saque_Atualizado = 0, quantidade_Deposito_Atualizado = 0;

    cout << "Bem-vindo ao sistema financeiro!!";

    while (true)
    {
        cout << "O que deseja fazer? \n[1]Sacar dinheiro \t[2]Depositar dinheiro \t[3]Ver o extrato: \t[>4]Sair" << endl;
        cin >> opcao;
        if (opcao == 1)
        {
            if (saldo <= 0)
            {
                cout << "Não é possivel fazer o saque! Motivo -> Sem saldo!" << endl;
                cout << "O que deseja fazer? \n[2]Depositar dinheiro \t[3]Ver o saldo: \t[>4]Sair" << endl;
                cin >> opcao;
            }
            else
            {
                cout << "Digite a quantidade que deseja sacar: ";
                cin >> quantidade_Saque;
                saldo -= quantidade_Saque;
                quantidade_Saque_Atualizado += quantidade_Saque;
            }
        }
        else if (opcao == 2)
        {
            cout << "Digite a quantidade que deseja depositar: ";
            cin >> quantidade_Deposito;
            saldo += quantidade_Deposito;
            quantidade_Deposito_Atualizado += quantidade_Deposito;
        }
        else if (opcao == 3)
        {
            system("clear||cls");
            cout << "Foi retirado " << quantidade_Saque_Atualizado << "RS da conta!" << endl;
            cout << "Foi acrescentado " << quantidade_Deposito_Atualizado << "RS na conta!" << endl;
            cout << "Seu saldo atual e de " << saldo << endl;
        }
        else if(opcao == 4)
        {
            break;
        }
        else
        {
            cout << "Nao foi possivel completar a acao, digite valores validos!";
        }
    }
    return 0;
}