#include "visitor.h"
#include "goodFruit.h"
#include "toxicFruit.h"

visitor::visitor()
{
}

int visitor::visit(toxicFruit tf) {
	eatenNumGood++;
	return eatenNumGood;
}

int visitor::visit(goodFruit tf) {
	eatenNumBad++;
	return eatenNumBad;
}

int visitor::visitScore(goodFruit gf) {
	scoreC += 100;
	return scoreC;
}

int visitor::visitScore(toxicFruit gf) {
	scoreC -= 100;
	return scoreC;
}