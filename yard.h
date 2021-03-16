//
// Created by Igor Telheiro on 16/03/2021.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Yard {
    private:
        int _rows;
        int _cols;
        int _amountOfPiles;
        int _pileLimit;
    public:
        int *yard;

    Yard(int rows, int cols, int pileLimit = 4) {
        _rows = rows;
        _cols = cols;
        _amountOfPiles = rows * cols;
        _pileLimit = pileLimit;
        buildYard();
        fillRandomPiles(_amountOfPiles / 4);
        cout << "[ Coletando dados do patio... " << " ]" << endl;
    }

    void displayYard() {
        cout << "-------------------- Patio --------------------" << endl;
        for (int row = 0; row < _rows; row++) {
            for (int col = 1; col <= _cols; col++) {
                int pilePosition = getPilePosition(row, col);
                displayPile(pilePosition);
            }
            cout << endl;
        }
    }

    void addToPile(int pile, bool displayConfirmation = true) {
        if (isPileFull(pile)) cout << "Pilha cheia! Favor selecionar outra opcao" << endl;
        else {
            int &pileValue = yard[pile];
            pileValue += 1;
            if (displayConfirmation)
                cout << "Adicionado a pilha " << pile << " com sucesso! Tamanho atual: " << pileValue << "/" << _pileLimit << endl;
        }
    }

    void removeFromPile(int pile, bool displayConfirmation = true) {
        if (isPileEmpty(pile)) cout << "Pilha vazia! Favor selecionar outra opcao" << endl;
        else {
            int &pileValue = yard[pile];
            pileValue -= 1;
            if (displayConfirmation)
                cout << "Removido da pilha " << pile << " com sucesso! Tamanho atual: " << pileValue << "/" << _pileLimit << endl;
        }
    }

    bool isPileFull(int pile) {
        if (yard[pile] < _pileLimit) return false;
        return true;
    }

    bool isPileEmpty(int pile) {
        if (yard[pile] == 0) return true;
        return false;
    }

    private:
        void buildYard() {
            yard = new int[_amountOfPiles];
            for (int row = 0; row < _rows; row++) {
                for (int col = 1; col <= _cols; col++) {
                    int pilePosition = getPilePosition(row, col);
                    yard[pilePosition] = 0;
                }
            }
        }

        void displayPile(int position) {
            int pile = yard[position];
            if (position < 10) cout << "0";
            cout << position << ": [" << pile << "]    ";
        }

        int getPilePosition(int row, int col) {
            return row * _cols + col;
        }

        void fillRandomPiles(int amount) {
            for (int count = 0; count < amount; count++) {
                int randomPile = rand() % _amountOfPiles + 1;
                addToPile(randomPile, false);
            }
        }
};
