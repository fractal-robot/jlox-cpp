#include "Lox.hpp"
#include <cstdlib>
#include <iostream>

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
