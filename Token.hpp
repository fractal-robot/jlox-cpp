#pragma once

#include "TokenType.hpp"
#include <string>

class Object {
public:
  Object(){};
  Object(const std::string &value) : lexemeString(value){};
  Object(double value) : lexemeDouble(value){};
  std::string get() const { return "whoami"; }

private:
  std::string lexemeString{};
  double lexemeDouble{};
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
