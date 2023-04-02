class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int rows = intervals.size();
        
        if(rows==1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> r;
        //In the sorted array, if start time of an interval is less than end of previous interval, then there is an overlap.
        
        int a = intervals[0][0];
        int b = intervals[0][1];
        
        for(int i=1;i<rows;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            
            if(start>=a && start<=b){
                a=min(a,start);
                b=max(b,end);
                if(i==rows-1){
                    r.push_back({a,b});
                }
            }
            else{
                r.push_back({a,b});
                a=start;
                b=end;
                if(i==rows-1){
                    r.push_back({start,end});
                }
            }
            
        }
        
        
        return r;
    }
};