#include <iostream>
#include <string>

// Функция возводит число в определенную степень
// Первый аргумент — число, второй — показатель степени, в которую пользователь хочет возвести число
long pow(long number, int exponent) {
  long result = 1;

  for (int i = 1; i <= exponent; i++) {
    result *= number;
  }
  return result;
}

//Вычисляет сумму ряда с точностью E = 0.001
void FindSumOfSeries() {
  const float E = 0.001;
  long double d, sum = 0;
  int n = 1;

  do {
    d = 1.0 / pow(2, n) + 1.0 / pow(3, n);
    sum += d;
    n++;
  }
  while (d >= E);

  std::cout << "Сумма ряда: S = " << sum << std::endl;
}

//Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 2. Вычисление суммы ряда. Выполнил: Глобаж Станислав.\n";
  std::cout << "Программа вычисляет сумму членов ряда вида d_n = 1 / (2 ^ n) + 1 / (3 ^ n), где n ∈ N, с условием: \n";
  std::cout << "  Точность вычисления будет достигнута тогда, когда член ряда d_n станет меньше E = 0.001 (d_n < E)\n\n";
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
      FindSumOfSeries();
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