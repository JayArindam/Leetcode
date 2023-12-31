enum class BoxCase { kEqualBalls, kEqualDistantBalls };

class Solution {
 public:
  double getProbability(vector<int>& balls) {
    const int n = accumulate(balls.begin(), balls.end(), 0) / 2;
    return cases(balls, 0, 0, 0, 0, 0, n, BoxCase::kEqualDistantBalls) /
           cases(balls, 0, 0, 0, 0, 0, n, BoxCase::kEqualBalls);
  }

 private:
  const vector<int> fact{1, 1, 2, 6, 24, 120, 720};

  double cases(const vector<int>& balls, int i, int ballsCountA,
               int ballsCountB, int colorsCountA, int colorsCountB, int n,
               BoxCase boxCase) {
    if (ballsCountA > n || ballsCountB > n)
      return 0;
    if (i == balls.size())
      return boxCase == BoxCase::kEqualBalls ? 1 : colorsCountA == colorsCountB;

    double ans = 0;

    for (int ballsTakenA = 0; ballsTakenA <= balls[i]; ++ballsTakenA) {
      const int ballsTakenB = balls[i] - ballsTakenA;
      const int newcolorsCountA = colorsCountA + (ballsTakenA > 0);
      const int newcolorsCountB = colorsCountB + (ballsTakenB > 0);
      ans += cases(balls, i + 1, ballsCountA + ballsTakenA,
                   ballsCountB + ballsTakenB, newcolorsCountA, newcolorsCountB,
                   n, boxCase) /
             (fact[ballsTakenA] * fact[ballsTakenB]);
    }

    return ans;
  }
};
