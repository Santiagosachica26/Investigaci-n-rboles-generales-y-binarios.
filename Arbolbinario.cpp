#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

void preorden(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    cout << raiz->dato << " ";  
    preorden(raiz->izquierda);   
    preorden(raiz->derecha);     
}

void inorden(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    inorden(raiz->izquierda);   
    cout << raiz->dato << " ";  
    inorden(raiz->derecha);     
}

void postorden(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    postorden(raiz->izquierda);  
    postorden(raiz->derecha);   
    cout << raiz->dato << " ";  
}

void liberarArbol(Nodo* raiz) {
    if (raiz == nullptr) return;
    liberarArbol(raiz->izquierda);
    liberarArbol(raiz->derecha);
    delete raiz;
}

int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(20);
    raiz->derecha = new Nodo(30);
    raiz->izquierda->izquierda = new Nodo(40);
    raiz->izquierda->derecha = new Nodo(50);

    cout << "Recorrido Preorden (Raiz - Izq - Der): ";
    preorden(raiz);
    cout << endl;

    cout << "Recorrido Inorden (Izq - Raiz - Der):  ";
    inorden(raiz);
    cout << endl;

    cout << "Recorrido Postorden (Izq - Der - Raiz): ";
    postorden(raiz);
    cout << endl;

    liberarArbol(raiz);

    return 0;
}