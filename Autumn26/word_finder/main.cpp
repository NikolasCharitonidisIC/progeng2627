#include <iostream>
#include <vector>



int first_letter_index(std::string word, std::string line) {
    if (word.size() > line.size()) {return -1;}//we just return -1 if the word is not in the line
    for (int i = 0;i <= line.size()-word.size();i++) {//Go through the possible starting letters
        bool matching = true;

        for (int j = 0;j < word.size();j++) {//go through the word
            if (line[i + j] != word[j]) {
                matching = false;
            }//now matching can only stay true if all letters matched
        }
        if (matching) {
            return i;//basically the same logic as before, but instead we return the starting index
        }
    }
    return -1;//if there is no instance of the first letter we return -1
}

std::string newword(std::string word, std::string row, int start_index) {
    for (int i = 0; i < word.size(); i++) {//Go through the word
        row[start_index + i] = word[i];//Replace the letters that correspond to the word, with the letters of the word. Leave the rest untouched because later on we initialized the solution to be full #
    }
    return row;
}

std::string get_col(const std::vector<std::string>& grid, int col_index){
    std::string out_word;//my output (return) word
    for (int row_index=0;row_index<grid.size();row_index++){
        out_word += grid[row_index][col_index];
    }
    return out_word;
}

void replace_col(std::vector<std::string>& grid,std::string newcol, int col_index){
    for (int char_index = 0; char_index < newcol.size(); char_index++){
        //go through each character of the word
        grid[char_index][col_index] = newcol[char_index];//replace all letters in that column
    }
}

bool num_in_vec(int num,const std::vector<int>& v){
    for (int i = 0; i<v.size();i++){
        if (v[i] == num) {return true;}
    }
    return false;
}

void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found){
        std::string hashline;
        for (int i = 0; i < grid[0].size();i++) {hashline += '#';}
        for (int i = 0; i< grid.size();i++) {solution.push_back(hashline);}//Start solution as full empty and add correct letters as we go
        std::vector<int> found_word_indices;
        // rows
        for (int word_index = 0; word_index < words.size(); word_index++) {
            for (int i = 0; i < grid.size(); i++) {
                int start = first_letter_index(words[word_index], grid[i]);
                if (start != -1) {//If word is in the row
                    solution[i] = newword(words[word_index], solution[i], start);//we replace the #s with the word letters
                    found_word_indices.push_back(word_index);//We also keep track of which words we found
                }
            }
        }

        // columns
        for (int word_index = 0; word_index < words.size(); word_index++) {//Check all words
            for (int j = 0; j < grid[0].size(); j++) {//Loop through the columns
                int start = first_letter_index(words[word_index], get_col(grid, j));//check where the word starts in this column
                if (start != -1) {//If the word is found somewhere in the column
                    replace_col(solution, newword(words[word_index], get_col(solution, j), start), j);
                    found_word_indices.push_back(word_index);
                }
            }
        }
        //Lastly we need to find which words were not found
        for (int i = 0; i < words.size();i++){//Go through all words
            if (!num_in_vec(i, found_word_indices)) {not_found.push_back(words[i]);}//If that was not recorded as found we add it to not_found
        }
    }

int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}
