// Caracteres.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;


string Caracteres;
string Letras;
string Numeros;
string entrada;





int main()
{
	char Letra = '9';
	int valor_ascii = Letra;

	cout << Letra << " " << valor_ascii;

	cout << "\n\n\n";

   
	cout << "\n\tDigite varias strings:  ";
	std::getline(cin, entrada);

	
	for (char c : entrada) {
		if (isdigit(c)) {
			//se for numero
			Numeros += c;

		}
		else if (isalpha(c)) {
			//se for letra
			Letras += c;
		}
		else {
			//se for caractere especial
			Caracteres += c;
		}
	}

	cout << "\n\n\n";
	cout << "SEM ORDEM";
	cout << "\n\n\n";



	cout << "\n\tCaracteres especiais(-" << Caracteres << "-)\n";
	cout << "\n\tNumeros(-" << Numeros << "-)\n";
	cout << "\n\tLetras(-" << Letras << "-)\n";


	cout << "\n\n\n";
	cout << "EM ORDEM";
	cout << "\n\n\n";



	sort(Numeros.begin(),Numeros.end());
	sort(Letras.begin(),Letras.end());
    sort(Caracteres.begin(),Caracteres.end());



	cout << "\n\tCaracteres especiais(-" << Caracteres << "-)\n";
	cout << "\n\tNumeros(-" << Numeros << "-)\n";
	cout << "\n\tLetras(-" << Letras << "-)\n";
	cout << "\n\n\n";

	system("pause");
}
