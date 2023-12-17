class Solution {
public:
int minimumTotalCost(int left, int right, vector<int>& cuts){
    if(left>right) return 0;
    int minimumCost = INT_MAX;
    for(int index = left; index<=right; index++){
        int cost = cuts[right+1] - cuts[left-1] + minimumTotalCost(left, index-1,cuts) + minimumTotalCost(index+1, right,cuts);
        minimumCost = min(minimumCost,cost);
    }
    return minimumCost;
    
}
    int minimumTotalCostMEM(int left, int right, vector<int>& cuts, vector<vector<int>> &memo){
        if(left>right) return 0;
        if(memo[left][right] !=-1) return memo[left][right];
    int minimumCost = INT_MAX;
    for(int index = left; index<=right; index++){
        int cost = cuts[right+1] - cuts[left-1] + minimumTotalCostMEM(left, index-1,cuts,memo) + minimumTotalCostMEM(index+1, right,cuts,memo);
        minimumCost = min(minimumCost,cost);
    }
    return memo[left][right] = minimumCost;
    }


    // int minimumTotalCostTAB(vector<int>& cuts){
    //     int cutsSize = cuts.size();
    //     vector<vector<int>> memo(cutsSize+2, vector<int>(cutsSize+2,0));
      
    // int r_index,l_index;
        
    //     for(l_index = cutsSize; l_index>=1; l_index--){

    //         for(r_index = 1; r_index<= cutsSize; r_index++){

    //             if(l_index>r_index) continue;

    //             int minimumCost = INT_MAX;
    //             for(int index =l_index;  index<=r_index; index++){

    //                 int cost = cuts[r_index+1] - cuts[l_index-1] + memo[l_index][index-1] + memo[index+1][r_index];
    //                 minimumCost = min(minimumCost,cost);
    //             }
    //             memo[l_index][r_index] = minimumCost;
                
    //         }
             
    //     }
    //     return memo[1][cutsSize];
        

   
    // }
    
    
    int minCost(int n, vector<int>& cuts) {
        int cutsSize = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());
        // int totalCost = minimumTotalCost(1,cutsSize,cuts);
        vector<vector<int>> memo(cutsSize+1, vector<int>(cutsSize+1, -1));
        int totalCost = minimumTotalCostMEM(1,cutsSize,cuts,memo);
        //  int totalCost = minimumTotalCostTAB(cuts);
        return totalCost;

 
    }
};