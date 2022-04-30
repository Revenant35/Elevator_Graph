
#include <malloc.h>
#include <stdio.h>
#include "Elevator.h"
#include "stdbool.h"

#define MAX_FLOORS (101)

typedef struct {
    bool isVisited[MAX_FLOORS];
    short parent[MAX_FLOORS];
} *Floors;


bool next_floor(Floors floors, short current_floor, short f, short g, short u, short d){

    if(current_floor == g)
        return true;

    floors->isVisited[current_floor] = true;

    if(current_floor + u <= f && !floors->isVisited[current_floor + u]){
        floors->parent[current_floor + u] = current_floor;
        if(next_floor(floors, (current_floor + u), f, g, u, d))
            return true;
    }

    if(current_floor - d >= 0 & !floors->isVisited[current_floor - d]){
        floors->parent[current_floor - d] = current_floor;
        if(next_floor(floors, (current_floor - d), f, g, u, d))
            return true;
    }

    return false;
}

void print_path(Floors floors, short s, short g){

    if(g == s){
        printf("%d", g);
        return;
    }

    print_path(floors, s, floors->parent[g]);
    printf(" -> %d", g);

}

void solve(short f, short s, short g, short u, short d){
    Floors floors;
    floors = malloc(sizeof(*floors));
    for(int i = 0; i < MAX_FLOORS; i++) {
        floors->parent[i] = -1;
        floors->isVisited[i] = false;
    }

    if(next_floor(floors, s, f, g, u, d))
        print_path(floors, s, g);
    else
        printf("use the stairs");
    printf("\n");
}