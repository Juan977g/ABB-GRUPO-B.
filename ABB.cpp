#include <iostream>
using namespace std;

/*--------------------------------------------------------------
    ESTRUCTURA DEL NODO
    Cada nodo contiene un valor (id) y dos punteros: izq y der.
--------------------------------------------------------------*/
struct Nodo {
    int id;          // Valor que almacena el nodo
    Nodo* izq;       // Puntero al hijo izquierdo
    Nodo* der;       // Puntero al hijo derecho

    // Constructor para inicializar un nodo
    Nodo(int valor) {
        id = valor;
        izq = der = NULL;
    }
};

/*--------------------------------------------------------------
    FUNCIÓN INSERTAR
    Inserta un valor siguiendo las reglas de un BST:
    - Si el árbol está vacío, el nuevo nodo será la raíz.
    - Si el valor es menor, va al subárbol izquierdo.
    - Si es mayor, va al subárbol derecho.
--------------------------------------------------------------*/
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {             // Árbol vacío
        return new Nodo(valor);
    }

    if (valor < raiz->id) {         // Insertar a la izquierda
        raiz->izq = insertar(raiz->izq, valor);
    }
    else if (valor > raiz->id) {    // Insertar a la derecha
        raiz->der = insertar(raiz->der, valor);
    }
    // Si es igual, no se inserta (evita duplicados)

    return raiz;                    // Retorna la raíz sin cambios
}

/*--------------------------------------------------------------
    FUNCIÓN BUSCAR
    Recorre el árbol comparando valores hasta encontrarlo.
--------------------------------------------------------------*/
bool buscar(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return false;               // Valor no encontrado

    if (valor == raiz->id)
        return true;                // Valor encontrado

    if (valor < raiz->id)           // Buscar en el subárbol izquierdo
        return buscar(raiz->izq, valor);
    else                            // Buscar en el subárbol derecho
        return buscar(raiz->der, valor);
}

/*--------------------------------------------------------------
    FUNCIÓN MÍNIMO
    Devuelve el nodo con el valor más pequeño del árbol.
    Es útil para eliminar nodos con dos hijos.
--------------------------------------------------------------*/
Nodo* minimo(Nodo* nodo) {
    while (nodo && nodo->izq != NULL)
        nodo = nodo->izq;
    return nodo;
}

/*--------------------------------------------------------------
    FUNCIÓN ELIMINAR NODO
    Casos:
    1) El nodo no tiene hijos → se elimina.
    2) Tiene un solo hijo → ese hijo reemplaza al nodo.
    3) Tiene dos hijos → se busca el menor del subárbol derecho 
       (sucesor), se copia su valor y se elimina ese sucesor.
--------------------------------------------------------------*/
Nodo* eliminarNodo(Nodo* raiz, int valor) {

    if (raiz == NULL)               // Árbol vacío
        return raiz;

    // Buscar el nodo por la izquierda
    if (valor < raiz->id) {
        raiz->izq = eliminarNodo(raiz->izq, valor);
    }
    // Buscar por la derecha
    else if (valor > raiz->id) {
        raiz->der = eliminarNodo(raiz->der, valor);
    }
    else {
        // Nodo encontrado

        // Caso 1: sin hijo izquierdo
        if (raiz->izq == NULL) {
            Nodo* temp = raiz->der;
            delete raiz;
            return temp;
        }
        // Caso 2: sin hijo derecho
        else if (raiz->der == NULL) {
            Nodo* temp = raiz->izq;
            delete raiz;
            return temp;
        }

        // Caso 3: nodo con dos hijos
        Nodo* temp = minimo(raiz->der);  // Sucesor

        raiz->id = temp->id;             // Reemplaza el valor
        raiz->der = eliminarNodo(raiz->der, temp->id);
    }

    return raiz;                        // Retorna la raíz actualizada
}

/*--------------------------------------------------------------
    RECORRIDO INORDEN (izq - raíz - der)
    Muestra los elementos en **orden ascendente**.
--------------------------------------------------------------*/
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    cout << raiz->id << " ";
    inorden(raiz->der);
}

/*--------------------------------------------------------------
    RECORRIDO PREORDEN (raíz - izq - der)
--------------------------------------------------------------*/
void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->id << " ";
    preorden(raiz->izq);
    preorden(raiz->der);
}

/*--------------------------------------------------------------
    RECORRIDO POSTORDEN (izq - der - raíz)
--------------------------------------------------------------*/
void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    cout << raiz->id << " ";
}

/*--------------------------------------------------------------
    FUNCIÓN PRINCIPAL
    Insertar – Buscar – Eliminar – Mostrar recorridos
--------------------------------------------------------------*/
int main() {
    Nodo* raiz = NULL;

    // Insertar valores en el árbol
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    // Mostrar recorridos
    cout << "\nRecorrido INORDEN: ";
    inorden(raiz);

    cout << "\nRecorrido PREORDEN: ";
    preorden(raiz);

    cout << "\nRecorrido POSTORDEN: ";
    postorden(raiz);

    // Búsqueda
    cout << "\n\nBuscar 40: " 
         << (buscar(raiz, 40) ? "Encontrado" : "No existe");

    // Eliminar un nodo
    raiz = eliminarNodo(raiz, 30);
    cout << "\n\nINORDEN luego de eliminar 30: ";
    inorden(raiz);

    cout << endl;
    return 0;
}