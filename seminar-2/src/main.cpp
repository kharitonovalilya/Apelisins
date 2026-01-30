#include <iostream>
#include <input_checkers.h>
#include <calculate.h>

int main() {
  std::string expression;
  getline(std::cin, expression);
  if (!check_symbols(expression) || !check_right_operations(expression)) {
    std::cout << "Input error. Please try again\n";
    return 0;
  }
  std::cout << parse_and_count_expression(esc_erase(expression)) << '\n';
}