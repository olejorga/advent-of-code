#pragma once

#include <string>
#include <vector>
#include <regex>

namespace lib {
  std::vector<std::string> read(std::string filepath);

  std::vector<std::string> find(std::regex pattern, std::string source);
}
