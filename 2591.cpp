class Solution {
 public:
  int distMoney(int money, int children) {
    
    money -= children;
    if (money < 0)
      return -1;

    const int count7 = money / 7;
    const int remaining = money % 7;
    
    if (count7 == children && remaining == 0)
      return count7;
    
    if (count7 == children - 1 && remaining == 3)
      return count7 - 1;
    return min(children - 1, count7);
  }
};