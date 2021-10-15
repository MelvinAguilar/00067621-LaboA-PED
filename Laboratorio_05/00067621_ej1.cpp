/*
 * 
  ~ Melvin Agu!lar*/

#include <iostream>
#include <string>

/**
 * Estructura del nodo de personas con el nombre
*/
struct PeopleNode {
    std::string name;
    PeopleNode *next; //Siguiente
    PeopleNode *prev; //Anterior "previous"

    //Constructores del struct
    PeopleNode() {next = prev = NULL;}
    PeopleNode(std::string name) {
        this->name = name;
        next = prev = NULL;
    }
};

/**
 * Clase de lista doblemente enlazada de personas
*/
class People {
    private:
        PeopleNode *front;
        PeopleNode *back;
    public:
        People();
        void insertAtEnd(std::string);
        void print();
        void printReverse();
        void removeAllBefore(std::string);
        void removeAllBefore(PeopleNode *, std::string);
};

/**
 * Metodo constructor de la Clase Persona
*/
People::People(){
    front = back = NULL;
};

/**
 * Metodo de la Clase Persona que agrega un nodo al final de la lista
 * @param name String con el nombre de la persona que se ingresara
*/
void People::insertAtEnd(std::string name) {
    PeopleNode *newNode = new PeopleNode(name); 
    if (!back) {
        front = back = newNode;
    } else {
        back->next = newNode;
        newNode->prev = back;
        back = newNode;
    }
    std::cout << "> Ingresado Correctamente\n";
};

/**
 * Metodo de la Clase Persona que imprime de forma ITERATIVA la lista 
*/
void People::print(){
    PeopleNode *current = front;

    while (current) {
        std::cout << "- " << current->name << std::endl;
        current = current->next;
    }
};

/**
 * Metodo de la Clase Persona que imprime de ITERATIVAMENTE la lista de forma inversa
*/
void People::printReverse() {
    PeopleNode *current = back;

    while (current) {
        std::cout << "- " << current->name << std::endl;
        current = current->prev;
    }
};

/**
 * Metodo de la Clase Persona que remueve todos los nodos de la lista antes de una persona dada,
 * sin eliminar ocurrencias de la misma
 * @param dataKey String con el nombre de la persona que servira de soporte para eliminar sus anteriores
 * @overload
*/
void People::removeAllBefore(std::string dataKey){
    if (front==back) //Si esta vacio (NULL==NULL) o si solo tiene un nodo (1==1)
        std::cout << "> No hay suficientes elementos!" << std::endl;
    else 
        //Envio el puntero BACK por referencia, pero nunca modifico el BACK (No es puntero Doble)   
        // https://www.geeksforgeeks.org/c-pointers-question-9/
        removeAllBefore(back, dataKey);
};

/**
 * Metodo de la Clase Persona que recorre y remueve de forma recursiva todos los nodos antes de una persona dada
 * @param current Puntero actual del nodo de las personas 
 * @param dataKey String con el nombre de la persona que servira de soporte para eliminar sus anteriores
*/
void People::removeAllBefore(PeopleNode *current, std::string dataKey){
    if (current == front) { //Caso base
        return;
    } else { //Caso recursivo
        //Operador relacional == devuelve un bool. compare() devuelve un int y funciona tambien para cosas complejas con str
        if ( (current->name == dataKey) && (current->prev->name != dataKey) ) {
            PeopleNode *auxNode = current->prev;
            current->prev = current->prev->prev;

            if (current->prev)
                current->prev->next = current;
            else
                front = current;
            delete(auxNode);
            removeAllBefore(current, dataKey);
        } else {
            removeAllBefore(current->prev, dataKey);
        } 
    }
};

//Prototipos de funciones
int menu();

/**
 * Main Function
*/
int main(int argc, char const *argv[]) {
    std::string name;
    std::cout << "<< PERSONAS >>"<<"\n";

    People peopleList;
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "> Ingresamdo . . .\n" << std::endl;
                std::cout << "Ingrese nombre a insertar: ";
                std::getline(std::cin, name);
                peopleList.insertAtEnd(name);
                break;
            case 2:
                std::cout << "> Eliminando . . .\n" << std::endl;
                std::cout << "Ingrese nombre para eliminiar anteriores: ";
                std::getline(std::cin, name);
                peopleList.removeAllBefore(name);
                break;
            case 3:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                peopleList.print();
                break;
            case 4:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                peopleList.printReverse();
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
    std::cout << "\n--------[ Menu ]-------" << "\n";
    std::cout << "1) Ingresar Nombre." << std::endl;
    std::cout << "2) Eliminar todos los nodos previos." << std::endl;
    std::cout << "3) Mostrar Nombres." << std::endl;
    std::cout << "4) Mostrar Nombres de forma inversa." << std::endl;
    std::cout << "5) Salir." << std::endl;
    std::cout << "Opcion: "; 
    std::cin >> opc; std::cin.ignore();
    return opc;
};