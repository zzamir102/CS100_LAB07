#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Add : public Base {
     public:
	Add (Base* leftChild, Base* rightChild) : Base () {
		leftVal = leftChild->evaluate();
		rightVal = rightChild->evaluate();
	}

	virtual double evaluate() {
		return (leftVal+rightVal);
	}

	virtual string stringify() {
		string str;
		string left = to_string(leftVal);
		string right = to_string(rightVal);
		str = "(" + left + " + " + right + ")";
		return str;
	}

     private:
	double leftVal;
	double rightVal;
};

#endif
