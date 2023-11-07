class Solution {
    int solveMemo(int ind,bool canBuy,int cap, int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(ind==n) return 0;
        if(cap==0) return 0;
        if(dp[ind][canBuy][cap]!=-1) 
        return dp[ind][canBuy][cap];
        int profit = 0;
        if(canBuy){
            int buy = -prices[ind]+ solveMemo(ind+1,false,cap,n,prices,dp);
            int notBuy = 0 + solveMemo(ind+1,true,cap,n,prices,dp);
            profit = max(buy,notBuy);
        }
        else{
            int sell = prices[ind]+solveMemo(ind+1,true,cap-1,n,prices,dp);
            int notSell = 0 + solveMemo(ind+1,false,cap,n,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[ind][canBuy][cap]= profit;
    }
    int solveTabu(int n,vector<int>& prices){
        // no need to write for base case as dp is already filled with 0
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap =1;cap<=2;cap++){
                    int profit = INT_MIN;
                    if(canBuy){
                        int buy = -prices[ind]+ dp[ind+1][0][cap];
                        int notBuy = 0 +  dp[ind+1][1][cap];
                        profit = max(buy,notBuy);
                    }
                    else{
                        int sell = prices[ind]+ dp[ind+1][1][cap-1];
                        int notSell = 0 +  dp[ind+1][0][cap];
                        profit = max(sell,notSell);
                    }
                    dp[ind][canBuy][cap]= profit;
                }
            }
        }
        return dp[0][1][2];
    }
    int spaceOpti(int n,vector<int>& prices){
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                for(int cap =1;cap<=2;cap++){
                    int profit = INT_MIN;
                    if(canBuy){
                        int buy = -prices[ind]+ next[0][cap];
                        int notBuy = 0 +  next[1][cap];
                        profit = max(buy,notBuy);
                    }
                    else{
                        int sell = prices[ind]+ next[1][cap-1];
                        int notSell = 0 +  next[0][cap];
                        profit = max(sell,notSell);
                    }
                    curr[canBuy][cap]= profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // MEMOIATION
        // bool canBuy = true;
        // int cap = 2;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solveMemo(0,canBuy,cap,n,prices,dp);

        // TABULATION
        // return solveTabu(n,prices);

        return spaceOpti(n,prices);

    }
};