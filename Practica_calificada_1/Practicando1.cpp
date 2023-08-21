#include <iostream>
#include<string>  

using namespace std;

int main() {
	int numero,i=1,j,contador=0,valor;
	cout << "Ingrese el numero n :" << endl;
	cin >> numero;
	while (1) {
		j = 1;
		while (j <= i) {
			if (i % j == 0) {
				contador++;
			}
			j++;
		}
		if (contador <= 2) {
			cout << "Procesando el numero primo " << i << " :" << endl;
			cout << "Numeros tachados : ";
			valor = i;
			if (valor * valor > numero) {
				break;
			}
			while (1) {
				valor = valor + i;
				cout << valor<<" ,";
				if (valor > numero) {
					cout << endl;
					break;
				}

			}
		}
		contador = 0;
		i++;
	}

	return 0;
} 