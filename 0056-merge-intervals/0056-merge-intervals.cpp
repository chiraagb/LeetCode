class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<vector<int>> r;
        
        if(n == 0) return r;
        
        sort(intervals.begin(),intervals.end());
        
        // intervals[0] = [1,3]
        // temp[0] = 1
        // temp[1] = 3
        vector<int> temp = intervals[0];
        
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=temp[1]){
                temp[1] = max(intervals[i][1],temp[1]);
            }
            else{
                r.push_back(temp);
                temp = intervals[i];
            }
        }
        r.push_back(temp);
        
        
        return r;
    }
};