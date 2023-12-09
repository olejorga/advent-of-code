#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <regex>

#include "../lib/lib.hpp"

int main(int argc, char const *argv[])
{
  std::vector<std::string> rows = lib::read(argv[1]);

  int answer = 0;

  for (const auto &row : rows) 
  {
    std::string body = lib::split(row, ':')[1];
    std::vector<std::string> columns = lib::split(body, '|');

    std::vector<std::string> cardNumbers = lib::find(std::regex("\\b\\d+\\b"), columns[0]);
    std::vector<std::string> myNumbers = lib::find(std::regex("\\b\\d+\\b"), columns[1]);

    int matches = 0;

    for (const auto &cardNum : cardNumbers) 
    {
      for (const auto &myNum : myNumbers)
      {
        if (myNum == cardNum) matches++;
      }
    }

    int points = 0;

    for (size_t i = 0; i < matches; i++)
    {
      if (points == 0) points += 1;
      else points *= 2;
    }

    answer += points;
  }

  std::cout << answer << std::endl;

  return 0;
}
