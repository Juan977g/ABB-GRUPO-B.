#include <iostream>
using namespace std;

/*--------------------------------------------------------------
    DEFINICIÓN DEL NODO DEL ÁRBOL BINARIO DE BÚSQUEDA (BST)
--------------------------------------------------------------*/
struct Nodo {
    int id;
    Nodo* izq;
    Nodo* der;

    Nodo(int valor) {
        id = valor;
        izq = der = NULL;
    }
};

/*--------------------------------------------------------------
    FUNCIÓN INSERTAR
--------------------------------------------------------------*/
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return new Nodo(valor);

    if (valor < raiz->id)
        raiz->izq = insertar(raiz->izq, valor);
    else if (valor > raiz->id)
        raiz->der = insertar(raiz->der, valor);

    return raiz;
}

/*--------------------------------------------------------------
    FUNCIÓN BUSCAR
--------------------------------------------------------------*/
bool buscar(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return false;

    if (valor == raiz->id)
        return true;

    if (valor < raiz->id)
        return buscar(raiz->izq, valor);
    else
        return buscar(raiz->der, valor);
}

/*--------------------------------------------------------------
    FUNCIÓN PARA ENCONTRAR EL MÍNIMO
--------------------------------------------------------------*/
Nodo* minimo(Nodo* nodo) {
    while (nodo && nodo->izq != NULL)
        nodo = nodo->izq;
    return nodo;
}

/*--------------------------------------------------------------
    FUNCIÓN ELIMINAR NODO
--------------------------------------------------------------*/
Nodo* eliminarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->id)
        raiz->izq = eliminarNodo(raiz->izq, valor);
    else if (valor > raiz->id)
        raiz->der = eliminarNodo(raiz->der, valor);
    else {
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

        // Caso 3: dos hijos
        Nodo* temp = minimo(raiz->der);
        raiz->id = temp->id;
        raiz->der = eliminarNodo(raiz->der, temp->id);
    }

    return raiz;
}

/*--------------------------------------------------------------
    RECORRIDOS DEL ÁRBOL
--------------------------------------------------------------*/
void inorden(Nodo* raiz) {
    if (raiz == NULL) return;
    inorden(raiz->izq);
    cout << raiz->id << " ";
    inorden(raiz->der);
}

void preorden(Nodo* raiz) {
    if (raiz == NULL) return;
    cout << raiz->id << " ";
    preorden(raiz->izq);
    preorden(raiz->der);
}

void postorden(Nodo* raiz) {
    if (raiz == NULL) return;
    postorden(raiz->izq);
    postorden(raiz->der);
    cout << raiz->id << " ";
}

/*--------------------------------------------------------------
    MENÚ INTERACTIVO
--------------------------------------------------------------*/
void mostrarMenu() {
    cout << "\n=======================";
    cout << "\n   MENU DEL ARBOL BST  ";
    cout << "\n=======================";
    cout << "\n1. Insertar nodo";
    cout << "\n2. Buscar nodo";
    cout << "\n3. Eliminar nodo";
    cout << "\n4. Mostrar recorrido INORDEN";
    cout << "\n5. Mostrar recorrido PREORDEN";
    cout << "\n6. Mostrar recorrido POSTORDEN";
    cout << "\n7. Salir";
    cout << "\n=======================";
    cout << "\nIngrese una opcion: ";
}

/*--------------------------------------------------------------
    PROGRAMA PRINCIPAL
--------------------------------------------------------------*/
int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            cin >> valor;
            raiz = insertar(raiz, valor);
            cout << "Nodo insertado.\n";
            break;

        case 2:
            cout << "Ingrese el valor a buscar: ";
            cin >> valor;
            cout << (buscar(raiz, valor) ? "Valor encontrado.\n" : "No existe en el árbol.\n");
            break;

        case 3:
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;
            raiz = eliminarNodo(raiz, valor);
            cout << "Nodo eliminado (si existía).\n";
            break;

        case 4:
            cout << "INORDEN: ";
            inorden(raiz);
            cout << "\n";
            break;

        case 5:
            cout << "PREORDEN: ";
            preorden(raiz);
            cout << "\n";
            break;

        case 6:
            cout << "POSTORDEN: ";
            postorden(raiz);
            cout << "\n";
            break;

        case 7:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción no válida. Intente nuevamente.\n";
        }

    } while (opcion != 7);

    return 0;
}
