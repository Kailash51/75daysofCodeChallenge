class Solution {
public:
//n -> represents the index of current house
int maximumNonAdjacentSum(vector<int>& arr, int n)
 {
     
    if(n < 0 )
        return 0;
    if(n == 0) {
        return arr[0];
    }

    //include
    int include = maximumNonAdjacentSum(arr, n-2) + arr[n];
    int exclude = maximumNonAdjacentSum(arr, n-1) + 0;

    return max(include, exclude);
}

int maximumNonAdjacentSumMEM(vector<int>& arr, int n,vector<int>& dp)
 {
     
    if(n < 0 )
        return 0;
    
    
    if(dp[n]!= -1) {
        return dp[n];
    }

    //include
    int include = maximumNonAdjacentSumMEM(arr, n-2,dp) + arr[n];
    int exclude = maximumNonAdjacentSumMEM(arr, n-1,dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}



int solveUsingTabulation(vector<int>& nums, int n ) {
    
    vector<int> dp(n+1, 0);
    dp[0] = nums[0];

        for(int i=1; i<=n; i++) {

            int temp = 0;
            if(i-2>=0)
                temp = dp[i-2];
            
            int include = temp + nums[i];
            int exclude = dp[i-1] + 0;

            dp[i] =  max(include, exclude);
    }

    return dp[n];
}


int spaceOptimisedSolution(vector<int>& nums, int n ) {

    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;
    
        for(int i=1; i<=n; i++) {

            int temp = 0;
            if(i-2>=0)
                temp = prev2;
            
            int include = temp + nums[i];
            int exclude = prev1 + 0;

            curr =  max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
    }

    return prev1;
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int index = 0; index<n; index++){
            if(index!=0) temp1.push_back(nums[index]);
            if(index != n-1) temp2.push_back(nums[index]);
        }

        // return  max(maximumNonAdjacentSum(temp1,temp1.size()-1), maximumNonAdjacentSum(temp2,temp2.size()-1));
        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);
         return  max(maximumNonAdjacentSumMEM(temp1,temp1.size()-1,dp1), maximumNonAdjacentSumMEM(temp2,temp2.size()-1,dp2));
        

    }
};                     