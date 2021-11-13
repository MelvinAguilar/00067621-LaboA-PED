/**
 * Desarrollar el ejercicio #8 de la guía de hoja de cálculo electrónica, 
 * el cual consiste en realizar la suma de los valores de una columna determinada
 * ~ Melvin Agu!lar - 00067621
*/

#include "Spreedsheet.hpp"

int menu();

/**
 * Main Function
*/
int main() {
    int opc, nCol, nRow, iCol, iRow, data;
    std::cout << "<< Hoja de calculo electonica >>\n" << std::endl;
    std::cout << "Ingrese cantidad de Columnas: "; std::cin >> nCol;
    std::cout << "Ingrese cantidad de Filas: "; std::cin >> nRow;
    Spreedsheet<int> sheet(nCol, nRow);
    
    do {
        opc = menu();
        switch (opc) {
            case 1:
                std::cout << "> Ingresando . . .\n" << std::endl;
                std::cout << "Finalice introduciendo ceros:" << std::endl;
                do {
                   std::cout << "Columna: "; std::cin >> iCol;
                   std::cout << "Fila: "; std::cin >> iRow;
                   std::cout << "Entero a almacenar: "; std::cin >> data;
                   sheet.insert(iCol, iRow, data);
                   std::cout << std::endl;
                } while (iCol!=0 && iRow!=0);
                break;
            case 2:
                std::cout << "> Imprimiendo . . .\n" << std::endl;
                sheet.print();
                break;
            case 3:
                std::cout << "> Calculando . . .\n" << std::endl;
                std::cout << "Columna a sumar: "; std::cin >> iCol;
                std::cout << "La suma total es: "<< sheet.sumOfColum(iCol) << std::endl;
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
    std::cout << "1) Ingresar Datos a la hoja." << std::endl;
    std::cout << "2) Imprimir." << std::endl;
    std::cout << "3) Sumar datos de una columna." << std::endl;
    std::cout << "4) Salir." << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opc; std::cin.ignore();
    return opc;
};