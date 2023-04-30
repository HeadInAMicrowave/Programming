class Solution {
public:
    string intToRoman(int num) {
        string result;
        int temp = num;
        int i = 1;

        while (temp >= 10){
            temp /= 10;
            i++;
        }
        cout << num << endl;
        if (i == 4){
            for (int j = 0; j < temp; j++){
                result += "M";
            }
        }
        if (i == 3){
            if ((temp >= 1 && temp <= 3)){
                for (int j = 0; j < temp; j++){
                    result += "C";
                }
            }
            else if (temp >= 5 && temp <= 8){
                result += "D";
                for (int j = 0; j < (temp - 5); j++){
                    result += "C";
                }
            }
            else if (num == 4){
                result += "CD";
            }
            else {
                result += "CM";
            }
        }
        if (i == 2){
           if ((temp >= 1 && temp <= 3)){
                for (int j = 0; j < temp; j++){
                    result += "X";
                }
            }
            else if (temp >= 5 && temp <= 8){
                result += "L";
                for (int j = 0; j < (temp - 5); j++){
                    result += "X";
                }
            }
            else if (num == 4){
                result += "XL";
            }
            else {
                result += "XC";
            }
        }
        if (i == 1){
            if ((num >= 1 && num <= 3)){
                for (int j = 0; j < num; j++){
                    result += "I";
                }
            }
            else if (num >= 5 && num <= 8){
                result += "V";
                for (int j = 0; j < (num - 5); j++){
                    result += "I";
                }
            }
            else if (num == 4){
                result += "IV";
            }
            else {
                result += "IX";
            }
            return result;
        }
        int next = num % 10^i;
        return result + intToRoman(next);
    }
};