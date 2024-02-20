#include "Scanner.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Lox {
public:
  static bool hadError;

  static void runFile(char *&inputFile) {
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

  static void runPrompt() {
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

private:
  static void run(const std::string &source) {
    Scanner scanner;
    std::vector<Token> tokens = scanner.scanTokens();

    for (Token &token : tokens)
      token.print(), std::cout << '\n';
  }

  static void error(int line, const std::string &message) {
    report(line, "", message);
  }

  //
  static void report(int line, const std::string &where,
                     const std::string &message) {
    std::cout << "[Line " << line << "] Error" << where << ": " << message;
    hadError = true;
  }
};

int main(int argc, char *argv[]) {
  Lox::hadError = false;

  if (argc > 2) {
    std::cout << "Usage: jlox [script]\n";
    return EXIT_FAILURE;
  } else if (argc == 2) {
    Lox::runFile(argv[1]);
  } else {
    Lox::runPrompt(); // run in interactive mode
  }

  return EXIT_SUCCESS;
}
