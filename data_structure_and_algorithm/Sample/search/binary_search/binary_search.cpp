// @ 二分查找的核心代码

// ~ 前提条件是已完成排序
// ~ 时间复杂度是logn
// ~ 空间复杂度是1

// 左闭右闭
// int BinarySearch(vector<int> vec, int target)
// {
//     int i(0);
//     int j(vec.size() - 1);
//     while (i <= j)
//     {
//         // 小细节 防止int类型越界
//         int middle = i + (j - i) / 2;

//         if (vec[middle] == target)
//         {
//             return middle;
//         }
//         else if (vec[middle] < target)
//         {
//             i = middle + 1;
//         }
//         else if (vec[middle] > target)
//         {
//             j = middle - 1;
//         }
//     }
//     return -1;
// }

// @ 示例

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 小到大
inline bool CmpLess(int a, int b);
// 大到小
inline bool CmpGreater(int a, int b);
// 左闭右闭
int BinarySearch(vector<int> vec, int target);

int main(void)
{
    vector<int> nums1{1, 2, 3, 5, 4, 3, 2, 6, 8, 9, 2, 4, 8};
    vector<int> nums2{9, 1, 2, 4, 6, 7, 8, 3, 2, 3, 4, 7};
    // 首地址 尾地址 比较函数的地址
    // sort 默认是小到大的排序
    sort(nums1.begin(), nums1.end(), CmpLess);
    sort(nums2.begin(), nums2.end(), CmpGreater);
    for (auto num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;
    for (auto num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;
    // 翻转函数
    reverse(nums2.begin(), nums2.end());
    for (auto num : nums2)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << BinarySearch(nums1, 1000) << endl;
    return 0;
}

inline bool CmpLess(int a, int b)
{
    a > b;
}

int BinarySearch(vector<int> vec, int target)
{
    int i(0);
    int j(vec.size() - 1);
    while (i <= j)
    {
        // 小细节 防止int类型越界
        int middle = i + (j - i) / 2;

        if (vec[middle] == target)
        {
            return middle;
        }
        else if (vec[middle] < target)
        {
            i = middle + 1;
        }
        else if (vec[middle] > target)
        {
            j = middle - 1;
        }
    }
    return -1;
}