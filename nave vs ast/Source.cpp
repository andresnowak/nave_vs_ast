#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <list>
using namespace std;

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hcon,pos);
}

void ocultarCursor()
{
	HANDLE hcon;
	hcon =  GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = false;

	SetConsoleCursorInfo(hcon,&cci);
}

void limitesEscenario()
{
	for (int y = 3; y < 33; y++)
	{
		gotoxy(2, y);
		printf("%C", 186);
		gotoxy(98, y);
		printf("%C", 186);
	}
	for (int x = 2; x < 99; x++)
	{
		gotoxy(x, 3);
		printf("%C", 205);
		gotoxy(x, 32);
		printf("%C", 205);
	}

	gotoxy(2, 3);
	printf("%C", 201);
	gotoxy(98, 3);
	printf("%C", 187);
	gotoxy(98, 32);
	printf("%c", 188);
	gotoxy(2, 32);
	printf("%c", 200);
}
class Nave
{
public:
	Nave(int _x, int _y, int _corazones, int _vidas)
		: x(_x)
		, y(_y)
		, corazones(_corazones)
		,Vidas(_vidas)
	{

	}

	void pintar()
	{
		gotoxy(x, y);
		printf("  %c", 94);
		gotoxy(x, y + 1);
		printf(" %c%C%c", 40, 207, 41);
		gotoxy(x, y + 2);
		printf("%c%C %C%C", 94, 190, 190, 94);
	}
	void borrar()
	{
		gotoxy(x, y);
		printf("         ");
		gotoxy(x, y + 1);
		printf("         ");
		gotoxy(x, y + 2);
		printf("        ");
	}
	void mover ()
	{
#define IZQUIERDA 75
#define DERECHA 77
#define ARRIBA 72
#define ABAJO 80
		if (_kbhit())
		{
			char tecla = _getch();
			borrar();

			if (tecla == IZQUIERDA && x>3) x--;
			if (tecla == DERECHA && x+6<96) x++;
			if (tecla == ARRIBA && y> 4)y--;
			if (tecla == ABAJO && y+3< 32)y++;
			pintar();
			
		}
	}
	void p_Corazones()
	{
		gotoxy(2, 2);
		printf("salud");
		gotoxy(10, 2);
		printf("     ");
		for (int i = 0; i < corazones; i++)
		{
			gotoxy(10+i, 2);
			printf("%c", 189);
		}
	}
	
	void vidas()
	{
		gotoxy(15, 2);
		printf("vidas: ");
		gotoxy(22, 2);
		gotoxy(22, 2);
		cout << Vidas;

	}

