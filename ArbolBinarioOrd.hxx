#include "ArbolBinarioOrd.h"
#include <queue>

template <class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd() {
	this->raiz = NULL;
}

template <class T>
bool ArbolBinarioOrd<T>::esVacio() {
	if (!this->raiz) {
		return true;
	}
	return false;
}

template <class T>
T& ArbolBinarioOrd<T>::datoRaiz() {
	return this->raiz->obtenerDato();
}

template <class T>
int ArbolBinarioOrd<T>::altura() {
	if (this->esVacio()) {
		return -1;
	}
	return this->raiz->altura();
}

template <class T>
int ArbolBinarioOrd<T>::tamano() {
	if (this->esVacio()) {
		return 0;
	}
	int tam = 1;
	tamanoRecursion(this->raiz, tam);
	return tam;
}


template<class T>
void ArbolBinarioOrd<T>::tamanoRecursion(NodoBinario<T>* nodo, int& tam) {
	if (nodo->obtenerHijoIzq() != NULL) {
		tam++;
		tamanoRecursion(nodo->obtenerHijoIzq(), tam);
	}
	if (nodo->obtenerHijoDer() != NULL) {
		tam++;
		tamanoRecursion(nodo->obtenerHijoDer(), tam);
	}
}

template <class T>
void ArbolBinarioOrd<T>::insert(T& val) {
	if (insertar(val)) {
		return;
	}
}

template <class T>
bool ArbolBinarioOrd<T>::insertar(T& val) {
	return insertarRecursion(this->raiz, val);
}

template <class T>
bool ArbolBinarioOrd<T>::insertarRecursion(NodoBinario<T>*& nodo, T& n) {
	if (nodo == NULL) {
		nodo = new NodoBinario<T>;
		nodo->fijarDato(n);
		return true;
	}
	if (nodo->obtenerDato() < n) {
		NodoBinario<T>* hijoDer = nodo->obtenerHijoDer();
		if(insertarRecursion(hijoDer, n)) {
			nodo->fijarHijoDer(hijoDer);
			return true;
		}
	}
	else if (nodo->obtenerDato() > n) {
		NodoBinario<T>* hijoIzq = nodo->obtenerHijoIzq();
		if(insertarRecursion(hijoIzq, n)){
			nodo->fijarHijoIzq(hijoIzq);
			return true;
		}
	}
	return false;
}

template <class T>
void ArbolBinarioOrd<T>::erase(T& val) {
	if (eliminar(val)) {
		return;
	}
}

template <class T>
bool ArbolBinarioOrd<T>::eliminar(T& val) {
	if (this->esVacio()) {
		return false;
	}
	return eliminarRecursion(this->raiz, val);
}

template <class T>
bool ArbolBinarioOrd<T>::eliminarRecursion(NodoBinario<T>* &nodo, T& n) {
	if (nodo == NULL) {
		return false;
	}
	if (nodo->obtenerDato() == n) {
		if (nodo->obtenerCantidadHijos() == 0) {
			delete nodo;
			nodo = NULL;
		}
		else if (nodo->obtenerCantidadHijos() == 1) {
			nodo = nodo->obtenerHijoNoVacio();
		}
		else {
			NodoBinario<T>* izqMay = nodo->obtenerHijoIzq()->obtenerMayor();
			izqMay->fijarHijoDer(nodo->obtenerHijoDer());
			izqMay->fijarHijoIzq(nodo->obtenerHijoIzq());
			nodo = izqMay;
			if (obtenerPadreNodo(izqMay)->obtenerDato() != nodo->obtenerDato()) {
				obtenerPadreNodo(izqMay)->fijarHijoDer(NULL);
			}
		}
		return true;
	}
	if (nodo->obtenerDato() < n) {
		NodoBinario<T>* hijoDer = nodo->obtenerHijoDer();
		if (eliminarRecursion(hijoDer, n)) {
			nodo->fijarHijoDer(hijoDer);
			return true;
		}
	}
	else if (nodo->obtenerDato() > n) {
		NodoBinario<T>* hijoIzq = nodo->obtenerHijoIzq();
		if (eliminarRecursion(hijoIzq, n)) {
			nodo->fijarHijoIzq(hijoIzq);
			return true;
		}
	}
	return false;
}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::obtenerPadreNodo(NodoBinario<T>* nodo) {
	if (nodo == NULL) {
		return NULL;
	}
	return obtenerPadreNodoRecursion(this->raiz, nodo);
}

