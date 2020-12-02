#include "../includes.h"

int main() {
  std::fstream newfile;
  std::vector<int> nums;

  newfile.open("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      nums.push_back(std::stoi(line));
    }

    newfile.close();
  }

  return 0;
}