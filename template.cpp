#include "../aoc.h"

int main() {
  std::ifstream newfile("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      // do something here
    }

    newfile.close();
  }

  return 0;
}
