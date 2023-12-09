#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../lib/lib.hpp"

std::vector<char> extractDigits(const std::string &input) {
  std::vector<char> digits;

  for (const auto ch : input) {
    if (isdigit(ch)) digits.push_back(ch);
  }

  return digits;
}

int main(int argc, char const *argv[])
{
  int answer = 0;

  std::vector<std::string> rows = lib::read(argv[1]);

  for (const auto &row : rows)
  {
    std::vector<char> digits = extractDigits(row);

    char first = digits.front();
    char last = digits.back();

    std::string number = std::string(1, first) + std::string(1, last);

    answer += std::stoi(number);
  }

  std::cout << answer << std::endl;
  
  return 0;
}
