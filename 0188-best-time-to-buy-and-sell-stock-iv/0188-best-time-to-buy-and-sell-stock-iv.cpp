class Solution {
public:
    // int getMaxProfitToBuyAndSellStock(int ind,int OperationNo,int k, int n,vector<int>& prices){
    //     if(ind==n) return 0;
    //     if(OperationNo==2*k) return 0;
       
    //     int profit = 0;

    //     if(OperationNo%2==0){
    //         int buy = -prices[ind]+ getMaxProfitToBuyAndSellStock(ind+1,OperationNo+1,k,n,prices);
    //         int notBuy = 0 + getMaxProfitToBuyAndSellStock(ind+1,true,k,n,prices);
    //         profit = max(buy,notBuy);
    //     }
    //     else{
    //         int sell = prices[ind]+getMaxProfitToBuyAndSellStock(ind+1,OperationNo+1,k,n,prices);
    //         int notSell = 0 + getMaxProfitToBuyAndSellStock(ind+1,false,k,n,prices);
    //         profit = max(sell,notSell);
    //     }
    //     return profit;
    //     }
    // int getMaxProfitToBuyAndSellStockMEM(int ind,int OperationNo,int k, int n,vector<int>& prices, vector<vector<int>> &dp){
    //     if(ind==n) return 0;
    //     if(OperationNo==2*k) return 0;

    //     if(dp[ind][OperationNo]!=-1) 
    //     return dp[ind][OperationNo];
       
    //     int profit = 0;
    //     if(OperationNo%2==0){
    //         int buy = -prices[ind]+ getMaxProfitToBuyAndSellStockMEM(ind+1,OperationNo+1,k,n,prices,dp);
    //         int notBuy = 0 + getMaxProfitToBuyAndSellStockMEM(ind+1,OperationNo,k,n,prices,dp);
    //         profit = max(buy,notBuy);
    //     }
    //     else{
    //         int sell = prices[ind]+getMaxProfitToBuyAndSellStockMEM(ind+1,OperationNo+1,k,n,prices,dp);
    //         int notSell = 0 + getMaxProfitToBuyAndSellStockMEM(ind+1,OperationNo,k,n,prices,dp);
    //         profit = max(sell,notSell);
    //     }
    //     return dp[ind][OperationNo] = profit;
    //     }

    int getMaxProfitToBuyAndSellStockTAb(int k,vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int operationNo = 2*k-1; operationNo >= 0; operationNo--){

                int profit = 0;
                if( (operationNo&1) == 0 ){
                    int choose = -prices[index] + dp[index+1][operationNo+1];
                    int skip = 0 + dp[index+1][operationNo];

                    profit = max(choose, skip);
                }
                else{
                    int choose = prices[index] + dp[index+1][operationNo+1];
                    int skip = 0 + dp[index+1][operationNo];

                    profit = max(choose, skip);
                }

                dp[index][operationNo] = profit;

            }
        }

        return dp[0][0];
   }


   int getMaxProfitToBuyAndSellStockSO(int k,vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int index = n-1; index >= 0; index--){
            for(int operationNo = 2*k-1; operationNo >= 0; operationNo--){

                int profit = 0;
                if( (operationNo&1) == 0 ){
                    int choose = -prices[index] + next[operationNo+1];
                    int skip = 0 + next[operationNo];

                    profit = max(choose, skip);
                }
                else{
                    int choose = prices[index] + next[operationNo+1];
                    int skip = 0 + next[operationNo];

                    profit = max(choose, skip);
                }

                curr[operationNo] = profit;

            }

            next = curr;
        }

        return curr[0];
   }
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // int ind = 0;
        // int ans = getMaxProfitToBuyAndSellStock(ind,0,k, n,prices);
        // vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
        // int ans = getMaxProfitToBuyAndSellStockMEM(ind,0,k, n,prices,dp);
        // int ans = getMaxProfitToBuyAndSellStockTAb(k,prices);
         int ans = getMaxProfitToBuyAndSellStockSO(k,prices);
      
        return ans;
    }
};