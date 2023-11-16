class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int larg{-1};
        sort(nums.begin() , nums.end());
        for (int i{0} ; i < nums.size()-2 ; i++) {
            int temp{0};
            if (nums[i] + nums[i+1] > nums[i+2]) {
                temp = nums[i] + nums[i+1] + nums[i+2];
            }
            if (temp > larg) {
                larg = temp;
            }
        }
        return larg < 1 ? 0 : larg; 
    }
};