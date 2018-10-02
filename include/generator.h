/* Copyright 2018 */
#ifndef DOCUMENTS_CODE_CPP_PSWDGEN_INCLUDE_GENERATOR_H_
#define DOCUMENTS_CODE_CPP_PSWDGEN_INCLUDE_GENERATOR_H_

#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>
using std::rand;

namespace generator {

enum Options { SPECIALCHAR, ALPHANUM, ALPHA };
std::string GeneratePassword();
std::string GeneratePassword(int length);
std::string GeneratePassword(int length, Options options);

char GetRandomSpecialChar();
char GetRandomAlphaChar();
char GetRandomAlphaNumChar();

}; // namespace generator

#endif
