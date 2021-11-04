/**
 * Realizar un programa en C++ para una lista circular simplemente enlazada que en sus
 * nodos guarde la información de un estudiante: ID, Nombre y Carrera.
 * ~ Melvin Agu!lar - 00067621
*/

#include "CircularLinkedList.hpp"
#include <string>

/**
 * Estructura del estudiante
*/
struct Student {
    unsigned int id;
    std::string name;
    std::string career;
};

/**
 * Sobrecarda del operador de salida. 
 * Para mostrar al estudiante en una linea Ej: "cout << st;"
*/
std::ostream& operator<< (std::ostream &out, const Student &st) { 
    out << "ID: " << st.id << " Nombre: " << st.name << ", Carrera: " << st.career << '\n';
    return out;
}

/**
 * Sobrecarda del operador de entrada. 
 * Para ingresar al estudiante en una linea Ej: "cin >> st;"
*/
std::istream& operator>> (std::istream &in, Student &st) {
    std::cout << "Ingrese ID: ";
    in >> st.id; in.ignore();
    std::cout << "Ingrese Nombre: ";
    std::getline(in, st.name);
    std::cout << "Ingrese Carrera: ";
    std::getline(in, st.career);
    return in;
}

/**
 * Sobrecarga del operador de igualacion.
 * ver si es el igual un entero al id del estudiante Ej: "if (st.id == _id)"
*/
bool operator== (const Student &st, const int &id) {
    return (st.id == id);
}

int menu();
void printCustom(CircularLL<Student>&);

/**
 * Main Function
*/
int main() {
    CircularLL<Student> cirList;
    int opc=0, tempID=0;
    Student tempStudent;
    
    do {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "> Ingresamdo . . .\n" << std::endl;
                std::cin >> tempStudent;
                cirList.insertAtEnd(tempStudent);
                break;
            case 2:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                // ! Uso el Iterador y no la funcion print(), porque quieren que muestre el nombre del siguiente al ultimo
                // "El siguiente de "<<name<<" es "<<name2;
                // y con los templates de la lista no puedo acceder al nombre del siguiente al ultimo
                // no puedo hacer un T.name para saber el nombre y que quede como en el ejemplo
                printCustom(cirList);
                break;
            case 3:
                std::cout << "> Eliminando . . .\n" << std::endl;
                std::cout << "Ingrese ID a eliminar: ";
                std::cin >> tempID; std::cin.ignore();
                cirList.deleteNode(tempID);
                break;
            case 4:
                std::cout << "\n> Saliendo . . .\n" << std::endl;
                break;
            default:
                std::cout << "\nOpcion Invalida" << std::endl;
        }
    } while (opc!=4);
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
    std::cout << "2) Imprimir" << std::endl;
    std::cout << "3) Eliminar." << std::endl;
    std::cout << "4) Salir." << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opc; std::cin.ignore();
    return opc;
};

/** 
 * Metodo para mostrar todos los estudiantes y el siguiente al ultimo para demostrar que esta circularmente conectado
 * @param cirList Referencia de la clase
 */
void printCustom(CircularLL<Student>& cirList) {
    CircularLL<Student>::Iterator it = cirList.begin();

    if (cirList.size() == 0) {//Si esta vacia
        std::cout << "> Lista circular vacia" << std::endl;
        return;
    }
    
    do {
        std::cout << *it;                //Muestro el contenido del iterador (estudiante)
        if ( it == cirList.end() ) {     //Si es el ultimo muestro el siguiente y avanzo
            std::cout << "> El siguiente de "<< (*it).name;
            ++it;
            std::cout << " es " << (*it).name << std::endl;
        } else {
            ++it;                        //Avanzo al siguiente, equivalente a "node = node->next" 
        }
    } while ( it != cirList.begin() );   //Hasta que recorra todo y llegue al inicio    
};