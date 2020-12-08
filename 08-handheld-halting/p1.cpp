#include "../aoc.h"

struct Instruction {
  std::string operation;
  int argument;
  bool visited = false;

  void print() {
    std::cout << "OP: " << operation << ", ARG: " << argument << std::endl;
  }

  Instruction(std::string &input) {
    operation = input.substr(0, 3);
    input.erase(0, 4);
    argument = std::stoi(input);
  }
};

int main() {
  std::vector<Instruction> instructions;

  std::ifstream input("input.txt", std::ios::in);
  if (input.is_open()) {
    std::string line;
    while(getline(input, line)) { instructions.emplace_back(Instruction(line)); }
    input.close();
  }

  int acc = 0;
  int idx = 0;
  do {
    if (instructions[idx].operation == "acc") {
      acc += instructions[idx].argument;
    } else if (instructions[idx].operation == "jmp") {
      idx += instructions[idx].argument - 1;
    }
    instructions[idx].visited = true;
    ++idx;
  } while (!instructions[idx].visited);

  std::cout << "Part 1: " << acc << std::endl;

  return 0;
}
