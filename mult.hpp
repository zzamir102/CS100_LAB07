#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "op.hpp"
#include <string>

using namespace std;

class Mult : public Base {
	public:
		Mult(Base* leftNum, Base* rightNum) : Base() {
			leftVal = leftNum->evaluate();
			rightVal = rightNum->evaluate();
		}
		
		virtual double evaluate() { 
			return (leftVal * rightVal);
		}
		
		virtual string stringify() {
			string s;
			string left = to_string(leftVal);
			string right = to_string(rightVal);
			s = "(" + left + " * " + right + ")";
			return s; 
		}
		
	private:
		double leftVal;
		double rightVal; 
}; 

#endif

