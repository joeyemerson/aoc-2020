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

  int a, b, c;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      for (int k = j + 1; k < nums.size(); k++) {
        a = nums[i];
        b = nums[j];
        c = nums[k];

        if (a + b + c == 2020) {
          std::cout << a << " * " << b << " * " << c << " = " << a * b * c << std::endl;
          break;
        }
      }
    }
  }

  return 0;
}