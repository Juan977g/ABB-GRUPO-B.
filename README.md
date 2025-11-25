# Árbol Binario de Búsqueda (BST) – Implementación en C++

Este archivo contiene la documentación completa del proyecto de implementación de un Árbol Binario de Búsqueda (Binary Search Tree — BST) en C++.

## 📘 Descripción General

Este proyecto implementa un **Árbol Binario de Búsqueda (BST)** permitiendo realizar operaciones como:
- Inserción de nodos
- Búsqueda de elementos
- Eliminación de nodos
- Recorridos: Inorden, Preorden y Postorden
- Menú interactivo para ejecutar las funciones

---

## 🌲 Estructura del Nodo

Cada nodo contiene:
- Un valor entero (id)
- Un puntero al hijo izquierdo
- Un puntero al hijo derecho

---

## ➕ Lógica de Inserción

1. Si el árbol está vacío → crear la raíz.  
2. Si el valor es menor al nodo → insertar a la izquierda.  
3. Si el valor es mayor → insertar a la derecha.  
4. Si el valor es igual → no se inserta (no hay duplicados).

---

## 🔍 Lógica de Búsqueda

La búsqueda compara el valor con el nodo actual:
- Si es NULL → no existe.
- Si coincide → encontrado.
- Si es menor → buscar a la izquierda.
- Si es mayor → buscar a la derecha.

---

## ❌ Lógica de Eliminación

Tres casos posibles:

### 1️⃣ Nodo sin hijos  
Se elimina directamente.

### 2️⃣ Nodo con un hijo  
El hijo ocupa el lugar del nodo eliminado.

### 3️⃣ Nodo con dos hijos  
Se reemplaza por el **sucesor inorden**:
- Mínimo del subárbol derecho.
- Sustituye al nodo.
- Se elimina el sucesor.

---

## 🔄 Recorridos

### Inorden  
Izquierda → Nodo → Derecha  
Presenta los valores en orden ascendente.

### Preorden  
Nodo → Izquierda → Derecha

### Postorden  
Izquierda → Derecha → Nodo

---

## 🖥️ Menú Interactivo

Opciones disponibles:
1. Insertar nodo  
2. Buscar nodo  
3. Eliminar nodo  
4. Mostrar recorrido Inorden  
5. Mostrar recorrido Preorden  
6. Mostrar recorrido Postorden  
7. Salir  

---

## 📸 Capturas de Pantalla

Agregar capturas en carpeta `/img` si las usas en tu repositorio.

---

## 📌 Conclusiones

El proyecto demuestra:
- La eficiencia del BST en operaciones de búsqueda.
- La utilidad de la recursividad.
- La estructura jerárquica como base para organizar datos.

---

## 📝 Autor

Proyecto desarrollado como parte de las prácticas de estructura de datos.
