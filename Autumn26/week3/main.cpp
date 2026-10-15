/*
//Valid Triangle
#include <iostream>
#include <cmath>

int main(){
  std::cout << "Please enter the three sides of the triangle: ";
  double a,b,c;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  int n = 0;
  if (a == b || b == c || a == c) {
    if (a == c && a == b) {
      n = 2;
    }
    else {
      n = 1;
    }
  }
  float perimeter = a+b+c;
  float area;
  float s = (a+b+c)/2;
  area = std::sqrt(s*(s-a)*(s-b)*(s-c));
  
  std::string idk;
  if (n == 2) {idk = "It is an equilateral triangle";}
  else if (n == 1) {idk = "It is an isosceles triangle.";}
  else if (n == 0) {idk = "It is a scalene triangle";}
  //ok so I just realised that I could've just defined the idk variable earlier and assigned the phrases right away instead of assagning the value of n and then the value of idk but im too lazy to fix it. If it works it works.
  bool valid = (a+b>c && a+c>b && b+c>a);
  if (!valid) {
    std::cout << "This triangle cannot possibly exist!\n";
  }
  else {
    std::cout << "This triangle is possible. " << idk << " with a perimeter of " << perimeter << " units and an area of " << area << " square units!\n";    
  }
  
  
  return 0;
}//*/
 
//Valid Chess Move
/*/
#include <iostream>

struct coordinate {
  int x;
  int y;
};

int main() {
  std::cout << "Please enter the x and y coordinate of the knight: ";
  int x,y;
  std::cin >> x;
  std::cin >> y;
  auto knight = coordinate {x,y};
  std::cout << "Please enter the x and y coordinate of the destination for your knight: ";
  std::cin >> x;
  std::cin >> y;
  auto destination = coordinate {x,y};
  bool valid = false;
  if ((knight.x - destination.x)*(knight.x - destination.x) + (knight.y - destination.y)*(knight.y - destination.y) == 5) {valid = true;}
  if (valid) {std::cout << "Your move is valid!\n";}
  else {std::cout << "Your move is NOT valid\n";}
  
  return 0;
}//*/


//3.1
/*/
#include <iostream>

int main(){
  int n = 1;
  double total = 0;
  int counter = 0;
  while (n != 0) {
    if (counter == 0) std::cin >> n;
    total += n;
    counter ++;
    std::cout << "The average number so far is " << total/counter << ".\n";
    std::cin >> n;
  }

  return 0;
}//*/

//for loops
/*/
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int total = 1;
  for (int i=1;i<=n;i++) {total *= i;}
  if (n == 0) {total = 1;}
  std::cout << n << "! = " << total << std::endl;

  return 0;
}//*/


//nested loops
/*/
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  for (int row = 1; row <= n; row++){
    for (int col = 1;col <=n; col++){
      std::cout << row * col << "\t";
    }
    std::cout << std::endl;
  }
  

  return 0;
}//*/

//Current max and min

#include <iostream>

int main() {
  int n, max, min;
  std::cout << "Please enter a number: ";
  std::cin >> n;
  max = n;
  min = n;
  
  std::cout << "The current maximum is " << max << " and the minimum is " << min << std::endl;
  while (n != 0) {
    std::cout << "Please enter a number: ";
    std::cin >> n;
    if (n > max) {max = n;}
    if (n < min) {min = n;}
    std::cout << "The current maximum is " << max << " and the minimum is " << min << std::endl; 
  }

  return 0;
}
