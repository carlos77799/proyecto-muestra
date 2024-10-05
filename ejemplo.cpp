#include <iostream>
#include <malloc.h>

using namespace std;

struct pasajero {
    char nombre[50];
    int documento;
    int destino; // 1: La Bocana, 2: Piangüita, 3: Ladrilleros
    pasajero *sig;
};

pasajero *cab = NULL, *aux;

// Función para registrar un nuevo pasajero
void registrar() {
    aux = (pasajero *) malloc(sizeof(pasajero));
    cout << "Nombre del pasajero: ";
    cin >> aux->nombre;
    cout << "Número de documento: ";
    cin >> aux->documento;
    cout << "Destino (1: La Bocana, 2: Piangüita, 3: Ladrilleros): ";
    cin >> aux->destino;

    // Validar destino
    while (aux->destino < 1 || aux->destino > 3) {
        cout << "Destino inválido. Ingrese nuevamente (1-3): ";
        cin >> aux->destino;
    }

    aux->sig = NULL;

    if (!cab) {
        cab = aux; // Primer pasajero
    } else {
        pasajero *temp = cab;
        while (temp->sig != NULL) {
            temp = temp->sig; // Navegar hasta el final de la lista
        }
        temp->sig = aux; // Añadir nuevo pasajero
    }
}

// Función para mostrar todos los pasajeros
void mostrar() {
    if (cab == NULL) {
        cout << "No hay pasajeros registrados." << endl;
        return;
    }

    aux = cab;
    while (aux != NULL) {
        cout << "Nombre: " << aux->nombre 
             << ", Documento: " << aux->documento 
             << ", Destino: " << aux->destino << endl;
        aux = aux->sig;
    }
}

// Función para ordenar los pasajeros
void ordenar() {
    if (!cab) return; // Si la lista está vacía

    bool intercambiado;
    do {
        intercambiado = false;
        pasajero *current = cab;

        while (current->sig != NULL) {
            if (current->destino > current->sig->destino || 
               (current->destino == current->sig->destino && current->documento > current->sig->documento)) {
                // Intercambiar los datos de los nodos
                pasajero temp = *current;
                *current = *current->sig;
                *current->sig = temp;
                intercambiado = true;
            }
            current = current->sig;
        }
    } while (intercambiado);
}

// Función para liberar la memoria utilizada
void liberarMemoria() {
    while (cab != NULL) {
        aux = cab;
        cab = cab->sig;
        free(aux);
    }
}

int main() {
    int opcion;
    do {
        cout << "Menu" << endl;
        cout << "1. Registrar Pasajero" << endl;
        cout << "2. Mostrar Pasajeros" << endl;
        cout << "3. Ordenar Pasajeros" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                ordenar();
                cout << "Pasajeros ordenados:" << endl;
                mostrar(); // Mostrar después de ordenar
                break;
        }
    } while (opcion != 4);

    liberarMemoria(); // Liberar memoria al salir
    return 0;
}
