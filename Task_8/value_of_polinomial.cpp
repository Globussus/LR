#include <iostream>
#include <string>

// Очищает поток ввода, если возникли ошибки при вводе
void CleanInput() {
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

// Функция возводит число в определенную степень
// Первый аргумент — число, второй — показатель степени, в которую пользователь хочет возвести число
long pow(long number, int exponent) {
  long result = 1;

  for (int i = 1; i <= exponent; i++) {
    result *= number;
  }
  return result;
}

//Функция вычисляет значение полинома P(n) = a_0 - 2 * a_1 + 4 * a_2 + ... + 2^(n-1) * (-1)^(n-1) * a_n
void FindValueOfPolinomial() {
  int n, a, sum = 0;
  bool is_correct_expression = true;

  std::cout << "Введите значение n: ";
  std::cin >> n;

  if (std::cin.fail()) {
    std::cout << "Программа работает лишь с числами!" << std::endl;
    CleanInput();
  } else if (n < 1) {
    std::cout << "Программа не расчитана на работу с вещественными числами!" << std::endl;
  } else {
    for (int i = 1; i <= n; i++) {
      std::cout << "Введите a_" << i - 1 << ": ";
      std::cin >> a;

      if (std::cin.fail()) {
        std::cout << "Программа работает лишь с числами!" << std::endl;
        CleanInput();
        is_correct_expression = false;
        break;
      }
      sum = sum + pow(-1, n - 1) * pow(2, n - 1) * a;
    }
    if (is_correct_expression) {
      std::cout << "При n = " << n << " значение многочлена: P(" << n << ") = " << sum << std::endl;
    }
  }
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 8. Вычисление значения полинома. Выполнил: Глобаж Станислав.\n";
  std::cout << "В данном задании нужно вычислить значение полинома ";
  std::cout << "P(n) = a_0 - 2 * a_1 + 4 * a_2 + ... + 2^(n-1) * (-1)^(n-1) * a_n\n";
  std::cout << "На вход пользователю дается число n — кол-во одночленов полинома.\n";
  std::cout << "Помимо этого пользователь должен ввести n чисел a_n. Для ввода n и a_n есть определенные условия:\n";
  std::cout << "  n и a_n должны быть натуральными числами! (n ∈ N, a_n ∈ N)\n";
  std::cout << "  В случае ввода дробных чисел — они будут округляться до целой части\n";
  std::cout << "  В случае ввода нечисловых значений — значение полинома не будет вычислено!\n";
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
      FindValueOfPolinomial();
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