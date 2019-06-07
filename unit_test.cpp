#include "compositepattern.h"
#include "iterator.h"
#include <iostream>
#include "gtest/gtest.h"

TEST(IteratorTests, BinaryIter) {
}
TEST(IteratorTests, UnaryIter) {
}
TEST(IteratorTests, NullIter) {
}
TEST(IteratorTests, PreOrderIter) {
  Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Add* add = new Add(op3, op4); //7
	Pow* pow  = new Pow(add,op2); //49
  Root* root = new Root(sub);
  PreOrderIterator* pre_itr = new PreOrderIterator(root);
  EXPECT_EQ(pre_itr->first()->stringify(),3.000000 + 4.000000 ** 2.000000);
  EXPECT_EQ(pre_itr->next()->stringify(),3.000000 + 4.000000);
  EXPECT_EQ(pre_itr->next()->stringify(),3.000000);
  EXPECT_EQ(pre_itr->next()->stringify(),4.000000);
  EXPECT_EQ(pre_itr->next()->stringify(),2.000000);
  pre_itr->next();
  EXPECT_EQ(pre_itr->is_done(),1);

}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
