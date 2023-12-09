#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

#include "../lib/lib.hpp"

int main(int argc, char const *argv[])
{
  int answer = 0;

  std::vector<std::string> rows = lib::read(argv[1]);

  std::map<std::string, std::string> conversion = {
    { "one", "1" }, { "two", "2" }, { "three", "3" },
    { "four", "4" }, { "five", "5" }, { "six", "6" },
    { "seven", "7" }, { "eight", "8" }, { "nine", "9" },
  };

  for (const auto &row : rows)
  {
    std::vector<std::string> digits = lib::find(std::regex("(\\d|one|two|three|four|five|six|seven|eight|nine)"), row);

    std::string first = digits.front();
    std::string last = digits.back();

    first = isdigit(first[0]) ? first : conversion[first];
    last = isdigit(last[0]) ? last : conversion[last];

    std::string number = first + last;

    std::cout << number << " --- " << row <<  std::endl;

    answer += std::stoi(number);
  }

  std::cout << answer << std::endl;
  
  return 0;
}
