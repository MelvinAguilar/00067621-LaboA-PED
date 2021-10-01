/*
 * Programa con funciones vistas en el laboratorio 3 para una pila (push y pop) (top, stackEmpty)
  ~ Melvin Agu!lar*/

#include <iostream>

//Estructura de nodos
struct stackNode {
    int data; //Valores
    stackNode* next; //Nodo Siguiente 
};

/** 
 * Clase pila
 */
class Stack {
    private:
        stackNode *firstNode; //Nodo inicio
    public:
        Stack();
        ~Stack();
        void push(int); //Insertar al inicio
        int pop(); //Elimina el primero y lo retorna
        int stackTop();
        int stackBottom();
        void display();
        bool stackEmpty(); 
};

/** 
 * Metodo Constructor de la clase Stack
 */
Stack::Stack() {
    firstNode = NULL;
};

/** 
 * Metodo Destructor de la clase Queue
 */
Stack::~Stack() {
    while (!stackEmpty()) { //Mientras tenga nodos, sacar nodos
        pop(); 
    }
}

/** 
 * Metodo para crear e insertar un nodo al tope de la pila 
 * @param value Entero con el valor a ingresar al nuevo nodo
 */
void Stack::push(int value) {
    stackNode *node = new stackNode;
    node->data = value;
    node->next = firstNode;
    firstNode = node;
    std::cout << "> Ingresado Correctamente\n";
};

/** 
 * Metodo que elimine el nodo que esta en el tope de pila "LIFO"
 * @return Entero con el valor del nodo eliminado
 */
int Stack::pop() {
    if (!stackEmpty()) {
        int value = firstNode->data;
        stackNode *nodeAux = firstNode;
        
        firstNode = firstNode->next; 
        delete(nodeAux);
        return value;
    }
    return -1; 
};

/** 
 * Metodo que retorna el elemento al inicio (tope) de la pila
 * @return Entero con el valor del nodo del tope de la pila
 */
int Stack::stackTop() {
    if (!stackEmpty()) 
        return firstNode->data;
    return -1; 
};

/** 
 * Metodo que retorna el elemento al fondo de la pila
 * @return Entero con el valor del nodo del fondo de la pila
 */
int Stack::stackBottom() {
    if (!stackEmpty()) {
        stackNode *current = firstNode;
        while (current->next) { //nodeAux->next != NULl
            current = current->next;
        }
        return current->data;
    }
    return -1;
};

/** 
 * Metodo para Imprimir en pantalla el valor de los nodos de la pila
 */
void Stack::display() {
    stackNode *nodeAux = firstNode;
    std::cout << std::endl;
    while (nodeAux) {//Hasta que se termine la lista
        std::cout << "Valor: " << nodeAux->data << std::endl;
        nodeAux = nodeAux->next;
    }  
};

/** 
 * Metodo que verifica si la pila esta vacia
 * @return Booleano con el valor de si esta vacia
 */
bool Stack::stackEmpty() {
    return (firstNode == NULL);
};

//Protoripos de funciones
int menu();

/**
 * Main Function
*/
int main(int argc, char const *argv[]) {
    std::cout << "<< EJERCICIO PILA >>"<<"\n";
    Stack nodeList;
    int opc;
    do {
        int value = 0;
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "> Ingresamdo . . .\n" << std::endl;
                std::cout << "Ingrese un numero: ";
                std::cin >> value;
                nodeList.push(value);
                break;
            case 2:
                std::cout << "> Eliminando . . .\n" << std::endl;
                std::cout << "El numero eliminado es: " << nodeList.pop() << std::endl;
                break;
            case 3:
                std::cout << "> Verificando . . .\n" << std::endl;
                std::cout << "El estado de la cola es : "<< ((nodeList.stackEmpty() == true) ? "Vacio" : "Con Datos") << std::endl;
                break;
            case 4:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                std::cout << "Primer numero de la pila es: " << nodeList.stackTop() << std::endl;
                break;
            case 5:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                std::cout << "Ultimo numero de la pila es: " << nodeList.stackBottom() << std::endl;
                break;
            case 6:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                nodeList.display();
                break;
            case 7:
                std::cout << "\n> Saliendo . . .\n" << std::endl;
                break;
        default:
                std::cout << "\nOpcion Invalida" << std::endl;
        }
    } while (opc!=7);

    return 0;
}

/** 
 * Metodo para mostrar menu y escoger una opc
 * @return Entero con el valor de la opcion
 */
int menu() {
    int opc = 0;
    std::cout << "\n--------[ Menu ]-------" << "\n";
    std::cout << "1) Insertar" << std::endl;
    std::cout << "2) Eliminar" << std::endl;
    std::cout << "3) Verificar si esta vacia" << std::endl;
    std::cout << "4) Imprimir Elemento del tope" << std::endl;
    std::cout << "5) Imprimir Elemento del fondo" << std::endl;
    std::cout << "6) Imprimir Pila" << std::endl;
    std::cout << "7) Salir" << std::endl;
    std::cout << "Opcion: "; 
    std::cin >> opc; std::cin.ignore();
    return opc;
};