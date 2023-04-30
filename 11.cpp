#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int temp = 0;
        int i = 0, index1 = 0, index2 = height.size() - 1;
        vector<int>::iterator p1 = height.begin();
        vector<int>::iterator p2 = height.end() - 1;

        if (height.size() == 2){
            temp = (height[0] < height[1]) ? height[0] : height[1];
            return temp;
        }
        // for (int i = 0; i < height.size(); i++){
        //     for (int j = height.size() - 1; j >= 0; j--){
        //         temp = (height[i] > height[j]) ? height[j] * (j-i) : height[i] * (j-i);
        //         max = (temp > max) ? temp : max;
        //     }
        // }

        while(i < height.size()){
            cout << *p1 << " " << *p2 << endl;
            if (*p1 <= *p2){
                temp = abs(index2 - index1) * (*p1);

                index1++;
                p1++;
            }
            else if (*p2 < *p1){
                temp = abs(index2 - index1) * (*p2);

                index2--;
                p2--;
            }
            max = (temp > max) ? temp : max;
            i++;
        }
        return max;
    }
};

int main(){
    Solution sol;
    std::vector<int> height;

    sol.maxArea(height);
}