#include "../includes.h"

struct PasswordValidator {
private:
  int lowIndex;
  int highIndex;
  char targetChar;
  std::string password;

public:
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

  // Is valid if only one of the index positions has the targetChar.
  bool isValid() {
    return (this->password[lowIndex] == targetChar) != (this->password[highIndex] == targetChar) ;
  }

  PasswordValidator(std::string input) {
    std::vector<std::string> parts = PasswordValidator::parse(input);
    this->lowIndex = std::stoi(parts[0]);
    this->highIndex = std::stoi(parts[1]);
    this->targetChar = parts[2][0]; // always a single char
    this->password = parts[3];
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