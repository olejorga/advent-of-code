#include <iostream>
#include <regex>

#include "../lib/lib.hpp"

int main(int argc, char const *argv[])
{
  auto answer = 0;

  const auto maxRed = 12;
  const auto maxGreen = 13;
  const auto maxBlue = 14; 

  auto lines = lib::read(argv[1]);
  auto id = 1;
  
  for (auto line : lines)
  {
    auto body = lib::split(line, ':')[1];
    auto sets = lib::split(body, ';');

    for (auto set : sets)
    {   
      auto draws = lib::split(set, ',');
      
      auto countRed = 0;
      auto countGreen = 0;
      auto countBlue = 0;

      for (auto draw : draws)
      {
        auto color = lib::find(std::regex("\\b[[:alpha:]]+\\b"), draw)[0];
        auto count = stoi(lib::find(std::regex("\\b\\d+\\b"), draw)[0]);

        if (color == "red") countRed += count;
        if (color == "green") countGreen += count;
        if (color == "blue") countBlue += count;
      }

      if (countRed > maxRed || countGreen > maxGreen || countBlue > maxBlue) goto impossible;
    }

    answer += id;

    impossible:;

    id++;
  }

  std::cout << answer << std::endl;

  return 0;
}
