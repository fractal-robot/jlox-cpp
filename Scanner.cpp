#include "Scanner.hpp"
#include "Token.hpp"
#include "TokenType.hpp"
#include <string>

Scanner::Scanner(std::string source) : source(source) {}

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }

  tokens.emplace_back(Token(TokenType::EOF_TOKEN, "", Object(), line));
}
