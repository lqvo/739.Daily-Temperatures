#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>ans;
        vector<vector<int>>index(101);
        for (int i = 0; i < T.size(); i++)
            index[T[i]].push_back(i);
        int big = *max_element(T.begin(), T.end());
        for (int i = 0; i < T.size() - 1; i++) {
            int temp = INT_MAX;
            for (int target = T[i] + 1; target <= big; target++) {
                if (index[target].empty() || index[target].back() <= i)continue;
                else {
                    auto p = upper_bound(index[target].begin(), index[target].end(), i);
                    temp = min(temp, *p - i);
                }
            }
            if (temp < INT_MAX)ans.push_back(temp);
            else ans.push_back(0);
        }
        ans.push_back(0);
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int>nums = { 73, 74, 75, 71, 69, 72, 76, 73 };
    vector<int>ans = sol.dailyTemperatures(nums);
    for (int i : ans)cout << i << "  ";
    return 0;
}