#include <iostream>
#include <vector>

template <typename T>
class LinkedNode
{
public:
  T value;
  LinkedNode<T> *next;

  LinkedNode(T val);
  LinkedNode(T val, LinkedNode *next);

  LinkedNode *insert(int pos, T val);
  LinkedNode *append(T val);

  LinkedNode *find(T val);
  LinkedNode *at(int position);
  int find_position(T val);

  LinkedNode *update(int pos, T val);
  LinkedNode<T> *sort();

  /**
   * Sorts all nodes from the current node (this), to the node with a next value of nullptr.
   * Utilizes a linear iteration approach, examining each element of the list until it's sorted.
   * Worst case: O(n^2)
   * Best case: O(n)
   */
  void sort_linear();

  std::vector<T> to_vector();
  void traverse();
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
LinkedNode<T> *LinkedNode<T>::insert(int pos, T val)
{
  LinkedNode *node = this;

  for (int i = 0; i < pos && node->next != nullptr; i++)
  {
    node = node->next;
  }

  LinkedNode<T> *temp_node = node->next;

  node->next = new LinkedNode(val, temp_node);

  return node->next;
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
LinkedNode<T> *LinkedNode<T>::update(int pos, T val)
{
  LinkedNode *node = this;

  while (pos > 0 && node != nullptr)
  {
    node = node->next;
    pos--;
  }

  if (node == nullptr)
    return nullptr;

  node->value = val;
  return node;
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::append(T val)
{
  LinkedNode<T> *node = this;

  while (node->next != nullptr)
  {
    node = node->next;
  }

  LinkedNode *new_node = new LinkedNode(val);
  node->next = new_node;

  return new_node;
}

template <typename T>
LinkedNode<T> *LinkedNode<T>::at(int position)
{
  LinkedNode<T> *node = this;
  int curr_pos = 0;

  while (curr_pos < position && node != nullptr)
  {
    curr_pos++;
    node = node->next;
  }

  return node;
}

template <typename T>
void LinkedNode<T>::sort_linear()
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
  LinkedNode<T> *node = this;

  while (node != nullptr)
  {
    list_length++;
    node = node->next;
  }

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
