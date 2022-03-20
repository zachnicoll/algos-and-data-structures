#include "./linked_list.hpp"

void linked_list_tests()
{
  LinkedNode<int> *linked_list = new LinkedNode(10);

  linked_list->append(9);
  linked_list->append(8);
  linked_list->append(7);
  linked_list->append(1);
  linked_list->append(6);
  linked_list->append(5);
  linked_list->append(4);
  linked_list->append(3);
  linked_list->append(2);
  linked_list->append(2);

  std::cout << "Linked List takes the form: " << std::endl;
  linked_list->traverse();

  auto found_node = linked_list->find(6);
  std::cout << "\nFound node with value: " << found_node->value << std::endl;

  auto found_node_pos = linked_list->find_position(found_node->value);
  std::cout << "Node exists at position: " << found_node_pos << std::endl;

  std::cout << "\nUpdating node at position " << found_node_pos << "..." << std::endl;
  linked_list->update(found_node_pos, 5);
  linked_list->traverse();

  int new_node_val = 20;
  std::cout << "\nAppending node with value " << new_node_val << std::endl;
  linked_list->append(new_node_val);
  linked_list->traverse();

  std::cout << "\nSorting linked list with merge sort..." << std::endl;
  linked_list = linked_list->sort(); // Not sure how to maintain the original objects pointer, so just re-assign to the merged ptr
  linked_list->traverse();

  std::cout << "\nConverting linked list to vector..." << std::endl;
  auto list_as_vector = linked_list->to_vector();

  std::cout << "[";
  for (auto x : list_as_vector)
    std::cout << " " << x << " ";
  std::cout << "]" << std::endl;
}
