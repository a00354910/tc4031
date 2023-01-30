#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std::out << "Sumando arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i=0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3)  * 3.7;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b ,c, pedazos) \
    schedule(static, pedazos)

    std::out << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endln;
    imprimeArreglo(a);

    std::out << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endln;
    imprimeArreglo(b);

    std::out << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endln;
    imprimeArreglo(c);
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endln;
}