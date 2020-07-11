#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include "snakeClass.h"
#include "goodFruit.h"
#include "toxicFruit.h"
#include "visitor.h"
using std::cout; using std::cin; using std::endl;



struct Node {
    int x;
    int y;
    struct Node* next;
};

Node* newNode(int x, int y) {
    Node* link = new(Node);
    link->x = x;
    link->y = y;
    link->next = nullptr;
    return link;
}


void rotateList(Node* head, int x, int y) {
    int i;
    Node* current = head;
    int tempX[2], tempY[2];
    for (i = 0; current != nullptr; i++) {

        if (i == 0) {
            tempX[0] = current->x;
            tempY[0] = current->y;
            current->x = x;
            current->y = y;
        }
        else {
            tempX[(i % 2 == 0) ? 0 : 1] = current->x;
            tempY[(i % 2 == 0) ? 0 : 1] = current->y;
            current->x = tempX[(i % 2 == 0) ? 1 : 0];
            current->y = tempY[(i % 2 == 0) ? 1 : 0];
        }

        current = current->next;
    }

}


void append(Node*& head, Node*& link) {
    Node* ptr;
    ptr = head;

    head = link;
    head->next = ptr;
}

void pop(Node*& head) {
    
    head = head->next;
}

Node* head;
goodFruit gf;
toxicFruit tf;
visitor vs;

snakeClass::snakeClass()
{
    width = 20;
    height = 20;
    gameState = true;
    achivementGood = 0;
    achivementBad = 0;
}

void snakeClass:: init() {
    //Initialise snake's position
    posX = width / 2;
    posY = height / 2;

    
    cout << "Please enter the player name: ";
    cin >> name;
    //Initialise first tail node
    head = newNode(posX, posY);

    //Spawn fruit
    gf.generateFruit(width, height);
    tf.generateFruit(width, height);

    //Initialise score
    achivementGood = 0;
    achivementBad = 0;
    //Initialise direction
    dir = STOP;
 
}
void snakeClass::draw() {
    system("cls");
    
    cout << "Welcome" << " " << name ;
    cout << "\n\n";
    cout << "############ Lets play the game ############# ";
    cout << "\n\n";
    //Draw top of playing field
    for (int i = 0; i < width + 2; i++)
        cout << '#';
    cout << '\n';

    //Main draw
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {


            bool found = false;

            //Draw left of playing field
            if (j == 0)
                cout << '#';

            //Draw snake's head
            if (i == posY && j == posX) {
                cout << 'O';
                found = true;
            }

            Node* current = head;

            //Draw snake's body by extracting data from a linked list
            while (current != nullptr && found != true) {
                if (i == current->y && j == current->x) {
                    cout << 'o';
                    found = true;
                }
                current = current->next;
            }

            //If snake's body is not found check to see if there is anything else in the location
            if (!found) {
                if (gf.fruitExists(i, j))
                {
                    cout << 'F';
                }

               else if (tf.fruitExists(i, j) && tailLen>=1)
                {
                    cout << 'X';
                }
                                
                else
                    cout << ' ';
            }


            //Draw right side of playing field
            if (j == width - 1)
                cout << '#';
        }
        //Add new lines where needed
        if (i != height - 1)
            cout << '\n';
    }
    cout << '\n';

    //Draw bottom of playing field
    for (int i = 0; i < width + 2; i++)
        cout << '#';
    cout << endl;

    //Score screen
    cout << "Score: " << vs.scoreC << " || Tail len: " << tailLen << '\n';

    cout << "Good Fruits Eaten: " << 
        
        achivementGood << endl;
    cout << "toxic Fruits Eaten: " <<

        achivementBad << endl;

}


void snakeClass::input() {
    //If a button is pushed
    if (_kbhit()) {

        //Controls
        switch (_getch()) {
        case 'W': case 'w':
            dir = UP;
            break;
        case 'A': case 'a':
            dir = LEFT;
            break;
        case 'S': case 's':
            dir = DOWN;
            break;
        case 'D': case 'd':
            dir = RIGHT;
            break;
        case 'x': case 'X':
            gameState = false;
            break;
        }
    
    }
}

void snakeClass::logic() {
    //Movement and snake tail logic
    switch (dir) {
    case UP:
        //Rotate list rotates the nodes for the snake tail
        rotateList(head, posX, posY);
        posY--;
        break;
    case DOWN:
        //Rotate list rotates the nodes for the snake tail
        rotateList(head, posX, posY);
        posY++;
        break;
    case LEFT:
        //Rotate list rotates the nodes for the snake tail
        rotateList(head, posX, posY);
        posX--;
        break;
    case RIGHT:
        //Rotate list rotates the nodes for the snake tail
        rotateList(head, posX, posY);
        posX++;
        break;
    }
    //Fruit logic (If fruit is picked up)
    if (gf.fruitExists(posY, posX)) {
        //Create new snake tail node
        Node* link = newNode(posX, posY);
        append(head, link);

        //Add score
        vs.visitScore(gf);

        achivementGood = vs.visit(gf);

        //Respawn fruit
        gf.generateFruit(width, height);

        //Play noise
        cout << '\a' << endl;

        //Update tail length score
        ++tailLen;
    }

    if (tf.fruitExists(posY, posX)) {
        //Create new snake tail node
        Node* link = newNode(posX, posY);
        pop(head);

        //Add score
        vs.visitScore(tf);

        achivementBad = vs.visit(tf);

        //Respawn fruit

        tf.generateFruit(width, height);

        //Play noise
        cout << '\a' << endl;

        //Update tail length score
        --tailLen;
    }

    //Game over logic

    //If snake goes out of bounds end game
    if (posX > width - 1 || posX < 0 || posY > height - 1 || posY < 0)
        gameState = false;

    //If snake touches tail end game (Cycles through linked list nodes to check)
    Node* current = head->next;
    while (current != nullptr) {
        if (posX == current->x && posY == current->y)
            gameState = false;
        current = current->next;
    }
}



