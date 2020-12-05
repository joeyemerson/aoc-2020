#include "../aoc.h"

int getID(const std::string &boardingPass) {
  const std::string rowBits = boardingPass.substr(0, 7);
  const std::string colBits = boardingPass.substr(7, 3);
  int row = std::stoi(rowBits, nullptr, 2);
  int col = std::stoi(colBits, nullptr, 2);
  return row * 8 + col;
}

std::string getBits(const std::string &boardingPass) {
  std::string bits;
  for (char c : boardingPass) {
    if (c == 'F' || c == 'L') bits += '0';
    else bits += '1';
  }
  return bits;
}

int main() {
  std::unordered_set<int> ids;
  int maxID = -1;
  int minID = std::numeric_limits<int>::max();
  int myID;

  std::ifstream newfile("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      std::string bits = getBits(line);
      int curID = getID(bits);
      if (maxID < curID) maxID = curID;
      if (curID < minID) minID = curID;
      ids.emplace(curID);
    }

    newfile.close();
  }

  for (int i = minID; i < maxID; ++i) {
    if (ids.find(i) == ids.end()) {
      myID = i;
      break;
    }
  }

  // Part 1: Find the max ID in input list
  std::cout << "Max ID: " << maxID << std::endl;

  // Part 2: Find the missing ID between minID and maxID
  std::cout << "My ID: " << myID << std::endl;

  return 0;
}
