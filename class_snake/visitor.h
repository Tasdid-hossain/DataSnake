#pragma once

#include "goodFruit.h"
#include "toxicFruit.h"
class visitor
{
private:

public:
	visitor();
	int eatenNumBad;
	int eatenNumGood;
	int scoreC;
	int visit(goodFruit gf);
	int visit(toxicFruit tf);
	int visitScore(goodFruit gf);
	int visitScore(toxicFruit tf);
};

