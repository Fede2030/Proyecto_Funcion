// Proyecto_Funcion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operaciones.h"

int main() {
    List<char> myList = List<char>();
    myList.PushBack('a');
    myList.PushBack('b');
    myList.PushBack('c');

    myList.Print();

    const int arraySize = 5;
    int myArray[arraySize] = { 1, 2, 5, 7, 9 };

    List<int> myList2 = List<int>(myArray, arraySize);
    myList2.Print();

    myList2.Reverse();
    myList2.Print();

    const int arraySize3 = 8;
    int myArray3[arraySize3] = { 1, 1, 2, 3, 4, 2, 3, 1 };

    List<int> myList3 = List<int>(myArray3, arraySize3);

    std::cout << "Lista original: ";
    myList3.Print();

    myList3.Unique();

    std::cout << "Lista sin duplicados: ";
    myList3.Print();

    return 0;
}


