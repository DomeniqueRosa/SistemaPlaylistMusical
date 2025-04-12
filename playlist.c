#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"

// Inicialização e finalização - ok
Playlist *criar_playlist()
{
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    playlist->atual = NULL;
    playlist->modo_repeticao = 1;
    playlist->tamanho = 0;

    return playlist;
}

// ok
void liberar_playlist(Playlist *playlist)
{

    if (playlist->atual == NULL)
    {
        free(playlist);
        return;
    }

    Musica *atual = playlist->atual->proxima;
    Musica *temp;

    do
    {
        temp = atual;
        atual = atual->proxima;
        free(temp);
    } while (atual != playlist->atual->proxima);

    playlist->atual = NULL;
    playlist->tamanho = 0;
    playlist->modo_repeticao = 0;
}

// Gerenciamento de músicas - ok
void adicionar_musica(Playlist *playlist, const char *titulo, const char *artista, int duracao)
{

    // disponibilizar memoria
    Musica *novo = (Musica *)malloc(sizeof(Musica));

    // adc dados da musica
    strcpy(novo->titulo, titulo);
    strcpy(novo->artista, artista);
    novo->duracao = duracao;

    if (playlist->atual == NULL)
    {
        novo->proxima = novo;
        playlist->atual = novo;
    }
    else
    {
        novo->proxima = playlist->atual->proxima;
        playlist->atual->proxima = novo;
    }
}
// int remover_musica(Playlist *playlist, const char *titulo)
// {
//     return 0;
//     //encontrar musica
//     Musica *remover = remover_musica(playlist, titulo);

//     //salvar proximo de remover
//     Musica *proxima_musica = remover->proxima;

//     //encontrar anterior
//     Musica *temp = proxima_musica;
//     Musica *atual = temp;
//     Musica *anterior = NULL;
//     do{

//     }while(atual != remover);

//      //remover

//      //ligar anterior com proximo da musica removida

// }

// Navegação

void proxima_musica(Playlist *playlist)
{
    printf("Titulo: %s\n", playlist->atual->proxima);
}
void musica_anterior(Playlist *playlist)
{
    if (playlist->atual != NULL)
    {
        Musica *temp = playlist->atual->proxima; // comeco da lista
        Musica *inicio = temp;

        do
        {

        } while (temp != inicio);
    }
}

// Configuração

void alternar_modo_repeticao(Playlist *playlist)
{
    !playlist->modo_repeticao;
}

// Visualização - ok
void listar_musicas(Playlist *playlist)
{
    if (playlist->atual == NULL)
    {
        printf("Playlist Vazia.\n");
        return;
    }

    Musica *atual = playlist->atual->proxima;

    printf("===========Playlist================\n");

    do
    {
        printf("Titulo: %s\nArtista: %s\nDuracao: %d\n",
               atual->titulo,
               atual->artista,
               atual->duracao);

        atual = atual->proxima;
    } while (atual != playlist->atual->proxima);

    printf("===================================\n");
}

//ok
Musica *buscar_musica(Playlist *playlist, const char *titulo)
{

    Musica *atual = playlist->atual;

    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            return atual;
        }

        atual = atual->proxima;
    }

    return NULL;
}
void exibir_musica_atual(Playlist *playlist)
{
}