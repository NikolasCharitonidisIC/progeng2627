#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ifstream myFile;

  myFile.open("input.txt");
  if (!myFile.is_open()) {
    std::cout << "Could not open file.";
    return EXIT_FAILURE;
  }

  std::string word;
  std::vector<std::string> words;
  while (myFile >> word) {
    words.push_back(word);
  }

  for (int i = words.size() - 1; i >=0;i--){
    std::cout << words.at(i) << std::endl;
  }

  return 0;
}
