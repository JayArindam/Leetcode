class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        vector<pair<int, int>> indexedNums; 

        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.emplace_back(nums[i], i);
        }

        mergeSort(indexedNums, result);

        return result;
    }

private:
    void mergeSort(vector<pair<int, int>>& indexedNums, vector<int>& result) {
        if (indexedNums.size() <= 1) {
            return;
        }

        int mid = indexedNums.size() / 2;
        vector<pair<int, int>> left(indexedNums.begin(), indexedNums.begin() + mid);
        vector<pair<int, int>> right(indexedNums.begin() + mid, indexedNums.end());

        mergeSort(left, result);
        mergeSort(right, result);

        merge(indexedNums, left, right, result);
    }

    void merge(vector<pair<int, int>>& indexedNums, vector<pair<int, int>>& left, vector<pair<int, int>>& right, vector<int>& result) {
        int i = 0, j = 0;

        while (i < left.size() || j < right.size()) {
            if (j == right.size() || (i < left.size() && left[i].first <= right[j].first)) {
                indexedNums[i + j] = left[i];
                result[left[i].second] += j; 
                ++i;
            } else {
                indexedNums[i + j] = right[j];
                ++j;
            }
        }
    }
};
