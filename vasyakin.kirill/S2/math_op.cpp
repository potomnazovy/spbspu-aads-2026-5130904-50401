#include "math_op.hpp"
#include "stack.hpp"
#include <limits>
#include <cstddef>
#include <stdexcept>
#include <string>

bool vasyakin::isNumber(const std::string& s)
{
  if (s.empty())
  {
    return false;
  }

  size_t start = 0;
  
  if (s[start] == '-')
  {
    if (s.length() == 1)
    {
      return false;
    }
    ++start;
  }

  for (size_t i = start; i < s.length(); ++i)
  {
    if (!std::isdigit(static_cast< unsigned char >(s[i])))
    {
      return false;
    }
  }

  return true;
}

bool vasyakin::isOperator(const std::string& s)
{
  if (s.empty())
  {
    return false;
  }

  if (s.length() == 1 && ((s[0] == '-') || (s[0] == '+') || (s[0] == '/') || (s[0] == '*') || (s[0] == '%')))
  {
    return true;
  }
  else if (s.length() == 3)
  {
    std::string correct_str = "lcm";

    if (correct_str == s)
    {
      return true;
    }
  }
  return false;
}

int vasyakin::getPrecedence(const std::string& op)
{
  if (op == "lcm")
  {
    return 3;
  }

  if (op == "*" || op == "/" || op == "%")
  {
    return 2;
  }

  if (op == "+" || op == "-")
  {
    return 1;
  }
  return 0;  
}

long long gcd(long long a, long long b)
{
  a = std::abs(a);
  b = std::abs(b);
  while (b != 0)
  {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

long long lcm(long long a, long long b)
{
  if (a == 0 || b == 0)
  {
    throw std::runtime_error("LCM with zero is undefined");
  }
  long long g = gcd(a, b);
  long long abs_a = std::abs(a);
  long long abs_b = std::abs(b);

  if (abs_a / g > vasyakin::MAX / abs_b)
  {
    throw std::overflow_error("LCM overflow");
  }
  return (abs_a / g) * abs_b;
}

long long sum(long long a, long long b)
{
  if (b > 0 && a > vasyakin::MAX - b)
  {
    throw std::overflow_error("Sum overflow");
  }
  else if (b < 0 && a < vasyakin::MIN - b)
  {
    throw std::overflow_error("Sum underflow");
  }
  return a + b;
}

long long subtract(long long a, long long b)
{
  if (b > 0 && a < vasyakin::MIN + b)
  {
    throw std::overflow_error("Subtract underflow");
  }
  else if (b < 0 && a > vasyakin::MAX + b)
  {
    throw std::overflow_error("Subtract overflow");
  }
  return a - b;
}

long long multiply(long long a, long long b)
{
  if (a == 0 || b == 0)
  {
    return 0;
  }

  if (a > 0)
  {
    if (b > 0 && a > vasyakin::MAX / b)
    {
      throw std::overflow_error("Mult overflow");
    }
    else if (b < 0 && b < vasyakin::MIN / a)
    {
      throw std::overflow_error("Mult underflow");
    }
  }
  else
  {
    if (b > 0 && a < vasyakin::MIN / b)
    {
      throw std::overflow_error("Mult underflow");
    }
    else if (b < 0 && a < vasyakin::MAX / b)
    {
      throw std::overflow_error("Mult overflow");
    }
  }
  return a * b;
}

long long divide(long long a, long long b)
{
  if (b == 0)
  {
    throw std::runtime_error("Division by zero");
  }

  if (a == vasyakin::MIN && b == -1)
  {
    throw std::overflow_error("Division overflow");
  }
  return a / b;
}

long long mod(long long a, long long b)
{
  if (b == 0)
  {
    throw std::runtime_error("Division by zero");
  }
  else
  {
    return (a % b + b) % b;
  }
}

long long vasyakin::calculate(long long a, long long b, const std::string& op)
{
  if (op == "+")
  {
    return sum(a, b);
  }
  if (op == "-")
  {
    return subtract(a, b);
  }
  if (op == "*")
  {
    return multiply(a, b);
  }
  if (op == "/")
  {
    return divide(a, b);
  }
  if (op == "%")
  {
    return mod(a, b);
  }
  if (op == "lcm")
  {
    return lcm(a, b);
  }
  throw std::runtime_error("Unknown operator: " + op);
}