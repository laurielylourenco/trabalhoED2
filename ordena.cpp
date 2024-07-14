#include <iostream>
#include <fstream>
#include <string>
#include "filme.h"
#include "sort.h"
#include <sstream>
#include <vector>
#include <type_traits>
#include <string.h>

using namespace std;

int obter_numeto_de_filmes(const std::string &NomeArquivoTexto)
{
    // Implemente esta função

    int length = 0;
    ifstream arquivo(NomeArquivoTexto, ios::binary);

    if (!arquivo)
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Filme total_filme;

    while (arquivo.read((char *)(&total_filme), sizeof(Filme)))
    {
        length++;
    }

    arquivo.close();
    return length;
}

int main(int argc, char *argv[])
{
    // o programa obrigatoriamente recebe dois argumentos por linha de comando
    // argv[1] é o nome do arquivo binário e argv[2] é um inteiro que indica qual método de ordenação será utilizado:
    // 1 - método simples
    // 2 - merge sort
    // 3 - quick sort
    if (argc != 3)
    {
        std::cout << "Uso: " << argv[0] << " <arquivo_binário>.csv inteiro" << std::endl;
        return 1;
    }

    if (atoi(argv[2]) < 1 || atoi(argv[2]) > 3)
    {
        std::cout << "O inteiro deve ser 1, 2 ou 3, onde  \n 1 - método simples \n 2 - merge sort \n 3 - quick sort" << std::endl;
        return 1;
    }

    std::string NomeArquivoTexto = argv[1];
    int n = obter_numeto_de_filmes(NomeArquivoTexto);
    int metodo_ord = atoi(argv[2]);

    // Criar um vetor de n filmes.
    Filme v_filmes[n];

    // Ler os filmes do arquivo binário e armazenar no vetor.
    Filme filme;
    ifstream readDAT(NomeArquivoTexto, ios::binary);

    int i = 0;
    if (!readDAT)
    {
        cout << "Erro ao abrir o arquivo binário." << endl;
        return 1;
    }

    while (readDAT.read((char *)(&filme), sizeof(Filme)))
    {
        v_filmes[i] = filme;

        i++;
    }

    // Ordenar o vetor de filmes de acordo com o método escolhido.

    switch (metodo_ord)
    {
    case 1:

        bubbleSort(v_filmes, n);

        break;
    case 2:
        mergeSort(v_filmes, 0, n);
        break;
    case 3:

        quicksort(v_filmes, 0, n - 1);
        break;
    }

    // Escrever o vetor de filmes ordenado em um arquivo texto chamado "filmes_ordenados.txt".'

    ofstream writeOrdenado("filmes_ordenados.txt", ios::out);

    if (!writeOrdenado.is_open())
    {
        cout << "Erro ao abrir o arquivo.";
        return 1;
    }
    /*
       NOME                                              Year    Metascore
       Pulp Fiction                                      1924    95
       */

    char nomeCab[50] = "Nome";
    char MetascoreCab[10] = "Metascore";
    char yearCab[8] = "Year";

    for (int w = 0; w < 50; w++)
    {

        if (w > strlen(nomeCab) - 1)
        {
            writeOrdenado << ' ';
        }
        else
        {
            writeOrdenado << nomeCab[w];
        }
    }
    writeOrdenado << ' ';

    for (int w = 0; w < strlen(yearCab); w++)
    {

        if (w > strlen(yearCab) - 1)
        {
            writeOrdenado << ' ';
        }
        else
        {
            writeOrdenado << yearCab[w];
        }
    }
    writeOrdenado << ' ';
    for (int w = 0; w < strlen(MetascoreCab); w++)
    {
        if (w > strlen(MetascoreCab) - 1)
        {
            writeOrdenado << ' ';
        }
        else
        {
            writeOrdenado << MetascoreCab[w];
        }
    }

    writeOrdenado << endl;

    for (int o = 0; o < n; o++)
    {

        for (int w = 0; w < 50; w++)
        {

            if (w > strlen(v_filmes[o].movie_name) - 1)
            {
                writeOrdenado << ' ';
            }
            else
            {
                writeOrdenado << v_filmes[o].movie_name[w];
            }
        }
        writeOrdenado << ' ';

        for (int w = 0; w < 8; w++)
        {

            if (w > strlen(v_filmes[o].year_of_release) - 1)
            {
                writeOrdenado << ' ';
            }
            else
            {
                writeOrdenado << v_filmes[o].year_of_release[w];
            }
        }
        writeOrdenado << ' ';

        for (int w = 0; w < strlen(v_filmes[o].metascore_of_movie) ; w++)
        {
             writeOrdenado << v_filmes[o].metascore_of_movie[w];
        }

        writeOrdenado << endl;
    }

    writeOrdenado.close();

    return 0;
}