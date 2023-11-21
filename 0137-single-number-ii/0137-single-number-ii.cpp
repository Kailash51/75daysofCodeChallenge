class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Brute
        // TC: O(N)
        // SC: O(N)

        // unordered_map<int , int> freq;
        // int size = nums.size();
        // for(int val = 0; val<size; val++){
        //     freq[nums[val]]++;
        // }    
        // for(auto x:freq){
        //     if(x.second == 1){
        //         return x.first;
        //     }
        // }
    
        // return -1;



        // Better
        // TC: O(Nlogn)
        // SC: O(1)
    //     int size = nums.size();
    //     sort(nums.begin(), nums.end());
         
    //   if(size<3){
    //       return nums[0];
    //   }

    //   if(nums[0]!= nums[1]){
    //       return nums[0];
    //     }
    //     int val = 1;
    //     while(val<size){
    //         if(nums[val]!= nums[val-1]){
    //         return nums[val-1];
    //         }
    //         val+=3;
            
    //     }
    //      return nums[size-1];
    // }

  //Bt manipulation
    // int ans = 0;

    // for (int i = 0; i < 32; ++i) {
    //   int sum = 0;
    //   for (const int num : nums)
    //     sum += num >> i & 1;
    //   sum %= 3;
    //   ans |= sum << i;
    // }

    // return ans;

        //  Magic:
     int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }


    
};