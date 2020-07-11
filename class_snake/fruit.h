#pragma once
class fruit
{
private:

public:
	int numEaten;
	int score;

protected:
	fruit();
	int x;
	int y;
	
	
	virtual void generateFruit(int width, int height) = 0;
	virtual bool fruitExists(int i, int j) = 0;
	virtual ~fruit();
};

