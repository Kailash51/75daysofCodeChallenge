class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // // brute force t.c = O(n^2)

        // for(int  index =0; index<n; index++){
        //     for(int  indexj =index+1; indexj<n; indexj++){
        //         if(nums[index]==nums[indexj]){
        //             return true;
        //         }
        //     }
        // }

        // return false;

        // using sort t.c = O(nlogn)

        // Hash set t.c = O(n)
        
        // unordered_set<int> seen;
        // for (int num = 0; num<n; num++) {
        //     if (seen.count(nums[num]) > 0)
        //         return true;
        //     seen.insert(nums[num]);
        // }
        // return false;

        //map t.c = O(n)
        // s.c = O(1)

        unordered_map<int,int> mp;
        for (int num = 0; num<n; num++){
            if(mp[nums[num]]>=1){
                return true;
            }
            mp[nums[num]]++;
            
            
        }
        return false;
        

  
    }
};