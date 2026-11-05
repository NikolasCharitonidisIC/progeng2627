#include <iostream>
#include <vector>
#include <fstream>

bool exists(const std::vector<std::string>& vec, std::string str) {
  bool flag = false;
  for (std::string word : vec) {
    if (word == str) {flag = true;}
  }
  return flag;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
  for (std::string word : vin1) {
    if (!exists(vout, word)) {vout.push_back(word);}
  }
  for (std::string word : vin2) {
    if (!exists(vout, word)) {vout.push_back(word);}
  }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
  for (std::string word : vin1) {
    if (exists(vin2,word)) {vout.push_back(word);}
  }
}

int main() {
  std::ifstream warehouse1;
  std::ifstream warehouse2;
  
  std::ofstream unionfile;
  std::ofstream intersectionfile;

  std::vector<std::string> vectorwarehouse1;
  std::vector<std::string> vectorwarehouse2;

  warehouse1.open("warehouse1.txt");
  if (!warehouse1.is_open()) {
    std::cout << "Error opening file." << std::endl;
    return EXIT_FAILURE;
  }
  
  std::string word;
  while (warehouse1 >> word) {
    vectorwarehouse1.push_back(word);
  }
  
  warehouse1.close();

  warehouse2.open("warehouse2.txt");
  if (!warehouse2.is_open()) {
    std::cout << "Error opening file.\n";
    return EXIT_FAILURE;
  }

  while (warehouse2 >> word) {
    vectorwarehouse2.push_back(word);
  }
  warehouse2.close();

  std::vector<std::string> vectorunion, vectorintersection;
  union_vector(vectorwarehouse1,vectorwarehouse2,vectorunion);
  intersection_vector(vectorwarehouse1,vectorwarehouse2,vectorintersection);
  
  unionfile.open("union.txt");
  if (!unionfile.is_open()) {
    std::cout << "Error opening file.\n";
    return EXIT_FAILURE;
  }
  for (std::string word : vectorunion) {unionfile << word << std::endl;}
  unionfile.close();


  intersectionfile.open("intersection.txt");
  if (!intersectionfile.is_open()) {
    std::cout << "Error opening file.\n";
    return EXIT_FAILURE;
  }
  for (std::string word : vectorintersection) {intersectionfile << word << std::endl;}
  unionfile.close();

  return 0;
}
