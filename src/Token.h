#pragma once

#include "TokenType.h"
#include <string>

class Token {
public:
  const TokenType type;
  const int line;
  std::string lexeme;

  Token(TokenType type, int line, std::string lexeme);
  std::string toString();
  void print();
};
