#include "Token.hpp"
#include <iostream>
#include <string>

std::string Token::toString() {
  return tokenMap[type] + " " + lexeme + " " + literal.get();
}

void Token::print() { std::cout << token << " - "; }
