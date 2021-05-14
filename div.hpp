#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Div : public Base {
	public:
		Div(Base* leftNum, Base* rightNum) : Base() { 
			rightVal = rightNum->evaluate();
			leftVal = leftNum->evaluate();
		}
		
		virtual double evaluate() { 
			return (leftVal / rightVal);
		}
		
		virtual string stringify() { 
			string s;
			string left = to_string(leftVal);
			string right = to_string(rightVal); 
			s = "(" + left + " / " + right + ")"; 
			return s;
		}

	private:
		double leftVal;
		double rightVal;
};

#endif
