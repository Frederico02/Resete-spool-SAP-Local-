/*            Resete de Spool local SAP - v2      */
/*		Gupo Multi 04/04/2023            */
/*	Frederico Almeida - Analista de Suporte PL */


#include<iostream>
#include<cstdlib> // para usar o system()
#include<windows.h>
#include <limits>


using namespace std;

void reiniciar_spool(){
    cout << "Reiniciando spool" << endl;
    // Para o spool local da impressora
    system("net stop spooler");
    //Inicia o spool da maquina
    system("net start spooler");
}

void para_sap(){
	
	//Para o SAPSprint
    system("net stop SAPSprint");
}


void volta_sap(){
	
	//inicia o SAPSprint
    system("net start SAPSprint");
}

void limpar_spool(){
    cout << "Limpando Fila" << endl;
    // Limpa toda a fila de impressão 
    system("del /Q /F /S \"%systemroot%\\System32\\spool\\printers\\*.*\"");
}

int main() {
    int escolha = 0;
    bool opcao_valida;

    while (escolha != 4) {
        cout << "==============================" << endl;
        cout << "Resete de Spool local SAP" << endl;
        cout << "==============================" << endl;
        cout << "Digite 1 Para limpar o spool" << endl
             << "Digite 2 Para reiniciar o spool e serviços sap " << endl
             << "Digite 3 para Reinciar serviços e limpar o spool" << endl
             << "Digite 4 para encerrar" << endl;

        opcao_valida = false;
        while (!opcao_valida) {
            if (cin >> escolha && (escolha >= 1 && escolha <= 4)) {
                opcao_valida = true;
            } else {
                cout << "Escolha inválida, tente novamente." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (escolha) {
            case 1:
                limpar_spool();
                para_sap();
                reiniciar_spool();
                volta_sap();
                break;

            case 2:
            	para_sap();
                reiniciar_spool();
                volta_sap();
                break;

            case 3:
                limpar_spool();
                para_sap();
                reiniciar_spool();
                volta_sap();
                
                break;

            case 4:
                break;
        }
    }

    return 0;
}

