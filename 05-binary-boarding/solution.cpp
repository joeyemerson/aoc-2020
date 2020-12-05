#include "../aoc.h"

int getID(const std::string &boardingPass) {
  std::string rowText = boardingPass.substr(0, 7);
  std::string colText = boardingPass.substr(7, 3);
  int row = 0;
  int col = 0;

  int offset = 0;
  while (rowText.length()) {
    row += (rowText.back() == 'F' ? 0 : 1) << offset++;
    rowText.pop_back();
  }

  offset = 0;
  while (colText.length()) {
    col += (colText.back() == 'L' ? 0 : 1) << offset++;
    colText.pop_back();
  }

  return row * 8 + col;
}

int main() {
  int maxID = -1;
  int minID = std::numeric_limits<int>::max();
  int myID;
  std::unordered_set<int> ids;
  std::ifstream newfile("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      int curID = getID(line);
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
