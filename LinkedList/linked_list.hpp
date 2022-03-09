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

  LinkedNode *find(T val);
  int find_position(T val);

  LinkedNode *update(int pos, T val);
  LinkedNode *sort();
  LinkedNode *merge();
  std::vector<T> to_vector();
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