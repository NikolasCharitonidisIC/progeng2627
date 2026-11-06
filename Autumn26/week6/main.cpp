#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged) {
  int i=0,j=0;
  while (i<size(v1) && j<size(v2)){
    if (v1.at(i) < v2.at(j)) {
      merged.push_back(v1.at(i));
        i++;
    }
    else {
      merged.push_back(v2.at(j));
      j++;
    }
  }
    for (int k=i;k<size(v1);k++){merged.push_back(v1.at(k));}
    for (int jj=j; jj<size(v2);jj++) {merged.push_back(v2.at(jj));}

}


int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);
    for (int num : out) {std::cout << num << std::endl;}
    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}
