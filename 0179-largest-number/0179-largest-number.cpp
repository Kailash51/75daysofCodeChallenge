class Solution {
public:
static bool myComp(string a, string b){
    string t1 = a+b;
    string t2 = b+a;
    return t1>t2;
}
    string largestNumber(vector<int>& nums) {
        vector<string> stringNums;
        for(auto it: nums){
            stringNums.push_back(to_string(it));
        }

        sort(stringNums.begin(), stringNums.end(), myComp);
        if(stringNums[0] == "0"){
            return "0";
        }
        string largestNumber = "";
        for(auto it: stringNums){
            largestNumber += it; 
        }
        return largestNumber;

    }
};