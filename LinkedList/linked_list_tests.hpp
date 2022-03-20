#include "./linked_list.hpp"

void linked_list_tests()
{
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "\tLinked List" << std::endl;
  std::cout << "----------------------------------------" << std::endl
            << std::endl;

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

  auto found_node = linked_list->find(10);
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
  linked_list = linked_list->sort();
  linked_list->traverse();

  std::cout << "\nConverting linked list to vector..." << std::endl;
  auto list_as_vector = linked_list->to_vector();

  std::cout << "[";
  for (auto x : list_as_vector)
    std::cout << " " << x << " ";
  std::cout << "]" << std::endl;

  std::cout << "\nPrepending value to linked list..." << std::endl;
  linked_list = linked_list->prepend(99);
  linked_list->traverse();

  std::cout << "\nTrying to remove head node..." << std::endl;
  linked_list->remove_at(0);

  std::cout << "Removing node at position 1..." << std::endl;
  linked_list->remove_at(1);
  linked_list->traverse();
}
