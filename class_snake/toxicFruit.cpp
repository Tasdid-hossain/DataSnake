#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <time.h>  
#include "toxicFruit.h"
#include "snakeClass.h"

toxicFruit::toxicFruit()
{
    x = 0;
    y = 0;
    srand(time(NULL));
}

void toxicFruit::generateFruit(int width, int height) {
    x = rand() % width;
    y = rand() % height;
}

bool toxicFruit::fruitExists(int i, int j) {
    if (i == y && j == x) {
        return true;
    }
    return false;
}

