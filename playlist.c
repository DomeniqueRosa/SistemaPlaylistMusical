#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"


// Inicialização e finalização
Playlist* criar_playlist(){
    Playlist* playlist= (Playlist*) malloc(sizeof(Playlist));
    playlist->atual = NULL;
    playlist->modo_repeticao = 1;
    playlist->tamanho = 0
    
    return playlist;
}
void liberar_playlist(Playlist* playlist){

    if(playlist->atual == NULL){
        free(lista);
        return;
    }

    Musica* atual = playlist->atual->proxima_musica;
    Musica* temp;

    do{
        temp = atual;
        atual = atual->proxima;
        free(temp);
    }while(atual != playlist->atual->proxima);

    free(lista);

}

// Gerenciamento de músicas
void adicionar_musica(Playlist* playlist, const char* titulo, const char* artista, int duracao){
    
    // disponibilizar memoria
    Musica* novo = (Musica*) malloc(sizeof(Musica));

    //adc dados da musica
    strcpy(novo->titulo, titulo);
    strcpy(novo->artista, artista);
    novo->duracao = duracao;

    if(playlist->atual == NULL){
        novo->proximo = novo;
        playlist-atual = novo;
    }else{
        novo->proximo = playlist->atual->proximo;
        playlist->atual->proximo = novo;
    }
}
int remover_musica(Playlist* playlist, const char* titulo){

    remover = buscar_musica(playlist,titulo);

    if(remover){
        
    }
}

// Navegação

void proxima_musica(Playlist* playlist);
void musica_anterior(Playlist* playlist);

// Configuração

void alternar_modo_repeticao(Playlist* playlist){
    !Playlist->modo_repeticao;   
}

// Visualização

void listar_musicas(Playlist* playlist){
    if(playlist->atual == NULL){
        printf("Playlist Vazia.\n");
        return;
    }

    Musica* atual = playlist->atual->proxima;

    printf("===========Playlist================")

    do{
        printf("Titulo: %s\nArtista: %s\nDuracao:%d\n",
        atual->titulo,
        atual->artista,
        atual->duracao);

        atual = atual->proximo;
    }while(atual != playlist->atual->proximo);

    printf("====================================");
}
Musica* buscar_musica(Playlist* playlist, const char* titulo){

    Musica* atual = playlist->atual;

    while (atual != NULL)
    {
        if(strcmp(atual->titulo, titulo) == 0){
            return atual;
        }
       
        atual = atual->proximo;
    }

    return NULL;
    
}
void exibir_musica_atual(Playlist* playlist);