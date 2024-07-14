#include <iostream>
#include <cmath>
#include <string.h>
#include "filme.h"
#include "sort.h"

using namespace std;

// Implemente aqui as funções declaradas em sort.h

void bubbleSort(Filme *filmes, int size)
{

    for (int i = size - 1; i > 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            /* strcmp retorna um valor negativo se o primeiro argumento for menor que o segundo */
            if (strcmp(filmes[j].movie_name, filmes[j + 1].movie_name) > 0)
            {

                Filme troca = filmes[j];
                filmes[j] = filmes[j + 1];
                filmes[j + 1] = troca;
            }
        }
    }
}

void mergeSort(Filme *filmes, int p, int size)
{

    if (p < (size - 1))
    {
        int q = (p + size) / 2;

        mergeSort(filmes, p, q);
        mergeSort(filmes, q, size);
        merge(filmes, p, q, size);
    }
}

void merge(Filme *filmes, int p, int q, int size)
{
    int i = p;
    int j = q;
    int k = 0;

    Filme aux[size];

    while ((i < q) && (j < size))
    {

        // if (filmes[i].movie_name[0] < filmes[j].movie_name[0])
        if (strcmp(filmes[i].movie_name, filmes[j].movie_name) < 0)
        {
            aux[k] = filmes[i];
            i++;
        }
        else
        {
            aux[k] = filmes[j];
            j++;
        }
        k++;
    }

    while (i < q)
    {
        aux[k] = filmes[i];
        i++;
        k++;
    }

    while (j < size)
    {
        aux[k] = filmes[j];
        j++;
        k++;
    }

    for (i = p; i < size; i++)
    {
        filmes[i] = aux[i - p];
    }
}

void quicksort(Filme *filmes, int esq, int dir)
{
    int p = 0;
    if (esq >= 0 && dir >= 0 && esq < dir)
    {
        p = partition(filmes, esq, dir);

        quicksort(filmes, esq, p);
        quicksort(filmes, p + 1, dir);
    }
}

int partition(Filme *filmes, int esq, int dir)
{
    int g = floor((esq + dir) / 2);

    Filme pivot = filmes[g];

    int i = esq - 1;
    int j = dir + 1;

    do
    {
        do
        {
            i = i + 1;
        } while (strcmp(filmes[i].movie_name, pivot.movie_name) < 0);

        do
        {
            j = j - 1;
        } while (strcmp(filmes[j].movie_name, pivot.movie_name) > 0);

        if (i >= j)
            return j;

        Filme troca;
        troca = filmes[i];
        filmes[i] = filmes[j];
        filmes[j] = troca;

    } while (true);
}