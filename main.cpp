#include <iostream>
#include "./LinkedList/linked_list_tests.hpp"

int main()
{
  try
  {
    linked_list_tests();
  }
  catch (NotEqualExcpetion e)
  {
    std::cout << "Linked List tests failed!\n"
              << e.what() << std::endl;
  }
}