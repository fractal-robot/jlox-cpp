#include "Token.h"
#include "TokenType.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

std::string Token::toString() {
  return tokenMap[type] + " " + lexeme + " " + literal.get();
}

void Token::print() {
  std::cout << std::setw(15) << std::left << tokenMap[type] << " | " << lexeme;
  std::cout << "[" << tokenMap[type] << "] ";
  if (type == TokenType::STRING || type == TokenType::IDENTIFIER)
    std::cout << lexe;
}
