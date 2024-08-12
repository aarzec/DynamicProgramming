#include <iostream>
#include "ListaSimple.h"

void encontrarCombinaciones(int inicio, int fin, int sumaObjetivo, Lista* combs) {
    if (inicio >= fin) {
        return;
    }

    for (int i = inicio; i <= fin; ++i) {
        int complemento = sumaObjetivo - i;
        std::string comb = std::to_string(i) + " + " + std::to_string(complemento) + " = " + std::to_string(sumaObjetivo);
        if (complemento > i && complemento <= fin && !combs->contiene(comb)) {
            std::cout << comb << std::endl;
            combs->agregar(comb);
        }
    }

    encontrarCombinaciones(inicio + 1, fin, sumaObjetivo, combs);
}

int calcularNumeroCombinaciones(int inicio, int fin, int sumaObjetivo) {
    int a = std::max(inicio, sumaObjetivo - fin);
    int b = std::min(sumaObjetivo - inicio, fin);
    return std::max(0, b - a) + 1;
}

int calcularTodasCombinaciones(int inicio, int fin) {
    int n = fin - inicio + 1;
    return n * (n + 1) / 2;
}

int encontrarCombinaciones(int inicio, int fin, int sumaObjetivo) {
    Lista* combs = new Lista();
    encontrarCombinaciones(inicio, fin, sumaObjetivo, combs);
    if (sumaObjetivo % 2 == 0) {
        std::string comb = std::to_string(sumaObjetivo/2) + " + " + std::to_string(sumaObjetivo/2) + " = " + std::to_string(sumaObjetivo);
        if (!combs->contiene(comb)) {
            std::cout << comb << std::endl;
            combs->agregar(comb);
        }
    }
    return combs->longitud();
}

int main() {
    int nMin = 0;
    int nMax = 100;
    int sumaObjetivo = 100;
    std::cout << "N.Combinaciones de sumandos dentro de un rango: " << std::endl;
    std::cout << "-> Números [" << nMin << " - " << nMax << "] que sumen " << sumaObjetivo << ": " << std::endl;
    int nComb = encontrarCombinaciones(nMin, nMax, sumaObjetivo);
    int nPosibles = calcularNumeroCombinaciones(nMin, nMax, sumaObjetivo);
    std::cout << "= " << nComb << " combinaciones únicas de entre " << nPosibles << " totales (" << calcularTodasCombinaciones(nMin, nMax) << " posibles)" << std::endl;

    return 0;
}
