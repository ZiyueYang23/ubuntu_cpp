// @ 哈希查找的核心代码
// ~ 对哈希表知识的熟练掌握
// ~ 时间复杂度是1
// ~ 空间复杂度是n

// vector<int> HashSearch(vector<int> nums, int target)
// {
//     int i(0);
//     int size(nums.size());
//     unordered_map<int, int> u_map;
//     for (int i(0); i < size; i++)
//     {
//         if (u_map.find(target - nums[i]) != u_map.end())
//         {
//             return {u_map[target - nums[i]], i};
//         }
//         u_map.emplace(nums[i], i);
//     }
//     return {};
// }

// @ 示例
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> HashSearch(vector<int> nums, int target);

int main(void)
{
    vector<int> nums1{1, 2, 3, 5, 4, 3, 2, 6, 8, 9, 2, 4, 8};
    sort(nums1.begin(), nums1.end());
    for (auto num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    vector<int> paly = HashSearch(nums1, 6);
    for (auto num : paly)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

vector<int> HashSearch(vector<int> nums, int target)
{
    int i(0);
    int size(nums.size());
    unordered_map<int, int> u_map;
    for (int i(0); i < size; i++)
    {
        if (u_map.find(target - nums[i]) != u_map.end())
        {
            return {u_map[target - nums[i]], i};
        }
        u_map.emplace(nums[i], i);
    }
    return {};
}