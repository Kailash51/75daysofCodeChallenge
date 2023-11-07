class Solution {
public:

     int getMaxProfitToBuyAndSellStock(int  index, int buy, vector<int>& prices){
        int n = prices.size();
        if(index == n){
            return 0;
        }

        int profit = 0;
        if(buy){
            // -profit means you have to Buy
            profit = max((-prices[index] + getMaxProfitToBuyAndSellStock(index+1,0,prices)),(0+ getMaxProfitToBuyAndSellStock(index+1,1,prices)));
        }
        else{
            // +profit means you have to sell
            profit = max((+prices[index] + getMaxProfitToBuyAndSellStock(index+1,1,prices)),(0+ getMaxProfitToBuyAndSellStock(index+1,0,prices)));
        }
        return profit;
    }

    int getMaxProfitToBuyAndSellStockMEM(int  index, int buy, vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(index == n){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            // -profit means you have to Buy
            profit = max((-prices[index] + getMaxProfitToBuyAndSellStockMEM(index+1,0,prices,dp)),(0+ getMaxProfitToBuyAndSellStockMEM(index+1,1,prices,dp)));
        }
        else{
            // +profit means you have to sell
            profit = max((+prices[index] + getMaxProfitToBuyAndSellStockMEM(index+1,1,prices,dp)),(0+ getMaxProfitToBuyAndSellStockMEM(index+1,0,prices,dp)));
        }
        return dp[index][buy] = profit;
    }

    int getMaxProfitToBuyAndSellStockTAB(vector<int>& prices){
        int n = prices.size();
       vector<vector<int>> dp(n+1,vector<int>(2,0));

       int profit = 0;
       for(int index = n-1; index>=0; index--){
           for(int buy = 0; buy<2; buy++){
               if(buy){
                // -profit means you have to Buy
                profit = max((-prices[index] + dp[index+1][0]),(0+dp[index+1][1]));
               }
               else{
                // +profit means you have to sell
                profit = max((prices[index] + dp[index+1][1]),(0+dp[index+1][0]));
               }
                dp[index][buy] = profit;
            }
       }
        return dp[0][1];
    }

    int getMaxProfitToBuyAndSellStockSO(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        int profit = 0;
       for(int index = n-1; index>=0; index--){
           for(int buy = 0; buy<2; buy++){
               if(buy){
                // -profit means you have to Buy
                profit = max((-prices[index] + next[0]),(0+next[1]));
               }
               else{
                // +profit means you have to sell
                profit = max((prices[index] + next[1]),(0+next[0]));
               }
                curr[buy] = profit;
            }
            next = curr;
       }
        return next[1];

    }
   
    int maxProfit(vector<int>& prices) {
        // most optimal solution without dp
        int profit = 0;
        for( int i = 1; i<prices.size(); i++){
            if(prices[i]> prices[i-1]){
                profit += prices[i]-prices[i-1];

            }
        }
        return profit;
    }
        // int ind = 0;
        // int buy = 1;
        //  int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // int ans = getMaxProfitToBuyAndSellStock(ind,buy, prices);
        // int ans = getMaxProfitToBuyAndSellStockMEM(ind,buy, prices,dp);
        //   int ans = getMaxProfitToBuyAndSellStockTAB(prices);
        //   int ans = getMaxProfitToBuyAndSellStockSO(prices);
        // return ans;
        
    
};