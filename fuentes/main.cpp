#include <iostream> // Entrada y salida estándar para interactuar con la consola
#include <cstdlib>
#include "../cabeceras/Grafo.h" // Incluimos la interfaz que armaron los chicos

using namespace std; 

// Funcioncita para frenar el programa y que no se nos cierre la consola de una
void esperarTecla() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(); // Limpia basura del buffer
    cin.get();    // Espera el enter
}

int main() {
    GrafoLogistico sistema; // Instanciamos el motor del grafo
    int opcionPrincipal; 
    
    // -------- BUCLE DEL MENU PRINCIPAL -------------------------
    do {
        // Esto es para que limpie la pantalla (la consola) segun si estas en Windows o Linux
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "\n====== SISTEMA DE GESTION LOGISTICA ======" << endl;
        cout << "1. Ver Red Logistica (Matriz)" << endl;
        cout << "2. Aniadir Corte de Ruta" << endl;
        cout << "3. Calcular Ruta Optima (Simulacion)" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;

        switch(opcionPrincipal) {
            case 1:
                // Muestra la matriz de adyacencia actual (la que tiene los km)
                sistema.imprimirMatriz();
                esperarTecla();
                break;
                
            case 2: {
                int opcionRuta;
                cout << "\n--- MODULO DE CONTINGENCIAS ---" << endl;
                cout << "Cual ruta se corto? (Esto pone INF en la matriz):" << endl;
                cout << "1. La Plata <-> Mar del Plata" << endl;
                cout << "2. Mar del Plata <-> Tandil" << endl;
                cout << "3. Tandil <-> Olavarria" << endl;
                cout << "4. Olavarria <-> Bahia Blanca" << endl;
                cout << "5. Mar del Plata <-> Bahia Blanca" << endl;
                cout << "6. RESET (Volver a la red normal)" << endl;
                cout << "0. Cancelar" << endl;
                cout << "Opcion: ";
                cin >> opcionRuta;

                // Aca mandamos los indices a mano segun el orden de la matriz
                switch(opcionRuta) {
                    case 1: sistema.cortarRutaUnica(0, 1); break;
                    case 2: sistema.cortarRutaUnica(1, 4); break;
                    case 3: sistema.cortarRutaUnica(4, 3); break;
                    case 4: sistema.cortarRutaUnica(3, 2); break;
                    case 5: sistema.cortarRutaUnica(1, 2); break;
                    case 6: sistema.restaurarRutas(); break; 
                    case 0: cout << "No se toco nada." << endl; break;
                    default: cout << "Le erraste a la tecla." << endl;
                }
                
                // Si cambio algo, le mostramos la matriz de nuevo para confirmar el cambio
                if(opcionRuta >= 1 && opcionRuta <= 6) { 
                    sistema.imprimirMatriz(); 
                }
                esperarTecla();
                break;
            }
            
            case 3: {
                int origen, destino;
                cout << "\n--- TESTEO DE RECORRIDOS ---" << endl;
                cout << "1. La Plata\n2. Mar del Plata\n3. Bahia Blanca\n4. Olavarria\n5. Tandil" << endl;
                
                cout << "Desde (1-5): ";
                cin >> origen;
                cout << "Hasta (1-5): ";
                cin >> destino;

                // Ojo: restamos 1 porque el usuario ve 1-5 pero el array es 0-4
                origen--; 
                destino--;

                if (origen == destino) {
                    cout << "Ya estas en el destino, crack." << endl;
                } else if (origen >= 0 && origen <= 4 && destino >= 0 && destino <= 4) {
                    cout << "\nCalculando ruta desde [" << origen << "] hasta [" << destino << "]..." << endl;
                    // TODO: Aca hay que enchufar el algoritmo de Dijkstra cuando lo terminemos
                    cout << "(Simulando busqueda en el grafo...)" << endl;
                } else {
                    cout << "Pusiste cualquier numero, no existe esa ciudad." << endl;
                }
                esperarTecla();
                break;
            }
            
            case 0:
                cout << "Cerrando... Nos vemos!" << endl;
                break;
                
            default:
                cout << "Opcion invalida, proba de nuevo." << endl;
        }
    } while(opcionPrincipal != 0);

    return 0;
}