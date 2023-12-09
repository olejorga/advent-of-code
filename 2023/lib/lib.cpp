#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>
#include <vector>

namespace lib {
  std::vector<std::string> read(std::string filepath) 
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

  std::vector<std::string> find(std::regex pattern, std::string source)
  {
    std::vector<std::string> matches;

    std::sregex_iterator iter(source.begin(), source.end(), pattern);
    std::sregex_iterator end;

    while (iter != end) {
      matches.push_back((*iter)[0]);
      ++iter;
    }

    return matches;
  }
}
