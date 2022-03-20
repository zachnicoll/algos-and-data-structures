#include <iostream>
#include <vector>

template <typename T>
class LinkedNode
{
public:
  /**
   * Value of the node (generic).
   */
  T value;

  /**
   * Pointer to next node in the Linked List.
   */
  LinkedNode<T> *next;

  /**
   * Construct a LinkedNode with the given value, and next = nullptr.
   */
  LinkedNode(T val);

  /**
   * Construct a LinkedNode with the given value and next ptr.
   */
  LinkedNode(T val, LinkedNode *next);

  /**
   * Insert a node at the given position AFTER this node (0 is the next node),
   * with the provided value.
   */
  void insert(int pos, T val);

  /**
   * Append a node to the end of this linked list.
   */
  void append(T val);

  /**
   * Preprend a node to start of this list, assuming this is the head node.
   * @returns The new head of the list
   */
  LinkedNode *prepend(T val);

  /**
   * Find the first node with a given value.
   * @returns Ptr to the first node with a given value
   */
  LinkedNode *find(T val);

  /**
   * Find the position of the first node with a given value.
   * Position refers to the number of nodes after this node, that the value occurs.
   * A positions of 0 is this node.
   * @returns Position of next node with given value
   */
  int find_position(T val);

  /**
   * Get a ptr to the node at a given position, where 0 is the current node
   * @returns Ptr to node at given position in the linked list
   */
  LinkedNode *at(int position);

  /**
   * Updates the node at a given position's value. Position refers to number of nodes
   * after this node, where 0 is this node.
   */
  void update(int pos, T val);

  /**
   * Sorts all nodes with a merge sort divide-and-conquer algorithm in O(nlog(n)) time.
   * @returns Ptr to new head of the linked list
   */
  LinkedNode<T> *sort();

  /**
   * Sorts all nodes from the current node (this), to the node with a next value of nullptr.
   * Utilizes a linear iteration approach, examining each element of the list until it's sorted.
   * Worst case: O(n^2)
   * Best case: O(n)
   */
  void sort_slow();

  /**
   * Convert the linked list into a vector of type T
   * @returns Vector containing all values of type T from the linked list
   */
  std::vector<T> to_vector();

  /**
   * Print all nodes in the linked list in order.
   */
  void traverse();

  /**
   * Delete a node at a given position after the current node, where 0 is this node.
   * This node cannot be removed, and so a minimum of pos = 1 should be passed to this function.
   */
  void remove_at(int pos);

private:
  static LinkedNode<T> *merge(LinkedNode<T> *x, LinkedNode<T> *y);
  int get_middle_node();
};

template <typename T>
LinkedNode<T>::LinkedNode(T val) : value(val), next(nullptr)
{
}

template <typename T>
LinkedNode<T>::LinkedNode(T val, LinkedNode *next) : value(val), next(next)
{
}

template <typename T>
void LinkedNode<T>::traverse()
{
  LinkedNode *node = this;

  while (node != nullptr)
  {
    std::cout << node->value << " -> ";
    node = node->next;
  }

  std::cout << "NULL" << std::endl;
}

template <typename T>
std::vector<T> LinkedNode<T>::to_vector()
{
  LinkedNode *node = this;
  std::vector<T> vec;

  while (node != nullptr)
  {
    vec.push_back(node->value);
    node = node->next;
  }

  return vec;
}

