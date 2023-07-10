#include <stdio.h>
#include <stdlib.h>
#include "labyrinth.h"

int move(Labyrinth * l, Mouse * m, enum direction d)
{
    switch (d) {
        case UP: {
            return moveUp(l, m);
        }
        case DOWN: {
            return moveDown(l, m);
        }
        case RIGHT: {
            return moveRight(l, m);
        }
        case LEFT: {
            return moveLeft(l, m);
        }
    }
    return 0;
}
///======================FEL==========================
int moveUp(Labyrinth * l, Mouse * m) {
    int ret = 0;
    //TODO
if(m->row!=0){
    if( l->table[m->row-1][m->col]==2 ){
        ret=1;
    }
    if( l->table[m->row-1][m->col]==0 || l->table[m->row-1][m->col]==2 ){
        l->table[m->row][m->col]=0;
        m->row--;
        l->table[m->row][m->col]=3;
    }else{
        printf("Nem lephetek oda!\n");
    }
}
    return ret;
}
///======================LE==========================
int moveDown(Labyrinth * l, Mouse * m) {
    int ret = 0;
    //TODO
if(m->row!=l->rows-1){
    if( l->table[m->row+1][m->col]==2 ){
        ret=1;
    }
    if( l->table[m->row+1][m->col]==0 || l->table[m->row+1][m->col]==2  ){
        l->table[m->row][m->col]=0;
        m->row++;
        l->table[m->row][m->col]=3;
    }else{
        printf("Nem lephetek oda!\n");
    }
}
    return ret;
}
///======================BALRA==========================
int moveLeft(Labyrinth * l, Mouse * m) {
    int ret = 0;
    //TODO
if(m->col!=0){
    if( l->table[m->row][m->col-1]==2 ){
        ret=1;
    }
    if( l->table[m->row][m->col-1]==0 || l->table[m->row][m->col-1]==2 ){
        l->table[m->row][m->col]=0;
        m->col--;
        l->table[m->row][m->col]=3;
    }else{
        printf("Nem lephetek oda!\n");
    }
}
    return ret;
}
///======================JOBRA==========================
int moveRight(Labyrinth * l, Mouse * m) {
    int ret = 0;
    //TODO
if(m->col!=l->cols-1){
    if( l->table[m->row][m->col+1]==2 ){
        ret=1;
    }
    if( l->table[m->row][m->col+1]==0 || l->table[m->row][m->col+1]==2){
        l->table[m->row][m->col]=0;
        m->col++;
        l->table[m->row][m->col]=3;
    }else{
        printf("Nem lephetek oda!\n");
    }
}
    return ret;
}
///======================  LABIRINTUS FELTOLTESE  ==========================
Labyrinth * loadLabyrinth(char * filename, Mouse * m)
{
    FILE *in = fopen(filename, "r");
    Labyrinth * l = (Labyrinth *)malloc(sizeof(struct labyrinth));
    int i, j;
//TODO
    fscanf(in,"%i", &l->rows);
    fscanf(in,"%i", &l->cols);
    l->table=(int**)calloc(l->rows,sizeof(int*));
    for(int i=0; i<l->rows; i++){
        l->table[i]=(int*)calloc(l->cols,sizeof(int));
    }

    for(int i=0; i<l->rows; i++){
        for(int j=0; j<l->rows; j++){
            fscanf(in,"%i",&l->table[i][j]);
        }
    }

    fscanf(in,"%i", &m->row);
    fscanf(in,"%i", &m->col);
    m->row--;
    m->col--;
    int sajtX,sajtY;
    fscanf(in,"%i", &sajtX);
    fscanf(in,"%i", &sajtY);

    l->table[ m->row ][ m->col ]=3;///Eger elhelyezese
    l->table[ sajtX-1  ][ sajtY-1  ]=2;///Sajt elhelyezese
//-
    fclose(in);
    return l;
}

void freeLabyrinth(Labyrinth * l) {
    //TODO
    for(int i=0; i<l->rows; i++){
        free(l->table[i]);
    }
    free(l);
}

void printLabyrinth(Labyrinth * l) {
    int i, j;
//TODO
    system("@cls||clear");///Kepernyotorles

    for(i=0; i<l->rows; i++){
        for(j=0; j<l->cols; j++){
            //printf("%3i",l->table[i][j]);///Standard kiiratasmod

            if(  l->table[i][j]==0 ){printf("  ");}
            if(  l->table[i][j]==1 ){printf("%c%c",178,178);}
            if(  l->table[i][j]==3 ){printf("_@");}
            if(  l->table[i][j]==2 ){printf("##");}

        }
        printf("\n");
    }
//-
    printf("\n");
}
