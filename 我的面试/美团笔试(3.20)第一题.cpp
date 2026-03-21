#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T, n;
    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        
        // 先排序，再利用 unique 去重
        sort(nums.begin(), nums.end());
        int unique_count = unique(nums.begin(), nums.end()) - nums.begin();
        
        cout << unique_count << "\n";
    }
    return 0;
}
