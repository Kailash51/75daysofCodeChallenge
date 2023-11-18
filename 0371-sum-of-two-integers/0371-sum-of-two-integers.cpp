class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            // take Carry then shift
            int temp = (a&b) << 1;
            //XOR
            a = a^b;
            b = temp;
        }
        return a;
    }

    // Time Complexity: The number of iterations in the while loop depends on the number of set bits in b. In the worst case, if b is large and has many set bits, the time complexity might be O(log(max(a, b))) considering the number of bits in the larger number.
};