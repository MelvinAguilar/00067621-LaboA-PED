/*
 * "Libreria" que administra las operaciones basicas de una lista circular simplemente enlazada
 * ~ Melvin Agu!lar - 00067621
*/

#pragma once
#include <iostream>

/** 
 * Clase Nodo, miembros privados para evitar que modifiquen un nodo desde main
 */
template <typename T>
class CLL_Node {
    public:
        CLL_Node<T>() : next(NULL) {};
        CLL_Node<T>(T dataArg) : data(dataArg), next(NULL) {};
        CLL_Node<T>(T dataArg, CLL_Node<T>* nextArg) 
            : data(dataArg), next(nextArg) {};
    private:
        T data;
        CLL_Node<T>* next;
        template <typename> friend class CircularLL; //CircularLL puede acceder a miembros privados
        template <typename> friend class CLL_Iterator; //CLL_Iterator puede acceder a miembros privados
};

/**
 * Clase Iterador, Sirve como un puntero a los nodos, pueden acceder a los miembros privados del nodo desde main, 
 * pero con la seguridad que no se pueden modificar los punteros, solo se puede hacer lo que las sobrecargas de operadores hacen.
 * Usa como template la clase CLL.
*/
template <typename CircularLL>
class CLL_Iterator {
    //Seccion publica de Alias-declaration with 'using'
    public:
        using ValueType = typename CircularLL::ValueType; //Tendra el mismo Tipo de dato que la lista Cicular (T)
        using ValueReference = ValueType&;                //Referencia del dato de un nodo (T&) [Si quiere actualizar el dato de un nodo]

        using Node = typename CircularLL::Node;           //Tendra el mismo Nodo que la lista Circular (CLL_Node<T>)
        using NodePointer = Node*;                        //Puntero al Nodo (CLL_Node<T>*)

    //Seccion publica de funciones
    public:
        CLL_Iterator() : currNode(NULL) {};
        CLL_Iterator(NodePointer ptr) : currNode(ptr) {};
        
        /** 
         * Sobrecarga de operadores
         */
        //Operador Prefijo de incremento. Ej: ++Node;
        CLL_Iterator& operator++() {
            if (currNode)
                currNode = currNode->next;
            return *this;
        }

        //Operador Postfijo. Ej: Node++;
        CLL_Iterator operator++(int) { //Este operador primero "retorna" y luego avanza, como en un entero i++ 
            CLL_Iterator temp = *this; //Creo una copia
            ++(*this); //Llamada del operador prefijo
            return temp;
        }

        //Operador de desreferencia
        ValueType operator*() {
            if (currNode)
                return currNode->data;
            return {};
        }

        //Operador de igualdad
        bool operator==(const CLL_Iterator& iterator) {
            return (currNode == iterator.currNode);
        }

        //Operador de desigualdad
        bool operator!=(const CLL_Iterator& iterator) {
            return (currNode != iterator.currNode);
        }
    private:
        NodePointer currNode; //CLL_Node<T> *currNode;
};

/** 
 * Clase circular simplemente enlazada
 */
template <typename T>
class CircularLL {
    public:
        using ValueType =   T;
        using Node =        CLL_Node<T>;
        using NodePointer = Node*;
        using Iterator =    CLL_Iterator< CircularLL<T> >; //Creo un Iterador con esta clase como template
    private:
        size_t m_size;
        NodePointer pStart;
        NodePointer pLast;
    public:
        CircularLL();
        void insertAtEnd(T);
        template <typename U> void deleteNode(U);
        void print();
        size_t size();   

        Iterator begin() { return Iterator(pStart); };
        Iterator end() { return Iterator(pLast); };
};

/** 
 * Metodo Constructor de la clase CircularLL
 */
template <typename T>
CircularLL<T>::CircularLL() {
    pStart = pLast = NULL;
    m_size = 0;
};

/** 
 * Metodo para insertar un nodo en una lista circular
 * @param newNode Tipo de dato del nodo 
 */
template <typename T>
void CircularLL<T>::insertAtEnd(T newData) {// (1)->[2]->(1)        //Lista Original
    NodePointer newNode = new Node(newData);
    if (!pStart)                         
        pStart = newNode;                // (3)                   (pStart)
    else                                 // (1)->[2]->(1)  3      //Lista Actual
        pLast->next = newNode;           // (1)->[2]-> 3          (pStart)[end]
    pLast = newNode;                     // (1)-> 2 ->[3]         (pStart)[end]
    pLast->next = pStart;                // (1)-> 2 ->[3]->(1)    (pStart)[end]
    m_size++;
};

/** 
 * Metodo para eliminar un nodo de una CLL
 * @param datakey Tipo de dato del nodo a eliminar
 */
template <typename T>
template <typename U>
void CircularLL<T>::deleteNode(U datakey) {
    NodePointer aux = pStart;
    NodePointer delN;
    //Si esta vacia
    if (!pStart) {
        std::cout << "> No hay elementos en la lista circular" << std::endl;
        return;
    }

    //Si es el unico nodo
    if ( (aux->next == pStart) && (aux->data == datakey) ) { 
        pStart = pLast = NULL; //Pongo a null todo
        delete(aux); //Elimino el unico
        m_size--;
        return;
    } 
    
    //Si es el primer nodo
    if ( (aux == pStart) && (aux->data == datakey) ) { 
        pStart = pStart->next; //Avanzo el primero
        pLast->next = pStart;  //El ultimo apuntara al NUEVO primer nodo
        delete(aux);
        m_size--;
    } else {
        //Mientras no de una vuelta y el sig. sea el primero
        while (aux->next != pStart) {
            if (aux->next->data == datakey) //Si el sig. es el buscado
                break;
            aux = aux->next;
        }

        //Si llego hasta el ultimo y no se encontro
        if (aux == pLast) {
            std::cout << "> Valor no Encontrado" << std::endl;
            return;
        }
        //Si es el ultimo nodo el que eliminare
        if (aux->next == pLast) 
            pLast = aux; //Para no perder referencia del ultimo

        delN = aux->next;
        aux->next = aux->next->next;
        delete(delN);
        m_size--;
    }
};


/** 
 * Metodo para Imprimir en pantalla el valor de los nodos de la cola
 */
template <typename T>
void CircularLL<T>::print(void){
    NodePointer curr = pStart;
    if (pStart) {
        do {
            std::cout << curr->data << std::endl;
            curr = curr->next;
        } while (curr != pStart); 
    }
};

/** 
 * Metodo que retorna el tamanio de la lista
 * @return Tamanio de la lista circular
 */
template <typename T>
size_t CircularLL<T>::size(){
    return m_size;
};