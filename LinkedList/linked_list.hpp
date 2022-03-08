#include <iostream>

template <typename T>
class LinkedNode
{
public:
  T value;
  LinkedNode<T> *next;

  LinkedNode(T val);
  LinkedNode(T val, LinkedNode *next);

  LinkedNode *insert(int pos, T val);
  LinkedNode *find(T val);
  LinkedNode *updated(int pos, T val);
  LinkedNode *sort();
  LinkedNode *merge();
  void traverse();
  void remove_at(int pos);
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