/*
 * "Libreria" que administra una lista doblemente enlazada
 * WARNING: Funciona para tipos planos, para tipos definidos por programador, se puede sobrecargar los operadores
 * ~Melvin Agu!lar - 00067621
*/

#include <iostream>

template <typename T>
struct listNode {
    T data;
    listNode<T>* next; //Siguiente
    listNode<T>* prev; //Anterior

    listNode<T>() {next = prev = NULL;}
    listNode<T>(T dataArg) : data(dataArg) {next = prev = NULL;}
};

/**
 * Clase de lista doblemente enlazada
*/
template <typename T>
class DoublyLinkedList {
    private:
        listNode<T> *front;
        listNode<T> *end;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void printReverse();
        void insertAtEnd(T);
        template <typename U> void insertAfter(U, T);
        template <typename U> listNode<T>* getNode(U); //Retorna un nodo especifico 
        template <typename U> void removeAllOcurrences(U);
        void remove(listNode<T> *);
};

/**
 * Metodo constructor de la Clase DoublyLinkedList
*/
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = end = NULL;
};

/**
 * Metodo destructor de la Clase DoublyLinkedList
*/
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    listNode<T> *n, *current = front;
    while (current) {
        n = current;
        current = current->next;
        delete(n);
    } 
};


/**
 * Metodo de la Clase DoublyLinkedList que imprime la lista de forma inversa
*/
template <typename T>
void DoublyLinkedList<T>::printReverse() {
    listNode<T> *current = end;

    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
};

/**
 * Metodo de la Clase DoublyLinkedList que agrega un nodo al final de la lista
 * @param node Tipo de dato con el objeto a insertar al final de la lista
*/
template <typename T>
void DoublyLinkedList<T>::insertAtEnd(T node) {
    listNode<T> *newNode = new listNode<T>(node);
    if (!end) {
        front = end = newNode;
    } else {                 // 1<->[2]   3
        end->next = newNode; // 1<->[2]-->3
        newNode->prev = end; // 1<->[2]<->3
        end = newNode;       // 1<->2<->[3]
        std::cout << "> Insertado Correctamente\n";
    }
};

/**
 * Metodo de la Clase DoublyLinkedList que agrega un nodo despues de otro en la lista
 * @param pNode Tipo de dato referente al nodo que se busca
 * @param node Tipo de dato con el objeto a insertar despues del nodo buscado
*/
template <typename T>
template <typename U> //Templates separados, Type es el tipo de la clase, y U el tipo a buscar
void DoublyLinkedList<T>::insertAfter(U pNode, T node){
    listNode<T> *prevNode = getNode(pNode);
    if (prevNode) { //Si no esta vacio
        listNode<T> *newNode = new listNode<T>(node);

        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode == end)
            end = newNode;
        else
            prevNode->next->prev = newNode;
        prevNode->next = newNode;
        std::cout << "> Insertado Correctamente\n";
    }
}; 

/**
 * Metodo de la clase DoublyLinkedList que retorna la direccion de memoria de un nodo en especifico
 * @param dataKey Tipo de dato a buscar
 * @return Puntero del nodo buscado
 */
template <typename T>
template <typename U>
listNode<T>* DoublyLinkedList<T>::getNode(U dataKey) {
    listNode<T> *current = front;
    while (current) {
        if (current->data == dataKey) 
            return current;
        current = current->next;
    }
    std::cout << "> Nodo no encontrado!!" << std::endl;
    return NULL; //Underflow
};


/**
 * Metodo de la Clase DoublyLinkedList que elimina todas las ocurrencias de un objeto
 * @param dataKey Tipo de dato de los nodos a eliminar
*/
template <typename T>
template <typename U>
void DoublyLinkedList<T>::removeAllOcurrences(U dataKey){
    if (front == NULL) {
        std::cout << "No hay elementos" << std::endl;
    } else {
        listNode<T> *current = front;
        listNode<T> *aux;

        while (current) {
            aux = current->next;
            if (current->data == dataKey)
                remove(current);
            current = aux;
        }
    }
};

/**
 * Metodo de la Clase DoublyLinkedList que elimina un nodo
 * @param dataKey Puntero al tipo de dato a eliminar
*/
template <typename T>
void DoublyLinkedList<T>::remove(listNode<T> *dataKey){
    if (!dataKey) {
        return;
    }

    if (front == end) { //Solamente es un nodo o lista nula
        front = end = NULL;
    } else if (front == dataKey) { //Se encuentra al inicio
        front = dataKey->next;
    } else if (end == dataKey) { //Se encuentra al final
        end = dataKey->prev;
    }
    
    if (dataKey->prev) { //No esta al inicio
        dataKey->prev->next = dataKey->next;
    }
    if (dataKey->next) { //No esta al final
        dataKey->next->prev = dataKey->prev;
    }

    delete(dataKey);
    std::cout << "> Eliminado Correctamente\n";
};