	void muerte()
	{
		if (corazones == 0)
		{
			borrar();
			gotoxy(x, y);
			printf(" *  ");
			gotoxy(x, y + 1);
			printf("*** ");
			gotoxy(x, y + 2);
			printf(" *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("* * *  ");
			gotoxy(x, y + 1);
			printf(" ***  ");
			gotoxy(x, y + 2);
			printf("* * *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("*  *  *  ");
			gotoxy(x, y + 1);
			printf(" * * *   ");
			gotoxy(x, y + 2);
			printf("*  *  *  ");
			Sleep(200);
			borrar();
			pintar();
			Vidas--;
			vidas();
			corazones = 3;
			p_Corazones();

		}
		if (corazones == 2)
		{
			borrar();
			gotoxy(x, y);
			printf(" *  ");
			gotoxy(x, y + 1);
			printf("*** ");
			gotoxy(x, y + 2);
			printf(" *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("* * *  ");
			gotoxy(x, y + 1);
			printf(" ***  ");
			gotoxy(x, y + 2);
			printf("* * *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("*  *  *  ");
			gotoxy(x, y + 1);
			printf(" * * *   ");
			gotoxy(x, y + 2);
			printf("*  *  *  ");
			Sleep(200);
			borrar();
			pintar();
		}
		if (corazones == 1)
		{
			borrar();
			gotoxy(x, y);
			printf(" *  ");
			gotoxy(x, y + 1);
			printf("*** ");
			gotoxy(x, y + 2);
			printf(" *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("* * *  ");
			gotoxy(x, y + 1);
			printf(" ***  ");
			gotoxy(x, y + 2);
			printf("* * *  ");
			Sleep(200);
			borrar();
			gotoxy(x, y);
			printf("*  *  *  ");
			gotoxy(x, y + 1);
			printf(" * * *   ");
			gotoxy(x, y + 2);
			printf("*  *  *  ");
			Sleep(200);
			borrar();
			pintar();
		}
	}
	int X()
	{
		return x;
	}
	int Y()
	{
		return y;
	}
	void COR()
	{
		corazones--;
	}

	int _vidas()
	{
		return Vidas;
	}

private:
	int x;
	int y;
	int corazones;
	int Vidas;
};

class Ast
{
public:
	Ast(int _x, int _y)
		:x (_x = rand() % 95)
		,y (_y)
	{

	}
	void pintar()
	{
		gotoxy(x, y);
		printf("%C", 184);
		
	}
		


	void mover()
	{
		gotoxy(x,y);
		printf(" ");
		y++;
		
		if (y > 31)
		{
			x = rand() % 94+4;
			y = 4;
			
		}
		pintar();
	}

	void choque(class Nave &N)
	{
		if (x >= N.X() && x <= N.X() + 6 && y >= N.Y() && y <= N.Y() + 3)
		{

			N.COR();
			N.muerte();
			N.p_Corazones();
			x = rand() % 94 + 4;
			y = 4;
		}
	}

	int X()
	{
		return x;
	}

	int Y()
	{
		return y;
	}

private:
    int x;
	int y;
};

class Balas
{
	private:
	int x;
	int y;
public:
	Balas(int _x, int _y)
		:x (_x)
		,y (_y)
	{

	}

	void mover()
	{
		gotoxy(x, y);
		printf(" ");
	    y--;
		gotoxy(x, y);
		printf("*");
	}

	bool fuera()
	{
		if (y == 4)return true;
		 return false;
	}

	int X()
	{

		return x;
	}

	int Y()
	{
		return y;
	}
};

int main()
{
	limitesEscenario();
	ocultarCursor();
	
	list <Ast*> A;
	list <Ast*>::iterator itA;
	for (int i = 0; i < 7; i++)
	{
		A.push_back(new Ast(rand() % 98 + 3, rand() % 10 + 4));
	}
	Nave n1(50, 29,3,3);
	n1.pintar();
	n1.p_Corazones();
	n1.vidas();

	list <Balas*> B;
	list<Balas*>::iterator it;
	bool gameover = false;

	int puntos = 0;
	while (gameover)
	{
		gotoxy(30, 2);
		cout << "puntos: 2" << puntos;
		if (_kbhit())
		{
			char tecla = _getch();
			if (tecla == 32)
			{
				B.push_back(new Balas(n1.X() + 2, n1.Y() - 2));
			}
		}
		for (it = B.begin(); it != B.end();) // < -DEBEMOS BORRAR EL ITERADOR DEL FOR, POR QUE SINO INCREMENTERA AUN CUANDO BORREMOS EL ELEMENTO.
			{
				(*it)->mover();
				if ((*it)->fuera())
				{
					gotoxy((*it)->X(),(*it)->Y());
					printf(" ");

					delete (*it);//elimina al elemento que sale fuera, pero hay que modificar los punteros debido a que son agrupaciones de bytes con
					//ahora un hueco existente, para esto hacemos que el it borre al elemento de la lista.  BORRA EL ELEMENTO (no modifica la lista)
					it = B.erase(it); // esto equivale a decir TOMA EL SIGUIENTE VALOR EN LA LISTA POR QUE FUE BORRADO. (modifica la lista)

				}
				
				else it++; // INDICAMOS CON EL "ELSE" QUE SOLO DEBE INCREMENTAR CUANDO NO SE HA BORRADO UN ELEMENTO DE LA LISTA.


			
				
			}
		for (itA = A.begin();itA != A.end(); itA++)
		{
			(*itA)->choque(n1);
			(*itA)->mover();
		}

		for (itA = A.begin(); itA != A.end(); )
		{
			for (it = B.begin(); it != B.end(); )
			{
				if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
				{
					gotoxy((*it)->X(), (*it)->Y());
					printf(" ");
					delete(*it);
					it = B.erase(it);
					A.push_back(new Ast(rand() % 98 + 3, rand() % 10 + 4));
					gotoxy((*itA)->X(), (*itA)->Y());
					printf(" ");
					delete(*it);
					itA = A.erase(itA);

					puntos = +5;
				}
				else
				{
					it++;
					
				}
		        
			}
		
		}
		if (n1._vidas == 0)
		{
			gameover = true;
		}

		
		
		Sleep(30);
	}//fin de while

	while (gameover)
	{

	}

}//termina main
