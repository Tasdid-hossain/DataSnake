#include "goodFruit.h"
#include <iostream>
#include <time.h>  
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "snakeClass.h"

goodFruit::goodFruit()
{
    x = 0;
    y = 0;
    srand(time(NULL));
}

void goodFruit::generateFruit(int width, int height) {
    x = rand() % width;
    y = rand() % height;
}

bool goodFruit::fruitExists(int i, int j) {
    if (i == y && j == x) {
        return true;
    }
    return false;
}
