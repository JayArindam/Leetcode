class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string a : words) {
            if (is_palindrome(a)){
                return a;
            }
        }
        return "";
    }
private:
    bool is_palindrome(string a) {
        string c = a;
        reverse(c.begin() , c.end());
        return a == c ? true : false;
    }
};