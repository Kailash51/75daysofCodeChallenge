class Solution {
public:
int firstOccurence(vector<int>&arr, int key){
    int sizeOfNums = arr.size();
    int start_index = -1;
    int start = 0 , end  = sizeOfNums-1;
    while(start<=end){
        int middle = start + (end - start)/2;
        if(arr[middle] > key) end = middle-1;
        else if(arr[middle] < key)  start = middle+1;
        else{
            start_index = middle;
            end = middle-1;
        }
    }
    return start_index;
}
int lastOccurence(vector<int>&arr, int key){
    int sizeOfNums = arr.size();
    int end_index = -1;
    int start = 0 , end  = sizeOfNums-1;
    while(start<=end){
        int middle = start + (end - start)/2;
        if(arr[middle] > key) end = middle-1;
        else if(arr[middle] < key)  start = middle+1;
        else{
            end_index = middle;
            start = middle+1;
        }
    }
    return end_index;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> firstAndLastOcc(2);
        firstAndLastOcc[0] = firstOccurence(nums,target);
        firstAndLastOcc[1] = lastOccurence(nums,target);
        return firstAndLastOcc;
    }        
};