#include <iostream>

#include "base.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "add.hpp"
#include "factory.hpp"

using namespace std;

int main(int argc, char** argv) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    //std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    
    Factory test;
    Base* new_expression = test.parse(argv, argc);
    cout << new_expression->stringify() << " = " << new_expression->evaluate() << endl;
    return 0;
}
