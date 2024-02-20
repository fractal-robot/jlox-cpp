#pragma once

#include "Token.hpp"
#include <string>
#include <vector>

class Scanner {
public:
  Scanner(std::string source);
  std::vector<Token> scanTokens();
  std::vector<Token> scanToken();

private:
  std::vector<Token> tokens;
  const std::string source;
  bool isAtEnd();
  int start{};   // first character of the lexeme being scanned
  int current{}; // current character being scanned
  int line{1};   // in order to debug Lox programs
};
