class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> r;
        for(int i= 0;i<m;i++){
            r.push_back(nums1[i]);
        }
        for(int i=0;i<n;i++){
            r.push_back(nums2[i]);
        }
        sort(r.begin(),r.end());
        
        
        for(int i=0;i<r.size();i++){
            nums1[i] = r[i];
        }
    }
};