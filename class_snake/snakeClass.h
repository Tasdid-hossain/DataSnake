#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class snakeClass
{
private:
    int posX;
    int posY;
    int tailLen = 0;
    enum eDirection { STOP = 0, UP, LEFT, RIGHT, DOWN };
    eDirection dir;

    int width;
    int height;
    
    string myText;
   
   
   
public:
   
	snakeClass();
    void init();
    void draw();
    void input();
    void logic();
    bool gameState = true;
    string name;
    int score;
    int achivementGood;
    int achivementBad;
};

