#include <iostream>
#include<string>  

using namespace std;

//Pregunta 1
// ----------------------------------------------------------------------
void Criba_Eratostenes(int n) {
    bool prime[100]; // Declarar un arreglo de booleanos para almacenar los números primos
    for (int i = 0; i <= n; i++) {
        prime[i] = true; // Inicializar todos los números como primos
    }
    prime[0] = false; // 0 no es primo
    prime[1] = false; // 1 no es primo

    // Iterar desde 2 hasta la raíz cuadrada de n
    for (int p = 2; p * p <= n; p++) {
        cout << "Procesando el numero primo " << p << endl;
        // Si el número actual es primo
        if (prime[p] == true) {
            // Actualizar todos sus múltiplos como no primos
            cout << "Numeros Tachados: ";
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
                cout << i << ", ";
            }
            cout << endl;
        }
    }

    // Imprimir todos los números primos
    cout << "Los numeros primos menores o iguales a " << n << " son: ";
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}

// Pregunta 2
// ----------------------------------------------------------------------
//Función que valida si es una fecha valida
bool esFechaValida(string sDia, string sMes, string sAnio) {
    //anio
    int anio = stoi(sAnio); //Conmvierte a entero
    if (anio <= 2010) return false;
    //mes
    int mes = stoi(sMes); //Conmvierte a entero
    if (mes == 0 && mes > 12) return false;
    //dia
    int dia = stoi(sDia); //Conmvierte a entero
    if (dia == 0 && dia > 31) return false;

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }

    if (mes == 2) {
        // Validar año bisiesto
        bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
        if (dia > 29 || (dia == 29 && !esBisiesto)) {
            return false;
        }
    }
    return true;
}

// Función que verifica si un número es capicúa
bool esCapicua(string num) {
    string original = num;
    string reverso = "";
    while (num.length() > 0) {
        //Mientras la longitu se mayor a cero
        int iPosicionUltimo = num.length() - 1;
        reverso = reverso + num.substr(iPosicionUltimo, 1);
        num = num.substr(0, iPosicionUltimo);
    }
    if (!esFechaValida(reverso.substr(0, 2), reverso.substr(2, 2), reverso.substr(4, 4)))
        return false;
    return original == reverso;
}

// Función que devuelve el número de días en un mes dado
int diasEnMes(int mes, int anio) {
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// main
// ----------------------------------------------------------------------
int main() {
    // Ultima actualizacion 2023-08-14

    // Pregunta 1
    // ----------------------------------------------------------------------
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Pregunta 1:" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    int n = 101;
    while (n > 100)
    {
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n > 100)
            cout << "El numero debe ser menor a 100" << endl;
    }

    Criba_Eratostenes(n);
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Pregunta 2:" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    // Pregunta 2
    // ----------------------------------------------------------------------
    int anio, mes, dia;
    anio = 2010;
    while (anio <= 2010)
    {
        cout << "Ingrese un anio (mayor que 2010): ";
        cin >> anio;
        if (anio <= 2010)
            cout << "El anio debe ser mayor a 2010" << endl;
    }

    mes = 0;
    while (mes < 1 || mes > 12)
    {
        cout << "Ingrese un mes [1 - 12]: ";
        cin >> mes;
        if (mes < 1 || mes > 12)
            cout << "El mes debe ser un valor entre [1 - 12]" << endl;
    }

    bool bContinuar = true; //Permite controla la salida del bucle
    while (bContinuar)
    {
        // Búsqueda de la siguiente fecha capicúa
        dia = 1;
        while (dia <= diasEnMes(mes, anio)) {
            string sFecha = to_string(dia * 1000000 + mes * 10000 + anio);
            //Si el día es menor 10, la fecha debe contener el cero por delante
            if (sFecha.length() == 7) sFecha = "0" + sFecha;
            //pe. 12/02/2021 -> 12022021
            //pe. 01/01/2020 -> 01012020
            if (esCapicua(sFecha)) {
                //Imprimimos la salida
                cout << "La siguiente fecha capicua es: " << sFecha.substr(0, 2) << "/" << sFecha.substr(2, 2) << "/" << sFecha.substr(4, 4) << " - " << sFecha << endl;
                bContinuar = false; //Sale del bucle
            }
            dia++;
        }
        // Si no se encontró fecha capicúa en el mes actual, se pasa al mes siguiente
        mes++;
        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
    return 0;
}