#include <iostream>
#include <cmath>
using namespace std;

struct PuntoTrayectoria
{
    int identificador;
    string nombre;
    // X,Y,Z
    int coordenadas[3];
    float distanciaOrigen;
    string clasificacion;
};


void registrarPunto(PuntoTrayectoria &punto)
{
    cout << "Cual es el identificar del punto? :" << endl;
    cin >> punto.identificador;

    cout << "Cual es el nombre del punto? :" << endl;
    cin >> punto.nombre;

    cout << "Cual es la coordenada X del punto? :" << endl;
    cin >> punto.coordenadas[0];

    cout << "Cual es la coordenada Y del punto? :" << endl;
    cin >> punto.coordenadas[1];

    cout << "Cual es la coordenada Z del punto? :" << endl;
    cin >> punto.coordenadas[2];
    cout << endl;
}

int main()
{
    int cantidad;
    PuntoTrayectoria puntos[10];
    do
    {
        cout << "Cuantos puntos desea registrar del 1 al 10?: " << endl;
        cin >> cantidad;
        if (cantidad < 1 || cantidad > 10)
        {
            system("cls");
            cout << "Cantidad invalida, escriba una cantidad correcta" << endl;
        }
    } while (cantidad < 1 || cantidad > 10);

    for (int i = 0; i < cantidad; i++)
    {
        cout << endl;
        cout << i + 1 << ". Punto: " << endl;
        cout << endl;
        registrarPunto(puntos[i]);
    }
    return 0;
}