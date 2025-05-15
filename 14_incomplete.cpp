//Incomplete

#include <iostream>
#include <vector>

class Solution {
    public:
        std::string shortestWord(std::vector<std::string>& vec){
            std::string shortestWord = vec[0];
            for (auto item : vec){
                if (item.length() < shortestWord.length()){
                    shortestWord = item;
                }
            }
            std::cout << shortestWord << std::endl;
            return shortestWord;
        }

        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            std::string result = "";
            // std::stringstream longWord;
            // std::string shortWord = this->shortestWord(strs);
            // int search = 0;
            int pos = strs[0].size();
            int temp_pos = 0;

            for (int i = 1; i < strs.size(); i++) {
                temp_pos = strs[i].find_first_not_of(strs[0]);
                std::cout << temp_pos << std::endl;
                if (temp_pos < pos && temp_pos != std::string::npos) {
                    pos = temp_pos;
                }
            }

            std::cout << pos << std::endl;

            result = strs[0].substr(0, pos);

            return result;
    }
};

int main(){
    Solution sol;

    std::vector<std::string> input = {"aa","ab"};
    std::string result;

    result = sol.longestCommonPrefix(input);

    std::cout << result << std::endl;
    return 0;
}