#include "../aoc.h"

uint64_t part1(const std::vector<uint64_t> &ratings) {
  uint64_t v1 = 0, v3 = 1;

  for (size_t i = 1; i < ratings.size(); ++i) {
    uint64_t diff = ratings[i] - ratings[i - 1];
    if (diff == 1) ++v1;
    if (diff == 3) ++v3;
  }

  return v1 * v3;
}

uint64_t part2(const std::vector<uint64_t> &ratings) {
  uint64_t possiblePaths = 1;
  size_t longestPossibleSubsequence = 5;
  std::vector<uint64_t> bases =   { 1, 1, 1, 2, 4, 7 };
  std::vector<uint64_t> lengths = { 0, 0, 0, 0, 0, 0 };

  uint64_t curLen = 1;
  for (size_t i = 0; i < ratings.size() - 1; ++i) {
    if (ratings[i+1] - ratings[i] == 1) {
      ++curLen;
    } else {
      ++lengths[curLen];
      curLen = 1;
    }
  }

  ++lengths[curLen]; // have to account for final subsequence

  for (size_t i = 0; i <= longestPossibleSubsequence; i++) {
    possiblePaths *= pow(bases[i], lengths[i]);
  }

  return possiblePaths;
}

int main() {
  std::vector<uint64_t> ratings = { 0 }; // initialize with wall outlet

  std::ifstream input("input.txt", std::ios::in);
  if (input.is_open()) {
    std::string line;
    while(getline(input, line)) { ratings.emplace_back(std::stoull(line)); }
    input.close();
  }

  std::sort(ratings.begin(), ratings.end());

  uint64_t p1 = part1(ratings);
  uint64_t p2 = part2(ratings);

  std::cout << "Part 1: " << p1 << std::endl;
  std::cout << "Part 2: " << p2 << std::endl;

  return 0;
}
