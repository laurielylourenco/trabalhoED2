#ifndef SORT_H__
#define SORT_H__


void bubbleSort(Filme *filmes, int size);

void mergeSort(Filme *filmes, int p, int size);
void merge(Filme *filmes, int p,int q, int size);

void quicksort(Filme *filmes, int esq, int dir);
int partition(Filme *filmes, int esq, int dir);

#endif /* SORT_H__ */
