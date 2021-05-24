#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "add.hpp"
#include <string>

using namespace std;

class Factory {

public:

  Base* parse(char** input, int length) {
	int i = 0;
	Base* left_op  = nullptr;
	string temp = "";
	while(i < length) {
		if (left_op  == nullptr) {
			int num = stod(input[++i]);
			left_op = new Op(num);
			++i;
			temp = string(input[i]);
		}
		temp = string(input[i]);
		if (temp == "+") {
			int num2 = stod(input[++i]);
			left_op = new Add(left_op, new Op(num2));
		}
		else if (temp == "-") {
			int num2 = stod(input[++i]);
			left_op = new Sub(left_op, new Op(num2));
		}
		else if(temp == "/") {
			int num2 = stod(input[++i]);
			left_op = new Div(left_op, new Op(num2));
		}
		else if (temp == "*") {
			int num2 = stod(input[++i]);
			left_op = new Mult(left_op, new Op(num2));
		}
		else if (temp == "**") {
			int num2 = stod(input[++i]);
			left_op = new Pow(left_op, new Op(num2));
		}
		else {
			cout << "ERROR!" << endl;
			delete left_op; 
			return nullptr;
		}
		++i;
	}
	return left_op;
  }

}; 
				
#endif 
