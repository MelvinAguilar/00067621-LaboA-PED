/*
 * Programa con funciones vistas en el laboratorio 3 para una cola (enqueue y dequeue) (isEmpty, isFull)
  ~ Melvin Agu!lar*/

#include <iostream>

//Estructura de nodos
struct queueNode {
    int data; //Valores
    queueNode* next; //Nodo Siguiente 
};

/** 
 * Clase cola
 */
class Queue {
    private:
        queueNode *frontN; //Primer Nodo
        queueNode *backN; //Ultimo nodo
    public:
        Queue();
        ~Queue();
        int back();
        int front();
        void enqueue(int); //Insertar al inicio
        int dequeue(); //Elimina el ULTIMO y lo retorna
        bool isFull();
        bool isEmpty();
        void display();
};

/** 
 * Metodo Constructor de la clase Queue
 */
Queue::Queue() {
    frontN = backN = NULL;
};

/** 
 * Metodo Destructor de la clase Queue
 */
Queue::~Queue() {
    while (isFull()) { //Mientras tenga nodos, sacar nodos
        dequeue(); 
    }
}

/** 
 * Metodo que retorna el ultimo elemento de la cola
 * @return Entero con el valor del ultimo nodo de la cola
 */
int Queue::back() {
    if (isFull()) 
        return backN->data;
    return -1;
};

/** 
 * Metodo que retorna el elemento cabeza de la cola
 * @return Entero con el valor del nodo cabeza de la cola
 */
int Queue::front() {
    if (isFull()) 
        return frontN->data;
    return -1;
};

/** 
 * Metodo para encolar un nodo en una cola
 * @param value Entero con el valor a ingresar al nuevo nodo
 */
void Queue::enqueue(int value){
    queueNode *node = new queueNode;
    node->data = value;
    node->next = NULL;
    
    if(isEmpty()) { //Si esta vacia
        frontN = backN = node; //1->NULL
    } else {
        backN->next = node; //1*->2->NULL
        backN = node; //1 - 2*->NULL   O   rearN = rearN->next;
    }
    std::cout << "> Ingresado Correctamente\n";
};

/** 
 * Metodo que desencola(elimine) el nodo que esta al final de la cola "FIFO"
 * @return Entero con el valor del nodo eliminado
 */
int Queue::dequeue() {
    queueNode *nodeAux = frontN;

    if (isFull()) {
        frontN = nodeAux->next;
        int value = nodeAux->data;
        delete(nodeAux);
        return value;
    }
    return -1; 
};

/** 
 * Metodo que verifica si la Cola contiene elementos
 * @return Booleano con el valor de si el inicio no esta vacia
 */
bool Queue::isFull(){
    return (frontN != NULL);
}; 

/** 
 * Metodo que verifica si la Cola esta vacia
 * @return Booleano con el valor de si esta vacia
 */
bool Queue::isEmpty(){
    return (frontN == NULL);
};

/** 
 * Metodo para Imprimir en pantalla el valor de los nodos de la cola
 */
void Queue::display(){
    queueNode *nodeAux = frontN;
    std::cout << std::endl;
    while(nodeAux) {
        std::cout << "Valor: " << nodeAux->data << std::endl;
        nodeAux = nodeAux->next;
    }
};

//Prototipo de funcion
int menu();

/**
 * Main Function
*/
int main(int argc, char const *argv[]) {
    std::cout << "<< EJERCICIO COLA >>"<<"\n";

    Queue cola;
    int opc;
    do
    {
        int value = 0;
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "\n> Ingresamdo . . .\n" << std::endl;
                std::cout << "Ingrese un numero: ";
                std::cin >> value;
                cola.enqueue(value);
                break;
            case 2:
                std::cout << "\n> Eliminando . . .\n" << std::endl;
                std::cout << "El numero eliminado es: " << cola.dequeue() << std::endl;
                break;
            case 3:
                std::cout << "\n> Verificando . . .\n" << std::endl;
                std::cout << "El estado de la Cola es : "<< ((cola.isEmpty() == true) ? "Vacio" : "Con Datos") << std::endl;
                break;
            case 4:
                std::cout << "\n> Imprimiendo . . .\n" << std::endl;
                std::cout << "Primer numero de la Cola  es: " << cola.front() << std::endl;
                break;
            case 5:
                std::cout << "\n> Imprimiendo . . .\n" << std::endl;
                std::cout << "Ultimo numero de la Cola es: " << cola.back() << std::endl;
                break;
            case 6:
                std::cout << "\n> Imprimiendo . . .\n" << std::endl;
                cola.display();
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
    std::cout << "4) Imprimir Primer Elemento" << std::endl;
    std::cout << "5) Imprimir Ultimo Elemento" << std::endl;
    std::cout << "6) Imprimir Cola" << std::endl;
    std::cout << "7) Salir" << std::endl;
    std::cout << "Opcion: "; 
    std::cin >> opc; std::cin.ignore();
    return opc;
    
};