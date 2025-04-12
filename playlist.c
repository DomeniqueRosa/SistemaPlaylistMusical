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
    playlist->tamanho++;
}

int remover_musica(Playlist *playlist, const char *titulo)
{

    // encontrar musica
    Musica *remover = buscar_musica(playlist, titulo);

    if (remover == NULL)
    {
        printf("Esta musica nao esta na lista.\n");
        return -1;
    }

    // se tiver so uma musica
    if (playlist->tamanho == 1)
    {
        free(remover);
        playlist->atual = NULL;
        return 0;
    }

    // salvar proximo de remover
    Musica *proxima_musica = remover->proxima;
    Musica *anterior = NULL;
    Musica *temp = proxima_musica;
    // encontrar anterior
    do
    {
        if (temp->proxima == remover)
        {
            anterior = temp;
            break;
        }
        temp = temp->proxima;

    } while (temp != remover);

    // remover
    free(remover);
    playlist->tamanho--;

    // ligar anterior com proximo da musica removida
    anterior->proxima = proxima_musica;

    if (playlist->atual == remover)
    {
        playlist->atual = proxima_musica;
    }
    return 0;
}

// Navegação
// ok
void proxima_musica(Playlist *playlist)
{
    playlist->atual = playlist->atual->proxima;
}
// ok
void musica_anterior(Playlist *playlist)
{
    // guardar o ponteiro da musica atual
    Musica *atual = playlist->atual;
    // guardar o proximo
    Musica *temp = atual->proxima;

    do
    {
        if (temp->proxima == atual)
        {
            playlist->atual = temp;
            return;
        }
        temp = temp->proxima;

    } while (atual != temp);
}

// Configuração
// ok
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

// ok
Musica *buscar_musica(Playlist *playlist, const char *titulo)
{

    Musica *atual = playlist->atual;
    Musica *temp = atual;

    do
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            return atual;
        }

        atual = atual->proxima;

    } while (atual != temp);

    return NULL;
}
// -ok
void exibir_musica_atual(Playlist *playlist)
{
    Musica *atual = playlist->atual;
    printf("Musica atual,\n");
    printf("titulo: %s\n", atual->titulo);
}