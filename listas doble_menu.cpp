#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class ListaEnlazadaDoble {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaEnlazadaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    // Función para insertar un elemento al final de la lista
    void insertarAlFinal(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        } else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    // Función para imprimir la lista en orden desde la cabeza
    void imprimirDesdeCabeza() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Función para buscar un elemento en la lista
    bool buscar(int valor) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Función para eliminar un elemento de la lista
    bool eliminar(int valor) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                if (actual == cabeza) {
                    cabeza = actual->siguiente;
                    if (cabeza) {
                        cabeza->anterior = nullptr;
                    }
                } else if (actual == cola) {
                    cola = actual->anterior;
                    cola->siguiente = nullptr;
                } else {
                    actual->anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = actual->anterior;
                }
                delete actual;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Función para actualizar un elemento de la lista
    bool actualizar(int valor, int nuevoValor) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                actual->dato = nuevoValor;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }
};

int main() {
    ListaEnlazadaDoble lista;

    char opcion;
    do {
        std::cout << "Menú:" << std::endl;
        std::cout << "1. Insertar elemento" << std::endl;
        std::cout << "2. Mostrar elementos" << std::endl;
        std::cout << "3. Buscar elemento" << std::endl;
        std::cout << "4. Eliminar elemento" << std::endl;
        std::cout << "5. Actualizar elemento" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese su opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1': // Insertar elemento
                int nuevoElemento;
                std::cout << "Ingrese el nuevo elemento: ";
                std::cin >> nuevoElemento;
                lista.insertarAlFinal(nuevoElemento);
                break;

            case '2': // Mostrar elementos
                std::cout << "Elementos: ";
                lista.imprimirDesdeCabeza();
                break;

            case '3': // Buscar elemento
                int elementoABuscar;
                std::cout << "Ingrese el elemento a buscar: ";
                std::cin >> elementoABuscar;
                if (lista.buscar(elementoABuscar)) {
                    std::cout << "Elemento encontrado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '4': // Eliminar elemento
                int elementoAEliminar;
                std::cout << "Ingrese el elemento a eliminar: ";
                std::cin >> elementoAEliminar;
                if (lista.eliminar(elementoAEliminar)) {
                    std::cout << "Elemento eliminado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '5': // Actualizar elemento
                int valorAActualizar, nuevoValor;
                std::cout << "Ingrese el valor a actualizar: ";
                std::cin >> valorAActualizar;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevoValor;
                if (lista.actualizar(valorAActualizar, nuevoValor)) {
                    std::cout << "Elemento actualizado." << std::endl;
                } else {
                    std::cout << "Elemento no encontrado." << std::endl;
                }
                break;

            case '6': // Salir
                std::cout << "Saliendo del programa." << std::endl;
                break;

            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != '6');

    return 0;
}