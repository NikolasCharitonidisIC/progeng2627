#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin) {
  if (vin.empty()) {return -1;}
  double min = vin.at(0);
  int index = 0;
  for (int i=0;i<size(vin);i++) {
    if (vin.at(i) < min) {
      min = vin.at(i);
      index = i;
    }
  }
  return index;
}

int search_vector(int n, const std::vector<int>& vin) {
  if (vin.empty()) {return -1;}
  for (int i = 0; i < size(vin); i++) {
    if (vin.at(i) == n) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<double> v = {3,4,1,2,8,6,7};
  std::vector<int> v2 = {4,3,6,1,2,9,8,7,6};
  std::cout << min_vector_element(v) << std::endl;
  std::cout << search_vector(10,v2) << std::endl;
  return 0;
}
