class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Gap Method
        
        int cnt = 0;
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[cnt];
            cnt++;
        }
        int gap = ceil((m+n)/2.0);
        
        while(gap>=1){
            int lo = 0;
            int hi = lo+gap;
            while(hi<m+n){
                if(nums1[hi]<=nums1[lo]) {
                  swap(nums1[lo],nums1[hi]);
                }
                lo++;
                hi++;
            }
            if(gap==1) break;
            gap = ceil(gap/2.0);
        }
        
        
    }
};