#pragma once

#include "Token.h"
#include "TokenType.h"
#include <string>
#include <unordered_map>
#include <vector>

class Scanner {
public:
  Scanner(const std::string &source);
  std::vector<Token> scanTokens();

private:
  bool isAtEnd();
  void scanToken();
  inline void addToken(TokenType type);
  inline void addToken(TokenType type, Object literal);
  inline char advance();
  bool match(char expected);
  char peek();
  char peekNext();
  inline bool isAlphaNumeric(char c);
  inline bool isAlpha(char c);
  inline bool isDigit(char c);
  void string();
  void number();
  void identifier();

  std::vector<Token> tokens;
  const std::string source;
  int start{};   // first character of the lexeme being scanned
  int current{}; // current character being scanned
  int line{1};   // in order to debug Lox programs

  const std::unordered_map<std::string, TokenType> keywords{
      {"and", TokenType::AND},       {"class", TokenType::CLASS},
      {"else", TokenType::ELSE},     {"false", TokenType::FALSE},
      {"for", TokenType::FOR},       {"fun", TokenType::FUN},
      {"if", TokenType::IF},         {"nil", TokenType::NIL},
      {"or", TokenType::OR},         {"print", TokenType::PRINT},
      {"return", TokenType::RETURN}, {"super", TokenType::SUPER},
      {"this", TokenType::THIS},     {"true", TokenType::TRUE},
      {"var", TokenType::VAR},       {"while", TokenType::WHILE},
  };
};
