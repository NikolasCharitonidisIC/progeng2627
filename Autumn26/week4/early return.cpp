#include <iostream>
int smallest_factor(int n) {
  //if (n <= 1) {return 0;}//This case is undefined
  for (int i = 2;i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}

void primes_in_range(int a, int b) {
  for (int i = a; i <=b;i++) {
    if (smallest_factor(i) == i) {std::cout << i << std::endl;}
  }
}


int main() {
  //for (int a : {2,3,4,7,8,12,13,95710271}) {std::cout << smallest_factor(a) << std::endl;}
  primes_in_range(2,101); 
  return 0;
}
