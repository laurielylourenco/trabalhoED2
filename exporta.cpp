

#include <iostream>
#include "filme.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <type_traits>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{

    if ((argc != 4) && (argc != 5))
    {
        /* -a -> all film , -r -> random film */
        cout << argc << endl;
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat -a" << endl;
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat -r N" << endl;
        return 1;
    }

    string NomeArquivoTexto = argv[1];
    string NomeArquivoBinario = argv[2];
    string tipoExtracao = argv[3];

    int num_random = 0;

    if (
        ((tipoExtracao.compare("-r") == 0) && (argc != 5)) ||
        ((tipoExtracao.compare("-a") == 0) && (argc != 4)))
    {
        cout << "Erro: Parametro errado!" << endl;
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat -a" << endl;
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat -r N" << endl;
        return 1;
    }

    if (tipoExtracao.compare("-a") == 0)
    {
        cout << "-a" << endl;
    }

    /*     ifstream readCSV(NomeArquivoTexto);

        if (!readCSV.is_open())
        {
            cout << "Erro ao abrir o arquivo!" << endl;
            return 1;
        }

        string linha;
        string linhaFilme;
        vector<Filme> vetor;

        int g = 0;
        string id_filme = "";
        while (getline(readCSV, linha))
        {

            stringstream ss(linha);
            string id;
            getline(ss, id, ',');

            if (id != "" && id != ",")
            {

                Filme filme;
                filme.id = g;

                string movie_name;

                getline(ss, movie_name, ',');

                string year_of_release;
                getline(ss, year_of_release, ',');

                string watch_time;
                getline(ss, watch_time, ',');

                string movie_rating;
                getline(ss, movie_rating, ',');

                string metascore_of_movie;
                getline(ss, metascore_of_movie, ',');

                string gross;
                getline(ss, gross, ',');

                strcpy(filme.movie_name, movie_name.c_str());
                strcpy(filme.year_of_release, year_of_release.c_str());
                strcpy(filme.watch_time, watch_time.c_str());
                strcpy(filme.movie_rating, movie_rating.c_str());
                strcpy(filme.metascore_of_movie, metascore_of_movie.c_str());
                strcpy(filme.gross, gross.c_str());

                vetor.push_back(filme);

                g++;
            }
        }
        readCSV.close();

        ofstream writeDAT(argv[2], ios::binary);

        if (!writeDAT.is_open())
        {
            cout << "Erro ao abrir o arquivo binario.";
            return 1;
        }

        for (const Filme &filme : vetor)
        {
            writeDAT.write((char *)&filme, sizeof(Filme));
        }

        writeDAT.close(); */

    return 0;
}