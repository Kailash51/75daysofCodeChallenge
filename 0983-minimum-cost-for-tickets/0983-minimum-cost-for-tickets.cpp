class Solution {
public:
    int minimumCost(vector<int>& days, vector<int>& costs, int index){
        int daysArraySize = days.size();
        int mini = INT_MAX;
        if(index>=daysArraySize) return 0;

        int oneDayPassCost = costs[0] + minimumCost(days,costs,index+1);

        int index2 =index;
        int passEndDay = days[index] + 7-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }
        int sevenDayCost = costs[1] +  minimumCost(days,costs,index2);

         index2 =index;
        passEndDay = days[index] + 30-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }

         int thirtyDayCost = costs[2] +  minimumCost(days,costs,index2);

         return mini = min(thirtyDayCost,min(sevenDayCost,oneDayPassCost));
    }


    int minimumCostMEM(vector<int>& days, vector<int>& costs, int index, vector<int>& memo){
        int daysArraySize = days.size();
        int mini = INT_MAX;
        if(index>=daysArraySize) return 0;

        if(memo[index] != -1) return memo[index];

        int oneDayPassCost = costs[0] + minimumCostMEM(days,costs,index+1,memo);

        int index2 =index;
        int passEndDay = days[index] + 7-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }
        int sevenDayCost = costs[1] +  minimumCostMEM(days,costs,index2,memo);

        index2 =index;
        passEndDay = days[index] + 30-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }

        int thirtyDayCost = costs[2] +  minimumCostMEM(days,costs,index2,memo);

        memo[index] = min(thirtyDayCost,min(sevenDayCost,oneDayPassCost));
        return memo[index];
    }
       
     int minimumCostTAB(vector<int>& days, vector<int>& costs){
        int daysArraySize = days.size();
        vector<int> memo(366,INT_MAX);
        memo[daysArraySize] = 0;

        for(int index1 = daysArraySize-1; index1>=0; index1--){
            
        int oneDayPassCost = costs[0] + memo[index1+1];

        int index2 =index1;
        int passEndDay = days[index1] + 7-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }
        int sevenDayCost = costs[1] + memo[index2];

        index2 =index1;
        passEndDay = days[index1] + 30-1;
        while(index2<daysArraySize && days[index2] <=passEndDay){
            index2++;
        }

        int thirtyDayCost = costs[2] + memo[index2];

        memo[index1] = min(thirtyDayCost,min(sevenDayCost,oneDayPassCost));
       
        }
         return memo[0];

     }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return minimumCost(days, costs, 0);
        // int daysArraySize = days.size();
        // vector<int> memo(daysArraySize+1,-1);
        // return minimumCostMEM(days, costs, 0,memo);
        return minimumCostTAB(days, costs);
    }
};