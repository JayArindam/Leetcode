class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int>height = heights;
        vector<string>ans;
        sort(height.begin(),height.end());
        reverse(height.begin(),height.end());
        for (const auto cur_hei : height) {
            for (int i{0} ; i<heights.size() ; i++) {
                if (heights[i] == cur_hei) {
                    ans.push_back(names[i]);
                }
            }
        }
        return ans;
    }
};