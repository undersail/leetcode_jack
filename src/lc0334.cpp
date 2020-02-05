// https://leetcode-cn.com/problems/reverse-string/submissions/

#include <algorithm>

class Solution {
public:
    // 双指针
    void reverseString1(vector<char>& s) {
        int head = 0;
        int tail = s.size() - 1;
        while (head < tail) {
            char temp = s[head];
            s[head] = s[tail];
            s[tail] = temp;
            head++;
            tail--;
        }
    }

    // STL reverse 函数
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};