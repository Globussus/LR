#define MATH_PI 3.1415926535;
#define LN_10 2.3025850929

//Функция для возведения числа в степень
long double pow(long double x, int exponent) {
  long double result = 1.0;

  for (int i = 1; i <= exponent; i++) {
    result *= x;
  }
  return result;
}

//Функция для вычисления модуля числа
long double abs(long double x) {
  if (x < 0.0) {
    x = x * (-1.0);
  }
  return x;
}

//Функция для вычисления факториала числа
long double factorial(long int number) {
  long double result = 1.0;

  for (int i = 1; i <= number; i++) {
    result *= i;
  }
  return result;
}

//Функция для вычисления синуса числа
long double sin(long double x) {
  long double result = 0;

  for (long int i = 0; i < 100; i++) {
    long double d = pow(x, 2 * i + 1) / factorial(2 * i + 1);

      if (i % 2 == 0) {
        result += d;
      } else {
        result -= d;
      } 
  }
  return result;
}

//Функция для вычисления косинуса числа
long double cos(long double x) {
  long double result = 0;
  x = abs(x);

  for (long int i = 0; i < 100; i++) {
    long double d = pow(x, 2 * i) / factorial(2 * i);

    if (i % 2 == 0) {
      result += d;
    } else {
      result -= d;
    }
  }
  return result;
}

//Функция для вычисления натурального логарифма числа
long double ln(long double x) {
  long double result = 0;
  int powers_of_ten = 0;

  while(x >= 2){
    x /= 10;
    powers_of_ten++;
  }

  for (long int i = 1; i < 100; i++) {
    long double d = pow(-1, i - 1) * pow(x - 1, i) / i;
    result += d;
  }
  return result + powers_of_ten * LN_10;
}