#include <iostream>
#include <cmath>
#include <string>

//Производит расчёты по условию задания
void calculate() {
  double H, B = M_PI / 2.0, A = 0, M = 20, X;

  H = (B - A) / M;
  std::cout << "\nЗначения фунции y = sin(x) - cos(x) на промежутке [0; π/2]: " << std::endl;

  for (int i = 0; A + i * H < B; i++) {
    X = A + i * H;
    std::cout << "  sin(" << X << ") - cos(" << X << ") = " << std::sin(X) - std::cos(X) << std::endl;
  }
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 3. Вычисление значений ф-ции y = sin(x) - cos(x), x ∈ [0; π/2]. Выполнил: Глобаж Станислав.\n";
  std::cout << "Программа вычисляет значения указанной выше функции в зависимости от значения x\n";
  std::cout << "Переменная x вычисляется по формуле: x = A + i * H, где: \n";
  std::cout << "  A = 0, H = (B - A) / M, B = π/2, M = 20, i — натуральное число (i ∈ N)\n\n";
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
      calculate();
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