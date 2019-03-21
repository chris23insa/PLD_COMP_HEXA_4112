#pragma once

#include <string.h>
#include <iostream>
#include "Expression.h"
#include "RightValue.h"

using namespace std;

class ExprSimple : public Expression{
	public:
		ExprSimple() {};
		virtual ~ExprSimple() {};
		string genererCodeAssembleur(map<string, pair<int, int>> *);
		string toString();
	
	protected:
		RightValue * right;
};
