#include <vector>
#include <unordered_map>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        std::unordered_map<int, int> hsh;
        for (int num : nums) {
            hsh[num]++;
        }
        int ans = 0;
        for (const auto& kv : hsh) {
            int val = kv.second;
            while (val) {
                if (val == 1) {
                    return -1;
                }
                if (val == 4 || val == 2) {
                    val -= 2;
                    ans++;
                } else {
                    val -= 3;
                    ans++;
                }
            }
        }
        return ans;
    }
};
