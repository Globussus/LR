#include <iostream>

// Данная функция вычисляет сумму биномов
void FindSumOfBinoms() {
  double a;
  int b, i = 1, counter = 0;

  while (i <= 30) {
    if (i % 2 == 1) {
      a = i;
    } else {
      a = i / 2.0;
    }

    if (i % 2 == 1) {
      b = i * i;
    } else {
      b = i * i * i;
    }
    
    i++;
    counter += (a - b) * (a - b);
  }

  std::cout << "Сумма 30 биномов Ньютона второй степени: ∑ (a_i + b_i) ^ 2 = " << counter << std::endl;
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 1. Вычисление суммы 30 биномов Ньютона 2 степени. Выполнил: Глобаж Станислав.\n";
  std::cout << "Данная программа вычисляет сумму 30 биномов Ньютона 2 степени вида: (a_i + b_i) ^ 2, где ";
  std::cout << "a, b — некоторые числа, i — порядковый номер от 1 до 30.\n";
  std::cout << "В зависимости от значения i, a и b могут принимать разные значения:\n";
  std::cout << "  a = i, если i — нечётное число. a = i / 2, если i — чётное число.\n";
  std::cout << "  b = i^2, если i — нечётное число. b = i^3, если i — чётное число.\n\n";
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
      FindSumOfBinoms();
    } else if (command == "Выйти") {
      std::cout << "Завершение работы\n";
      break;
    } else if (command == "Инструкция") {
      ShowInstructions();
    } else {
      std::cout << "Программа не обрабатывает введённую команду." << std::endl;
    }
  }
  return 0;
}