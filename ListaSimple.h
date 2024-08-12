#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

#include <iostream>
#include <stdexcept>
#include "NodoLista.h"

class Lista {
    private:
        NodoLista* cabeza;

    public:
        Lista();
        void agregar(std::string val);
        std::string obtener(int index) const;
        int longitud() const;
        bool contiene(std::string val) const;
        void imprimir() const;
};

#endif