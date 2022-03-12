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
  static void sort(LinkedNode<T> *node, int left, int right);
  std::vector<T> to_vector();
  void traverse();
  void remove_at(int pos);

private:
  static void merge(LinkedNode<T> *node, int left, int mid, int right);
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
void LinkedNode<T>::sort(LinkedNode<T> *node, int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2;

    sort(node, left, mid);
    sort(node, mid + 1, right);

    LinkedNode::merge(node, left, mid, right);
  }
}

template <typename T>
void LinkedNode<T>::merge(LinkedNode<T> *node, int left, int mid, int right)
{
  int l1 = mid - left + 1;
  int l2 = right - mid;
  LinkedNode<T> *L = nullptr;
  LinkedNode<T> *R = nullptr;

  for (int i = 0; i < l1; i++)
  {
    if (L == nullptr)
      L = new LinkedNode(node->at(i)->value);
    else
      L->append(node->at(i)->value);
  }

  node->traverse();

  for (int i = 0; i < l2; i++)
  {
    if (R == nullptr)
      R = new LinkedNode(node->at(mid + i + 1)->value);
    else
      R->append(node->at(mid + i + 1)->value);
  }

  int i = 0, j = 0, k = left;

  while (i < l1 && j < l2)
  {
    LinkedNode *right_node = R->at(j);
    LinkedNode *left_node = L->at(i);

    if (left_node->value <= right_node->value)
    {
      node->at(k)->value = left_node->value;
      i++;
    }
    else
    {
      node->at(k)->value = right_node->value;
      j++;
    }

    k++;
  }

  while (i < l1)
  {
    node->at(k)->value = L->at(i)->value;
    i++;
    k++;
  }

  while (j < l2)
  {
    node->at(k)->value = R->at(j)->value;
    j++;
    k++;
  }
}