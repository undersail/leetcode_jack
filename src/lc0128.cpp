// https://leetcode-cn.com/problems/longest-consecutive-sequence/

// 最大子序问题
// STL中，set/map 对应的数据结构是红黑树。红黑树是一种近似于平衡的二叉查找树，里面的数据是有序的。在红黑树上做查找操作的时间复杂度为 O(logN)。
// 而 unordered_set/unordered_map 对应哈希表，哈希表的特点就是查找效率高，时间复杂度为常数级别 O(1)， 而额外空间复杂度则要高出许多。
// 所以对于需要高效率查询的情况，使用 unordered_map 容器。而如果对内存大小比较敏感或者数据存储要求有序的话，则可以用 map 容器。
// https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/
// https://blog.csdn.net/vevenlcf/article/details/51743058

#include <unordered_map>

class Solution {
public:
    // 动态规划+HashMap
    int longestConsecutive1(vector<int>& nums) {
        // dp[i]表示当数字i在连续序列的左端或右端时的最大长度
        unordered_map<int, int> dp;
        int ret = 0;
        for(auto &x : nums) {
            if(!dp[x]) {
                // 根据 map 特性下标不存在时将自动插入空值，此处 dp[x] == 0意味着x元素尚未遍历过
                // 那么dp[x - 1]表示以 x-1为右端的子序长度，dp[x + 1]表示以 x+1为左端的子序长度
                dp[x] = dp[x - 1] + dp[x + 1] + 1;
                // [x-1], x, [x+1]拼接成功，更新左端点（x-dp[x-1])
                dp[x - dp[x - 1]] = dp[x];
                // 及右端点（x + dp[x + 1）dp 值
                dp[x + dp[x + 1]] = dp[x];
            }
            ret = max(ret, dp[x]);
        }
        return ret;
    }

    // 暴力枚举+HashSet
    int longestConsecutive(vector<int>& nums) {
        // 数据转存到 hash set中
        std::unordered_set<int> numSet;
        for (auto &num : nums) {
            numSet.insert(num);
        }
        int longestStreak = 0;
        for (auto num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                // 在set中找不到num的相邻较小数，则以num作为连续子序左端进行计算
                int currentNum = num;
                int currentStreak = 1;
                // 计算以num为左端的子序长度
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};