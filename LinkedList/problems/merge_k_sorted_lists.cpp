#include "../linked_list.hpp"
#include <vector>

/**
 * https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 * Test Cases:

  Input: lists = [[1,4,5],[1,3,4],[2,6]]
  Output: [1,1,2,3,4,4,5,6]
  Explanation: The linked-lists are:
  [
    1->4->5,
    1->3->4,
    2->6
  ]
  merging them into one sorted list:
  1->1->2->3->4->4->5->6

  Input: lists = []
  Output: []

  Input: lists = [[]]
  Output: []
 */

template <typename T>
LinkedNode<T> *merge(LinkedNode<T> *x, LinkedNode<T> *y)
{
  if (!x)
    return y;
  else if (!y)
    return x;

  if (x->value <= y->value)
  {
    x->next = merge(x->next, y);
    return x;
  }
  else
  {
    y->next = merge(x, y->next);
    return y;
  }
}

template <typename T>
LinkedNode<T> *mergeKLists(std::vector<LinkedNode<T> *> &lists)
{
  int num_lists = lists.size();

  if (num_lists == 0)
    return nullptr;

  if (num_lists == 1)
    return lists[0];

  LinkedNode<T> *merged_list = nullptr;

  for (int i = 0; i < num_lists; i++)
  {
    if (i == 0)
    {
      merged_list = merge(lists[i], lists[i + 1]);
      i++;
    }
    else
    {
      merged_list = merge(merged_list, lists[i]);
    }
  }

  return merged_list;
}

int main()
{
  try
  {
    /* ------------------------------- Test Case 1 ------------------------------ */
    LinkedNode<int> *list1 = new LinkedNode(5);
    list1 = list1->prepend(4);
    list1 = list1->prepend(1);

    LinkedNode<int> *list2 = new LinkedNode(4);
    list2 = list2->prepend(3);
    list2 = list2->prepend(1);

    LinkedNode<int> *list3 = new LinkedNode(6);
    list3 = list3->prepend(2);

    std::vector<LinkedNode<int> *> lists = {list1, list2, list3};

    LinkedNode<int> *merged_list = mergeKLists<int>(lists);

    std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};
    auto actual = merged_list->to_vector();

    if (expected != actual)
      throw "Test Case 1 did not pass!";

    /* ------------------------------- Test Case 2 ------------------------------ */
    std::vector<LinkedNode<int> *> lists_2 = {};
    LinkedNode<int> *expected_2 = nullptr;
    auto actual_2 = mergeKLists<int>(lists_2);

    if (expected_2 != actual_2)
      throw "Test Case 2 did not pass!";

    /* ------------------------------- Test Case 3 ------------------------------ */
    std::vector<LinkedNode<int> *> lists_3 = {{}};
    LinkedNode<int> *expected_3 = nullptr;
    auto actual_3 = mergeKLists<int>(lists_3);

    if (expected_3 != actual_3)
      throw "Test Case 3 did not pass!";

    /* ------------------------------- Test Case 4 ------------------------------ */
    std::vector<LinkedNode<int> *> lists_4 = {{}, {}, {}, {}, {}, {}, {}};
    LinkedNode<int> *expected_4 = nullptr;
    auto actual_4 = mergeKLists<int>(lists_4);

    if (expected_4 != actual_4)
      throw "Test Case 4 did not pass!";

    std::cout << "All test cases passed!" << std::endl;
  }
  catch (const char *e)
  {
    std::cout << e << std::endl;
  }
}