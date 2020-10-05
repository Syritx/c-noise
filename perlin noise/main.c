#include <stdio.h>
#include <stdlib.h>
#include "noise.h"

float add(float a, float b) {
    return a+b;
}


int main() {

    int WIDTH = 760;
    int HEIGHT = 760;

    float rows[WIDTH][HEIGHT];

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {

            float val;
            for (int j = 1; j < 2; j++) {
                float frequency = 100;
                float amplitude = 55;

                float xRel = (float)x/WIDTH;
                float yRel = (float)y/HEIGHT;

                xRel = xRel*(frequency/(j*2));
                yRel = yRel*(frequency/(j*2));

                val = noise(xRel,yRel)*(amplitude+(j*2));
                printf("%f C\n", val);
            }
            rows[x][y] = val;
        }
    }

    FILE* file;
    file = fopen("noise.txt","w+");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(file, "%f ",rows[x][y]);
        }
        fprintf(file,"\n");
    }
}