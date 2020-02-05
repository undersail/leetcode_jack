// https://leetcode-cn.com/problems/palindrome-linked-list/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 利用栈特性实现（部分用例通过，总长度为奇数时不适用）
    bool isPalindrome1(ListNode* head) {
        stack<int> vals;
        while (head != nullptr) {
            if (vals.size() > 0 && vals.top() == head->val) {
                vals.pop();
            } else {
                vals.push(head->val);
            }
            head = head->next;
        }
        return (vals.size() == 0);
    }

    // 复制链表值到数组列表中，使用双指针法判断是否为回文
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        int end = vals.size() - 1;
        if (start >= end) {
            return true;
        }
        while (start <= end) {
            if (vals[start] != vals[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};