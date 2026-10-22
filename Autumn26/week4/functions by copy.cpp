#include <iostream>

double abs(double n) {return n < 0 ? -n : n;}
double mypow(double base, int exponent) {
  double total = 1;
  for (int i=1;i<=exponent;i++) {
    total *= base;
  }
  if (exponent == 0) {return 1;}
  if (exponent < 0) {return 1/mypow(base,-exponent);}
  return total;
}

double SumOfPowers(double base, int index) {
  double total = 0;
  for (int i = 1;i<=index;i++) {
    total += mypow(base,i);
  }
  return total;
}

int factorial(int n) {
  if (n == 0) {return 1;}
  int total = 1;
  for (int i=1; i <= n; i++) {
    total *= i;
  }
  return total;
}

bool isLeap(int year) {
  bool leap;
  if (year % 100 == 0 || ! (year %4)) {leap = false;}
  if (year % 400 == 0 || (year % 4 == 0 && ! (year % 100 == 0))) {leap = true;}
  return leap;
}


int main() {
  for (int i : {1600,1700,1800,2024,2023,2026}) {std::cout << isLeap(i) << std::endl;}


  return 0;
}
