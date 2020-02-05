// https://leetcode-cn.com/problems/relative-sort-array/submissions/

#include <algorithm>

class Solution {
public:
    // 暴力查找
    vector<int> relativeSortArray1(vector<int>& arr1, vector<int>& arr2) {        
        vector<int> subArr1;
        vector<int> subArr2;
        for (int i = 0; i < arr1.size(); i++) {
            if (find(arr2.begin(), arr2.end(), arr1[i]) == arr2.end()) {
                subArr2.push_back(arr1[i]);
            } else {
                subArr1.push_back(arr1[i]);
            }
        }
        // 按 arr2的顺序调整 subArr1
        arr1.clear();
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < subArr1.size(); j++) {
                if (subArr1[j] == arr2[i]) {
                    arr1.push_back(subArr1[j]);
                }
            }
        }
        // subArr2按升序排列
        sort(subArr2.begin(), subArr2.end());
        arr1.insert(arr1.end(), subArr2.begin(), subArr2.end());
        return arr1;
    }

    // count 函数统计元素出现次数
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {        
        vector<int> subArr1;
        vector<int> subArr2;
        for (int i = 0; i < arr2.size(); i++) {
            // 计算arr2[i]在 arr1中出现的次数
            int cnt = count(arr1.begin(), arr1.end(), arr2[i]);
            while (cnt > 0) {
                subArr1.push_back(arr2[i]);
                cnt--;
            }
        }
        for (int i = 0; i < arr1.size(); i++) {
            if (find(arr2.begin(), arr2.end(), arr1[i]) == arr2.end()) {
                subArr2.push_back(arr1[i]);
            }
        }
        sort(subArr2.begin(), subArr2.end());
        subArr1.insert(subArr1.end(), subArr2.begin(), subArr2.end());
        return subArr1;
    }
};