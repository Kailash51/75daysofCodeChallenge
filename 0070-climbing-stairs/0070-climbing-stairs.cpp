class Solution {
public:
// brute Force TC =O(2^n) And Space Complexity O(n)
    int distinctWatsToClimTop(int num){
        if(num == 1 || num == 2) return num;

        int minimumSteps = distinctWatsToClimTop(num-1) + distinctWatsToClimTop(num-2);
        return minimumSteps;
    }

    int distinctWatsToClimTopMEM(int num,vector<int> &memDp){
        if(num == 1 || num == 2) return num;
        if(memDp[num] != -1){
            return memDp[num];
        }
        memDp[num] = distinctWatsToClimTopMEM(num-1,memDp) + distinctWatsToClimTopMEM(num-2,memDp);
        return memDp[num];
    }

    int distinctWatsToClimTopTab(int num){
         if(num == 1 || num == 2) return num;
         vector<int> memDp(46);
         memDp[1] = 1;
         memDp[2] = 2;

         for(int index = 3; index<=num; index++){
            memDp[index] =  memDp[index-1] + memDp[index-2];
         }
         return memDp[num];
    }
    int distinctWatsToClimTopOP(int num){
        if(num == 1 || num == 2) return num;
         int previousAns1 =1, previousAns2 = 2;
         for(int index = 3; index<=num; index++){
            int currentAns = previousAns1+previousAns2;
            previousAns1 = previousAns2;
            previousAns2 = currentAns;
           
        }
         return previousAns2;
    }
    int climbStairs(int n) {
        // return distinctWatsToClimTop(n);
        // vector<int> memDp(46,-1);
        // return distinctWatsToClimTopMEM(n, memDp);   
        //  return distinctWatsToClimTopTab(n); 
         return distinctWatsToClimTopOP(n); 

    }
};