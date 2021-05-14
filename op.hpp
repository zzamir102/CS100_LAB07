#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

using namespace std;

class Op : public Base {
    public:
        Op(double value) : Base() { 
		val = value;
	}
        virtual double evaluate() { return val; }
        virtual std::string stringify() {
		string str;
		str = to_string(val);
		return str; 
	}
    private:
	double val;
};

#endif //__OP_HPP__
