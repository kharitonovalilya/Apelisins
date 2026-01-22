#include <iostream>

#include "sub.h"

int main() {
  std::cout << "Enter two numbers:\n";

  long long first_number = 0;
  long long second_number = 0;

  std::cin >> first_number;
  std::cin >> second_number;

  std::cout << sub(first_number, second_number);
}