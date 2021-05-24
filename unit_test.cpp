#include "gtest/gtest.h"
#include "rand.hpp"
#include "add.hpp"
#include "op.hpp"
#include "div.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "mult.hpp"
#include "factory.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}	

//---------------Multiplication--------------

TEST(Base_Mult, Multiplication) {
	Factory test;
	char* args[] = {"n","5", "*", "7"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 35);
	delete op;
}

TEST(Zero_Mult, Multiplication) {
	Factory test;
	char* args[] = {"n","0", "*", "7"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	delete op;
}


TEST(Negative_Mult, Multiplication) {
	Factory test;
	char* args[] = {"n","5", "*", "-7"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -35);
	delete op;
}

//--------------------------------------------

//---------------Division---------------------


TEST(Base_Div, Division) {
	Factory test;
	char* args[] = {"n","4", "/", "8"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), .5);
	delete op;
}

TEST(Zero_Div, Division) {
	Factory test;
	char* args[] = {"n","0", "/", "8"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 0);
	delete op;
}

TEST(Negative_Div, Division) {
	Factory test;
	char* args[] = {"n","-4", "/", "8"};
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -.5);
	delete op;
}

//--------------------------------------------

//---------------Addition---------------------


TEST((Addition, Base_Add) {
	Factory test;
	char* args[] = {"n", "5", "+", "7"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 12);
	delete op;
}

TEST(Addition, Zero_Add) {
	Factory test;
	char* args[] = {"n", "0", "+", "7"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 7);
	delete op;
}

TEST(Addition, Negative_Add) {
	Factory test;
	char* args[] = {"n", "5", "+", "-7"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -2);
	delete op;
}

//--------------------------------------------


//---------------Subtraction------------------

TEST(Subtraction, Base_Sub) {
	Factory test;
	char* args[] = {"n", "9", "-", "7"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 2);
	delete op;
}

TEST(Subtraction, Zero_Sub) {
	Factory test;
	char* args[] = {"n", "5", "-", "0"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(),5);
	delete op;
}

TEST(Subtraction, Negative_Sub) {
	Factory test;
	char* args[] = {"n", "5", "-", "7"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -2);
	delete op;
}

//--------------------------------------------

//---------------Power------------------------

TEST(Power, Base_Pow) {
	Factory test;
	char* args[] = {"n", "5", "**", "2"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 25);
	delete op;
}

TEST(Power, Zero_Pow) {
	Factory test;
	char* args[] = {"n", "2", "**", "0"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), 1);
	delete op;
}

TEST(Power, Negative_Pow) {
	Factory test;
	char* args[] = {"n", "-5", "**", "3"}; 
	Base* op = test.parse(args, 4);
	EXPECT_DOUBLE_EQ(op->evaluate(), -125);
	delete op;
}

//--------------------------------------------

//---------------Using Multiple op------------

TEST(ThreeOps, Mult_Add_Sub) {
	Factory test; 
	char* args[] = {"n", "2", "*", "2", "+", "2", "-", "2"};
	Base* op = test.parse(args, 8);
	EXPECT_DOUBLE_EQ(op->evaluate(), 4);
	delete op;
} 

TEST(ThreeOps, Div__Add_Sub) {
	Factory test; 
	char* args[] = {"n", "2", "/", "2", "+", "2", "-", "2"};
	Base* op = test.parse(args, 8);
	EXPECT_DOUBLE_EQ(op->evaluate(), 1);
	delete op;
} 



///--------------------------------------------




TEST(InvalidTest, OpusingString) {
	Factory test;
	char* args[] = {"n", "5",  "hello"};
	Base* op = test.parse(args, 3);
	EXPECT_TRUE(op == nullptr);
	delete op;	
}

TEST(InvalidTest, MissingOp) {
	Factory test;
	char* args[] = {"n" , "5", "1"}; 
	Base* op = test.parse(args, 3);
	EXPECT_TRUE(op == nullptr);
	delete op;
}

