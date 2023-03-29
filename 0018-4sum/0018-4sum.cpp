class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> r;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        set<vector<int>>s;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long more =(long long)target - (long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                    if(binary_search(nums.begin()+k+1,nums.end(),more)){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(more);
                        
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                    
                    
                }
            }
        }
        for(auto it:s){
            r.push_back(it);
        }
        return r;
    }
};