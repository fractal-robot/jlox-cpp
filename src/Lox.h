#pragma once

#include <string>
class Lox {
public:
  static bool hadError;

  static void runFile(char *&inputFile);
  static void runPrompt();
  static void error(int line, const std::string &message);

private:
  static void run(const std::string &source);
  static void report(int line, const std::string &where,
                     const std::string &message);
};
