#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    string nombre;
    int codigo;
    float nota;
    Estudiante* siguiente;
};

// Función para agregar un estudiante a la lista enlazada
void agregarEstudiante(Estudiante*& cabeza, string nombre, int codigo, float nota) {
    Estudiante* nuevo = new Estudiante();
    nuevo->nombre = nombre;
    nuevo->codigo = codigo;
    nuevo->nota = nota;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// Función para mostrar la lista de estudiantes
void mostrarEstudiantes(Estudiante* cabeza) {
    if (!cabeza) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* actual = cabeza;
    while (actual != Null) {
        cout << "Nombre: " << actual->nombre << ", Código: " << actual->codigo << ", Nota: " << actual->nota << endl;
        actual = actual->siguiente;
    }
}

// Método de burbuja para ordenar la lista de estudiantes por código
void ordenarPorCodigo(Estudiante*& cabeza) {
    if (!cabeza) return;
    bool intercambiado;
    do {
        intercambiado = false;
        Estudiante* actual = cabeza;
        Estudiante* anterior = Null;

        while (actual->siguiente != Null) {
            if (actual->codigo > actual->siguiente->codigo) {
                Estudiante* temporal = actual->siguiente;
                actual->siguiente = temporal->siguiente;
                temporal->siguiente = actual;

                if (anterior == Null) {
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

// Método de burbuja para ordenar la lista de estudiantes por nota
void ordenarPorNota(Estudiante*& cabeza) {
    if (!cabeza) return;
    bool intercambiado;
    do {
        intercambiado = false;
        Estudiante* actual = cabeza;
        Estudiante* anterior = Null;

        while (actual->siguiente != Null) {
            if (actual->nota < actual->siguiente->nota) {
                Estudiante* temporal = actual->siguiente;
                actual->siguiente = temporal->siguiente;
                temporal->siguiente = actual;

                if (anterior == Null) {
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
void mayorNota(Estudiante* cabeza) {
    if (!cabeza) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* actual = cabeza;
    Estudiante* mejorEstudiante = actual;
    while (actual != Null) {
        if (actual->nota > mejorEstudiante->nota) {
            mejorEstudiante = actual;
        }
        actual = actual->siguiente;
    }
    cout << "La mayor nota es: " << mejorEstudiante->nota << " de " << mejorEstudiante->nombre << endl;
}

// Función para encontrar la menor nota del curso
void menorNota(Estudiante* cabeza) {
    if (!cabeza) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* actual = cabeza;
    Estudiante* peorEstudiante = actual;
    while (actual != Null) {
        if (actual->nota < peorEstudiante->nota) {
            peorEstudiante = actual;
        }
        actual = actual->siguiente;
    }
    cout << "La menor nota es: " << peorEstudiante->nota << " de " << peorEstudiante->nombre << endl;
}

// Función para calcular el promedio de las notas del curso
void promedioNotas(Estudiante* cabeza) {
    if (!cabeza) {
        cout << "La lista está vacía." << endl;
        return;
    }
    Estudiante* actual = cabeza;
    float suma = 0;
    int contador = 0;
    while (actual != Null) {
        suma += actual->nota;
        contador++;
        actual = actual->siguiente;
    }
    float promedio = suma / contador;
    cout << "El promedio de las notas es: " << promedio << endl;
}

// Función para liberar la memoria de la lista
void liberarLista(Estudiante*& cabeza) {
    while (cabeza != Null) {
        Estudiante* siguiente = cabeza->siguiente;
        delete cabeza;
        cabeza = siguiente;
    }
}

// Función para mostrar el menú
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
    Estudiante* lista = Null; // Inicializar la lista
    int opcion;
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        switch (opcion) {
            case 1: {
                string nombre;
                int codigo;
                float nota;
                cout << "Ingrese el nombre del estudiante: ";
                getline(cin, nombre);
                cout << "Ingrese el código del estudiante: ";
                cin >> codigo;
                cout << "Ingrese la nota del estudiante: ";
                cin >> nota;
                agregarEstudiante(lista, nombre, codigo, nota);
                break;
            }
            case 2:
                ordenarPorCodigo(lista);
                mostrarEstudiantes(lista);
                break;
            case 3:
                ordenarPorNota(lista);
                mostrarEstudiantes(lista);
                break;
            case 4:
                mayorNota(lista);
                break;
            case 5:
                menorNota(lista);
                break;
            case 6:
                promedioNotas(lista);
                break;
            case 7:
                mostrarEstudiantes(lista);
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                liberarLista(lista); // Liberar memoria antes de salir
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } while (opcion != 8);
    return 0;
}
       
   
      
          
