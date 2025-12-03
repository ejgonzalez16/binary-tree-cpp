#include <iostream>
#include "ArbolBinarioOrd.h"
#include "NodoBinario.h"

using namespace std;

void insertarNodo(ArbolBinarioOrd<int>& arbolBinario);
void eliminarNodo(ArbolBinarioOrd<int>& arbolBinario);
void insertarNodoBinario(ArbolBinarioOrd<int>& arbolBinario);
void eliminarNodoBinario(ArbolBinarioOrd<int>& arbolBinario);

int main() {
    int opc;
    ArbolBinarioOrd<int> arbolBinario;
    do {
        cout << "Digite:\n1. insertar nodo\n2. eliminar nodo\n3. insertar nodo binario\n4. eliminar nodo binario\n5. salir";
        cin >> opc;
        switch (opc) {
        case 1: insertarNodo(arbolBinario); break;
        case 2: eliminarNodo(arbolBinario); break;
        case 3: insertarNodoBinario(arbolBinario); break;
        case 4: eliminarNodoBinario(arbolBinario); break;
        }
        system("pause");
        system("cls");
    } while (opc != 5);
}

void insertarNodo(ArbolBinarioOrd<int>& arbolBinario) {
    int numero;
    if (arbolBinario.esVacio()) {
        cout << "Digite la raiz del arbol: ";
        cin >> numero;
    }
    else {
        cout << "Digite el numero a insertar: ";
        cin >> numero;
    }
    if (arbolBinario.insertar(numero)) {
        cout << "\nSe inserto el nodo\n";
    }
    else {
        cout << "\nNo se inserto el nodo\n";
    }
    cout << "Tamano: " << arbolBinario.tamano() << endl;
    cout << "\nPre-orden: ";
    arbolBinario.preOrden();
    cout << "\nIn-orden: ";
    arbolBinario.inOrden();
    cout << "\nPos-Orden: ";
    arbolBinario.posOrden();
    cout << "\nPor niveles: ";
    arbolBinario.nivelOrden();
    if (arbolBinario.buscar(numero)) {
        cout << "\nSe encontro el nodo\n";
    }
    else {
        cout << "\nNo se encontro el nodo\n";
    }
    cout << "Altura: " << arbolBinario.altura() << endl;
    cout << "Digite la ruta a buscar: ";
    cin >> numero;
    cout << "ruta: " << arbolBinario.buscarCaminoOrdenado(numero) << endl;
}

void eliminarNodo(ArbolBinarioOrd<int>& arbolBinario) {
    int numero;
    cout << "Digite el numero a eliminar: ";
    cin >> numero;
    if (arbolBinario.eliminar(numero)) {
        cout << "\nSe elimino el nodo\n";
    }
    else {
        cout << "\nNo se elimino el nodo\n";
    }
    cout << "Tamano: " << arbolBinario.tamano() << endl;
    cout << "\nPre-orden: ";
    arbolBinario.preOrden();
    cout << "\nIn-orden: ";
    arbolBinario.inOrden();
    cout << "\nPos-Orden: ";
    arbolBinario.posOrden();
    cout << "\nPor niveles: ";
    arbolBinario.nivelOrden();
    if (arbolBinario.buscar(numero)) {
        cout << "\nSe encontro el nodo\n";
    }
    else {
        cout << "\nNo se encontro el nodo\n";
    }
    cout << "Altura: " << arbolBinario.altura() << endl;
}

void insertarNodoBinario(ArbolBinarioOrd<int>& arbolBinario) {
    int numero, padre;
    if (arbolBinario.esVacio()) {
        cout << "Digite la raiz del arbol: ";
        cin >> numero;
    }
    else {
        cout << "Digite el numero a insertar: ";
        cin >> numero;
        cout << "Digite el padre del numero a insertar: ";
        cin >> padre;
    }
    if (arbolBinario.insertarBinario(numero, padre)) {
        cout << "\nSe inserto el nodo\n";
    }
    else {
        cout << "\nNo se inserto el nodo\n";
    }
    cout << "Tamano: " << arbolBinario.tamano() << endl;
    cout << "\nPre-orden: ";
    arbolBinario.preOrden();
    cout << "\nIn-orden: ";
    arbolBinario.inOrden();
    cout << "\nPos-Orden: ";
    arbolBinario.posOrden();
    cout << "\nPor niveles: ";
    arbolBinario.nivelOrden();
    if (arbolBinario.buscar(numero)) {
        cout << "\nSe encontro el nodo\n";
    }
    else {
        cout << "\nNo se encontro el nodo\n";
    }
    cout << "Altura: " << arbolBinario.altura() << endl;
    cout << "Digite la ruta a buscar: ";
    cin >> numero;
    cout << "ruta: " << arbolBinario.buscarCaminoBinario(numero) << endl;
}

void eliminarNodoBinario(ArbolBinarioOrd<int>& arbolBinario) {
    int numero;
    cout << "Digite el numero a eliminar: ";
    cin >> numero;
    if (arbolBinario.eliminarBinario(numero)) {
        cout << "\nSe elimino el nodo\n";
    }
    else {
        cout << "\nNo se elimino el nodo\n";
    }
    cout << "Tamano: " << arbolBinario.tamano() << endl;
    cout << "\nPre-orden: ";
    arbolBinario.preOrden();
    cout << "\nIn-orden: ";
    arbolBinario.inOrden();
    cout << "\nPos-Orden: ";
    arbolBinario.posOrden();
    cout << "\nPor niveles: ";
    arbolBinario.nivelOrden();
    if (arbolBinario.buscar(numero)) {
        cout << "\nSe encontro el nodo\n";
    }
    else {
        cout << "\nNo se encontro el nodo\n";
    }
    cout << "Altura: " << arbolBinario.altura() << endl;
}