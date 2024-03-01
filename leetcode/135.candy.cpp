#include <vector>


using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> ans(n, 1);
    int val = 0;
    for (int i = 1; i < n; i++) {
      if (ratings[i] > ratings[i-1]) {
        ans[i] = ans[i-1] + 1;
      }
    }

    for (int j = n - 2; j >= 0; j--) {
      if (ratings[j] > ratings[j+1]) {
        ans[j] = max(ans[j+1] + 1, ans[j]);
      }
      val += ans[j];
      
    }
    val += ans[n-1];
    return val;
  }
};
