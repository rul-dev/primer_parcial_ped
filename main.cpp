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

float calcularDistancia(PuntoTrayectoria *punto)
{
    float distancia = (pow(punto->coordenadas[0], 2) + pow(punto->coordenadas[1], 2) + pow(punto->coordenadas[2], 2));

    punto->distanciaOrigen = distancia;
    return distancia;
}

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
    cout << "Distancia origen: " << calcularDistancia(&punto) << endl;
}

void clasificarPunto(PuntoTrayectoria &punto)
{
    float distancia = punto.distanciaOrigen;

    if (distancia >= 0 && distancia <= 5)
    {
        punto.clasificacion = "CERCANO";
    }
    else if (distancia > 5 && distancia <= 10)
    {
        punto.clasificacion = "INTERMEDIO";
    }
    else if (distancia > 10 && distancia <= 20)
    {
        punto.clasificacion = "LEJANO";
    }
    else if (distancia > 20)
    {
        punto.clasificacion = "EXTREMO";
    }

    cout << "Clasificacion de la distancia del punto: " << punto.clasificacion << endl;
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
        cout << endl;
        clasificarPunto(puntos[i]);
    }
    return 0;
}