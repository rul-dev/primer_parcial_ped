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

PuntoTrayectoria *obtenerPuntoMasAlejado(PuntoTrayectoria puntos[], int cantidad)
{
    PuntoTrayectoria *mayordistancia = &puntos[0];
    for (int i = 1; i < cantidad; i++)
    {
        if (puntos[i].distanciaOrigen > mayordistancia->distanciaOrigen)
        {
            mayordistancia = &puntos[i];
        }
    }

    return mayordistancia;
}

void corregirCoordenadas(PuntoTrayectoria &punto, float desplazamientoX, float desplazamientoY, float desplazamientoZ)
{
    float newX = punto.coordenadas[0] + desplazamientoX;
    punto.coordenadas[0] = newX;
    float newY = punto.coordenadas[1] + desplazamientoY;
    punto.coordenadas[1] = newY;
    float newZ = punto.coordenadas[2] + desplazamientoZ;
    punto.coordenadas[2] = newZ;
}

void generarInforme(PuntoTrayectoria puntos[], int cantidad)
{
    cout << "Informe de elementos registrados: " << endl;
    cout << endl;

    int contadorCERCANO = 0, contadorINTERMEDIO = 0, contadorLEJANO = 0, contadorEXTREMO = 0;

    float distanciaPromedio = 0;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "ID: " << puntos[i].identificador << endl;
        cout << "Nombre: " << puntos[i].nombre << endl;
        cout << "Coordenada X: " << puntos[i].coordenadas[0] << endl;
        cout << "Coordenada Y:" << puntos[i].coordenadas[1] << endl;
        cout << "Coordenada Z:" << puntos[i].coordenadas[2] << endl;
        cout << "Distancia al origen: " << puntos[i].distanciaOrigen << endl;
        cout << "Clasificacion: " << puntos[i].clasificacion << endl;
        cout << endl;
        // deberá contabilizar cuántos elementos pertenecen a cada estado:

        if (puntos[i].clasificacion == "CERCANO")
        {
            contadorCERCANO++;
        }
        else if (puntos[i].clasificacion == "INTERMEDIO")
        {
            contadorINTERMEDIO++;
        }
        else if (puntos[i].clasificacion == "LEJANO")
        {
            contadorLEJANO++;
        }
        else if (puntos[i].clasificacion == "EXTREMO")
        {
            contadorEXTREMO++;
        }

        distanciaPromedio += puntos[i].distanciaOrigen;
    }

    cout << "Cantidad de elementos en estado CERCANO: " << contadorCERCANO << endl;
    cout << "Cantidad de elementos en estado INTERMEDIO: " << contadorINTERMEDIO << endl;
    cout << "Cantidad de elementos en estado LEJANO: " << contadorLEJANO << endl;
    cout << "Cantidad de elementos en estado EXTREMO: " << contadorEXTREMO << endl;

    cout << "Factor promedio de todos los elementos: " << distanciaPromedio / cantidad << endl;
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

    PuntoTrayectoria *mayorDistancia = obtenerPuntoMasAlejado(puntos, cantidad);

    cout << endl
         << endl;
    cout << "------------------ PUNTO CON MAYOR DISTANCIA --------------------- " << endl;

    cout << "Identificador: " << mayorDistancia->identificador << endl;
    cout << "Nombre: " << mayorDistancia->nombre << endl;
    cout << "Coordenada 1: " << mayorDistancia->coordenadas[0] << endl;
    cout << "Coordenada 2: " << mayorDistancia->coordenadas[1] << endl;
    cout << "Coordenada 3: " << mayorDistancia->coordenadas[2] << endl;
    cout << "Distancia respecto al origen: " << mayorDistancia->distanciaOrigen << endl;
    cout << "Clasificacion: " << mayorDistancia->clasificacion << endl;

    string respuesta;
    cout << "Quiere recalibrar las coordenadas de este punto?: Si/No " << endl;
    cin >> respuesta;

    if (respuesta == "Si")
    {
        float desplazamientoX, desplazamientoY, desplazamientoZ;
        cout << "Cuanto de desplazamiento tiene X?: " << endl;
        cin >> desplazamientoX;
        cout << "Cuanto de desplazamiento tiene Y?: " << endl;
        cin >> desplazamientoY;
        cout << "Cuanto de desplazamiento tiene Z?: " << endl;
        cin >> desplazamientoZ;
        corregirCoordenadas(*mayorDistancia, desplazamientoX, desplazamientoY, desplazamientoZ);

        cout << "Coordenada X: " << mayorDistancia->coordenadas[0] << endl;
        cout << "Coordenada Y: " << mayorDistancia->coordenadas[1] << endl;
        cout << "Coordenada Z: " << mayorDistancia->coordenadas[2] << endl;

        cout << "Distancia origen: " << calcularDistancia(mayorDistancia) << endl;
        clasificarPunto(*mayorDistancia);
    }
    else
    {
        cout << "No se aumentaron las cargas del elemento critico" << endl;
    }

    generarInforme(puntos, cantidad);
    return 0;
}