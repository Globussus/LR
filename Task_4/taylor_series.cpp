#include <iostream>
#include <cmath>

//Очищает поток ввода, если возникли ошибки при вводе
void CleanInput() {
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

//Вычисляет факториал
long factorial(int number) {
  long result = 1;

  for (int i = 1; i <= number; i++) {
    result *= i;
  }
  return result;
}

//Производит декомпозицию функции
long double DecomposeTheFunction(long double x, long int n) {
  long double sum = 0;

  for (int i = 0; i <= n; i++) {
    sum = sum + ((std::pow(i, 2) + 1.0) / factorial(i)) * std::pow(x / 2.0, i);
  }
  return sum;
}

//Сравнивает разные результаты вычисления значений функции 
void ShowDecompositions() {
  int n;
  long double x, my_result, cmath_result;

  std::cout << "Разложение ф-ции f(x) = (x ^ 2 / 4 + x / 2 + 1) * e ^ (x / 2): " << std::endl;
  std::cout << "Введите число членов разложения: ";
  std::cin >> n;

  if (std::cin.fail()) {
    std::cout << "Программа работает лишь с числами!" << std::endl;
    CleanInput();
  } else if (n < 1) {
    std::cout << "Вы ввели ненатуральное число!" << std::endl;
  } else {
    std::cout << "Введите число x (x ∈ [0.1, 1]): ";
    std::cin >> x;

    if (std::cin.fail()) {
      std::cout << "Программа работает лишь с числами!" << std::endl;
      CleanInput();
    } else if (x >= 0.1l && x <= 1.0l) {
      my_result = DecomposeTheFunction(x, n);
      cmath_result = (pow(x, 2) / 4.0 + x / 2.0 + 1) * pow(std::exp(1.0), x / 2.0);
      std::cout << "Результат работы моей ф-ции f(" << x << ") = " << my_result << std::endl;
      std::cout << "Результат работы ф-ций cmath f(" << x << ") = " << cmath_result << std::endl;
    } else {
      std::cout << "Программа не раскладывает ф-ции на ряды при x ∉ [0.1, 1]!" << std::endl;
    }
  }
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 4. Разложение ряда для функции. Вариант 9. Выполнил: Глобаж Станислав.\n";
  std::cout << "В данном задании нужно вычислить значение функции f(x) = (x ^ 2 / 4 + x / 2 + 1) * e ^ (x / 2)\n";
  std::cout << "Предлагается сделать это 2-мя способами: используя разложение ряда и";
  std::cout << " пользуясь методами стандартной библиотеки\n\n";
  std::cout << "Пользователю необходимо ввести 2 переменные: \n";
  std::cout << "  n — количество членов разложения ряда, (n ∈ N)\n";
  std::cout << "  x — аргумент функции, x ∈ [0.1, 1]\n";
  std::cout << "Если переменные x и n не удовлетворяют условию — вычисление значении функции не будет произведено\n\n";
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
      ShowDecompositions();
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