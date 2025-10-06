#include <iostream>
#include <cmath>

// Очищает поток ввода, если возникли ошибки при вводе
void CleanInput() {
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

//Приблизительно вычисляет корень уравнения lg(cosh(x)) - tanh(x) + 0.5 = 0
void FindTheRoot() {
  long long int parts;
  long double step, root, x, min_value = 3;

  std::cout << "Введите количество частей области поиска корня: ";
  std::cin >> parts;

  if (std::cin.fail()) {
    std::cout << "Parts не может принимать нечисловые значения!" << std::endl;
    CleanInput();
  } else if (parts < 1) {
    std::cout << "Вы ввели ненатуральное число!" << std::endl;
  } else {
    step = 2.0 / parts;

    for (long double i = 0.0; i <= 2.0; i += step) {
      root = log10(cosh(i)) - tanh(i) + 0.5;

      if (fabs(root) < min_value) {
        min_value = root;
        x = i;
      }
    }
    std::cout << "Корень уравнения x ≈ " << x << std::endl;
  }
}

// Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 5. Вычисление корня уравнения lg(cosh(x)) - tanh(x) + 0.5 = 0 (x ∈ [0, 2]). Выполнил: Глобаж Станислав.\n";
  std::cout << "Программа позволяет вычислить приблизительное значение корня, разбивая промежуток [0, 2] ";
  std::cout << "На несколько частей\n";
  std::cout << "Пользователю необходимо ввести 1 переменную: \n";
  std::cout << "  parts — количество отрезков, на которые разбивается промежуток [0, 2], (n ∈ N)\n";
  std::cout << "Если переменные parts не удовлетворяет условию — вычисление корня уравнения не будет произведено\n\n";
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
      FindTheRoot();
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