template <class T>
NodoBinario<T>* ArbolBinarioOrd<T>::obtenerPadreNodoRecursion(NodoBinario<T>* nodo, NodoBinario<T>* hijo) {
	if (nodo == NULL) {
		return NULL;
	}
	if (nodo->obtenerDato() > hijo->obtenerDato() && nodo->obtenerHijoIzq() != NULL) {
		if (nodo->obtenerHijoIzq()->obtenerDato() == hijo->obtenerDato()) {
			return nodo;
		}
		return obtenerPadreNodoRecursion(nodo->obtenerHijoIzq(),hijo);
	}
	else if (nodo->obtenerDato() < hijo->obtenerDato() && nodo->obtenerHijoDer() != NULL) {
		if (nodo->obtenerHijoDer()->obtenerDato() == hijo->obtenerDato()) {
			return nodo;
		}
		return obtenerPadreNodoRecursion(nodo->obtenerHijoDer(),hijo);
	}
	return NULL;
}

template <class T>
bool ArbolBinarioOrd<T>::buscar(T& val) {
	if (this->esVacio()) {
		return false;
	}
	return buscarRecursion(this->raiz, val);
}

template <class T>
bool ArbolBinarioOrd<T>::buscarRecursion(NodoBinario<T>* nodo, T& n) {
	if (nodo == NULL) {
		return false;
	}
	if (nodo->obtenerDato() == n) {
		return true;
	}
	if (nodo->obtenerDato() < n) {
		return buscarRecursion(nodo->obtenerHijoDer(), n);
	}
	else {
		return buscarRecursion(nodo->obtenerHijoIzq(), n);
	}
	return false;
}

template <class T>
std::string ArbolBinarioOrd<T>::buscarCaminoOrdenado(T& val) {
	if (this->raiz == NULL) {
		return	"";
	}
	std::string ruta = "";
	buscarCaminoOrdenadoRecursion(this->raiz, val, "", ruta);
	return ruta;
}

template <class T>
void ArbolBinarioOrd<T>::buscarCaminoOrdenadoRecursion(NodoBinario<T>* nodo, T& n,
	std::string ruta, std::string &rutaFinal) {
	if (nodo == NULL) {
		return;
	}
	if (nodo->obtenerDato() == n) {
		rutaFinal = ruta;
		return;
	}
	if (nodo->obtenerDato() < n) {
		std::string rutaIzq = ruta + "Der";
		buscarCaminoOrdenadoRecursion(nodo->obtenerHijoDer(), n, rutaIzq, rutaFinal);
	}
	else {
		std::string rutaIzq = ruta + "Izq";
		buscarCaminoOrdenadoRecursion(nodo->obtenerHijoIzq(), n, rutaIzq, rutaFinal);
	}
}

template <class T>
std::string ArbolBinarioOrd<T>::buscarCaminoBinario(T& val) {
	if (this->raiz == NULL) {
		return	"";
	}
	std::string ruta = "";
	buscarCaminoBinarioRecursion(this->raiz, val, "", ruta);
	return ruta;
}

template <class T>
void ArbolBinarioOrd<T>::buscarCaminoBinarioRecursion(NodoBinario<T>* nodo, T& n,
	std::string ruta, std::string& rutaFinal) {
	if (nodo == NULL) {
		return;
	}
	if (nodo->obtenerDato() == n) {
		rutaFinal = ruta;
		return;
	}
	std::string rutaDer = ruta + "Der";
	buscarCaminoBinarioRecursion(nodo->obtenerHijoDer(), n, rutaDer, rutaFinal);
	std::string rutaIzq = ruta + "Izq";
	buscarCaminoBinarioRecursion(nodo->obtenerHijoIzq(), n, rutaIzq, rutaFinal);
}


template <class T>
bool ArbolBinarioOrd<T>::insertarBinario(T& val, T& padre) {
	if (this->raiz == NULL) {
		this->raiz = new NodoBinario<T>;
		this->raiz->fijarDato(val);
		return true;
	}
	if (this->buscar(val)) { //Ver si esta repetido
		return false;
	}
	return insertarBinRecursion(this->raiz, padre, val);
}

