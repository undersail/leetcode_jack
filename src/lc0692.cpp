// https://leetcode-cn.com/problems/top-k-frequent-words/submissions/

// map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是有序的，红黑树的每一个节点都代表着map的一个元素，
// 因此，对于map进行的查找，删除，添加等一系列的操作都相当于是对红黑树进行这样的操作，故红黑树的效率决定了map的效率。
// unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的

#include <algorithm>
#include <map>

class Solution {
private:
    static bool pairCmp(const pair<string, int> &p1,const pair<string, int> &p2)
    {
        // 出现次数相同时按字母顺序
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        // 首先按出现次数倒序
        return p1.second > p2.second;
    }
public:
    // 用 map 保存每个单词的出现次数
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordCnt;
        for (int i = 0; i < words.size(); i++) {
            if (wordCnt.find(words[i]) == wordCnt.end()) {
                int cnt = count(words.begin(), words.end(), words[i]);
                wordCnt[words[i]] = cnt;
            }
        }
        // 将 key/value 放入到 vector<pair<>>类型变量中进行排序
        vector<pair<string, int>> res;
        for(map<string, int>::iterator it = wordCnt.begin(); it != wordCnt.end(); it++) {
            res.push_back(make_pair(it->first, it->second));
        }
        sort(res.begin(), res.end(), pairCmp);
        // 取出前 k 个单词
        vector<string> resWords;
        for(int i = 0; i < res.size() && i < k; i++) {
            resWords.push_back(res[i].first);
        }
        return resWords;
    }
};