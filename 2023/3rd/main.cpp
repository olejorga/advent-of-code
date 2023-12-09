#include <iostream>
#include <regex>
#include <string>

#include "../lib/lib.hpp"

bool isSymbol(char ch) {
  return !std::isalnum(ch) && ch != '.' && ch != '\0';
}

int main(int argc, char const *argv[])
{
  auto answer = 0;

  auto matrix = lib::read(argv[1]);

  for (size_t row = 0; row < matrix.size(); row++)
  {
    auto symbol = false;
    auto part = std::string();

    for (size_t col = 0; col < matrix[row].size(); col++)
    {
      auto c = matrix[row][col];

      if (!isdigit(c)) continue;

      auto t = (row == 0) ? '\0' : matrix[row - 1][col];
      auto b = (row == (matrix.size() - 1)) ? '\0' : matrix[row + 1][col];

      auto l = (col == 0) ? '\0' : matrix[row][col - 1];
      auto r = (col == (matrix[row].size() - 1)) ? '\0' : matrix[row][col + 1];

      auto tl = (row == 0 || col == 0) ? '\0' : matrix[row - 1][col - 1];
      auto tr = (row == 0 || col == (matrix[row].size() - 1)) ? '\0' : matrix[row - 1][col + 1];

      auto bl = (row == (matrix.size() - 1) || col == 0) ? '\0' : matrix[row + 1][col - 1];
      auto br = (row == (matrix.size() - 1) || col == (matrix[row].size() - 1)) ? '\0' : matrix[row + 1][col + 1];

      part += c;

      if (
        isSymbol(t) ||
        isSymbol(b) ||
        isSymbol(l) ||
        isSymbol(r) ||
        isSymbol(tl) ||
        isSymbol(tr) ||
        isSymbol(bl) ||
        isSymbol(br)
      ) symbol = true;

      if (isdigit(r)) continue;

      if (symbol) answer += std::stoi(part);

      part = "";
      symbol = false;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
