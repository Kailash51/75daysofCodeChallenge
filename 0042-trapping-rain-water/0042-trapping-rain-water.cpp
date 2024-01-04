// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int size = height.size();
//         vector<int> leftMax(size);
//         leftMax[0] = height[0];
//         vector<int> rightMax(size);
//         rightMax[size-1] = height[size-1];

//         int left = 1;
//         int right = size-2;

//         while(left<size && right>=0){
//             leftMax[left] = max(leftMax[left-1], height[left]);
//             rightMax[right] = max(rightMax[right+1], height[right]);
//             left++;
//             right--;
//         }
//         int totalRainTrapped = 0;
//         for(int ind = 0; ind<size; ind++){
//             totalRainTrapped += (min(leftMax[ind],rightMax[ind]))-height[ind];
//         }
//         return totalRainTrapped;
//     }
// };

        class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& height) {
        int left = 0,right = height.size()-1;
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int totalRainTrapped=0;
        while(left<right){
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            totalRainTrapped += (leftMax < rightMax)? leftMax-height[left++]: rightMax-height[right--];
        }
        return totalRainTrapped;
    }
};
        