template <typename T>
void LinkedNode<T>::insert(int pos, T val)
{
  LinkedNode *node = this;

  for (int i = 0; i < pos && node->next != nullptr; i++)
  {
    node = node->next;
  }

  LinkedNode<T> *temp_node = node->next;

  node->next = new LinkedNode(val, temp_node);
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::find(T val)
{
  LinkedNode *node = this;

  while (node != nullptr)
  {
    if (node->value == val)
      break;
    node = node->next;
  }

  if (node == nullptr)
    std::cout << "Could not find a node with that value!" << std::endl;

  return node;
}

template <typename T>
int LinkedNode<T>::find_position(T val)
{
  LinkedNode *node = this;
  int pos = 0;

  while (node != nullptr)
  {
    if (node->value == val)
      break;

    node = node->next;
    pos++;
  }

  return pos;
}

template <typename T>
void LinkedNode<T>::update(int pos, T val)
{
  LinkedNode *node = this;

  while (pos > 0 && node != nullptr)
  {
    node = node->next;
    pos--;
  }

  if (node == nullptr)
    return;

  node->value = val;
}

template <typename T>
void LinkedNode<T>::append(T val)
{
  LinkedNode<T> *node = this;

  while (node->next != nullptr)
  {
    node = node->next;
  }

  node->next = new LinkedNode(val);
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::prepend(T val)
{
  return new LinkedNode(val, this);
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::at(int position)
{
  LinkedNode<T> *node = this;

  while (position > 0 && node != nullptr)
  {
    position--;
    node = node->next;
  }

  return node;
}

template <typename T>
void LinkedNode<T>::sort_slow()
{
  bool sorted = false;

  while (!sorted)
  {
    LinkedNode *node = this;
    bool local_sorted = true;

    while (node->next != nullptr)
    {
      if (node->value > node->next->value)
      {
        T temp = node->value;
        node->value = node->next->value;
        node->next->value = temp;

        local_sorted = false;
      }

      node = node->next;
    }

    sorted = local_sorted;
  }
}

template <typename T>
int LinkedNode<T>::get_middle_node()
{
  int list_length = 0;
  LinkedNode<T> *fast_ptr = this->next;

  while (fast_ptr != nullptr && fast_ptr->next != nullptr)
  {
    list_length++;
    fast_ptr = fast_ptr->next->next;
  }

  if (fast_ptr == nullptr)
    list_length++;

  return list_length / 2;
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::sort()
{
  if (this->next == nullptr)
    // List only has one node, nothing to sort
    return this;

  if (this->next->next == nullptr)
  {
    // List only has two nodes, compare & sort them
    if (this->value > this->next->value)
    {
      T temp = this->value;
      this->value = this->next->value;
      this->next->value = temp;
    }

    return this;
  }

  int middle_pos = this->get_middle_node();

  LinkedNode<T> *left_list = this;
  LinkedNode<T> *last_node_in_left_list = this->at(middle_pos - 1);

  LinkedNode<T> *right_list = last_node_in_left_list->next;

  // Break the left and right lists' connection to each other
  last_node_in_left_list->next = nullptr;

  LinkedNode<T> *merged = LinkedNode::merge(left_list->sort(), right_list->sort());
  return merged;
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::merge(LinkedNode<T> *x, LinkedNode<T> *y)
{
  LinkedNode<T> *merged = new LinkedNode(0);
  auto head = merged;

  while (x != nullptr && y != nullptr)
  {
    if (x->value <= y->value)
    {
      merged->next = x;
      x = x->next;
    }
    else
    {
      merged->next = y;
      y = y->next;
    }

    merged = merged->next;
  }

  while (x != nullptr)
  {
    merged->next = x;
    x = x->next;
    merged = merged->next;
  }

  while (y != nullptr)
  {
    merged->next = y;
    y = y->next;
    merged = merged->next;
  }

  return head->next;
}

template <typename T>
void LinkedNode<T>::remove_at(int pos)
{
  LinkedNode<T> *node = this;
  LinkedNode<T> *temp = nullptr;

  if (pos == 0)
  {
    std::cout << "\nWARNING: Attempted to remove head node, exiting LinkedNode::remove_at early.\n"
              << std::endl;
    return;
  }

  while (pos > 0 && node != nullptr)
  {
    if (pos == 1)
    {
      temp = node;
    }
    pos--;

    node = node->next;
  }

  auto temp2 = node->next;
  temp->next = temp2;

  delete node;
}
