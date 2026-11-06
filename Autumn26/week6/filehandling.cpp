#include <iostream>
#include <vector>
#include <fstream>

int countwords(const std::vector<std::string>& vec, std::string word) {
  int counter = 0;
  for (std::string element : vec) {
    if (element == word) {counter++;}
  }
  return counter;
}


int main() {
  std::ifstream myFile;
  std::string tmp;
  std::vector<std::string> words;
  myFile.open("text.txt");
  if (!myFile.is_open()) {
    std::cout << "Could not open file!" << std::endl;
    return EXIT_FAILURE;
  }
  while (myFile >> tmp){words.push_back(tmp);}
  myFile.close();
 
  myFile.open("words.txt");
  if (!myFile.is_open()) {
    std::cout << "Could not open file" << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<std::string> checklist;
  while (myFile >> tmp) {checklist.push_back(tmp);}
  myFile.close();
  for (std::string word : checklist) {
    std::cout << word << ": " << countwords(words,word) << std::endl;
  }


  return 0;
}
