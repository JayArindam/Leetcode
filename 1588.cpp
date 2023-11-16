class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            int sum = 0;
            for (int j = i; j < A.size(); j += 2) {
                sum += (j > i ? A[j - 1] : 0) + A[j];
                ans += sum;
            }
        }
        return ans;
    }
};