class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         int n= nums.size();
//         vector<int> left(n, 1);
//         vector<int> right(n, 1);
//         vector<int> output(n,1);
       
//         // left[0] = 1;
//                 for(int i = 1; i<n; i++){
         
//             left[i] = nums[i-1] * left[i-1];
//         }
        
//         // right[nums.size()-1] = 1;
//                 for(int i = n-2; i>=0; i--){
         
//             right[i] = nums[i+1] * right[i+1];
//         }
//          for(int i = 0; i<n; i++){
//              output[i] = left[i]*right[i];
//          }
        
//         return output;
        
        
    int n = nums.size();
    vector<int> output(n, 1);

    // Calculate the product of all elements to the left of each element and store in the output vector.
    int left = 1;
    for (int i = 0; i < n; i++) {
        output[i] *= left;
        left *= nums[i];
    }

    // Calculate the product of all elements to the right of each element and update the output vector.
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
    }
};