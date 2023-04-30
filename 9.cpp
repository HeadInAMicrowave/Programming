#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool palindrome(int x){
    auto result = to_string(x);
    auto reverse_result = reverse(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++){
        if (result[i] != reverse_result[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int x = 10001;
    cout << palindrome(x);
}