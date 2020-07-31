#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iomanip>
using namespace std;

void recursiva(double verticeX, double respuesta, int a, int b, int c, int cont){
    if (cont >= 0){
    respuesta = recursiva(verticeX, respuesta, a, b, c, cont-1) - ((a * (pow(verticeX, 2)) + (b*verticeX) + c) / (2*a*(verticeX) +b));
    } else {
        cout << "Respuesta: " << respuesta; 
    }
}

void ejercicio3(int limit, int cont, double pi)
{

    if (cont <= limit)
    {
        pi = pi + ((pow(-1, cont)) / ((2 * cont) + 1));
        //cout << cont << " = " << pi << endl;
        ejercicio3(limit, cont + 1, pi);
    }
    else if (cont > limit)
    {
        cout << "PI= " << pi * 4 << endl;
    }
}

int main()
{
    int opcion;
    do
    {
        cout << "Menu: \n"
             << "1) Ejercicio 1 \n"
             << "2) Ejercicio 2 \n"
             << "3) Ejercicio 3 \n"
             << "0) Salir\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            cout << "Ejercicio 1\n";
            int a, b, c;
            cout << "ingrese el valor de a: ";
            cin >> a;
            while (a == 0)
            {
                cout << "ingrese el valor de a: ";
                cin >> a;
            }
            cout << "ingrese el valor de b: ";
            cin >> b;
            cout << "ingrese el valor de c: ";
            cin >> c;
            double verticeX = (-1 * b) / (2*a);
            double verticeY = a * (pow(verticeX, 2)) + (b*verticeX) + c;
            recursiva(verticeX, 0, a, b, c, 0);
        }
            break;
        
        case 2:
        {
            cout << "Ejercicio 2\n";

            int x = 9, temp;
            cout << "Ingrese el tamaño de la matriz: ";
            cin >> x;
            int matriz[x][x];

            for (int i = 0; i < x; i++)
            {
                cout << "[ ";
                for (int j = 0; j < x; j++)
                {
                    matriz[i][j] = 10 + rand() % (99 - 10);
                    temp = temp + matriz[i][j];
                    cout << matriz[i][j] << " ";
                }
                cout << "] \n";
            }
            double r, u, temp2;
            u = temp / (x * x);
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    temp2 = matriz[i][j] - u;
                    temp2 = pow(temp2, 2);
                    r += temp2;
                }
            }
            r = r / x * x;
            r = sqrt(r);
            double matrixE[x][x];

            for (int i = 0; i < x; i++)
            {
                cout << "[ ";
                for (int j = 0; j < x; j++)
                {
                    matrixE[i][j] = (matriz[i][j] - u) / r;
                    cout << setw(5) << matrixE[i][j] << " ";
                }
                cout << "] \n";
            }
        }
        break;

        case 3:
        {
            cout << "Ejercicio 3\n";
            cout << "Ingrese el limite de la sumatoria: ";
            int limit;
            double pi;
            cin >> limit;
            ejercicio3(limit, 0, 0);

            break;
        }
        default:
            break;
        }
    } while (opcion != 0);
}