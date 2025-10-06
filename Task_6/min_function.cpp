#include <iostream>
#include "math_functions.h"
#include <string>

// Очищает поток ввода, если возникли ошибки при вводе
void CleanInput() {
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

//Находит наименьшее из 3-х значений
long double FindTheSmallest(long double var_1, long double var_2, long double var_3) {
  long double result = 0;

  if (var_1 <= var_2 && var_1 <= var_3) {
    result = var_1;
  } else if (var_2 <= var_1 && var_2 <= var_3) {
    result = var_2;
  } else if (var_3 <= var_1 && var_3 <= var_2) {
    result = var_3;
  }
  return result;
}

void Calculate() {
  long double x, result;

  std::cout << "Введите x: ";
  std::cin >> x;

  if (std::cin.fail()) {
    std::cout << "Программа работает лишь с числами!" << std::endl;
    CleanInput();
  } else {
    std::cout << "cos(" << x << ") = " << cos(x) << std::endl;
    std::cout << "sin(" << x << ") = " << sin(x) << std::endl;
    std::cout << "ln(" << x << ") = " << ln(x) << std::endl;
    result = FindTheSmallest(sin(x), cos(x), ln(x));
    std::cout << "Минимальное значение = " << result << std::endl;
  }
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 6. Вычисление минимального значения из значений трёх ф-ций. Выполнил: Глобаж Станислав.\n";
  std::cout << "В данном задании вычисляются значения cos(x), sin(x), ln|x| и из них выбирается наименьшее\n";
  std::cout << "Пользователю нужно ввести переменную x — число с плавающей точкой\n";
  std::cout << "  Если значение x не соответствует условию — вычисления не будут произведены!\n";
  std::cout << "Пользователю доступны следующие команды:\n";
  std::cout << "  Запуск — запустить программу\n";
  std::cout << "  Выйти — заканчивает работу программы\n";
  std::cout << "  Инструкция — выводит инструкцию по использованию программы" << std::endl;
}

int main() {
  std::string command;

  ShowInstructions();

  while (true) {
    std::cout << "Введите команду: ";
    std::cin >> command;

    if (command == "Запуск") {
      Calculate();
    } else if (command == "Выйти") {
      std::cout << "Завершение работы" << std::endl;
      break;
    } else if (command == "Инструкция") {
      ShowInstructions();
    } else {
      std::cout << "Программа не обрабатывает введённую команду." << std::endl;
    }
  }
  return 0;
}