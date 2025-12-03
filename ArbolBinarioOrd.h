#ifndef __ArbolBinarioOrd_h__
#define __ArbolBinarioOrd_h__
#include "NodoBinario.h"
#include <vector>
#include <list>
#include <string>

template<class T>
class ArbolBinarioOrd {
protected:
	NodoBinario<T>* raiz;
	bool insertarRecursion(NodoBinario<T>* &nodo, T& n);
	bool eliminarRecursion(NodoBinario<T>* &nodo, T& n);
	NodoBinario<T>* obtenerPadreNodoRecursion(NodoBinario<T>* nodo, NodoBinario<T>* hijo);
	bool buscarRecursion(NodoBinario<T>* nodo, T& n);
	void tamanoRecursion(NodoBinario<T>* nodo, int& tam);
	void preOrdenRecursion(NodoBinario<T>* nodo);
	void inOrdenRecursion(NodoBinario<T>* nodo);
	void posOrdenRecursion(NodoBinario<T>* nodo);
	void inOrdenListaRecursion(NodoBinario<T>* nodo, std::list<T>& lista);
	void buscarCaminoOrdenadoRecursion(NodoBinario<T>* nodo, T& n,
		std::string ruta, std::string& rutaFinal);
	void buscarCaminoBinarioRecursion(NodoBinario<T>* nodo, T& n,
		std::string ruta, std::string& rutaFinal);
	bool eliminarBinarioRecursion(NodoBinario<T>*& nodo, T& n); 
public:
	ArbolBinarioOrd();
	bool esVacio();
	T& datoRaiz();
	int altura();
	int tamano();
	void insert(T& val);
	bool insertar(T& val);
	void erase(T& val);
	bool eliminar(T& val);
	NodoBinario<T>* obtenerPadreNodo(NodoBinario<T>* nodo);
	bool buscar(T& val);
	void preOrden();
	void inOrden();
	void posOrden();
	void nivelOrden();
	void inOrdenLista(std::list<T>& lista);
	std::string buscarCaminoOrdenado(T& val);
	std::string buscarCaminoBinario(T& val);
	bool insertarBinario(T& val, T& padre);
	bool insertarBinRecursion(NodoBinario<T>* nodo, T& padre, T& n);
	bool eliminarBinario(T& n);
};
#include "ArbolBinarioOrd.hxx"
#endif