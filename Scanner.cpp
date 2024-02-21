#include "Scanner.hpp"
#include "Lox.hpp"
#include "Token.hpp"
#include "TokenType.hpp"
#include <cctype>
#include <iterator>
#include <string>

Scanner::Scanner(const std::string &source) : source(source) {}

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }

  tokens.emplace_back(Token(TokenType::EOF_TOKEN, "", Object(), line));
  return tokens;
}

bool Scanner::isAtEnd() { return current >= std::size(source); }

inline void Scanner::addToken(TokenType type) { addToken(type, Object()); }
inline void Scanner::addToken(TokenType type, Object literal) {
  tokens.emplace_back(Token(type, text, literal, line));
}
inline char Scanner::advance() { return source.at(current++); }

bool Scanner::match(char expected) {
  // we only consume the current character if it's what we're looking for
  if (isAtEnd())
    return false;
  if (source.at(current) != expected)
    return false;
  current++;
  return true;
}

char Scanner::peek() {
  // called a lookahead, does not consume the characters
  if (isAtEnd())
    return '\0';
  return source.at(current);
}

char Scanner::peekNext() {
  if (current + 1 >= std::size(source))
    return '\0';
  return source.at(current + 1);
}

bool isAlphaNumeric(char c) { return isalpha(c) || c == '_' || isdigit(c); }

void Scanner::string() {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n')
      ++line;
    advance();
  }
  if (isAtEnd()) {
    Lox::error(line, "Unterminated string.");
    return;
  }

  advance(); // the closing "

  std::string value{source.substr(start + 1, current - 1)};
  addToken(TokenType::STRING, Object(value));
}

void Scanner::number() {
  while (isdigit(peek()))
    advance();
  if (peek() == '.' && isdigit(peekNext()))
    advance();
  while (isdigit(peek()))
    advance();

  addToken(TokenType::NUMBER, std::stod(source.substr(start, current)));
}

void Scanner::identifier() {
  while (isAlphaNumeric(peek()))
    advance();
  std::string text{source.substr(start, current)};

  auto it = keywords.find(text);
  if (it != keywords.end())
    addToken(it->second);
  else
    addToken(TokenType::IDENTIFIER);
}

void Scanner::scanToken() {
  char c{advance()};

  switch (c) {
  case '(':
    addToken(TokenType::LEFT_PARENT);
    break;
  case ')':
    addToken(TokenType::RIGHT_PARENT);
    break;
  case '{':
    addToken(TokenType::LEFT_BRACE);
    break;
  case '}':
    addToken(TokenType::RIGHT_BRACE);
    break;
  case ',':
    addToken(TokenType::COMMA);
    break;
  case '.':
    addToken(TokenType::DOT);
    break;
  case '-':
    addToken(TokenType::MINUS);
    break;
  case '+':
    addToken(TokenType::PLUS);
    break;
  case ';':;
    addToken(TokenType::SEMICOLON);
    break;
  case '*':
    addToken(TokenType::STAR);
    break;
  case '!':
    addToken(match('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    addToken(match('=') ? TokenType::EQUAL_EQUAL : TokenType::EQUAL);
    break;
  case '<':
    addToken(match('=') ? TokenType::LESS_EQUAL : TokenType::EQUAL);
    break;
  case '>':
    addToken(match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  case '/':
    if (match('/')) {
      while (peek() != '\n' && !isAtEnd())
        advance();
    } else if (isalpha(c) || c == '_')
      identifier();
    else
      addToken(TokenType::SLASH);
    break;
  case '\r':
  case '\t':
  case ' ':
    break;
  case '\n':
    ++line;
    break;
  case '"':
    string();
    break;
  default:
    if (isdigit(c))
      number();
    else
      Lox::error(line,
                 "Unexpected character."); // the incorrect character is still
                                           // consumed by the advance()
    break;
    // we keep advancing in the program even if one error have been found so we
    // can report all the errors
  }
}
