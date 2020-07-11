#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "snakeClass.h"
#include "fruit.h"
#include "toxicFruit.h"
#include "BinaryTree.h"
#include <fstream>
#include <string>

using std::cout; 
using std::cin; 
using std::endl;
using std::string;

int main() {
 
  

    string mystr;
    string myString;
    BinaryTree myTree("");
    ifstream infile;

    infile.open("test.txt");

    while (infile)
    {
        infile >> myString;
        myTree.insert(myString, myTree.root);
    }

    ofstream outFile;

    outFile.open("index.txt");

   
      cout << "Score gained by thre players who played the game" << endl;
    myTree.display(myTree.root, outFile);

    outFile.close();

    //Run all the code
    do {

        snakeClass snake;
        snake.init();
        while (snake.gameState) {

            snake.draw();
            snake.input();
            snake.logic();



        }


        std::ofstream outfile;
        // Write to the file
        outfile.open("test.txt", std::ios_base::app); // append instead of overwrite
        outfile << snake.name << "=" << snake.score << endl;

        // Close the file
        outfile.close();

        cout << "\n";
        cout << "Type no to exit the game or press any letter to contunue the game: ";
        cin >> mystr;
        cout << "\n\n";
    } while (mystr != "no");
 

    system("pause");
    return 0;
}