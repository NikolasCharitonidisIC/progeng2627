#include <iostream>
#include <fstream>
//#include <vector>

int main(int argc, char* argv[]){
  std::ifstream myFile;
  myFile.open(argv[1]);
  if (!myFile.is_open()) {
    std::cout << "Coule not open file\n";
    return EXIT_FAILURE;}
  std::string tmp;
  while (myFile >> tmp) {
    std::cout << tmp << " ";
  }
  std::cout << std::endl;

  

}
