#include <iostream>
#include <string>

// Очищает поток ввода, если возникли ошибки при вводе
void CleanInput() {
  std::cin.clear();
  std::cin.ignore(32767, '\n');
}

//Функция возводит число в определенную степень
//Первый аргумент — число, второй — показатель степени, в которую пользователь хочет возвести число
long pow(long number, int exponent) {
  long result = 1;

  for (int i = 1; i <= exponent; i++) {
    result *= number;
  }
  return result;
}

//Данная функция вычисляет кол-во цифр в числе
int AmountOfDigits(long number) {
  int counter = 0;

  while (number != 0) {
    counter += 1;
    number /= 10;
  }
  return counter;
}

//Данная функция выяснят, является ли введенное число числом Армстронга?
bool CheckIsNumberOfArmstrong(long number) {
  long sum = 0, number_copy = number;
  int amount_of_digits = AmountOfDigits(number), digit;

  while (number_copy != 0) {
    digit = number_copy % 10;
    sum += pow(digit, amount_of_digits);
    number_copy /= 10;
  }

  if (sum == number) {
    return true;
  } else {
    return false;
  }
}

//Данная функция находит числа Армстронга от 1 до введенного пользователем числа
void FindNumbersOfArmstrong() {
  double input;

  std::cout << "Введите число: ";
  std::cin >> input;

  if (std::cin.fail()) {
    std::cout << "Программа работает лишь с числами!\n\n";
    CleanInput();
  } else {
    long number = (long)input;

    if (number <= 0) {
      std::cout << "Программа не обрабытывает ненатуральные числа!\n\n";
    } else {
      std::cout << "Числа Армстронга на промежутке от 1 до " << number << ":\n"; 

      for (int i = 1; i <= number; i++) {
        if (CheckIsNumberOfArmstrong(i) == true) {
          std::cout << i << " ";
        }
      }
      std::cout << std::endl << std::endl;
    }
  }
}

//Инструкции по использованию программы
void ShowInstructions() {
  std::cout << "\nЗадание 7. Вычисление чисел Армстронга. Выполнил: Глобаж Станислав.\n";
  std::cout << "Число Армстронга — это число, равное сумме своих цифр, возведенных в степень, равную количеству цифр.\n";
  std::cout << "Инструкция по использованию программы:\n";
  std::cout << "  Пользователю нужно ввести натуральное число\n";
  std::cout << "  Программа находит все числа Армстронга от 1 до числа, введённого пользователем.\n";
  std::cout << "  Если пользователь введет отрицательное число или 0 — программа не выполнится\n";
  std::cout << "  Если пользователь введет положительное дробное число — программа выполнится до меньшего целого числа\n";
  std::cout << "  Если пользователь введет значение нечислового типа — программа не выполнится\n\n";
  std::cout << "Пользователю доступны следующие команды:\n";
  std::cout << "  Запуск — запустить программу\n";
  std::cout << "  Выйти — заканчивает работу программы\n";
  std::cout << "  Инструкция — выводит инструкцию по использованию программы" << std::endl;
}

int main() {
  std::string command;

  ShowInstructions();
  
  while(true) {
    std::cout << "Введите команду: ";
    std::cin >> command;

    if (command == "Запуск") {
      FindNumbersOfArmstrong();
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