#include <iostream>
#include "./LinkedList/linked_list.hpp"

int main()
{

  LinkedNode<int> linked_list(10);

  linked_list.insert(0, 32);
  linked_list.insert(0, 24);
  linked_list.insert(10, 200);
  linked_list.insert(1, 2000);

  std::cout << "Linked List takes the form: " << std::endl;
  linked_list.traverse();

  auto found_node = linked_list.find(24);
  std::cout << "\nFound node with value: " << found_node->value << std::endl;

  auto found_node_pos = linked_list.find_position(found_node->value);
  std::cout << "Node exists at position: " << found_node_pos << std::endl;

  std::cout << "\nUpdating node at position " << found_node_pos << "..." << std::endl;
  linked_list.update(found_node_pos, 999);
  linked_list.traverse();

  auto list_as_vector = linked_list.to_vector();
}