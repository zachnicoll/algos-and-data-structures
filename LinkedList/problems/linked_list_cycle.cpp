#include "../linked_list.hpp"

/**
 * https://leetcode.com/problems/linked-list-cycle/
 *
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer.
 * Internally, pos is used to denote the index of the node that tail's next pointer
 * is connected to. Note that pos is not passed as a parameter.
 * Return true if there is a cycle in the linked list. Otherwise, return false.

 * Test Cases:

  Input: head = [3,2,0,-4], pos = 1
  Output: true
  Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

  Input: head = [1,2], pos = 0
  Output: true
  Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

  Input: head = [1], pos = -1
  Output: false
  Explanation: There is no cycle in the linked list.
*/

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