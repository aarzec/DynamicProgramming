#include <iostream>
#include <stdexcept>
#include "ListaSimple.h"
#include "NodoLista.h"

Lista::Lista() : cabeza(nullptr) {}

void Lista::agregar(std::string val) {
    NodoLista* nuevoNodo = new NodoLista(val);
    if (!cabeza) {
        cabeza = nuevoNodo;
    } else {
        NodoLista* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

std::string Lista::obtener(int index) const {
    NodoLista* temp = cabeza;
    int count = 0;
    while (temp) {
        if (count == index) {
            return temp->valor;
        }
        temp = temp->siguiente;
        count++;
    }
    throw std::out_of_range("Índice fuera de rango");
}

bool Lista::contiene(std::string val) const {
    NodoLista* temp = cabeza;
    while (temp) {
        if (temp->valor == val) {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
}

int Lista::longitud() const {
    int count = 0;
    NodoLista* temp = cabeza;
    while (temp) {
        count++;
        temp = temp->siguiente;
    }
    return count;
}

void Lista::imprimir() const {
    NodoLista* temp = cabeza;
    while (temp) {
        std::cout << temp->valor << " ";
        temp = temp->siguiente;
    }
    std::cout << std::endl;
}
