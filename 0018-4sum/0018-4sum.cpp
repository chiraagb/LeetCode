class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        
        if(nums.empty()) return r;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left = j+1;
                int right = n-1;
                
                // target = 9
                // a[]={1,1,1,2,2,3,3,4,4,4}
                //      i j l             r
                // remaining = 7
                // 1+4 = 5 < remaining
                long long rem = (long long)target - (long long)(nums[i]+nums[j]);
                
                while(left<right){
                    int two_sum = nums[left]+nums[right];
                    if(two_sum == rem){
                        vector<int> temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        
                        r.push_back(temp);
                        while(left<right && nums[left]==temp[2]) left++;
                        while(left<right && nums[right]==temp[3]) right--;
                    }
                    else if(two_sum<rem){
                        left++;
                    }
                    else{
                        right--;
                    }
                    
                }
                
                while(j+1<n && nums[j+1]==nums[j]) ++j;
                
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        
        
        return r;
    }
};