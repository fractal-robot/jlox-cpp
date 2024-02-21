#include "Token.h"
#include "TokenType.h"
#include <iostream>
#include <string>

Token::Token(TokenType type, int line, std::string lexeme)
    : type(type), line(line), lexeme(lexeme) {}

void Token::print() {
  std::cout << "[" << tokenMap[type] << "] ";
  if (type == TokenType::STRING || type == TokenType::IDENTIFIER ||
      type == TokenType::NUMBER)
    std::cout << "Value: " << lexeme;
}
