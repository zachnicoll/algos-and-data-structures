#include "../linked_list.hpp"


/**
 * https://leetcode.com/problems/reorder-list/
 * You are given the head of a singly linked-list. The list can be represented as:
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 */

template <typename T>
void reorderList(LinkedNode<T> *head)
{
  if (!head) return;

  if (head->next) {
	std::vector<LinkedNode<T>*> vec_ptrs;
	std::vector<LinkedNode<T>*> ordered_ptrs;

	LinkedNode<T>* node = head;

	while (node)
	{
		vec_ptrs.push_back(node);
		auto temp = node->next;
		node->next = nullptr;
		node = temp;
		
	}

	int vec_size = vec_ptrs.size();
	for (int i = 0; i < vec_size; i++) {
		int end_index = vec_size - 1 - i;
		if (i > end_index) break;
		
		ordered_ptrs.push_back(vec_ptrs[i]);
		
		auto end_ptr = vec_ptrs[end_index];
		if (i != end_index)
 			ordered_ptrs.push_back(end_ptr);
	}
	

	LinkedNode<T>* new_head = nullptr;
	LinkedNode<T>* temp = nullptr;
	for (int i = 0; i < ordered_ptrs.size(); i++) {
		if (!new_head) {
	            	new_head = ordered_ptrs[i];
	    		temp = new_head;
          	} else {
            		temp->next = ordered_ptrs[i];
	    		temp = temp->next;
          	}
        }

	head = new_head;
  }
}

int main()
{
  try
  {
    /* ------------------------------- Test Case 1 ------------------------------ */
    LinkedNode<int> list_1(1);
    list_1.append(2);
    list_1.append(3);
    list_1.append(4);
    
    reorderList(&list_1);
    std::vector<int> expected = {1,4,2,3};
    std::vector<int> actual = list_1.to_vector();

    if (expected != actual) {
    	throw "Test 1 failed!";
    }

    LinkedNode<int> list_2(1);
    list_2.append(2);
    list_2.append(3);
    list_2.append(4);
    list_2.append(5);

    reorderList(&list_2);
    expected = {1,5,2,4,3};
    actual = list_2.to_vector();

    if (expected != actual) {
    	throw "Test 2 failed!";
    }
    
    std::cout<< "All test cases passed!" << std::endl;
  }
  catch (const char *e)
  {
    std::cout << e << std::endl;
  }
}
