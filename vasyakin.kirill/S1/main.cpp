#include <iostream>
#include <string>
#include <utility>
#include "list.hpp"

int main()
{
  vasyakin::List< std::pair< std::string, vasyakin::List< int > > > sequences;
  std::string name;

  while (std::cin >> name)
  {
    vasyakin::List< int > numbers;
    int num = 0;
    vasyakin::Node< int >* last_num = nullptr;

    while (std::cin >> num)
    {
      if (last_num == nullptr)
      {
        last_num = numbers.insert(numbers.get_fake(), num);
      }
      else
      {
        last_num = numbers.insert(last_num, num);
      }
    }
    std::cin.clear();

    sequences.push_back(std::make_pair(name, std::move(numbers)));
  }

  if (sequences.begin() == sequences.end())
  {
    std::cout << "0\n";
    return 0;
  }

  auto seq_it = sequences.begin();
  std::cout << seq_it->first;
  ++seq_it;
  while (seq_it != sequences.end())
  {
    std::cout << " " << seq_it->first;
    ++seq_it;
  }
  std::cout << '\n';

  size_t max_len = 0;
  for (auto it = sequences.cbegin(); it != sequences.cend(); ++it)
  {
    size_t len = 0;
    for (auto nit = it->second.cbegin(); nit != it->second.cend(); ++nit)
    {
      ++len;
    }
    if (len > max_len)
    {
      max_len = len;
    }
  }

  return 0;
}