#include "../includes.h"

struct PasswordValidator {
  int lBound;
  int uBound;
  char targetChar;
  std::string password;

  static std::vector<std::string> parse(std::string input) {
    std::vector<std::string> parts;
    std::string curPart;

    for (char c : input) {
      if ((c == ' ' || c == '-' || c == ':') && curPart.length()) {
        parts.push_back(curPart);
        curPart.clear();
      } else {
        curPart += c;
      }
    }

    parts.push_back(curPart);
    return parts;
  }

  PasswordValidator(std::string input) {
    std::vector<std::string> parts = PasswordValidator::parse(input);
    this->lBound = std::stoi(parts[0]);
    this->uBound = std::stoi(parts[1]);
    this->targetChar = parts[2][0]; // always a single char
    this->password = parts[3];
  }

  // Is valid if the count of targetChar in password string is within the bounds of validator.
  bool isValid() {
    int targetCount = 0;
    for (char c : this->password)
      if (c == targetChar) targetCount++;
    return targetCount >= lBound && targetCount <= uBound;
  }
};

int main() {
  std::fstream newfile;
  int validPasswordCount = 0;

  newfile.open("input.txt", std::ios::in);

  if (newfile.is_open()) {
    std::string line;

    while(getline(newfile, line)) {
      PasswordValidator pw(line);
      if (pw.isValid()) validPasswordCount++;
    }

    newfile.close();
  }

  std::cout << validPasswordCount << std::endl;

  return 0;
}