/**
 * "Libreria" que administra las operaciones con un arbol binario de busqueda BST (Binary Search Tree)
*/
#pragma once
#include <iostream>

/** 
 * Clase Nodo del arbol
 */
template <typename T>
class BSTnode {
    public:
        BSTnode<T>() 
            : left(NULL), right(NULL) {};
        BSTnode<T>(T dataA) 
            : data(dataA), left(NULL), right(NULL) {};
            
    private:
        T data;
        BSTnode<T> *left;
        BSTnode<T> *right;

        template <typename> friend class BST; //BST puede acceder a miembros privados de esta clase
        /*Si se desea actualizar, se ulitizan getters y setters, incluso para los hijos*/
        //T getInfo() { return data; }; //Obtener dato de un nodo
        //void setInfo(T d) { data = d; }; //Establecer dato del nodo
};

template <typename T>
class BST {
    public:
        using Node = BSTnode<T>;
        using NodePointer = Node*;

    private:
        NodePointer root;

    public:
        BST();

        void insert(T);
        BSTnode<T>* insert(NodePointer, T);
        
        void preOrder() const;
        void preOrder(NodePointer) const;

        void inOrder() const;
        void inOrder(NodePointer) const;

        void postOrder() const;
        void postOrder(NodePointer) const;
};

/** 
 * Metodo constructor del arbol
 */
template <typename T>
BST<T>::BST() {
    root = NULL;
}

/** 
 * Metodo para insertar una llave al arbol, verifica y envia a la sobrecarga la raiz privada de la clase
 */
template <typename T>
void BST<T>::insert(T data) {
    if (!root) //Si la raiz esta null, lo establezco
        root = new Node(data);
    else
        insert(root, data);
}

/**
 * Metodo para insertar una llave al arbol
 * @return Puntero al nodo insertado, se utiliza para evitar punteros dobles
*/
template <typename T> 
BSTnode<T>* BST<T>::insert(NodePointer tree, T data) {
    //typename BST<T>::NodePointer *BST<T>::insert(NodePointer tree, T data) { //Si uso de retorno "NodePointer"
    if (!tree)
        tree = new Node(data);
    else
        if (data < tree->data) //Si es menor, lo inserto en su hijo izq
            tree->left = insert(tree->left, data);
        else
            if (data > tree->data) //Si es mayor, lo inserto en su hijo der
                tree->right = insert(tree->right, data);
            else //Ya existe esa llave
                std::cout << "La llave ya esta en el arbol" << std::endl;
    return tree;
};

/** 
 * Metodo para mostrar todos las llaves en InOrder, envia a la sobrecarga la raiz privada de la clase
 */
template <typename T>
void BST<T>::inOrder() const {
    inOrder(root);
};

/** 
 * Metodo para mostrar todos las llaves en InOrder de manera recursiva
 */
template <typename T>
void BST<T>::inOrder(NodePointer tree) const {
    if (tree) {
        inOrder(tree->left);
        std::cout << tree->data << "  ";
        inOrder(tree->right);
    }
};

/** 
 * Metodo para mostrar todos las llaves en PreOrder, envia a la sobrecarga la raiz privada de la clase
 */
template <typename T>
void BST<T>::preOrder() const {
    preOrder(root);
};

/** 
 * Metodo para mostrar todos las llaves en PreOrder de manera recursiva
 */
template <typename T>
void BST<T>::preOrder(NodePointer tree) const {
    if (tree) {
        std::cout << tree->data << "  ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
};

/** 
 * Metodo para mostrar todos las llaves en PostOrden, envia a la sobrecarga la raiz privada de la clase 
 */
template <typename T>
void BST<T>::postOrder() const {
    postOrder(root);
};

/** 
 * Metodo para mostrar todos las llaves en PostOrden de manera recursiva
 */
template <typename T>
void BST<T>::postOrder(NodePointer tree) const {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout << tree->data << "  ";
    }
};