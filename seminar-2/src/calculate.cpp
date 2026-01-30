#include <calculate.h>
int calculate(int number_first, int number_second, char operation) {
  switch (operation) {
  case '+':
    return number_first + number_second;
    break;
  case '-':
    return number_first - number_second;
    break;
  default:
    return number_second;
    break;
  }
}

int parse_and_count_expression(std::string expression) {
  int result = 0;
  int current = 0;
  char current_operation;
  for (int index = 0; index < expression.size(); ++index) {
    if (expression[index] == '+' || expression[index] == '-') {
      result = calculate(result, current, current_operation);
      current_operation = expression[index];
      current = 0;
    } else {
      current = current * 10 + int(expression[index] - '0');
    }
  }
  result = calculate(result, current, current_operation);
  return result;
}