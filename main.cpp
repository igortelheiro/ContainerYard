#include <iostream>
#include "yard.h"

using namespace std;

void displayMenu() {
    cout << "---------- MENU ----------" << endl;
    cout << "1 - Visualizar patio" << endl;
    cout << "2 - Adicionar container a uma pilha" << endl;
    cout << "3 - Remover container de uma pilha" << endl;
    cout << "0 - Sair" << endl;
    cout << "Selecione uma opcao: ";
}

void handleSelectedOption(Yard &yard, int &option) {
    int pile;
    cin >> option;
    switch (option) {
        case 1:
            yard.displayYard();
            break;
        case 2:
            yard.displayYard();
            cout << "Selecione a pilha que deseja adicionar o container: ";
            cin >> pile;
            yard.addToPile(pile);
            break;
        case 3:
            yard.displayYard();
            cout << "Selecione a pilha que deseja remover um container: ";
            cin >> pile;
            yard.removeFromPile(pile);
            break;
        case 0:
            cout << "[ Fechando o patio... ]" << endl;
            break;
        default:
            cout << "Favor selecionar uma opcao valida" << endl;
    }
}

int main() {
    Yard yard(5, 8);
    int exitOption = 0;
    int option;

    while (true) {
        displayMenu();
        handleSelectedOption(yard, option);
        if (option == exitOption)
            return 0;
    }
}