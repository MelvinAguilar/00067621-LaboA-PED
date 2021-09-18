/*
 * Realizar una lista simplemente enlaza con la forma que gusten, ya sea insertando al inicio o al
 * final (pila o cola), la lista representará una colección de libros donde deberá guardarse el id y
 * nombre de cada libro, para este ejercicio se deberán insertar libros e imprimirlos de forma
 * recursiva.
  ~ Melvin Agu!lar*/

#include <iostream>
#include <string>

//Estructura de cola de Libros
struct listaLibros {
    int id;
    std::string nombre;
    listaLibros *siguiente;
};

/** 
* Clase Libro contenedora 
*/
class Libro {
    private:
        listaLibros *libroInicio;
    public:
        Libro();
        void ingresarLibro();
        void ingresarLibro(int, std::string nombre);
        void impresionRecursiva();
        void impresionRecursiva(listaLibros *auxiliar);
        void impresionContraria();
        void impresionContraria(listaLibros *auxiliar);
};

//Prototipos de funciones
int menu();
void imprimirLibro(listaLibros*);

/** 
* Metodo constructor de clase libro
*/
Libro::Libro() {
    libroInicio = NULL;
};

/** 
 * Metodo de la clase Libro encargada de recopilar informacion del libro
 */
void Libro::ingresarLibro() {
    int id = 0;
    std::string nombre;
    std::cout << "Ingresar ID del libro: "; 
    std::cin >> id; std::cin.ignore();
    std::cout << "Ingresar Nombre del libro: ";
    std::getline(std::cin, nombre);

    ingresarLibro(id, nombre);
};

/** Metodo de la clase Libro para ingresar Libro a la cola
 * @param id Int con Identificador del Libro
 * @param nombre String del nombre del libro
 * @overload
 */
void Libro::ingresarLibro(int id, std::string nombre) { //Insertando al inicio
    listaLibros *nuevoLibro = new listaLibros;

    nuevoLibro->id = id;
    nuevoLibro->nombre = nombre;
    nuevoLibro->siguiente = libroInicio;
    libroInicio = nuevoLibro;

    std::cout << "~ Libro Ingresado Correctamente" << std::endl;
};

/** 
 * Metodo de la clase Libro para imprimir los Libros de forma recursiva por Orden de llegada
 */
void Libro::impresionRecursiva(){
    listaLibros *auxiliar = libroInicio;

    if (!libroInicio) { //Si hay NULL
        return;
    }else {
        impresionRecursiva(auxiliar); 
    }
};

/** Metodo de la clase Libro para imprimir los Libros de forma recursiva por Orden de llegada
 * @param auxiliar Nodo de listaLibros 
 * @overload
 */
void Libro::impresionRecursiva(listaLibros *auxiliar){
    if (auxiliar == NULL) { //Caso Base: Si se encuetra al final: 
        return;
    }else { //Caso Recursivo: Imprimir
        imprimirLibro(auxiliar);
        impresionRecursiva(auxiliar->siguiente);
    }
};

/** 
 * Metodo de la clase Libro para imprimir los Libros de forma recursiva ultimos ingresados primero
 */
void Libro::impresionContraria(void) {
    listaLibros *auxiliar = libroInicio;
    if (!libroInicio) { //Si hay NULL
        return;
    }else {
        impresionContraria(auxiliar);
    }
};

/** Metodo de la clase Libro para imprimir los Libros ordenados ultimos ultimos ingresados primero
 * @param auxiliar Nodo de listaLibros 
 * @overload
 */
void Libro::impresionContraria(listaLibros *auxiliar) {
    if (auxiliar == NULL) {
        return;
    } else {
        impresionContraria(auxiliar->siguiente);
        imprimirLibro(auxiliar);
    }
};

/**
 * Main Function
*/
int main(int argc, char const *argv[])
{
    Libro listLibros;
    std::cout << "\n<< COLECCION DE LIBROS >>"<<"\n";

    int opc = 0;
    do
    {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "\nIngresando . . .\n" << std::endl;
                listLibros.ingresarLibro();
                break;
            case 2:
                std::cout << "\nImprimiendo . . .\n" << std::endl;
                listLibros.impresionRecursiva();
                break;
            case 3:
                std::cout << "\nImprimiendo . . .\n" << std::endl;
                listLibros.impresionContraria();
                break;
            case 4:
                std::cout << "\nSaliendo . . .\n" << std::endl;
                break;
        default:
                std::cout << "\nOpcion Invalida!!!" << std::endl;
        }
    } while (opc!=4);

    std::cout << std::endl;
    return 0;
}


/** Metodo para mostrar el menu
* @return int Opcion que escogio
*/
int menu() {
    int opc = 0;
    std::cout << "\n\t\t\t[~ Menu ~] : " << "\n";
    std::cout << "\t1) Ingresar un libro." << std::endl;
    std::cout << "\t2) Imprimir libros (Orden de llegada)." << std::endl;
    std::cout << "\t3) Imprimir libros (Ultimos ingresados Primeros)." << std::endl;
    std::cout << "\t4) Salir." << std::endl;
    std::cout << "Opcion: "; 
    std::cin >> opc; std::cin.ignore();
    return opc;
};

/** Metodo para imprimir libro 
 * @param[out] libro Nodo de libro Pasado por referencia
*/
void imprimirLibro(listaLibros *libro) { //Paso por referencia de Libro
    std::cout << "-----[Libro]-----" << std::endl;
    std::cout << "ID: " << libro->id << std::endl;
    std::cout << "Nombre: " << libro->nombre << "\n";
    std::cout << "-----------------" << std::endl;
    std::cout << std::endl;
};