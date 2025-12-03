# Binary Search Tree (BST) Implementation in C++

This project contains a custom implementation of a **Binary Search Tree (BST)** written in C++ from scratch.  
It uses raw pointers, recursive algorithms, and manual memory management to provide ordered insertion, deletion, search, and traversal operations.

The tree supports additional utilities such as computing node paths, obtaining ordered lists, and handling special insertion modes.

---

## 🚀 Features

### ✔ Fully Custom BST (No STL Tree Structures)
Built entirely with:
- Raw pointers (`NodoBinario<T>*`)
- Manual memory management
- Recursive insertion and deletion
- Template-based generic type support

### ✔ Ordered Insertion & Deletion
Implements BST rules:
- Left child < parent  
- Right child > parent  

Supports:
- Recursive insertion (`insertar`, `insert`)
- Node deletion with 0, 1, or 2 children
- Alternative binary insertion mode (`insertarBinario`)

### ✔ Search Operations
- Standard search by value (`buscar`)
- Retrieve parent node (`obtenerPadreNodo`)

### ✔ Tree Traversals
Supports classic recursive traversals:
- **Pre-order**
- **In-order**
- **Post-order**
- **Level-order**

### ✔ Utility Functions
The structure includes additional helper methods:

- `altura()` – height of the tree  
- `tamano()` – number of nodes  
- `inOrdenLista()` – fill a list with sorted elements  
- `buscarCaminoOrdenado()` – path to a node using BST rules  
- `buscarCaminoBinario()` – path using binary numbering (0/1 decisions)  

These are useful for debugging, visualization, and verifying tree correctness.

---
