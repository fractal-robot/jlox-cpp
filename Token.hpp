#pragma once

#include "TokenType.hpp"

class Object {
public:
  Object(){};
  std::string get() const { return "whoami"; }
};

class Token {
public:
  const TokenType type;
  const std::string lexeme;
  const Object literal;
  const int line;

  Token(TokenType type, const std::string lexeme, Object literal, int line)
      : type(type), lexeme(lexeme), literal(literal), line(line) {}

  std::string toString();

  void print();

private:
  std::string token;
};
