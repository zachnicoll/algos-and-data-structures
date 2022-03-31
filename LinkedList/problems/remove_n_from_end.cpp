#include "../linked_list.hpp"

/**
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given the head of a linked list,
 * remove the nth node from the end of the list and return its head.
 *
 * Test cases:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    Input: head = [1], n = 1
    Output: []

    Input: head = [1,2], n = 1
    Output: [1]
  */

template <typename T>
LinkedNode<T> *removeNthFromEnd(LinkedNode<T> *head, int n)
{
  if (!head || !head->next)
    return nullptr;

  LinkedNode<T> *fast = head;
  LinkedNode<T> *slow = head;

  while (fast && fast->next)
  {
    if (n == 0)
    {
      slow = slow->next;
    }
    else
    {
      n--;
    }

    fast = fast->next;
  }

  if (n > 0)
  {
    return head->next;
  }
  else
  {
    auto temp = slow->next->next;
    slow->next = temp;

    return head;
  }
}

int main()
{
  try
  {
    /* ------------------------------- Test Case 1 ------------------------------ */
    LinkedNode<int> linked_list(5);
    auto list_ptr = linked_list.prepend(4);
    list_ptr = list_ptr->prepend(3);
    list_ptr = list_ptr->prepend(2);
    list_ptr = list_ptr->prepend(1);

    int n = 2;

    auto list_with_removed_node = removeNthFromEnd(list_ptr, n);

    std::vector<int> expected = {1, 2, 3, 5};
    auto actual = list_with_removed_node->to_vector();

    if (expected != actual)
      throw "Test Case 1 did not pass!";

    /* ------------------------------- Test Case 2 ------------------------------ */
    LinkedNode<int> linked_list_2(1);
    int n_2 = 1;

    auto actual_2 = removeNthFromEnd(&linked_list_2, n_2);

    LinkedNode<int> *expected_2 = nullptr;

    if (expected_2 != actual_2)
      throw "Test Case 2 did not pass!";

    /* ------------------------------- Test Case 3 ------------------------------ */
    LinkedNode<int> linked_list_3(1);
    linked_list_3.append(2);
    int n_3 = 1;

    list_with_removed_node = removeNthFromEnd(&linked_list_3, n_3);

    auto actual_3 = list_with_removed_node->to_vector();
    std::vector<int> expected_3 = {1};

    if (expected_3 != actual_3)
      throw "Test Case 3 did not pass!";

    /* ------------------------------- Test Case 4 ------------------------------ */
    LinkedNode<int> linked_list_4(1);
    linked_list_4.append(2);
    int n_4 = 2;

    list_with_removed_node = removeNthFromEnd(&linked_list_4, n_4);

    auto actual_4 = list_with_removed_node->to_vector();
    std::vector<int> expected_4 = {2};

    if (expected_4 != actual_4)
      throw "Test Case 4 did not pass!";

    std::cout << "All test cases passed!" << std::endl;
  }
  catch (const char *e)
  {
    std::cout << e << std::endl;
  }
}
