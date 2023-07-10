
#ifndef LABYRINTH_H
#define	LABYRINTH_H

typedef struct labyrinth {
    int rows, cols;
    int **table;
} Labyrinth;

typedef struct mouse {
    int row;
    int col;
} Mouse;

enum direction {UP = '8', DOWN = '2', RIGHT = '6', LEFT = '4'};

//0 - ut, 1 - fal, 2 - sajt, 3 - eger
Labyrinth * loadLabyrinth(char * filename,  Mouse * m);
void freeLabyrinth(Labyrinth * l);
void printLabyrinth(Labyrinth * l);
//A mozgatast vegzo fuggvenyek 1-t teritenek vissza
//ha vege a jateknak, kulonben 0-t.
int move(Labyrinth * l, Mouse * m, enum direction d);
int moveUp(Labyrinth * l, Mouse * m);
int moveDown(Labyrinth * l, Mouse * m);
int moveLeft(Labyrinth * l, Mouse * m);
int moveRight(Labyrinth * l, Mouse * m);

#endif	/* Labyrinth_H */

