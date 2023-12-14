class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // int minintervalRemove = INT_MAX;
        // vector<int> nonOverlappingInterval;
        // int index = 0;
        // int sizeOfIntervals = intervals.size();
        // sort(intervals.begins(), intervals.end());
        // while(index<sizeOfIntervals);
        //     if(intervals[index][1] > intervals[index+1][0]){
        //         ans++;
        //         if(intervals[index+1][1]<=intervals[index][1]){
        //             prev=curr;
        //         }
        //     }
        //     else {
        //         prev=curr;
        //     }
        // } 
        // return ans;
        // }
         int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int prev = 0;
        int ans=0;

        for(int curr=1;curr<n;curr++){
            if(intervals[curr][0]<intervals[prev][1]){
                ans++;
                if(intervals[curr][1]<=intervals[prev][1]){
                    prev=curr;
                }
            }
            else {
                prev=curr;
            }
        } 
        return ans;
        
    }
};