#include <iostream>
#include <vector>

int main() {
  std::cout << "Enter the size of the vector you would like to populate: ";
  int n;
  std::cin >> n;
  int input;
  std::vector<int> v;
  for (int i=0; i < n; i++) {
    std::cin >> input;
    v.push_back(input);
  }
  int t;
  std::cout << "Enter a number to compare your values with: ";
  std::cin >> t;
  int counter = 0;
  for (int i : v) {
    if (i < t) {std::cout << i << " is less than " << t << std::endl;}
  }
  int s;
  std::cout << "Enter another number to see how many times that number appears in your vector: ";
  std::cin >> s;
  for (int i = 0; i < size(v); i++) {
    if (v.at(i) == s) {counter++;
    std::cout << "The number " << s << " appears at index " << i << " of your vector\n";}
  }
  std::cout << "The number " << s << " appears " << counter << " times in your vector.\n";

  return 0;
}
