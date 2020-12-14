#include "../aoc.h"

uint64_t part1(const std::vector<std::string> &input) {
  std::unordered_map<std::string, uint64_t> memory;
  std::string address;
  std::string mask;

  for (const std::string &line : input) {
    if (line.substr(0, 4) == "mask") {
      mask = line.substr(7);
    } else {
      address = line.substr(4, line.find(']') - 4);
      std::bitset<64> bits(std::stoull(line.substr(line.find('=') + 2)));

      for (size_t i = 0; i < 36; ++i) {
        if (mask[35-i] == '1') { bits.set(i); }
        else if (mask[35-i] == '0') { bits.reset(i); }
      }

      memory[address] = bits.to_ullong();
    }
  }

  uint64_t sum = 0LL;
  for (auto &it : memory) { sum += it.second; }

  return sum;
}

uint64_t part2(const std::vector<std::string> &input) {
  std::unordered_map<std::string, uint64_t> memory;
  std::string mask;
  uint64_t sum = 0LL;
  uint64_t value;

  for (const std::string &line : input) {
    if (line.substr(0, 4) == "mask") {
      mask = line.substr(7);
    } else {
      std::bitset<64> address(line.substr(4, line.find(']') - 4));
      value = std::stoull(line.substr(line.find('=') + 2));

      for (size_t i = 0; i < 36; ++i) {
        if (mask[35-i] == '1') {
          address.set(i);
        } else if (mask[35-i] == '0') {
          address &= ~(1ULL << i);
        }
      }
      memory[address] = value;
    }
  }

  return 1ULL;
}

int main() {
  std::vector<std::string> inputRows;

  std::ifstream input("input.txt", std::ios::in);
  if (input.is_open()) {
    std::string line;
    while(getline(input, line)) { inputRows.push_back(line); }
    input.close();
  }

  std::cout << "Part 1: " << part1(inputRows) << std::endl;
  std::cout << "Part 2: " << part2(inputRows) << std::endl;

  return 0;
}
