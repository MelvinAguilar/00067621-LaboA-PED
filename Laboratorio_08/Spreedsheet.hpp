/**
 * "Libreria" que administra las operaciones basicas de una hoja electronica
  ~ Melvin Agu!lar*/

#pragma once
#include <iostream>

/** 
 * Estructura Nodo
 */
template <typename T>
class SS_Node {
    public:
        SS_Node<T>() : nextRow(NULL), nextCol(NULL) {};
        SS_Node<T>(T d, size_t nRow, size_t nCol) 
            : data(d), m_row(nRow), m_col(nCol) {
                nextRow = nextCol = NULL;
            };
        SS_Node<T>(T d, SS_Node<T>* nextR, SS_Node<T>* nextC, size_t nRow, size_t nCol)
            : data(d), nextRow(nextR), nextCol(nextC), m_row(nRow), m_col(nCol) {};
    private:
        T data;
        size_t m_col, m_row;
        SS_Node<T> *nextRow, *nextCol;
        template <typename> friend class Spreedsheet;
};

/** 
 * Clase Spreedsheet
 */
template <typename T>
class Spreedsheet {
    public:
        using Node = SS_Node<T>;
        using NodePointer = Node*;
    private:
        size_t totRows;
        size_t totCols;
        NodePointer pBase;
    public:
        Spreedsheet(size_t, size_t);
        void insert(size_t, size_t, T);
        void deleteNode(size_t, size_t);
        void print();
        T sumOfColum(size_t);
};

/** 
 * Metodo Constructor de la clase Spreedsheet
 * @param totColumns Entero cantidad de calumnas de la hoja
 * @param totRows Entero cantidad de calumnas de la hoja
 */
template <typename T>
Spreedsheet<T>::Spreedsheet(size_t totColumns, size_t totRows) {
    this->totCols = totColumns;
    this->totRows = totRows;
    NodePointer newNode, prev;
    
    pBase = new Node({}, pBase, pBase, 0, 0);

    //Rellenar la primera fila
    prev = pBase;
    for (size_t i = 1; i <= totRows; i++) {
        newNode = new Node({}, i, 0);
        newNode->nextCol = newNode;
        prev->nextRow = newNode;
        prev = prev->nextRow;
    }
    newNode->nextRow = pBase;

    //Rellenar la primera columnna
    prev = pBase;
    for (size_t i = 1; i <= totColumns; i++) {
        newNode = new Node({}, 0, i);
        newNode->nextRow = newNode;
        prev->nextCol = newNode;
        prev = prev->nextCol;
    }
    newNode->nextCol = pBase;
};

/** 
 * Metodo de la clase Spreedsheet que imprime toda la hoja electronica
 */
template <typename T>
void Spreedsheet<T>::print() {
    std::cout << "[Columna,Fila]->Dato"<< std::endl;
    NodePointer curr = pBase;
    int i;
    do {
        i = 0;
        do {
            if(i!=curr->m_col) {
                std::cout << "\t\t";
            } else {
                std::cout << "[" << curr->m_col << "," << curr->m_row << "]->" << curr->data << '\t'; //
                curr = curr->nextCol;
            }
            i++;
        } while (curr->m_col != 0);
        std::cout << std::endl;
        curr = curr->nextRow;
    } while (curr->m_row != 0);
};

/** 
 * Metodo de la clase Spreedsheet que inserta datos en la hoja
 * @param col Entero con la calumna de la hoja
 * @param row Entero con la fila de la hoja
 * @param data Dato a insertar en la hoja
 */
template <typename T>
void Spreedsheet<T>::insert(size_t col, size_t row, T data) {
    if (row < 1 || row > totRows || col < 1 || col > totCols ) {
        std::cout << "Ubicacion invalida" << std::endl;
        return;
    }
    NodePointer pRow = pBase;
    NodePointer pCol = pBase;
    
    size_t i;
    for (i = 1; i <= row; i++)
        pRow = pRow->nextRow;
    while ( (pRow->nextCol->m_col < col) && (pRow->nextCol->m_col != 0) ) 
        pRow = pRow->nextCol;

    for (i = 1; i <= col; i++)
        pCol = pCol->nextCol;
    while ( (pCol->nextRow->m_row < row) && (pCol->nextRow->m_row != 0) ) 
        pCol = pCol->nextRow;

    //Si exite actualizo
    if (pRow->nextCol->m_col == col) { // && pRow->nextCol->m_col == col
        pRow->nextCol->data = data;
        std::cout << "> Actualizado correctamente" << std::endl;
    } else {
        NodePointer newNode = new Node(data, row, col);
        newNode->nextCol = pRow->nextCol;
        pRow->nextCol = newNode;

        newNode->nextRow = pCol->nextRow;
        pCol->nextRow = newNode;
        std::cout << "> Ingresado correctamente" << std::endl;
    }
};

/** 
 * Metodo de la clase Spreedsheet que elimina un dato en la hoja
 * @param col Entero con la calumna de la hoja
 * @param row Entero con la fila de la hoja
 */
template <typename T>
void Spreedsheet<T>::deleteNode(size_t col, size_t row) {
    if (row < 1 || row > totRows || col < 1 || col > totCols ) {
        std::cout << "Ubicacion invalida" << std::endl;
        return;
    }
    NodePointer pDelete = NULL;
    NodePointer pRow = pBase;
    NodePointer pCol = pBase;
    
    size_t i;
    for (i = 1; i <= row; i++)
        pRow = pRow->nextRow;
    while ( (pRow->nextCol->m_col < col) && (pRow->nextCol->m_col != 0) ) 
        pRow = pRow->nextCol;

    for (i = 1; i <= col; i++)
        pCol = pCol->nextCol;
    while ( (pCol->nextRow->m_row < row) && (pCol->nextRow->m_row != 0) ) 
        pCol = pCol->nextRow;

    //Si exite actualizo
    if (pRow->nextCol->m_col == col) { // && pRow->nextCol->m_col == col
        pDelete = pRow->nextCol;
        pCol->nextRow = pCol->nextRow->nextRow;
        pRow->nextCol = pRow->nextCol->nextCol;
        delete(pDelete);
    } else {
        std::cout << "Nodo no existente" << std::endl;
    }
};

/** 
 * Metodo de la clase Spreedsheet que elimina un dato en la hoja
 * @param keyCol Entero con la calumna de la hoja
 * @return Dato con la suma de los valores de la columna
 * @warning Suma de datos Templates
 */
template <typename T>
T Spreedsheet<T>::sumOfColum(size_t keyCol) {
    if (keyCol < 1 || keyCol > totCols ) {
        std::cout << "Ubicacion invalida" << std::endl;
        return 0;
    }
    T sum = {};
    NodePointer pCol = pBase;
    size_t i;

    for (i = 1; i <= keyCol; i++)
        pCol = pCol->nextCol;
    pCol = pCol->nextRow; //Me salto la fila principal

    while (pCol->m_row != 0){
        sum += pCol->data;
        pCol = pCol->nextRow;
    };  
    return sum;
};