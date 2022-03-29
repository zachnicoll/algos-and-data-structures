#include "../linked_list.hpp"
#include "algorithm"

/**
 * https://leetcode.com/problems/reverse-linked-list/
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 * Test Cases:
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 * Input: head = [1,2]
 * Output: [2,1]
 *
 * Input: head = []
 * Output: []
 */

template <typename T>
LinkedNode<T> *reverse(LinkedNode<T> *head)
{
  if (head == nullptr)
    return nullptr;
  if (!head->next)
    return head;

  LinkedNode<T> *node = head;
  std::vector<LinkedNode<T> *> nodes;

  while (node != nullptr)
  {
    nodes.push_back(node);
    node = node->next;
  }

  int num_nodes = nodes.size();
  LinkedNode<T> *last_node = nodes[num_nodes - 1];
  node = last_node;

  for (int i = num_nodes - 1; i > 0; i--)
  {
    node->next = nodes[i - 1];
    node = node->next;
  }

  node->next = nullptr;

  return last_node;
}

int main()
{
  try
  {
    /* ----------------------------- First Test Case ---------------------------- */
    LinkedNode<int> linked_list(1);
    linked_list.append(2);
    linked_list.append(3);
    linked_list.append(4);
    linked_list.append(5);

    LinkedNode<int> *reversed_list = reverse(&linked_list);
    std::vector<int> expected = {5, 4, 3, 2, 1};
    std::vector<int> actual = reversed_list->to_vector();

    if (expected != actual)
    {
      throw "Test Case 1 did not pass!";
    }

    /* ---------------------------- Second Test Case ---------------------------- */
    LinkedNode<int> linked_list_2(1);
    linked_list_2.append(2);

    reversed_list = reverse(&linked_list_2);
    expected = {2, 1};
    actual = reversed_list->to_vector();

    if (expected != actual)
    {
      throw "Test Case 2 did not pass!";
    }

    std::cout << "All test cases passed!" << std::endl;
  }
  catch (char const *e)
  {
    std::cout << e << std::endl;
  }
}
