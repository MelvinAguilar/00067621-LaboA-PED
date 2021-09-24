/* 
 * Realizar una lista que permita almacenar los datos de los clientes frecuentes de un
 * negocio de comida rápida. Debe considerar que cada cliente tiene: nombre, apellido,
 * Documento Único de Identidad (DUI), ID de tarjeta de cliente frecuente, y sellos en
 * tarjeta ~ Melvin Agu!lar */

#include <iostream>
#include <string>

//Estructura de tarjeta de cliente frecuente
struct structTarjeta{
    int idTarjeta;
    int cantSellos;
};

//Estructura de Nodos del cliente
struct nodoCliente {
    std::string nombre;
    std::string apellido;
    std::string _DUI;

    structTarjeta tarjeta;
    nodoCliente *siguiente;
};

/**
 * Clase cliente o lista enlazada de cliente
*/
class Cliente {
    private: 
        nodoCliente *cliInicio;

    public:
        Cliente();
        void mostrarCliente(void);
        void ingresarCliente(void);
        void ingresarCliente(std::string, std::string, std::string, int, int);
        void calcularProductos(void);
        void imprimirCliente(nodoCliente *);
        nodoCliente* buscarCliente(std::string);
};

/** 
 * Metodo constructor de clase Cliente
 */
Cliente::Cliente() {
    cliInicio = NULL;
};

/** 
 * Metodo de clase Cliente que ingresa un nombre y lo imprime
*/
void Cliente::mostrarCliente(void) {
    std::string _DUI;
    nodoCliente *cliente;

    std::cout << "Ingresar DUI del cliente: ";
    getline(std::cin, _DUI);

    cliente = buscarCliente(_DUI);

    if (cliente) 
        imprimirCliente(cliente);
};

/** 
 * Metodo de clase Cliente que pide info de cliente y lo mando a su metodo sobrecargado
 */
void Cliente::ingresarCliente(void) {
    std::string nombre, apellido, _DUI;
    int idTarjeta, cantSellos = 0;

    std::cout << "Ingrese Nombre del cliente: ";
    getline(std::cin, nombre);
    std::cout << "Ingrese Apellido del cliente: ";
    getline(std::cin, apellido);
    std::cout << "Ingrese DUI del cliente: ";
    getline(std::cin, _DUI);
    std::cout << "Ingrese ID de tarjeta: ";
    std::cin >> idTarjeta;
    do {
        std::cout << "Ingrese cantidad de sellos: ";
        std::cin >> cantSellos;
        if (cantSellos < 0)
            std::cout << "> Cantidad Invalida\n";
    } while (cantSellos < 0); //Si ingresa negativos
    
    ingresarCliente(nombre, apellido, _DUI, idTarjeta, cantSellos);
};

/** Metodo de clase Cliente que ingresa un Cliente 
 * @param nombre Nombre del cliente a ingresar
 * @param apell Apellido del del cliente a ingresar
 * @param _DUI String con el DUI a buscar
 * @param idTarjeta Entero con ID de tarjeta de cliente frecuente
 * @param cantSellos Entero con cant de sellos para poder canjear productos
 * @overload
*/
void Cliente::ingresarCliente (std::string nombre, std::string apell, std::string _DUI, int idTarjeta, int cantSellos) {
    nodoCliente *nuevoCliente = new nodoCliente; //1.[PASOS] Crear el nodo

    //2.[PASOS] Introducir datos en el nuevo nodo
    nuevoCliente->nombre = nombre;
    nuevoCliente->apellido = apell;
    nuevoCliente->_DUI = _DUI;
    nuevoCliente->tarjeta.idTarjeta = idTarjeta;
    nuevoCliente->tarjeta.cantSellos = cantSellos;

    nuevoCliente->siguiente = cliInicio; //3.[PASOS] Hacer que el nuevo nodo apunte al primer elemento de la lista
    cliInicio = nuevoCliente; //4.[PASOS] Hacer que el ptr cabeza apunte al nuevo nodo creado

    std::cout << "> Cliente Ingresado Correctamente"<< std::endl;
}

/** 
 * Metodo de clase Cliente que imprime los datos de un cliente
*/
void Cliente::calcularProductos(void) {
    std::string _DUI;
    nodoCliente *auxCliente;

    std::cout << "Ingresar DUI del cliente: ";
    std::cin >> _DUI;

    auxCliente = buscarCliente(_DUI);
    if (auxCliente) { //Si cliente existe 
        imprimirCliente(auxCliente);

        int cant, aux = auxCliente->tarjeta.cantSellos;
        for(cant = 0; aux >= 10; cant++, aux-=10); //Restar 10 a los productos hasta que sean < 10
        auxCliente->tarjeta.cantSellos = aux; //Actualizar cant de sellos

        std::cout << "- Productos gratis: " << cant << std::endl;
        std::cout << "- Nuevo total de sellos: " << auxCliente->tarjeta.cantSellos << std::endl;
    }
};

/** Metodo de clase Cliente que imprime los datos de un cliente
* @param cliente Puntero al nodo cliente a imprimir
*/
void Cliente::imprimirCliente(nodoCliente *cliente) {
    std::cout << std::endl;
    std::cout << "Nombre: "<< cliente->nombre << std::endl;
    std::cout << "Apellido: "<< cliente->apellido << std::endl;
    std::cout << "DUI: "<< cliente->_DUI << std::endl;
    std::cout << "ID de tarjeta: "<< cliente->tarjeta.idTarjeta << std::endl;
    std::cout << "Cantidad de sellos: "<< cliente->tarjeta.cantSellos << std::endl;
};

/** Metodo de clase Cliente que busca un cliente en particular
 * @param _DUI String con el DUI a buscar
 * @return nodoCliente Ref al cliente encontrado
*/
nodoCliente* Cliente::buscarCliente(std::string _DUI) {
    nodoCliente *aux;
    aux = cliInicio; //Apunte al inicio

    while (aux!=NULL && (aux->_DUI != _DUI) )  //Hasta que se termine la lista
        aux = aux->siguiente;
    
    if (!aux) {
        std::cout << "> Cliente no encontrado!!" << std::endl;
        return NULL;
    }
   return aux;
};

//Prototipos de funciones
int menu(void); 

/**
 * Main Function
*/
int main(int argc, char const *argv[])
{
    std::cout << "<< CLIENTES FRECUENTES >>"<<"\n";

    Cliente clienteLista; 
    //clienteLista.test();
    int opc;
    do {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "\n> Insertando . . .\n" << std::endl;
                clienteLista.ingresarCliente();
                break;
            case 2:
                std::cout << "\n> Mostrando . . .\n" << std::endl;
                clienteLista.mostrarCliente();
                break;
            case 3:
                std::cout << "\n> Calculando . . .\n" << std::endl;
                clienteLista.calcularProductos();
                break;
            case 4:
                std::cout << "\n> Saliendo . . .\n" << std::endl;
                break;
            default:
                std::cout << "\n> Opcion Invalida" << std::endl;
        }
    } while (opc!=4);

    return 0;
}

/** 
 * Metodo para mostrar menu
*/
int menu(void) {
    int opc = 0;
    std::cout << std::endl;
    std::cout << " -------------[ Menu ]-------------" << "\n";
    std::cout << " 1) Insertar Cliente" << std::endl;
    std::cout << " 2) Mostrar Cliente por DUI" << std::endl;
    std::cout << " 3) Calcular cantidad productos a canjear" << std::endl;
    std::cout << " 4) Salir" << std::endl;
    std::cout << "Opcion: "; 
    std::cin >> opc; std::cin.ignore();
    return opc;
};