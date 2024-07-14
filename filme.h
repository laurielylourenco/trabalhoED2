#ifndef FILME_H__
#define FILME_H__

// Coloque aqui aa definição da estrutura que representa o filme.
const int MAX_TAM = 100;


struct Filme
{
    int id;
    char movie_name[50];
    char year_of_release[8];
    char watch_time[MAX_TAM];
    char movie_rating[MAX_TAM];
    char metascore_of_movie[10];
    char gross[MAX_TAM];
};

struct FilmeTexto
{
    char movie_name[50];
    char year_of_release[8];
    char metascore_of_movie[10];
};

#endif /* FILME_H__ */
