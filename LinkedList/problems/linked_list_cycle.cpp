#include "../linked_list.hpp"
#include "unordered_set"

template <typename T>
bool hasCycle(LinkedNode<T> *head)
{
  if (head == nullptr || head->next == nullptr)
    return false;

  LinkedNode<T> *slow = head;
  LinkedNode<T> *fast = head->next;

  while (fast && fast->next)
  {
    if (fast == slow)
      return true;

    slow = slow->next;
    fast = fast->next->next;
  }

  return false;
}

int main()
{
  try
  {
    /* ------------------------------- Test Case 1 ------------------------------ */
    LinkedNode<int> linked_list(1);
    linked_list.append(2);
    linked_list.append(3);
    linked_list.append(4);

    auto last_node = linked_list.at(3);
    auto second_node = linked_list.at(1);

    last_node->next = second_node;

    bool expected = true;
    bool actual = hasCycle(&linked_list);

    if (expected != actual)
    {
      throw "Test Case 1 did not pass!";
    }

    /* ------------------------------- Test Case 2 ------------------------------ */
    LinkedNode<int> linked_list_2(1);
    linked_list_2.append(2);
    linked_list_2.append(3);
    linked_list_2.append(4);

    expected = false;
    actual = hasCycle(&linked_list_2);

    if (expected != actual)
    {
      throw "Test Case 2 did not pass!";
    }

    /* ------------------------------- Test Case 3 ------------------------------ */
    LinkedNode<int> linked_list_3(1);

    expected = false;
    actual = hasCycle(&linked_list_3);

    if (expected != actual)
    {
      throw "Test Case 3 did not pass!";
    }

    /* ------------------------------- Test Case 4 ------------------------------ */
    LinkedNode<int> *linked_list_4 = nullptr;

    expected = false;
    actual = hasCycle(linked_list_4);

    if (expected != actual)
    {
      throw "Test Case 4 did not pass!";
    }

    std::cout << "All test cases passed!" << std::endl;
  }
  catch (char const *e)
  {
    std::cout << e << std::endl;
  }
}