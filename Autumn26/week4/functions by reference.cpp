#include <iostream>

void swapString(std::string& str1 , std::string& str2) {
  std::string temp = str1;
  str1 = str2;
  str2 = temp;
}

void rectangleCalculations(double side1, double side2, double& area, double& perimeter) {
  perimeter = 2*(side1 + side2);
  area = side1 * side2;
}

int main() {
  std::string myString1 = "This is string 1";
  std::string myString2 = "This is string 2";
  swapString(myString1,myString2);
  std::cout << myString1 << std::endl << myString2 << std::endl;
  
  double myArea,myPerimeter;
  rectangleCalculations(5,2,myArea,myPerimeter);
  std::cout << "Area: " << myArea << std::endl;
  std::cout << "Perimeter: " << myPerimeter << std::endl;

  return 0;
}
