#ifndef NODO_LISTA_H
#define NODO_LISTA_H

class NodoLista {
    public:
        std::string valor;
        NodoLista* siguiente;

        NodoLista(std::string val) : valor(val), siguiente(nullptr) {}
};

#endif