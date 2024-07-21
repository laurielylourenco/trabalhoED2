#ifndef FILME_H__
#define FILME_H__

// Coloque aqui aa definição da estrutura que representa o filme.
const int MAX_TAM = 100;

struct Filme1
{
    int id;
    char movie_name[50];
    char year_of_release[8];
    char watch_time[MAX_TAM];
    char movie_rating[MAX_TAM];
    char metascore_of_movie[10];
    char gross[MAX_TAM];
};

struct Filme
{
    int id;
    bool adult;
    char genres[MAX_TAM];
    int id_filme; // => id
    char imdb_id[20];
    char original_language[10];
    char original_title[50];
    char overview[200];
    float popularity;
    char production_companies[MAX_TAM];
    int production_countries[MAX_TAM];
    char release_date[8];
    float revenue;
    float runtime;
    char spoken_languages[MAX_TAM];
    char title[50];
    float vote_average;
    float vote_count;
};

struct FilmeTexto
{
    char movie_name[50];
    char year_of_release[8];
    char metascore_of_movie[10];
};

#endif /* FILME_H__ */
