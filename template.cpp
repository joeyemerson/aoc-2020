#include "../aoc.h"

int main() {
  std::ifstream newfile("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      nums.push_back(std::stoi(line));
    }

    newfile.close();
  }

  return 0;
}