#include "Affectation.h"

Affectation::Affectation(RightValue *r, LeftValue *l, string t) {
	right=r;
	left=l;
	type=convertTypeToInt(t);
 	
}

Affectation::~Affectation()
{
	
}

RightValue *Affectation::getRight() {
    return right;
}

LeftValue *Affectation::getLeft() {
    return left;
}

int Affectation::getType(){
	return type;
}

void Affectation::setType(int t){
	type = t;
}

int Affectation::convertTypeToInt(string nom) {
	type_e t = VIDE;
	if (nom == "") t = VIDE;
	else if (nom == "int") t = INT;
	return t; 
}