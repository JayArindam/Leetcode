class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    long Max_count = 0;

    for (const string& s : sentences)
      Max_count = max(Max_count, ranges::count(s, ' '));

    return Max_count + 1;
  }
};
