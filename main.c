#include <stdio.h>
#include "playlist.h"

int main(){

    Playlist* play = criar_playlist();

    printf("Lista vazia\n");
    listar_musicas(play);

    printf("Adicionar musica\n");
    adicionar_musica(play, "Beautiful Things", "Benson Boone", 192);
    printf("Adicionar musica\n");
    adicionar_musica(play, "Save your tears", "The  Weeknd", 220);

    printf("Listar\n");
    listar_musicas(play);

    printf("Exibir musica atual\n");
    exibir_musica_atual(play);

    printf("Proxima musica.\n");
    proxima_musica(play);

    printf("Exibir musica atual\n");
    exibir_musica_atual(play);

    printf("Exibir musica anterior\n");
    musica_anterior(play);
    exibir_musica_atual(play);


    printf("buscar musica\n");
    Musica* musica = buscar_musica(play, "I want it that way");
    printf("titulo: %s\n", musica->titulo);


    printf("Remover musica\n");
    remover_musica(play, "Save your tears");

    printf("Listar\n");
    listar_musicas(play);

    printf("\nLimpar lista\n");
    liberar_playlist(play);

    printf("Listar\n");
    listar_musicas(play);


    return 0;
}