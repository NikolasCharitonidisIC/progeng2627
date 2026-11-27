#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// useful for manipulation of strings
#include <sstream>

// to set precision when printing
#include <iomanip>

double scalar_product(const std::vector<double>& v1, const std::vector<double>& v2){
  if (v1.size() != v2.size() || v1.size() <= 0) {std::cout << "Dimension error, operation cannot be performed.\n";}
  double total = 0;
  for (int i = 0;i<v1.size();i++){
    total += v1.at(i) * v2.at(i);
  }
  return total;
}

std::vector<double> column_index(const std::vector<std::vector<double>>& m, int index) {
  std::vector<double> out;
  for (std::vector<double> row : m){
    out.push_back(row[index]);
  }
  return out;
}

std::vector<std::vector<double>> multiply_matrix(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m2){
  std::vector<double> row;
  std::vector<std::vector<double>> result;
  for (int i=0;i<m1.size();i++){
    row.clear();
    for (int j = 0; j < m1[0].size();j++) {
      row.push_back(scalar_product(m1[i],column_index(m2,j)));
    }
    result.push_back(row);
  }
  return result;
}


std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    // we can use a stringstream as if it were a stream object 
    // such as std::cout or something of type
    // std::ifstream or std::ofstream

    ss << s;
    while(ss >> tmp){
        // std::stod converts from string to double
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){

    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    // std::getline reads a whole line as a string
    // by default the separator is the newline
    // rather than any whitespace
    while(std::getline(infile, line)){
        out.push_back(line_to_vector(line));
    }

    return out;
}

// sum of two matrices
std::vector<std::vector<double>> 
matrix_sum
(
    const std::vector<std::vector<double>>& m1,
    const std::vector<std::vector<double>>& m2
)
{ 

    std::vector<std::vector<double>> out;

    for(int i = 0; i < m1.size(); i++){

        std::vector<double> row;
        for(int j = 0; j < m1[0].size(); j++){

            // bidimensional indexing
            row.push_back(m1[i][j] + m2[i][j]);
        }
        out.push_back(row);

    }

    return out;

}

std::string matrix_to_string(std::vector<std::vector<double>> m){

    std::stringstream out;
    // to set precision when printing
    out << std::fixed << std::setprecision(2);

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }

    // getting the std::string representation 
    // of this std::stringstream object
    return out.str();
}

int main(int argc, char* argv[]){

    if(argc != 3){
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]);
    std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]);

    std::vector<std::vector<double>> m3 = matrix_sum(m1, m2);

    std::cout << matrix_to_string(m1) << std::endl;
    std::cout << "+" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;

    std::cout << matrix_to_string(multiply_matrix(m1,m2));
    


  return 0;
}
