class Solution {
public:
    long long int mod = 1000000007;
    long long int possibleWaysRollDiceGetTargetSum(int n, int k, int target){
        if(n<0) return 0;
        if(n==0 && target ==0) return 1; // dice bhi khatam ho gayi aur target bhi achieve ho gaya then return 1;
        if(n==0 && target !=0) return 0;
        if(n!=0 && target ==0) return 0;


        long long int ans = 0;
        for(int i = 1; i<=k; i++){ // question say number of ways that's why use for loop;
            long long int recAns = 0;
            if(target -i >=0){
                recAns = possibleWaysRollDiceGetTargetSum(n-1,k,target-i);
                ans = (ans%mod + recAns%mod)%mod;
            }
        }
        return ans;

    }

    long long int possibleWaysRollDiceGetTargetSumMEM(int n, int k, int target,vector<vector<long long int>>&dp){
        if(n<0) return 0;
        if(n==0 && target ==0) return 1;
        if(n==0 && target !=0) return 0;
        if(n!=0 && target ==0) return 0;


        if(dp[n][target] !=-1){
            return dp[n][target];
        }


        long long int ans = 0;
        for(int i = 1; i<=k; i++){
            long long int recAns = 0;
            if(target -i >=0){
                recAns = possibleWaysRollDiceGetTargetSumMEM(n-1,k,target-i,dp);
                ans = (ans%mod + recAns%mod)%mod;
            }
            
        }
        dp[n][target] = ans;
        return dp[n][target];
    }


    long long int possibleWaysRollDiceGetTargetSumTAB(int &n, int k, int &target){
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1,0));

        dp[0][0] = 1;

        long long int ans = 0;
        for(int index = 1; index<=n; index++){
            for(int obj = 1; obj<=target; obj++){
                long long int ans = 0;
                for(int i = 1; i<=k; i++){
                    long long int recAns = 0;
                    if(obj -i >=0){
                        recAns =dp[index-1][obj-i];
                        ans = (ans%mod + recAns%mod)%mod;
                    }
                }
                 dp[index][obj] = ans;
            }
            
        }
        
        return dp[n][target];
    }
    int possibleWaysRollDiceGetTargetSumSO(int n, int k, int target) {

        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;

        for(int index = 1; index <=n; index++) {
            for(int t=1; t<=target; t++) {

                long long int ans = 0;
                for(int i=1; i<=k; i++) {
                    long long int recAns = 0;
                    if(t - i >= 0 )
                        recAns = prev[t-i];
                    ans = (ans % mod + recAns % mod) % mod;
                }
                curr[t] =  ans;
            }
            //shift
            prev = curr;
        }

    return prev[target];

    }

    
        

    

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1,-1)); 
        // long long int ans = possibleWaysRollDiceGetTargetSum(n,k,target);
        // long long int ans = possibleWaysRollDiceGetTargetSumMEM(n,k,target,dp);
        // long long int ans = possibleWaysRollDiceGetTargetSumTAB(n,k,target);
        long long int ans = possibleWaysRollDiceGetTargetSumSO(n,k,target);
        return ans;
    }
};