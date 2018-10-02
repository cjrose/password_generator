/* Copyright 2018 */
#include "../include/generator.h"

namespace generator {

std::string GeneratePassword(int length, Options options) {
  std::string password = "";
  for(int i = 0; i < length; i++) {
    switch(options) {
      case SPECIALCHAR:
        password += GetRandomSpecialChar();
        break;
      case ALPHANUM:
        password += GetRandomAlphaNumChar();
        break;
      case ALPHA:
        password += GetRandomAlphaChar();
        break;
    }
  }

  return password;
}

char GetRandomSpecialChar() {
  // Range: 32 - 126
  return (char)((rand() % 95) + 32);
}

char GetRandomAlphaNumChar() {
  // 48 - 57 numbers
  // 65 - 90 uppercase lettering
  // 97 - 122 lowercase lettering
  int type = rand() % 3; // get what type of char we're getting
  char random_char;
  switch(type) {
    case 0:
      random_char = (char)((rand() % 10) + 48);
      break;
    case 1:
      random_char = (char)((rand() % 26) + 65);
      break;
    case 2:
      random_char = (char)((rand() % 26) + 97);
      break;
  }
  return random_char;
}

char GetRandomAlphaChar() {
  // 65 - 90 uppercase lettering
  // 97 - 122 lowercase lettering
  int type = rand() % 2;
  char random_char;
  switch(type) {
    case 0:
      random_char = (char)((rand() % 26) + 65);
      break;
    case 1:
      random_char = (char)((rand() % 26) + 97);
      break;
  }
  return random_char;
}

};  // namespace generator

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int length, option;
  generator::Options o;
  std::cout << "||| Password Generator |||" << std::endl;
  std::cout << "Please enter a password length" << std::endl;
  std::cin >> length;

  std::cout << "Please enter a password type (between 0 - 2)\n"
            << "0 = Special characters and Alphanumeric characters\n"
            << "1 = Alphanumeric characters\n"
            << "2 = Only alphabetical characters" << std::endl;
  std::cin >> option;
  if (option > 2 || option < 0) {
    std::cout << "Entered number out of range" << std::endl;
    return 1;
  }

  switch(option) {
    case 0:
      o = generator::SPECIALCHAR;
      break;
    case 1:
      o = generator::ALPHANUM;
      break;
    case 2:
      o = generator::ALPHA;
      break;
  }
  std::cout << generator::GeneratePassword(length, o) << std::endl;
  return 0;

}
