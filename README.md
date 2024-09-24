#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float nota;
    Estudiante* siguiente;
};

class ListaEnlazada {
private:
    Estudiante* cabeza;

public:
    ListaEnlazada() {
        cabeza = nullptr;
    }

    // Función para agregar un estudiante a la lista enlazada
    void agregarEstudiante(string nombre, int codigo, float nota) {
        Estudiante* nuevo = new Estudiante();
        nuevo->nombre = nombre;
        nuevo->codigo = codigo;
        nuevo->nota = nota;
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    // Función para mostrar la lista de estudiantes
    void mostrarEstudiantes() {
        Estudiante* actual = cabeza;
        if (!actual) {
            cout << "La lista está vacía." << endl;
            return;
        }
        while (actual != nullptr) {
            cout << "Nombre: " << actual->nombre << ", Código: " << actual->codigo << ", Nota: " << actual->nota << endl;
            actual = actual->siguiente;
        }
    }

    // Método de burbuja para ordenar la lista de estudiantes por código (menor a mayor)
    void ordenarPorCodigo() {
        if (!cabeza) return;
        bool intercambiado;
        do {
            intercambiado = false;
            Estudiante* actual = cabeza;
            Estudiante* anterior = nullptr;
            while (actual->siguiente != nullptr) {
                if (actual->codigo > actual->siguiente->codigo) {
                    // Intercambiar los nodos
                    Estudiante* temporal = actual->siguiente;
                    actual->siguiente = temporal->siguiente;
                    temporal->siguiente = actual;
                    if (anterior == nullptr) {
                        cabeza = temporal;
                    } else {
                        anterior->siguiente = temporal;
                    }
                    intercambiado = true;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
        } while (intercambiado);
    }

    // Método de burbuja para ordenar la lista de estudiantes por nota (mayor a menor)
    void ordenarPorNota() {
        if (!cabeza) return;
        bool intercambiado;
        do {
            intercambiado = false;
            Estudiante* actual = cabeza;
            Estudiante* anterior = nullptr;
            while (actual->siguiente != nullptr) {
                if (actual->nota < actual->siguiente->nota) {
                    // Intercambiar los nodos
                    Estudiante* temporal = actual->siguiente;
                    actual->siguiente = temporal->siguiente;
                    temporal->siguiente = actual;
                    if (anterior == nullptr) {
                        cabeza = temporal;
                    } else {
                        anterior->siguiente = temporal;
                    }
                    intercambiado = true;
                }
                anterior = actual;
                actual = actual->siguiente;
            }
        } while (intercambiado);
    }

    // Función para encontrar la mayor nota del curso
    void mayorNota() {
        if (!cabeza) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Estudiante* actual = cabeza;
        Estudiante* mejorEstudiante = actual;
        while (actual != nullptr) {
            if (actual->nota > mejorEstudiante->nota) {
                mejorEstudiante = actual;
            }
            actual = actual->siguiente;
        }
        cout << "La mayor nota es: " << mejorEstudiante->nota << " de " << mejorEstudiante->nombre << endl;
    }

    // Función para encontrar la menor nota del curso
    void menorNota() {
        if (!cabeza) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Estudiante* actual = cabeza;
        Estudiante* peorEstudiante = actual;
        while (actual != nullptr) {
            if (actual->nota < peorEstudiante->nota) {
                peorEstudiante = actual;
            }
            actual = actual->siguiente;
        }
        cout << "La menor nota es: " << peorEstudiante->nota << " de " << peorEstudiante->nombre << endl;
    }

    // Función para calcular el promedio de las notas del curso
    void promedioNotas() {
        if (!cabeza) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Estudiante* actual = cabeza;
        float suma = 0;
        int contador = 0;
        while (actual != nullptr) {
            suma += actual->nota;
            contador++;
            actual = actual->siguiente;
        }
        float promedio = suma / contador;
        cout << "El promedio de las notas es: " << promedio << endl;
    }
};

void mostrarMenu() {
    cout << "----- MENÚ -----" << endl;
    cout << "1. Ingresar datos de estudiantes" << endl;
    cout << "2. Ordenar por código" << endl;
    cout << "3. Ordenar por nota" << endl;
    cout << "4. Mostrar la mayor nota" << endl;
    cout << "5. Mostrar la menor nota" << endl;
    cout << "6. Mostrar el promedio de las notas" << endl;
    cout << "7. Mostrar lista de estudiantes" << endl;
    cout << "8. Salir" << endl;
    cout << "----------------" << endl;
}

int main() {
    ListaEnlazada lista;
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                string nombre;
                int codigo;
                float nota;
                cout << "Ingrese el nombre del estudiante: ";
                cin >> nombre;
                cout << "Ingrese el código del estudiante: ";
                cin >> codigo;
                cout << "Ingrese la nota del estudiante: ";
                cin >> nota;
                lista.agregarEstudiante(nombre, codigo, nota);
                break;
            }
            case 2:
                lista.ordenarPorCodigo();
                lista.mostrarEstudiantes();
                break;
            case 3:
                lista.ordenarPorNota();
                lista.mostrarEstudiantes();
                break;
            case 4:
                lista.mayorNota();
                break;
            case 5:
                lista.menorNota();
                break;
            case 6:
                lista.promedioNotas();
                break;
            case 7:
                lista.mostrarEstudiantes();
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}
