#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char t[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
bool turno;

void guia() {
    cout << "-------------\n";
    for (int i = 0; i < 9; i++) {
        cout << "| " << i+1 << " ";
        if (i % 3 == 2) {
            cout << "|\n-------------\n";
        }
    }
}

void mostrar() {
    cout << "-------------\n";
    for (int i = 0; i < 9; i++) {
        cout << "| " << t[i] << " ";
        if (i % 3 == 2) {
            cout << "|\n-------------\n";
        }
    }
}

bool gana(char c) {
    int l[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };
    for (int i = 0; i < 8; i++) {
        if (t[l[i][0]] == c && t[l[i][1]] == c && t[l[i][2]] == c) {
            return true;
        }
    }
    return false;
}

bool lleno() {
    for (int i = 0; i < 9; i++) {
        if (t[i] == ' ') {
            return false;
        }
    }
    return true;
}

void jugadaJugador() {
    int p;
    while (true) {
        cout << "Tu turno (1-9): ";
        cin >> p;
        if (p >= 1 && p <= 9 && t[p-1] == ' ') {
            t[p-1] = 'X';
            break;
        }
    }
}

void jugadaPC() {
    int p;
    while (true) {
        p = rand() % 9;
        if (t[p] == ' ') {
            t[p] = 'O';
            cout << "La computadora eligio la posicion " << p+1 << "\n";
            break;
        }
    }
}

int main() {
    srand(time(0));
    cout << "Bienvenido a Triqui \n";
    cout << "Eres la X\n";
    turno = rand() % 2;
    if (turno) {
        cout << "Empiezas tu\n";
    } else {
        cout << "Empieza la computadora\n";
    }
    cout << "Asi estan organizadas las posiciones:\n";
    guia();
    if (!turno) {
        jugadaPC();
        turno = true;
    }
    while (true) {
        mostrar();
        if (turno) {
            jugadaJugador();
            if (gana('X')) {
                mostrar();
                cout << "Ganaste\n";
                break;
            }
        } else {
            jugadaPC();
            if (gana('O')) {
                mostrar();
                cout << "Perdiste\n";
                break;
            }
        }
        if (lleno()) {
            mostrar();
            cout << "Empate\n";
            break;
        }
        turno = !turno;
    }
}