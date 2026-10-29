#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout) {
  for (int num : vin1) {
    vout.push_back(num);
  }
  for (int num : vin2) {
    vout.push_back(num);
  }
}


void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout) {
  for (double num : vin) {
    if (num < t) {vout.push_back(num);}
  }
}

int main() {
  std::vector<int> v1 = {1,2,3,4,5};
  std::vector<int> v2 = {6,7,8,9,10};
  std::vector<int> vempty;
  append_vectors(v1,v2,vempty);

  for (int n : vempty) {
    std::cout << n << std::endl;
  }
  std::vector<double> myVector = {1.2,5,3.2,6,12};
  std::vector<double> myEmptyVector;
  filter_v(myVector,5.1,myEmptyVector);
  for (double num : myEmptyVector) {
    std::cout << num << std::endl;
  }
  return 0;
}
