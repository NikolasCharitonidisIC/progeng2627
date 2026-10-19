#include <iostream>
#include <ctime>

bool inRange(int coord) {
  return (coord > 0 && coord < 9) ? true : false;
}

int main() {
  std::srand(std::time(NULL));
  bool escaped;
  //starting coordinates
  const int originalx = std::rand() % 6 + 2,originaly = std::rand() % 6 + 2; 
  int kx = originalx, ky = originaly;
  int Dx,Dy; //Destinatio x and Destination y
  bool valid = false;
  //while loop
  int counter = 0;
  std::cout << "Your current coordinates are (" << kx << "," << ky << ")\n";
  while (!((kx == 8 || kx == 1) && (ky == 1 || ky == 8))) {
      std::cout << "You have " << 5 - counter << " more moves.\n";
      std::cout << "Please enter the coordinates of your destination: ";
      std::cin >> Dx;
      std::cin >> Dy;
      while (!inRange(Dx)) {
        std::cout << "Please enter a valid x coordinate: ";
        std::cin >> Dx;
    }
      while (!inRange(Dy)) {
        std::cout << "Please enter a valid y coordinate: ";
      std :: cin >> Dy;
      }
      if ((kx-Dx)*(kx-Dx) + (ky-Dy)*(ky-Dy) == 5) {valid = true;}
      if (valid) {
        kx = Dx;
        ky = Dy;
        std::cout << "Your new coordinates are (" << kx << "," << ky << ")\n";
        counter ++;
      }
      else {std::cout << "These coordinates are invalid.\n";}

    
    //counter ++;
    //escaped = ((kx == 8 || kx == 1) && (ky == 1 || ky == 8));
    //a bunch of these comments were made due to changes in my code, instead of removing the code I commented it in case I wanted to come back to it
    if (counter >= 5) {
      std::cout << "You ran out of attempts!\n";
      kx = originalx;
      ky = originaly;
      std::cout << "Your knight's position was reset back to (" << kx << "," << ky << "). Try again!\n";
      counter = 0;
    }
  }
  std::cout << "Good job, your knight escaped in " << counter << " moves!\n";

  return 0;
}
