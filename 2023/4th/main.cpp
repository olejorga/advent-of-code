#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

std::vector<std::string> readLines(const std::string &filepath)
{
  std::vector<std::string> lines;
  std::ifstream file(filepath);

  if (file.is_open()) {
    std::string line;

    while (std::getline(file, line)) {
      lines.push_back(line);
    }

    file.close();
  }

  return lines;
}

std::vector<int> extractNumbers(const std::string &input) {
  std::vector<int> numbers;
  std::istringstream iss(input);
  std::string token;

  while (iss >> token) {
    bool isNumber = true;
    
    for (char c : token) {
      if (!std::isdigit(c)) {
        isNumber = false;
        break;
      }
    }

    if (isNumber) {
      numbers.push_back(std::stoi(token));
    }
  }

  return numbers;
}

std::vector<std::string> split(const std::string &input, char delimiter) 
{
  std::vector<std::string> result;
  std::istringstream stream(input);
  std::string token;

  while (std::getline(stream, token, delimiter)) {
    result.push_back(token);
  }

  return result;
}

int main(int argc, char const *argv[])
{
  std::vector<std::string> rows = readLines(argv[1]);

  int answer = 0;

  for (const auto &row : rows) 
  {
    std::vector<std::string> columns = split(row, '|');

    std::vector<int> cardNumbers = extractNumbers(columns[0]);
    std::vector<int> myNumbers = extractNumbers(columns[1]);

    int matches = 0;

    for (int cardNum : cardNumbers) 
    {
      for (int myNum : myNumbers)
      {
        if (myNum == cardNum)
        {
          matches++;
        }
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
