class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        for (int x : nums) {
            ans.push_back(x);
            while (ans.size() > 1) {
                long long a = ans.back(), b = ans[ans.size() - 2];
                if (a != b) break;
                ans.pop_back(); ans.pop_back();
                ans.push_back(a * 2);
            }
        }
        return ans;
    }
};