template<class T>
bool ArbolBinarioOrd<T>::insertarBinRecursion(NodoBinario<T>* nodo, T& padre, T& n) {
	if (nodo == NULL) {
		return false;
	}
	if (nodo->obtenerDato() == padre) {
		return nodo->adicionarDesc(n);
	}
	if (insertarBinRecursion(nodo->obtenerHijoIzq(), padre, n)) {
		return true;
	}
	if (insertarBinRecursion(nodo->obtenerHijoDer(), padre, n)) {
		return true;
	}
}

template<class T>
bool ArbolBinarioOrd<T>::eliminarBinario(T& n) {
	return eliminarBinarioRecursion(this->raiz, n);
}

template<class T>
bool ArbolBinarioOrd<T>::eliminarBinarioRecursion(NodoBinario<T>*& nodo, T& n) {
	if (nodo == NULL) {
		return false;
	}
	if (n == nodo->obtenerDato()) {
		nodo = NULL;
		delete nodo;
		return true;
	}
	NodoBinario<T>* hijoIzq = nodo->obtenerHijoIzq();
	if (eliminarBinarioRecursion(hijoIzq, n)) {
		nodo->fijarHijoIzq(hijoIzq);
		return true;
	}
	NodoBinario<T>* hijoDer = nodo->obtenerHijoDer();
	if (eliminarBinarioRecursion(hijoDer,n)) {
		nodo->fijarHijoDer(hijoDer);
		return true;
	}
}

template <class T>
void ArbolBinarioOrd<T>::preOrden() {
	if (!this->esVacio()) {
		preOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolBinarioOrd<T>::preOrdenRecursion(NodoBinario<T>* nodo) {
	if (nodo != NULL) {
		std::cout << nodo->obtenerDato() << " ";
		preOrdenRecursion(nodo->obtenerHijoIzq());
		preOrdenRecursion(nodo->obtenerHijoDer());
	}
}

template <class T>
void ArbolBinarioOrd<T>::inOrden() {
	if (!this->esVacio()) {
		inOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolBinarioOrd<T>::inOrdenRecursion(NodoBinario<T>* nodo) {
	if (nodo != NULL) {
		inOrdenRecursion(nodo->obtenerHijoIzq());
		std::cout << nodo->obtenerDato() << " ";
		inOrdenRecursion(nodo->obtenerHijoDer());
	}
}

template <class T>
void ArbolBinarioOrd<T>::posOrden() {
	if (!this->esVacio()) {
		posOrdenRecursion(this->raiz);
	}
}

template <class T>
void ArbolBinarioOrd<T>::posOrdenRecursion(NodoBinario<T>* nodo) {
	if (nodo != NULL) {
		posOrdenRecursion(nodo->obtenerHijoIzq());
		posOrdenRecursion(nodo->obtenerHijoDer());
		std::cout << nodo->obtenerDato() << " ";
	}
}

template <class T>
void ArbolBinarioOrd<T>::nivelOrden() {
	if (!this->esVacio()) {
		std::queue<NodoBinario<T>*> cola;
		cola.push(this->raiz);
		NodoBinario<T>* nodo;
		while (!cola.empty()) {
			nodo = cola.front();
			cola.pop();
			std::cout << nodo->obtenerDato() << " ";
			if (nodo->obtenerHijoIzq() != NULL)
				cola.push(nodo->obtenerHijoIzq());
			if (nodo->obtenerHijoDer() != NULL)
				cola.push(nodo->obtenerHijoDer());
		}
	}
}

template <class T>
void ArbolBinarioOrd<T>::inOrdenLista(std::list<T>& lista) {
	if (!this->esVacio()) {
		inOrdenListaRecursion(this->raiz, lista);
	}
}

template <class T>
void ArbolBinarioOrd<T>::inOrdenListaRecursion(NodoBinario<T>* nodo, std::list<T>& lista) {
	if (nodo != NULL) {
		inOrdenListaRecursion(nodo->obtenerHijoIzq(),lista);
		lista.push_back(nodo->obtenerDato());
		inOrdenListaRecursion(nodo->obtenerHijoDer(),lista);
	}
}