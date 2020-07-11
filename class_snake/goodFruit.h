#pragma once

#include "fruit.h"

class goodFruit : public fruit
{
private:

public:
	goodFruit();
	//int x;
	//int y;
	//void generateToxicFruit(int width, int height);
	//bool toxicFruitExists(int i, int j);

	void generateFruit(int width, int height);
	bool fruitExists(int i, int j);
	//int scored();
};

