#include <iostream>
#include <unordered_map>

class Solution {
    public:
    int romanToInt(std::string s){
        std::unordered_map<char,int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;

        int result = 0;

        for (int i = 0; i <= s.length() - 1; i++){
            if (umap[s[i+1]] > umap[s[i]]){
                result -= umap[s[i]];
            } else {
                result += umap[s[i]];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    std::string s = "CMLII";

    int result = sol.romanToInt(s);

    std::cout << result;
    return 0;
}