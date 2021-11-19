/**
 * Realizar un programa en C++ para un árbol binario de búsqueda que en sus nodos
 * almacene la información de un estudiante: ID, nombre y apellido (deberá tomar como
 * criterio de ordenamiento el ID del estudiante).
 * ~ Melvin Agu!lar - 00067621
*/
#include "BinarySearchTree.hpp"
#include <string>

struct student {
    unsigned int  id; //ID deberia ser positivo y unico, por eso solo sobrecargo <, > y no el <=
    std::string firstName;
    std::string lastName;

    /** Constructores */
    student() {};
    student(unsigned int  _id, std::string _firstName, std::string _lastName)
        : id (_id), firstName(_firstName), lastName(_lastName) {};

    /** Sobrecarga del operador de Desigualdad < */
    bool operator< (const student &st) {
        return (this->id < st.id);
    };

    /** Sobrecarga del operador de Desigualdad > */
    bool operator> (const student &st) {
        return (this->id > st.id);
    };

    /** Sobrecarga del operador de Igualacion. No se ocupa*/
    /*bool operator== (const student &st) {
        return (this->id == st.id);
    };*/

    /** Sobrecarga del operador de salida. */
    friend std::ostream& operator<< (std::ostream &out, const student &st) { 
        out << ("\nID: " + std::to_string(st.id) + " Nombre: " + st.firstName + ", " + st.lastName);
        return out;
    };
};

int menu();
student newStudent();

/**
 * Main Function
*/
int main() {
    BST<student> tree;
    int opc = 0;

    do {
        opc = menu();
        switch (opc) {
            case 1: {
                std::cout << "> Ingresando . . .\n" << std::endl;
                tree.insert( newStudent() );
                break;
            } case 2:
                std::cout << "> Imprimiendo . . ." << std::endl;
                tree.preOrder();
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "> Imprimiendo . . ." << std::endl;
                tree.inOrder();
                std::cout << std::endl;
                break;
            case 4:
                std::cout << "> Imprimiendo . . ." << std::endl;
                tree.postOrder();
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
 * Metodo para crear un estudiante, establecer sus datos y devolverlo
 * @return Structura con el estudiante creado
*/
student newStudent() {
    student st;
    std::cout << "Ingrese ID: ";
    std::cin >> st.id;
    std::cout << "Ingrese Nombre: ";
    std::getline(std::cin >> std::ws, st.firstName);
    std::cout << "Ingrese Apellido: ";
    std::getline(std::cin, st.lastName);
    return st;
}

/** 
 * Metodo para mostrar menu y escoger una opc
 * @return Entero con el valor de la opcion
 */
int menu() {
    int opc = 0;
    std::cout << "\n--------[ Menu ]-------" << std::endl;
    std::cout << "1) Agregar Estudiante." << std::endl;
    std::cout << "2) Imprimir PreOrden." << std::endl;
    std::cout << "3) Imprimir InOrden." << std::endl;
    std::cout << "4) Imprimir PostOrden." << std::endl;
    std::cout << "5) Salir." << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opc; std::cin.ignore();
    return opc;
};