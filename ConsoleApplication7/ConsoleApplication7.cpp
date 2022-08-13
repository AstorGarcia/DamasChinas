
#include "pch.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>


using namespace std;
using namespace System;

struct Player {
	char simbolo;
	int x, y;
};


char Tablero[23][57] = {
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
	{' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
	{' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
	{' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' '},
	{' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N'},
	{' ',' ',' ',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N'},
	{' ',' ',' ',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N',' ','N'},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ',' ',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','O',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','N',' ','N',' ','N',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
};

void JugadoresNombres(char* nom1, char* nom2) {

	cout << "Ingresar nombre de jugador:" << endl;
	cin >> nom1;
	cout << "Ingresar nombre de jugador:" << endl;
	cin >> nom2;
}
void Dado(int& P1, int& P2, char* nom1, char* nom2) {
	int dado1;
	int dado2;

	srand(time(NULL));
	dado1 = 1 + rand() % (6 + 1 - 1);
	dado2 = 1 + rand() % (6 + 1 - 1);

	cout << "\n Dados lanzandose";
	_sleep(800);
	cout << ".";
	_sleep(800);
	cout << ".";
	_sleep(800);
	cout << ".";

	P1 = dado1;
	P2 = dado2;

	if (P1 > P2) {
		cout << "\n Puntaje mas alto:" << nom1 << endl;
	}
	else {
		cout << "\n Puntaje mas alto:" << nom2 << endl;
	}
}
void SeleccionarFicha(char& F1, char& F2, char* nom1, char* nom2, int pP1, int pP2, int& T) {
	int opcion;

	if (pP1 > pP2)
	{
		T = 1;
		cout << "\n" << nom1 << "Elige la ficha que qieras jugar" << endl;
		cout << "(1) Posicion A" << endl;
		cout << "(2) Posicion B" << endl;
		cout << "(3) Posicion C" << endl;
		cout << "(4) Posicion D" << endl;
		cout << "(5) Posicion E" << endl;
		cout << "(6) Posicion F" << endl;

		do {
			Console::SetCursorPosition(1, 15); cout << "                 ";
			Console::SetCursorPosition(1, 15); cout << "Ingrese seleccion";
			cin >> opcion;
		} while (opcion < 1 || opcion>6);

		switch (opcion)
		{
		case 1: F1 = 'A';break;
		case 2: F1 = 'B';break;
		case 3: F1 = 'C';break;
		case 4: F1 = 'D';break;
		case 6: F1 = 'E';break;
		case 5: F1 = 'F';
		}

		if (F1 == 'A') {
			F2 == 'B';
		}
		else if (F1 == 'B') { F2 == 'A'; }
		else if (F1 == 'C') { F2 == 'D'; }
		else if (F1 == 'D') { F2 == 'C'; }
		else if (F1 == 'E') { F2 == 'F'; }
		else if (F1 == 'F') { F2 == 'E'; }
	}

	else
	{
		T = 2;
		cout << "\n" << nom2 << "Elige la ficha que qieras jugar" << endl;
		cout << "(1) Posicion A" << endl;
		cout << "(2) Posicion B" << endl;
		cout << "(3) Posicion C" << endl;
		cout << "(4) Posicion D" << endl;
		cout << "(5) Posicion E" << endl;
		cout << "(6) Posicion F" << endl;
	}

	do {
		Console::SetCursorPosition(1, 15); cout << "                 ";
		Console::SetCursorPosition(1, 15); cout << "Ingrese seleccion";
		cin >> opcion;
	} while (opcion < 1 || opcion>6);

	switch (opcion)
	{
	case 1: F1 = 'A';
		break;
	case 2: F1 = 'B';
		break;
	case 3: F1 = 'C';
		break;
	case 4: F1 = 'D';
		break;
	case 5: F1 = 'E';
		break;
	case 6: F1 = 'F';
		break;
	}

	if (F1 == 'A')
	{
		F2 == 'B';
	}
	else if (F1 == 'B') { F2 == 'A'; }
	else if (F1 == 'C') { F2 == 'D'; }
	else if (F1 == 'D') { F2 == 'C'; }
	else if (F1 == 'E') { F2 == 'F'; }
	else if (F1 == 'F') { F2 == 'E'; }

};
void PosicionTablero(char F) {
	switch (F)
	{
	case 'A':
	case 'B':
		Tablero[18][24] = 'A';Tablero[18][28] = 'A';Tablero[18][32] = 'A';Tablero[18][36] = 'A';
		Tablero[19][26] = 'A';Tablero[19][30] = 'A';Tablero[19][34] = 'A';Tablero[20][28] = 'A';
		Tablero[20][32] = 'A';Tablero[21][30] = 'A';

		Tablero[8][24] = 'B';Tablero[8][28] = 'B';Tablero[8][32] = 'B';Tablero[8][36] = 'B';
		Tablero[7][26] = 'B';Tablero[7][30] = 'B';Tablero[7][34] = 'B';Tablero[6][28] = 'B';
		Tablero[6][32] = 'B';Tablero[5][30] = 'B';

		break;
	case 'C':
	case 'D':
		Tablero[17][6] = 'C';Tablero[17][10] = 'C';Tablero[17][14] = 'C';Tablero[17][18] = 'C';
		Tablero[16][8] = 'C';Tablero[16][12] = 'C';Tablero[16][16] = 'C';Tablero[15][10] = 'C';
		Tablero[15][14] = 'C';Tablero[14][12] = 'C';

		Tablero[9][42] = 'D';Tablero[9][46] = 'D';Tablero[9][50] = 'D';Tablero[9][54] = 'D';
		Tablero[10][44] = 'D';Tablero[9][48] = 'D';Tablero[9][52] = 'D';Tablero[11][46] = 'D';
		Tablero[11][50] = 'D';Tablero[12][48] = 'D';

		break;
	case 'E':
	case 'F':
		Tablero[17][42] = 'E';Tablero[17][46] = 'E';Tablero[17][50] = 'E';Tablero[17][54] = 'E';
		Tablero[16][44] = 'E';Tablero[16][48] = 'E';Tablero[16][52] = 'E';	Tablero[15][46] = 'E';
		Tablero[15][50] = 'E';Tablero[14][48] = 'E';

		break;
	}
};
void mostrarTablero() {

	for (int i = 0;i < 23;i++)
	{
		for (int j = 0; j < 57; j++)
		{
			Console::SetCursorPosition(j, i);
			if (Tablero[i][j] == 'O')Console::ForegroundColor = ConsoleColor::White;
			else if (Tablero[i][j] == 'A')Console::ForegroundColor = ConsoleColor::Red;
			else if (Tablero[i][j] == 'B')Console::ForegroundColor = ConsoleColor::Green;
			else if (Tablero[i][j] == 'C')Console::ForegroundColor = ConsoleColor::Red;
			else if (Tablero[i][j] == 'D')Console::ForegroundColor = ConsoleColor::Green;
			else if (Tablero[i][j] == 'E')Console::ForegroundColor = ConsoleColor::Red;
			else if (Tablero[i][j] == 'F')Console::ForegroundColor = ConsoleColor::Green;

			if (Tablero[i][j] == 'N') cout << '    ';
			else cout << Tablero[i][j];
		}
		cout << endl;
	}
}
void FilasColumnas() {
	Console::ForegroundColor = ConsoleColor::Yellow;

	Console::SetCursorPosition(6, 2);cout << "A";
	Console::SetCursorPosition(8, 2);cout << "B";
	Console::SetCursorPosition(10, 2);cout << "C";
	Console::SetCursorPosition(12, 2);cout << "D";
	Console::SetCursorPosition(14, 2);cout << "E";
	Console::SetCursorPosition(16, 2);cout << "F";
	Console::SetCursorPosition(18, 2);cout << "G";
	Console::SetCursorPosition(20, 2);cout << "H";
	Console::SetCursorPosition(22, 2);cout << "I";
	Console::SetCursorPosition(24, 2);cout << "J";
	Console::SetCursorPosition(26, 2);cout << "K";
	Console::SetCursorPosition(28, 2);cout << "L";
	Console::SetCursorPosition(30, 2);cout << "M";
	Console::SetCursorPosition(32, 2);cout << "N";
	Console::SetCursorPosition(34, 2);cout << "O";
	Console::SetCursorPosition(36, 2);cout << "P";
	Console::SetCursorPosition(38, 2);cout << "Q";
	Console::SetCursorPosition(40, 2);cout << "R";
	Console::SetCursorPosition(42, 2);cout << "S";
	Console::SetCursorPosition(44, 2);cout << "T";
	Console::SetCursorPosition(46, 2);cout << "U";
	Console::SetCursorPosition(48, 2);cout << "V";
	Console::SetCursorPosition(50, 2);cout << "W";
	Console::SetCursorPosition(52, 2);cout << "X";
	Console::SetCursorPosition(54, 2);cout << "Y";

	Console::SetCursorPosition(2, 5);cout << "A";
	Console::SetCursorPosition(2, 6);cout << "B";
	Console::SetCursorPosition(2, 7);cout << "C";
	Console::SetCursorPosition(2, 8);cout << "D";
	Console::SetCursorPosition(2, 9);cout << "E";
	Console::SetCursorPosition(2, 10);cout << "F";
	Console::SetCursorPosition(2, 11);cout << "G";
	Console::SetCursorPosition(2, 12);cout << "H";
	Console::SetCursorPosition(2, 13);cout << "I";
	Console::SetCursorPosition(2, 14);cout << "J";
	Console::SetCursorPosition(2, 15);cout << "K";
	Console::SetCursorPosition(2, 16);cout << "L";
	Console::SetCursorPosition(2, 17);cout << "M";
	Console::SetCursorPosition(2, 18);cout << "N";
	Console::SetCursorPosition(2, 19);cout << "O";
	Console::SetCursorPosition(2, 20);cout << "P";
	Console::SetCursorPosition(2, 21);cout << "Q";
}
void DatosJugadores() {
	Console::SetCursorPosition(76, 9);
	cout << "_______________________________________________________";
	Console::SetCursorPosition(75, 11);
	cout << "_______________________________________________________";
	Console::SetCursorPosition(74, 13);
	cout << "_______________________________________________________";
	Console::SetCursorPosition(73, 15);
	cout << "_______________________________________________________";
	Console::SetCursorPosition(72, 18);
	cout << "_______________________________________________________";

	Console::SetCursorPosition(75, 10);cout << "|";
	Console::SetCursorPosition(75, 11);cout << "|";
	Console::SetCursorPosition(75, 12);cout << "|";
	Console::SetCursorPosition(75, 13);cout << "|";
	Console::SetCursorPosition(75, 14);cout << "|";
	Console::SetCursorPosition(75, 15);cout << "|";
	Console::SetCursorPosition(75, 16);cout << "|";
	Console::SetCursorPosition(75, 17);cout << "|";
	Console::SetCursorPosition(75, 18);cout << "|";

	Console::SetCursorPosition(88, 10);cout << "|";
	Console::SetCursorPosition(88, 11);cout << "|";
	Console::SetCursorPosition(88, 12);cout << "|";
	Console::SetCursorPosition(88, 13);cout << "|";
	Console::SetCursorPosition(88, 14);cout << "|";
	Console::SetCursorPosition(88, 15);cout << "|";
	Console::SetCursorPosition(88, 16);cout << "|";
	Console::SetCursorPosition(88, 17);cout << "|";
	Console::SetCursorPosition(88, 18);cout << "|";

	Console::SetCursorPosition(105, 10);cout << "|";
	Console::SetCursorPosition(105, 11);cout << "|";
	Console::SetCursorPosition(105, 12);cout << "|";
	Console::SetCursorPosition(105, 13);cout << "|";
	Console::SetCursorPosition(105, 14);cout << "|";
	Console::SetCursorPosition(105, 15);cout << "|";
	Console::SetCursorPosition(105, 16);cout << "|";
	Console::SetCursorPosition(105, 17);cout << "|";
	Console::SetCursorPosition(105, 18);cout << "|";

	Console::SetCursorPosition(124, 10);cout << "|";
	Console::SetCursorPosition(124, 11);cout << "|";
	Console::SetCursorPosition(124, 12);cout << "|";
	Console::SetCursorPosition(124, 13);cout << "|";
	Console::SetCursorPosition(124, 14);cout << "|";
	Console::SetCursorPosition(124, 15);cout << "|";
	Console::SetCursorPosition(124, 16);cout << "|";
	Console::SetCursorPosition(124, 17);cout << "|";
	Console::SetCursorPosition(124, 18);cout << "|";

	Console::SetCursorPosition(76, 12);
	cout << "Y";
	Console::SetCursorPosition(76, 14);
	cout << "X";
	Console::SetCursorPosition(76, 16);
	cout << "Movmientos";
	Console::SetCursorPosition(76, 17);
	cout << "realizados:";
}
int main() {

	char fP1;
	char fP2;
	int turno;
	char* nomP1 = new char[20];
	char* nomP2 = new char[20];
	int puntajeP1, puntajeP2;
	int movimientoP1 = 0, movimientosP2 = 0;

	JugadoresNombres(nomP1, nomP2);
	Dado(puntajeP1, puntajeP2, nomP1, nomP2);
	SeleccionarFicha(fP1, fP2, nomP1, nomP2, puntajeP1, puntajeP2, turno);
	PosicionTablero(fP1);
	Console::Clear();
	Console::CursorVisible = false;

	Player* P1 = new Player;
	Player* P2 = new Player;

	while (true)
	{
		Console::CursorVisible = false;

		mostrarTablero();
		FilasColumnas();
	}
}