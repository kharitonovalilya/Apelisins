#include <input_checkers.h>

bool check_symbols(std::string input_string) {
  char symbol = '\0';
  bool result = true;
  for (int index = 0; index < input_string.length(); index++) {
    symbol = input_string[index];
    if (!(std::isspace(symbol) || std::isdigit(symbol) || symbol == '-' ||
          symbol == '+')) {
      result = false;
      break;
    }
  }
  return result;
}

bool check_right_operations(std::string task) {
  int str_size = task.size();
  int last_space_idx = -1;
  int last_operation_idx = -1;
  int last_num_idx = -1;
  for (int idx = 0; idx < str_size; idx++) {
    if (task[idx] == ' ') {
      last_space_idx = idx;
    }
    if (task[idx] == '+' || task[idx] == '-') {
      if (last_operation_idx < last_space_idx &&
          last_num_idx < last_operation_idx) {
        return false;
      }
      last_operation_idx = idx;
    }
    if (isdigit(task[idx])) {
      if (last_num_idx == -1) {
        last_num_idx = idx;
        continue;
      }
      if (last_num_idx < last_space_idx && last_num_idx > last_operation_idx) {
        return false;
      }
      last_num_idx = idx;
    }
  }
  if (last_num_idx < last_operation_idx) {
    return false;
  }
  return true;
}

std::string esc_erase(std::string task) {
  std::string new_task = "";
  for (int idx = 0; idx < static_cast<int> (task.size()); idx++) {
    if (!isspace(task[idx])) {
      new_task += task[idx];
    }
  }
  return new_task;
}
