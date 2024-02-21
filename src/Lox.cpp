#include "Lox.h"
#include "Scanner.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool Lox::hadError;

void Lox::runFile(char *&inputFile) {
  std::ifstream file;
  file.open(inputFile);
  if (!file.is_open()) {
    std::cerr << "Unable to open file for reading.\n";
    exit(1);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();
  std::string fileContent{buffer.str()};

  if (hadError == true)
    exit(1);

  run(fileContent);
}

void Lox::runPrompt() {
  std::string userInput;
  while (true) {
    std::cout << "> ";
    getline(std::cin, userInput);
    if (userInput.empty())
      break;
    run(userInput);
    hadError = false;
  }
}

void Lox::run(const std::string &source) {
  Scanner scanner(source);
  std::vector<Token> tokens = scanner.scanTokens();

  for (Token &token : tokens)
    token.print(), std::cout << '\n';
}

void Lox::error(int line, const std::string &message) {
  report(line, "", message);
}

void Lox::report(int line, const std::string &where,
                 const std::string &message) {
  std::cout << "[Line " << line << "] Error" << where << ": " << message
            << '\n';
  hadError = true;
}
