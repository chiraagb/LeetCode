class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
    //O(logn) || O(1)
        int idx = 0;
        int lo = 0;
        int hi = nums.size()-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            if(nums[mid] < target){
                lo = idx = mid+1;
            }
            else if(nums[mid]>target){
                hi = mid - 1;
            }
            else{
                return mid;
            }
            
        }
        return idx;
    }
};