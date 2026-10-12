//1.3
/*
#include <iostream>

int main() {
  std::cout << "Enter your name: ";
  std::string name;
  std::cin >> name;
  std::string surname;
  std::cout << "Enter your surname: ";
  std::cin >> surname;
  std::cout << "Hello " << name << " " << surname << std::endl;

  
  return 0;
}
//*/

//1.4
/*
#include <iostream>

int main() {
  double n1,n2,product;
  std::cout << "Please enter the first number: ";
  std::cin >> n1;
  std::cout << "Please enter the second number: ";
  std::cin >> n2;
  product = n1*n2;
  std::cout << n1 << " * " << n2 << " = " << product << std::endl;
  std::cout << 5/2.0 << std::endl;

  //BMI calculator
  double height, mass;
  std::cout << "Please enter your height in meters: ";
  std::cin >> height;
  std::cout << "Please enter your weight in kg: ";
  std::cin >> mass;
  double index = mass / (height * height);
  std::cout << "Your BMI index is " << index << std::endl;

  return 0;
}//*/

//2.1
/*
#include <iostream>

int main() {
  std::cout << "Please enter an integer: ";
  int num;
  std::cin >> num;
  if (num % 2) {
    std::cout << "Number is odd\n";
  }
  else {
    std::cout << "Number is even\n";
  }

  //absolute value
  std::cout << "Please enter a number: ";
  double number===;
  std::cin >> number;
  double abs_val;
  abs_val = number;
  if (number < 0) {abs_val = number * -1;}
  std::cout << "| " << number << " | = " <<  abs_val << std::endl;
  

  return 0;
}//*/

//2.2

/*
#include <iostream>

int main() {
  int year;
  std::cout << "Please enter a year: ";
  std::cin >> year;
  if ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0) {std::cout << year << " is not a leap year.\n";}
  
  else {
    if (year % 4 == 0) {std::cout << year << " is a leap year\n";}

  }

  return 0;
}//*/

#include <iostream>

int main() {
  int n1,n2;
  std::cin >> n1 >> n2;

  std::cout << n1 << " , " << n2 << std::endl;

  return 0;
}
