#include "../aoc.h"

struct Instruction {
  std::string operation;
  int argument;
  bool visited = false;

  Instruction(std::string &input) {
    operation = input.substr(0, 3);
    input.erase(0, 4);
    argument = std::stoi(input);
  }
};

class Program {
private:
  std::vector<Instruction> items;
  int lastChangeIdx = -1;

  void resetVisitedState() {
    for (Instruction &i : items) { i.visited = false; }
  }

public:
  Program(std::ifstream input) {
    if (input.is_open()) {
      std::string line;
      while(getline(input, line)) { items.emplace_back(Instruction(line)); }
      input.close();
    }
  }

  int execute() {
    int acc = 0;
    int idx = 0;

    while (!items[idx].visited && idx < items.size()) {
      items[idx].visited = true;
      if (items[idx].operation == "acc") { acc += items[idx].argument; }
      if (items[idx].operation == "jmp") { idx += items[idx].argument - 1; }
      ++idx;
    }

    this->resetVisitedState();
    return acc;
  }

  bool hasInfiniteLoop() {
    int idx = 0;

    while (idx < items.size() && !items[idx].visited) {
      items[idx].visited = true;
      if (items[idx].operation == "jmp") { idx += items[idx].argument - 1; }
      ++idx;
    }

    this->resetVisitedState();
    return idx != items.size();
  }

  void changeNextOp() {
    // revert back previous change if exists
    if (lastChangeIdx > -1) {
      items[lastChangeIdx].operation = items[lastChangeIdx].operation == "jmp" ? "nop" : "jmp";
    }

    // find next qualifying op and change that value
    int idx = lastChangeIdx < 0 ? 0 : lastChangeIdx + 1;
    while (idx < items.size()) {
      if (items[idx].operation == "jmp" || items[idx].operation == "nop") break;
      ++idx;
    }

    items[idx].operation = items[idx].operation == "jmp" ? "nop" : "jmp";
    lastChangeIdx = idx;
  }
};

int main() {
  Program program(std::ifstream("input.txt", std::ios::in));

  while (program.hasInfiniteLoop()) { program.changeNextOp(); }

  std::cout << "Part 2: " << program.execute() << std::endl;

  return 0;
}
