#include <iostream>
#include "./LinkedList/linked_list.hpp"

int main()
{

  LinkedNode<int> linked_list(10);

  linked_list.insert(0, 32);
  linked_list.insert(0, 24);
  linked_list.insert(10, 200);
  linked_list.insert(1, 2000);

  linked_list.traverse();
}