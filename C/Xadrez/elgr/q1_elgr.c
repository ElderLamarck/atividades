#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char tabuleiro[8][8];
int peao(int linha, int coluna);
int cavalo(int linha, int coluna);
int torre(int linha, int coluna);
int bispo(int linha, int coluna);
int rei(int linha, int coluna);

int main(){
    int l, c;
    int linha, coluna;
    int STOP = 0;

    for (linha=0; linha != 8; linha++){
        for (coluna=0; coluna != 8; coluna++){
        scanf(" %c", &tabuleiro[linha][coluna]);
        }
    }

    for(l = 0; l != 8; l++){
        if (STOP == 1){break;}
        for(c = 0; c != 8; c++){
            if (STOP == 1){break;}

            //pegar as peças do adversário:
            if (tabuleiro[l][c] > 'a' && tabuleiro[l][c] < 'z'){
                
                if (tabuleiro[l][c] == 't'){
                    STOP = torre(l,c);
                }
                else if (tabuleiro[l][c] == 'c'){
                    STOP = cavalo(l,c);
                }
                else if (tabuleiro[l][c] == 'b'){
                    STOP = bispo(l,c);
                }
                else if (tabuleiro[l][c] == 'k'){
                    STOP = rei(l,c);
                }
                else if (tabuleiro[l][c] == 'q'){
                    STOP = bispo(l,c);
                    if (STOP == 0){
                        STOP = torre(l,c);
                    }
                }
                else if (tabuleiro[l][c] == 'p'){
                    STOP = peao(l,c);
                }
            }
        }
        if (l == 7 && STOP == 0){
            printf("NAO XEQUE");
        }
    }

	return 0;
}
int rei(int linha, int coluna){
    int STOP = 0;
    int l, c, control;

    //superior
    l = linha -1;
    for(c = coluna-1; c <= coluna + 1; c++){
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
    }

    //inferior
    l = linha + 1;
    for(c = coluna-1; c <= coluna + 1; c++){
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
    }

    //esquerda
     if (tabuleiro[l][c-1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }

    //direita
    if (tabuleiro[l][c+1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
    return STOP;
}

int bispo(int linha, int coluna){
    int STOP = 0;
    int l, c;

    //diagonal superior esquerda
    l = linha-1;
    c = coluna-1;
    while(l != -1 || c != -1){
        if (tabuleiro[l][c] != 'K' && (tabuleiro[l][c] != '-') ){
            break;
        }
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
        l--;
        c--;
    }
    //diagonal inferior esquerda
    l = linha+1;
    c = coluna-1;
    while(l != 8 || c != -1){
        if (tabuleiro[l][c] != 'K' && (tabuleiro[l][c] != '-') ){
            break;
        }
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
        l++;
        c--;
    }
    
    //diagonal superior direita
    l = linha-1;
    c = coluna+1;
    while(l != -1 || c != 8){
        if (tabuleiro[l][c] != 'K' && (tabuleiro[l][c] != '-') ){
            break;
        }
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
        l--;
        c++;
    }
    //diagonal inferior direita
    l = linha+1;
    c = coluna+1;
    while(l != 8 || c != 8){
        if (tabuleiro[l][c] != 'K' && (tabuleiro[l][c] != '-') ){
            break;
        }
        if (tabuleiro[l][c] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        }
        l++;
        c++;
    }
    return STOP;
}

int torre(int linha, int coluna){
    int STOP = 0;
    int i, j;

    //vertical
    for(i = linha+1; i != 8; i++){
        if (tabuleiro[i][coluna] != 'K' && (tabuleiro[i][coluna] != '-') ){
            break;
        }
        if (tabuleiro[i][coluna] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        } 
    }
    for(i = linha-1; i != -1; i--){
        if (tabuleiro[i][coluna] != 'K' && (tabuleiro[i][coluna] != '-') ){
            break;
        }
        if (tabuleiro[i][coluna] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        } 
    }
    //horizontal
    for(j = coluna+1; j != 8; j++){
        if (tabuleiro[linha][j] != 'K' && (tabuleiro[linha][j] != '-') ){
            break;
        }
        if (tabuleiro[linha][j] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        } 
    }
    for(j = coluna-1; j != -1; j--){
        if (tabuleiro[linha][j] != 'K' && (tabuleiro[linha][j] != '-') ){
            break;
        }
        if (tabuleiro[linha][j] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
        } 
    }
    return STOP;
}

int peao(int linha, int coluna){
    int STOP = 0;
    linha = linha + 1;
    if (tabuleiro[linha][coluna+1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
    }
    else if (tabuleiro[linha][coluna-1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP;
    }
    return STOP;
}

int cavalo(int linha, int coluna){
    int STOP = 0;
    int L;
    //inferior
    L = linha + 2;
    if (tabuleiro[L][coluna+1] == 'K' || tabuleiro[L][coluna-1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP; 
    }
    L = linha + 1;  
    if (tabuleiro[L][coluna+2] == 'K' || tabuleiro[L][coluna-2] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP; 
    }
    
    //superior
    L = linha - 2;
    if (tabuleiro[L][coluna+1] == 'K' || tabuleiro[L][coluna-1] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP; 
    }
    L = linha - 1;
    if (tabuleiro[L][coluna+2] == 'K'|| tabuleiro[L][coluna-2] == 'K'){
        printf("XEQUE");
        STOP = 1;
        return STOP; 
    }
    return STOP;
}