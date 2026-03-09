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

  return 0;
}