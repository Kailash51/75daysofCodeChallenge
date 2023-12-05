class Solution {
public:
    string intToRoman(int num) {
        string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string output = "";

        for(int index = 0; index<13; index++){
            while(num>=values[index]){
                output += romanSymbols[index];
                num -= values[index]; 
            }
        }
        return output;
    }
};