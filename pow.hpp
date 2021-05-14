#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <string>
#include <math.h>

using namespace std;

class Pow : public Base {
   public:
	Pow(Base* leftChild, Base* rightChild) : Base() {
		leftVal = leftChild->evaluate();
		rightVal = rightChild->evaluate();
	}		
	
	virtual double evaluate() {
		return(pow(leftVal, rightVal));
	}

	virtual string stringify() {
		string str;
		string left = to_string(leftVal);
		string right = to_string(rightVal);
		str = "(" + left + " ** " + right + ")";
		return str;
	}

   private:
	double leftVal;
	double rightVal;

};

#endif
