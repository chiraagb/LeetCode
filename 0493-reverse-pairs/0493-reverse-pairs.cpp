class Solution {
public:
    int _merge(vector<int> &nums,vector<int> &temp,int lo,int mid,int hi){
        int inv = 0;
        int j = mid+1;
        for(int i=lo;i<=mid;i++){
            while(j<=hi && nums[i] > 2LL*nums[j]){
                j++;
            }
            inv+=(j-(mid+1));
        }
        int left = lo;
        int right = mid+1;
        int k = 0;
        while(left<=mid && right<=hi){
            if(nums[left]<nums[right]){
                temp[k++]=nums[left++];
            }
            else{
                temp[k++]=nums[right++];
            }
        }
        while(left<=mid){
            temp[k++]=nums[left++];
        }
        while(right<=hi){
            temp[k++]=nums[right++];
        }
        
        int m= 0;
        
        for(int i=lo;i<=hi;i++){
            nums[i] = temp[m++];
        }
        
        return inv;
    }
    int _mergeSort(vector<int> &nums,vector<int> &temp, int lo,int hi){
        int inv =0;
        if(lo>=hi){
            return 0;
        }
        else{
            int mid = (lo+hi) >> 1;
            inv += _mergeSort(nums,temp,lo,mid);
            inv += _mergeSort(nums,temp,mid+1,hi);
            
            inv+= _merge(nums,temp,lo,mid,hi); 
        }
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return _mergeSort(nums,temp,0,nums.size()-1);
    }
};