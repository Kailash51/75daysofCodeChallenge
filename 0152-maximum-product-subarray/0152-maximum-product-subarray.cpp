class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // brute force

        //     int maxi  = INT_MIN;
        //     for(int i = 0; i<n; i++){
        //         int product = 1;
        //         for(int j =i; j<n; j++){
        //             product *= nums[j];
        //             maxi = max(maxi, product);
                    
        //         }
            
        //     }
        // return maxi;

        int leftProduct = 1;
        int rightProduct = 1;
        int maximum = INT_MIN;

        for(int i = 0; i<n; i++){
            
            if(leftProduct == 0){
                leftProduct = 1;
            }
            if(rightProduct == 0){
                rightProduct = 1;
            }
            leftProduct *= nums[i];
            rightProduct *= nums[n-i-1];
            
            
            maximum = max(maximum, max(leftProduct,rightProduct));
        }
        return maximum;

        
    }
};