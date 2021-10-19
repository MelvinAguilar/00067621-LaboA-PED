/*
 * Realizar un programa en C++ que lea números enteros desde teclado y los inserte en una
 * lista doblemente enlazada
  ~ Melvin Agu!lar  - 00067621*/

#include "DoublyLinkedList.hpp"

int menu();

/**
 * Main Function
*/
int main(int argc, char const *argv[]) {
    std::cout << "<< LISTAS DOBLEMENTE ENLAZADAS >>"<<"\n";
    
    DoublyLinkedList<int> list;

    int opc, value, ref;
    do {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "> Ingresamdo . . .\n" << std::endl;
                std::cout << "Ingrese numero: ";
                std::cin >> value; std::cin.ignore();
                list.insertAtEnd(value);
                break;
            case 2:
                std::cout << "> Ingresamdo . . .\n" << std::endl;
                std::cout << "Ingrese numero a ingresar: ";
                std::cin >> value;
                std::cout << "Numero de referencia: ";
                std::cin >> ref; std::cin.ignore();
                list.insertAfter(ref, value);
                break;
            case 3:
                std::cout << "> Eliminando . . .\n" << std::endl;
                std::cout << "Ingrese numero a eliminar: ";
                std::cin >> ref; std::cin.ignore();
                list.removeAllOcurrences(ref);
                break;
            case 4:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                list.printReverse();
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "\n> Saliendo . . .\n" << std::endl;
                break;
            default:
                std::cout << "\nOpcion Invalida" << std::endl;
        }
    } while (opc!=5);
    return 0;
}

/** 
 * Metodo para mostrar menu y escoger una opc
 * @return Entero con el valor de la opcion
 */
int menu() {
    int opc = 0;
    std::cout << "\n--------[ Menu ]-------" << std::endl;
    std::cout << "1) Insertar al final." << std::endl;
    std::cout << "2) Insertar despues de." << std::endl;
    std::cout << "3) Eliminar." << std::endl;
    std::cout << "4) Imprimir." << std::endl;
    std::cout << "5) Salir." << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opc; std::cin.ignore();
    return opc;
};