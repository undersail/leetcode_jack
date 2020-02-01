
#include <iostream>
#include <vector>

#include "lc0001.cpp"

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(12);
    nums.push_back(13);
    Solution a;
    vector<int> res = a.twoSum(nums, 25);
    for (int i = 0; i < res.size(); i++) {
        cout << i << ": " << res[i] << endl;
    }
    return 0;
}
