#include "NodoBinario.h"


template <class T>
NodoBinario<T>::NodoBinario() {
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

template <class T>
T NodoBinario<T>::obtenerDato() {
	return this->dato;
}

template <class T>
void NodoBinario<T>::fijarDato(T& val) {
	this->dato = val;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
	return this->hijoIzq;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
	return this->hijoDer;
}

template <class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* izq) {
	this->hijoIzq = izq;
}

template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* der) {
	this->hijoDer = der;
}

template <class T>
unsigned int NodoBinario<T>::altura() {
	int altura = 0;
	alturaRecursion(this, 0, altura);
	return altura;
}

template <class T>
void NodoBinario<T>::alturaRecursion(NodoBinario<T>* nodo, unsigned int alturaR, int& alturaFinal) {
	if (nodo->obtenerHijoIzq() != NULL) {
		alturaRecursion(nodo->obtenerHijoIzq(), alturaR + 1, alturaFinal);
	}
	if (nodo->obtenerHijoDer() != NULL) {
		alturaRecursion(nodo->obtenerHijoDer(), alturaR + 1, alturaFinal);
	}
	if(alturaR > alturaFinal) {
		alturaFinal = alturaR;
	}
}

template <class T>
int NodoBinario<T>::obtenerCantidadHijos() {
	if (this->hijoDer == NULL && this->hijoIzq == NULL) {
		return 0;
	}
	if (this->hijoDer != NULL && this->hijoIzq != NULL) {
		return 2;
	}
	return 1;
}


template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerMayor() {
	return obtenerMayorRecursion(this);
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerMayorRecursion(NodoBinario<T>* nodo) {
	if (nodo == NULL) {
		return NULL;
	}
	if (nodo->obtenerHijoDer() == NULL) {
		return nodo;
	}
	else {
		return obtenerMayorRecursion(nodo->obtenerHijoDer());
	}
	return NULL;
}


template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoNoVacio() {
	if (obtenerCantidadHijos() == 1) {
		if (this->hijoIzq != NULL) {
			return this->hijoIzq;
		}
		return this->hijoDer;
	}
	return NULL;
}

template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoInsertar() {
	if (this->hijoIzq == NULL) {
		return this->hijoIzq;
	}
	return this->hijoDer;
}


template <class T>
void NodoBinario<T>::fijarHijoInsertar(NodoBinario<T>* nodo) {
	if (this->hijoIzq == NULL) {
		this->hijoIzq = nodo;
		return;
	}
	this->hijoDer = nodo;
	return;
}

template<class T>
bool NodoBinario<T>::adicionarDesc(T& nval) {
	NodoBinario<T>* temp = new NodoBinario<T>;
	temp->fijarDato(nval);
	if (this->hijoIzq == NULL) {
		this->hijoIzq = temp;
		return true;
	}
	if (this->hijoDer == NULL) {
		this->hijoDer = temp;
		return true;
	}
	return false;
}
