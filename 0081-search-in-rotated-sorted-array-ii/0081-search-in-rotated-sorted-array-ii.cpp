class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Brute Force
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i]==target){
        //         return true;
        //     }
           
        // }
        //  return false;
        int lower = 0;
        int higher = nums.size()-1;
        
        while(lower<=higher){
            int mid = (lower+higher)/2;
            if(nums[mid] == target) return true;

            // id duplicate is present 
            if(nums[lower] == nums[mid] && nums[mid] == nums[higher]){
                higher -= 1;
                lower += 1; 
                continue;
            }
            
            // Identify Sorted Half -> left/right
            
            if(nums[lower] <= nums[mid]){
                //check the target lie between them
                if(nums[lower] <= target && target <= nums[mid]){
                    higher = mid-1;
                }
                else{
                    lower = mid+1;
                }
            }
            
            else{
                 if(nums[mid] <= target && target <= nums[higher]){
                    lower = mid+1;
                 }
                else{
                    higher = mid-1;
                }
               }                                          
                                                         
        }
        return false;
        

    }
};