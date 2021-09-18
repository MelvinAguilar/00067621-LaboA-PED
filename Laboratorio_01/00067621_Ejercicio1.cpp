/*
 * Realizar la multiplicación de dos enteros en forma de suma recursiva. Por ejemplo:
 * 4 × 3 = 4 + 4 + 4
  ~ Melvin Agu!lar*/

#include <iostream>

int multiRecursiva(int, int, int); //Prototipo de funcion

/**
 * Main Function
*/
int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    std::cout << "\n<< MULTIPLICACION RECURSIVA >>" << std::endl; 

    std::cout << "Ingrese Primer Valor a multiplicar: ";
    std::cin >> num1;
    std::cout << "Ingrese Segundo Valor a multiplicar: ";
    std::cin >> num2;

    std::cout << "\nEl resultado de la Multiplicacion iterativa es: " << multiRecursiva(num1, num2, 0) << std::endl; 
    return 0;
}

/** Metodo para multiplicar en forma de suma recursiva 
* @param num Numero base para multiplicar
* @param limit Numero de cantidad de veces a sumar
* @param i Iterador para conocer las veces que se ha sumado
* @return int Total de la suma
*/
int multiRecursiva(int num, int limit, int i) {
    if (i == limit) { //Caso Base
        return 0;
    } else { //Caso Recursivo
        return num + multiRecursiva(num, limit, ++i);
    }
};