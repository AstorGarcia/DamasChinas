#include "pch.h"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>


using namespace std;
using namespace System;

//Estructura para jugador 1 y 2
struct Jugador {
	char simbolo;
	int x, y;
};

//Tablero Damas Chinas
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

//Donde se ingresa el nombre de los jugadores
void JugadoresNombres(char* nom1, char* nom2) {

	cout << "Ingresar nombre de jugador:" << endl;
	cin >> nom1;
	cout << "Ingresar nombre de jugador:" << endl;
	cin >> nom2;
}
//Accion de dado para saber quien empieza primero
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
//Se selecciona la posicion en que cada jugador va a jugar
void SeleccionarFicha(char& F1, char& F2, char* nom1, char* nom2, int pP1, int pP2, int&T) {
	int opcion;

	if (pP1 > pP2)
	{
		T = 1;
		cout << "\n" << nom1 <<" "<< "elige la ficha que quieras jugar" << endl;
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
		case 1: F1 = 'A';
				F2 = 'B';break;
		case 2: F1 = 'B';
			    F2 = 'A';break;
		case 3: F1 = 'C';
			    F2 = 'D';break;
		case 4: F1 = 'D';
			    F2 = 'C';break;
		case 5: F1 = 'E';
			    F2 = 'F';break;
		case 6: F1 = 'F';
				F2 = 'E';break;
		}
	}

	else
	{
		T = 2;
		cout << "\n" << nom2<<" " << "elige la ficha que quieras jugar" << endl;
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
			F2 = 'B';break;
	case 2: F1 = 'B';
			F2 = 'A';break;
	case 3: F1 = 'C';
			F2 = 'D';break;
	case 4: F1 = 'D';
			F2 = 'C';break;
	case 5: F1 = 'E';
			F2 = 'F';break;
	case 6: F1 = 'F';
		    F2 = 'E';break;
	}
};
//Se asigna el caracter en cada parte respectiva del tabero
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
		Tablero[10][44] = 'D';Tablero[10][48] = 'D';Tablero[10][52] = 'D';Tablero[11][46] = 'D';
		Tablero[11][50] = 'D';Tablero[12][48] = 'D';

		break;
	case 'E':
	case 'F':
		Tablero[17][42] = 'E';Tablero[17][46] = 'E';Tablero[17][50] = 'E';Tablero[17][54] = 'E';
		Tablero[16][44] = 'E';Tablero[16][48] = 'E';Tablero[16][52] = 'E';	Tablero[15][46] = 'E';
		Tablero[15][50] = 'E';Tablero[14][48] = 'E';

		Tablero[9][6] = 'F';Tablero[9][10] = 'F';Tablero[9][14] = 'F';Tablero[9][18] = 'F';
		Tablero[10][8] = 'F';Tablero[10][12] = 'F';Tablero[10][16] = 'F';Tablero[11][10] = 'F';
		Tablero[11][14] = 'F';Tablero[12][12] = 'F';

		break;
	}
};
//Muestra el tablero
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

			if (Tablero[i][j] == 'N') cout << ' ';
			else cout << Tablero[i][j];
		}
		cout << endl;
	}
	
}
// Muestra las filas y columnas a partir del abcdario
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
//Cuadro que muestra la posicion de la ficha elegida por cualquiera de los dos jugadores
void DatosJugadores() {
	Console::SetCursorPosition(76, 9);
	cout << "_________________________________________________";
	Console::SetCursorPosition(75, 11);
	cout << "__________________________________________________";
	Console::SetCursorPosition(75, 13);
	cout << "__________________________________________________";
	Console::SetCursorPosition(75, 15);
	cout << "__________________________________________________";
	Console::SetCursorPosition(76, 18);
	cout << "_________________________________________________";

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
	cout << "X";
	Console::SetCursorPosition(76, 14);
	cout << "Y";
	Console::SetCursorPosition(76, 16);
	cout << "Movmientos";
	Console::SetCursorPosition(76, 17);
	cout << "realizados:";
}
//La posicion anterior de donde estaba una ficha que moviste se convierte en una "O"
void PintarPosAnt(Jugador* P)
{
	for (int i = 0; i < 19; i++) {
		for (int j = 0;j < 27;j++)
		{
			Tablero[P->y][P->x] = 'O';
		}
	}

}
//Se guarda los datos de la estructura del jugador por turno
void Caracteristicas(Jugador* P, char c, int xpos, int ypos) {
	P->simbolo = c;
	P->x = xpos;
	P->y = ypos;

}
//Se determina los bordes donde no se pueden ir (N) ni los espacion en blanco, despues determina si los saltos son de un casillero o de dos
void EvaluarPosTablero(Jugador* P,int x, int y, bool& salir) {
	bool saltoUno = false, saltoDoble = false, band = false;

	if (Tablero[x][y] != 'N' && Tablero[y][x] != ' ')
	{
		if(((P->x) + 2 == x || (P->x)- 2 == x) && ((P->y)+1 == y || (P->y) - 1 == y))
		{
			saltoUno = true;
		}
		else if (((P->x) + 4 == x || (P->x) - 4 == x) && ((P->y) + 2 == y || (P->y) - 2 == y)) 
		{
			saltoDoble = true;
		}
		if (saltoUno == true && (Tablero[x][y] != 'A' && Tablero[y][x] != 'B' && Tablero[y][x] != 'C'
			&& Tablero[y][x] != 'D' && Tablero[y][x] != 'E' && Tablero[y][x] != 'F'))
		{
			if(P->simbolo == 'A' && (P->y) > y)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
			if (P->simbolo == 'B' && (P->y) < y)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
			if (P->simbolo == 'C' && (P->x) < x)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
			if (P->simbolo == 'D' && (P->x) > x)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
			if (P->simbolo == 'E' && (P->x) > x)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
			if (P->simbolo == 'F' && (P->x) < x)
			{
				P->x = x;
				P->y = y;
				band = true;

			}
		}

		if (saltoDoble == true && (Tablero[y][x] !='A' && Tablero[y][x] != 'B' && Tablero[y][x] != 'C'
			&& Tablero[y][x] != 'D' && Tablero[y][x] != 'E' && Tablero[y][x] != 'F'))
		{
			if (P->x > x && P->y > y && (P->simbolo == 'E' || P->simbolo == 'A' || P->simbolo == 'D'))
			{
				if (Tablero[(P->y) - 1][(P->x) - 2] >= 'A' && Tablero[(P->y) - 1][(P->x) - 2] <= 'F')
				{
					P->x = x;
					P->y = y;
					band = true;
				}
			}
			else if (P->x <x && P->y > y && (P->simbolo == 'C' || P->simbolo == 'A' || P->simbolo == 'F'))
			{
				if (Tablero[(P->y) - 1][(P->x) + 2] >= 'A' && Tablero[(P->y) - 1][(P->x) + 2] <= 'F')
				{
					P->x = x;
					P->y = y;
					band = true;
				}

			}
			else if (P->x > x && P->y < y && (P->simbolo == 'B' || P->simbolo == 'D' || P->simbolo == 'E'))
			{
				if (Tablero[(P->y) + 1][(P->x) - 2] >= 'A' && Tablero[(P->y) + 1][(P->x) - 2] <= 'F')
				{
					P->x = x;
					P->y = y;
					band = true;
				}
			}
			else if (P->x < x && P->y < y && (P->simbolo == 'F' || P->simbolo == 'B' || P->simbolo == 'C'))
			{
				if (Tablero[(P->y) + 1][(P->x) + 2] >= 'A' && Tablero[(P->y) + 1][(P->x) + 2] <= 'F')
				{
					P->x = x;
					P->y = y;
					band = true;
				}
			}
		}
	}
	if (band == false) { Console::SetCursorPosition(2, 31), cout << "No se puede realizar el movimiento"; _getch(); }
};
//Es donde se almacena donde va a mover el jugador la fucha correspondiente
void movimientoFicha(Jugador* P)
{
	int x, y;
	bool salir;
	Console::BackgroundColor = ConsoleColor::Gray;
	Console::SetCursorPosition(P->x, P->y), cout << P->simbolo;
	Console::BackgroundColor = ConsoleColor::Black;

	do
	{
		Console::SetCursorPosition(2, 28);cout << "                                                  ";
		Console::SetCursorPosition(2, 28);cout << "Posicion X a la que desea moverse:";
		cin >> x;
	} while (x < 0 || x>57);

	do
	{
		Console::SetCursorPosition(2, 29);cout << "                                                  ";
		Console::SetCursorPosition(2, 29);cout << "Posicion Y a la que desea moverse:";
		cin >> y;
	} while (y < 0 || y>23);

	

	EvaluarPosTablero(P, x, y, salir);
	Console::SetCursorPosition(2, 25);cout << "                                                  ";
	Console::SetCursorPosition(2, 26);cout << "                                                  ";
	Console::SetCursorPosition(2, 27);cout << "                                                  ";
	Console::SetCursorPosition(2, 28);cout << "                                                  ";
	Console::SetCursorPosition(2, 29);cout << "                                                  ";

}
//En la direccion donde el jugador mueve la ficha se torna de la letra de la misma
void PinterPosAct(Jugador* P) {
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0;j < 27;j++)
		{
			Tablero[P->y][P->x] = P->simbolo;
		}
	}
}
//Se escoje que ficha vas a jugar mediante las filas y columnos 
void EscogerFicha(Jugador* P, char* nombre, char ficha, int T) 
{
	int opc;
	int posX, posY;
	bool salir = false;
	char columna, fila;

	do
	{
		Console::SetCursorPosition(2, 25);
		cout << "                                                                                ";
		Console::SetCursorPosition(2, 26);
		cout << "                                                                                ";
		Console::SetCursorPosition(2, 27);
		cout << "                                                                                ";
		Console::SetCursorPosition(2, 28);
		cout << "                                                                                ";
			
		
		Console::SetCursorPosition(2, 25);
		cout << nombre <<" " << "ingresa la ficha en la columna que quieras mover:";
		cin >> columna;

		switch (toupper(columna))
		{
		case 'A': posX = 6;break;
		case 'B': posX = 8;break;
		case 'C': posX = 10;break;
		case 'D': posX = 12;break;
		case 'E': posX = 14;break;
		case 'F': posX = 16;break;
		case 'G': posX = 18;break;
		case 'H': posX = 20;break;
		case 'I': posX = 22;break;
		case 'J': posX = 24;break;
		case 'K': posX = 26;break;
		case 'L': posX = 28;break;
		case 'M': posX = 30;break;
		case 'N': posX = 32;break;
		case 'O': posX = 34;break;
		case 'P': posX = 36;break;
		case 'Q': posX = 38;break;
		case 'R': posX = 40;break;
		case 'S': posX = 42;break;
		case 'T': posX = 44;break;
		case 'U': posX = 46;break;
		case 'V': posX = 48;break;
		case 'W': posX = 50;break;
		case 'X': posX = 52;break;
		case 'Y': posX = 54;break;
		}

		Console::SetCursorPosition(2, 26);
		cout << nombre <<" " << "Ingresa la ficha en la fila que quieras mover:";
		cin >> fila;

		switch (toupper(fila))
		{
		case 'A': posY = 5;break;
		case 'B': posY = 6;break;
		case 'C': posY = 7;break;
		case 'D': posY = 8;break;
		case 'E': posY = 9;break;
		case 'F': posY = 10;break;
		case 'G': posY = 11;break;
		case 'H': posY = 12;break;
		case 'I': posY = 13;break;
		case 'J': posY = 14;break;
		case 'K': posY = 15;break;
		case 'L': posY = 16;break;
		case 'M': posY = 17;break;
		case 'N': posY = 18;break;
		case 'O': posY = 19;break;
		case 'P': posY = 20;break;
		case 'Q': posY = 21;break;
		}
		if (Tablero[posY][posX] == ficha)salir = true;
		if (salir != true)
		{
			Console::SetCursorPosition(3, 28); cout << "No se habilita mover esta ficha";
				getch();
		}
	} while (salir != true);

	if (T == 1)
	{
		Console::SetCursorPosition(96, 14); cout << posY;
		Console::SetCursorPosition(96, 12); cout << posX;
	}
	else {
		Console::SetCursorPosition(115, 14); cout << posY;
		Console::SetCursorPosition(115, 12); cout << posX;
	}

	Caracteristicas(P, ficha, posX, posY);
	PintarPosAnt(P);
	movimientoFicha(P);
	PinterPosAct(P);

	if (T == 1)
	{
		Console::SetCursorPosition(96, 14); cout << "    ";
		Console::SetCursorPosition(96, 12); cout << "    ";
	}
	else
	{
		Console::SetCursorPosition(115, 14); cout << "    ";
		Console::SetCursorPosition(115, 12); cout << "    ";
	}
}
//Declara el ganador
bool Ganador(Jugador* P)
{
	for (int i = 0;i < 19;i++) 
	{
		for (int j = 0; j < 27; j++)
		{
			if (P->simbolo == 'A' || P->simbolo == 'B')
			{
				if (Tablero[8][24] == 'A' && Tablero[8][28] == 'A' && Tablero[8][32] == 'A' && Tablero[8][36] == 'A'
					&& Tablero[7][26] == 'A' && Tablero[7][30] == 'A' && Tablero[7][34] == 'A' && Tablero[6][28] == 'A'
					&& Tablero[6][32] == 'A' && Tablero[5][30] == 'A')return true;

				else if (Tablero[18][24] == 'A' && Tablero[18][28] == 'A' && Tablero[18][32] == 'A' && Tablero[18][36] == 'A'
					  && Tablero[19][26] == 'A' && Tablero[19][30] == 'A' && Tablero[19][34] == 'A' && Tablero[20][28] == 'A'
					  && Tablero[20][32] == 'A' && Tablero[21][30] == 'A')return true;
			}
			else if (P->simbolo == 'C' || P->simbolo == 'D')
			{
				if (Tablero[17][6] == 'D' && Tablero[17][10] == 'D' && Tablero[17][14] == 'D' && Tablero[17][18] == 'D'
			    && Tablero[10][44] == 'D' && Tablero[16][12] == 'D' && Tablero[16][16] == 'D' && Tablero[15][10] == 'D'
			   	&& Tablero[15][14] == 'D' && Tablero[14][12] == 'D')return true;

				else if (Tablero[9][42] == 'C' && Tablero[9][46] == 'C' && Tablero[9][50] == 'A' && Tablero[9][54] == 'A'
					  && Tablero[10][44] == 'C' && Tablero[10][48] == 'C' && Tablero[10][52] == 'A' && Tablero[11][46] == 'A'
					  && Tablero[11][50] == 'C' && Tablero[12][48] == 'C')return true;
			}
			else if (P->simbolo == 'E' || P->simbolo == 'F')
			{
				if (Tablero[9][6] == 'E' && Tablero[9][10] == 'E' && Tablero[9][14] == 'E' && Tablero[9][18] == 'E'
					&& Tablero[16][44] == 'E' && Tablero[10][12] == 'E' && Tablero[10][16] == 'E' && Tablero[11][10] == 'E'
					&& Tablero[15][14] == 'E' && Tablero[12][12] == 'E')return true;

				else if (Tablero[17][42] == 'F' && Tablero[17][46] == 'F' && Tablero[17][50] == 'F' && Tablero[17][54] == 'F'
					&& Tablero[16][44] == 'F' && Tablero[10][48] == 'F' && Tablero[16][52] == 'F' && Tablero[15][46] == 'F'
					&& Tablero[15][50] == 'F' && Tablero[14][48] == 'F')return true;
			}
		}
	}
}
int main() {

	char fichaJ1;
	char fichaJ2;
	int turno;
	char* nombreJ1 = new char[20];
	char* nombreJ2 = new char[20];
	int puntajeJ1, puntajeP2;
	int movimientoJ1 = 0, movimientoJ2 = 0;

	JugadoresNombres(nombreJ1, nombreJ2);
	Dado(puntajeJ1, puntajeP2, nombreJ1, nombreJ2);
	SeleccionarFicha(fichaJ1, fichaJ2, nombreJ1, nombreJ2, puntajeJ1, puntajeP2, turno);
	PosicionTablero(fichaJ1);
	Console::Clear();
	Console::CursorVisible = false;

	Jugador* P1 = new Jugador;
	Jugador* P2 = new Jugador;

	while (true)
	{
		Console::CursorVisible = false;

		mostrarTablero();
		FilasColumnas();
		DatosJugadores();

		Console::SetCursorPosition(91, 10);
		cout << nombreJ1 << "[" << fichaJ1 << "]";
		Console::SetCursorPosition(109, 10);
		cout << nombreJ2 << "[" << fichaJ2 << "]";
		Console::SetCursorPosition(97, 17);cout << movimientoJ1;
		Console::SetCursorPosition(115, 17);cout << movimientoJ2;
		
	if (Ganador(P1) == true)break;

		if (turno == 1)
		{
			EscogerFicha(P1,nombreJ1, fichaJ1, turno);
			movimientoJ1++;
			turno = 2;
		}
		else
		{
			EscogerFicha(P2,nombreJ2, fichaJ2, turno);
			movimientoJ2++;
			turno = 1;
		}
	}
	Console::Clear();
	if (turno == 1)
		cout << "El ganador es: " << nombreJ2 << endl;
	else cout << "El ganador es: " << nombreJ1 << endl;



	_getch();
	return 0;

}