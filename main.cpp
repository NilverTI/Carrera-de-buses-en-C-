#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void nombre(string& Bus1, string& Bus2) {
    gotoxy(15, 3); cout << "INGRESAR NOMBRE" << endl;
    gotoxy(10, 4); cout << "Nombre Bus 1: ";
    getline(cin, Bus1);
    gotoxy(10, 5); cout << "Nombre Bus 2: ";
    getline(cin, Bus2);

    gotoxy(25, 7); cout << "INICIAMOS LA CARRERA: " << endl;
    gotoxy(28, 8); cout << Bus1 << " Y " << Bus2 << endl;
}

void pista(int inx, int iny) {
    gotoxy(inx, iny);      cout << "|----------------------------------------------------------------------------||";
    gotoxy(inx, iny +  1); cout << "|                                                                            ||";
    gotoxy(inx, iny +  2); cout << "|                                                                            ||";
    gotoxy(inx, iny +  3); cout << "|                                                                            |M";
    gotoxy(inx, iny +  4); cout << "|                                                                            |E";
    gotoxy(inx, iny +  5); cout << "|----------------------------------------------------------------------------|T";
    gotoxy(inx, iny +  6); cout << "|                                                                            |A";
    gotoxy(inx, iny +  7); cout << "|                                                                            |A";
    gotoxy(inx, iny +  8); cout << "|                                                                            ||";
    gotoxy(inx, iny +  9); cout << "|                                                                            ||";
    gotoxy(inx, iny + 10); cout << "|----------------------------------------------------------------------------||";
}

void bus(int position, int line, int color) {
    setColor(color);
    gotoxy(position, line);     cout << "_______________ ";
    gotoxy(position, line + 1); cout << "|__|__|__|__|__|___ ";
    gotoxy(position, line + 2); cout << "|                 |)";
    gotoxy(position, line + 3); cout << "|~~~@~~~~~~~~~@~~~|)";
    setColor(7);
}

void imprimirNombre(int position, int line, const string& name) {
    gotoxy(position + 4, line + 2); // Ajusta la posición para centrar el nombre
    cout << name;
}

void carrera(string Bus1, string Bus2) {
    int bus1Pos = 1;
    int bus2Pos = 1;

    srand(static_cast<unsigned int>(time(0)));

    while (bus1Pos < 65 && bus2Pos < 65) {
        Sleep(100);

        bus1Pos += rand() % 3;
        bus2Pos += rand() % 3;

        gotoxy(2, 11); cout << "                                                                            ";
        gotoxy(2, 12); cout << "                                                                            ";
        gotoxy(2, 13); cout << "                                                                            ";
        gotoxy(2, 14); cout << "                                                                            ";
        gotoxy(2, 16); cout << "                                                                            ";
        gotoxy(2, 17); cout << "                                                                            ";
        gotoxy(2, 18); cout << "                                                                            ";
        gotoxy(2, 19); cout << "                                                                            ";

        bus(bus1Pos, 11, 9); imprimirNombre(bus1Pos, 11, Bus1);
        bus(bus2Pos, 16, 10);  imprimirNombre(bus2Pos, 16, Bus2);

        if (bus1Pos >= 58) {
            gotoxy(60, 21); cout << Bus1 << " es el ganador!" << endl;
            break;
        }
        else if (bus2Pos >= 58) {
            gotoxy(60, 21); cout << Bus2 << " es el ganador!" << endl;
            break;
        }
    }
}

int main() {
    string Bus1, Bus2;
    nombre(Bus1, Bus2);

    int inx = 1;
    int iny = 10;
    pista(inx, iny);

    carrera(Bus1, Bus2);

    cout << "\n\n\n\n\n\n\n";

    return 0;
}

