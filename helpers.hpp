#include <iostream>

class NotEqualExcpetion : public std::exception
{
public:
  explicit NotEqualExcpetion(const char *message)
      : msg_(message) {}

  explicit NotEqualExcpetion(const std::string &message)
      : msg_(message) {}

  virtual ~NotEqualExcpetion() noexcept {}

  virtual const char *what() const noexcept
  {
    return msg_.c_str();
  }

protected:
  /** Error message.
   */
  std::string msg_;
};

template <class T>
void assert_equal(T *a, T *b)
{
  if (*a != *b)
  {
    throw NotEqualExcpetion("Assertion between two values failed!");
  }
}