class Solution {
public:
    int minPartitions(string n) {
        int ans{0};
        for (int i{0} ; i<n.size() ; i++) {
            int q = n[i] - '0';
            if (q > ans) {
                ans = q; 
            }
        }
        return ans;
    }
};