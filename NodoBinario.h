#ifndef NodoBinario_h
#define NodoBinario_h

#include <vector>

template<class T>
class NodoBinario {
protected:
	T dato;
	NodoBinario<T>* hijoIzq;
	NodoBinario<T>* hijoDer;
	void alturaRecursion(NodoBinario<T>* nodo, unsigned int alturaR, int& alturaFinal);
	//void alturaRecursion(NodoBinario<T>* nodo, unsigned int altura, std::vector<unsigned int>& alturas);
	NodoBinario<T>* obtenerMayorRecursion(NodoBinario<T>* nodo);
public:
	NodoBinario();
	T obtenerDato();
	void fijarDato(T& val);
	NodoBinario<T>* obtenerHijoIzq();
	NodoBinario<T>* obtenerHijoDer();
	void fijarHijoIzq(NodoBinario<T>* izq);
	void fijarHijoDer(NodoBinario<T>* der);
	unsigned int altura();
	int obtenerCantidadHijos();
	NodoBinario<T>* obtenerMayor();
	NodoBinario<T>* obtenerHijoNoVacio();
	NodoBinario<T>* obtenerHijoInsertar();
	void fijarHijoInsertar(NodoBinario<T>* nodo);
	bool adicionarDesc(T& nval);
};
#include "NodoBinario.hxx"
#endif