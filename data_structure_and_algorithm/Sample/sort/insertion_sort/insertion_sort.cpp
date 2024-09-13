// @  插入排序的核心代码
// ~ 时间复杂度n的平方
// ~ 插入排序的性能要比冒泡或者选择排序高
// void InsertionSort(vector<int> &nums)
// {
//     int size(nums.size());
//     // 外循环：从第二个元素开始 第一个元素已经视为排好序
//     for (int i(1); i < size; i++)
//     {
//         // 储存需要排序位置的值
//         int base(nums[i]);
//         // j的索引就是需要排序位置的前一个 也就是已排序的最后一个
//         int j(i - 1);
//         // 循环的目的是让需要排序的那个位置的值与已排好序的元素逐一比较
//         while (j >= 0 && nums[j] > base)
//         {
//             // 如果比已排序的元素大就继续往前走
//             nums[j + 1] = nums[j];
//             j--;
//         }
//         // 最终会在首个小于或者等于base的位置停下 将其插入其后即可
//         nums[j + 1] = base;
//     }
// }

// @ insertion sort 示例
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void InsertionSort(vector<int> &nums);

int main(void)
{
    vector<int> nums{9, 3, 5, 2, 4, 1, 5, 6, 2, 4, 9};
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    InsertionSort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
// 注意理清楚思路
void InsertionSort(vector<int> &nums)
{
    int size(nums.size());
    // 外循环：从第二个元素开始 第一个元素已经视为排好序
    for (int i(1); i < size; i++)
    {
        // 储存需要排序位置的值
        int base(nums[i]);
        // j的索引就是需要排序位置的前一个 也就是已排序的最后一个
        int j(i - 1);
        // 循环的目的是让需要排序的那个位置的值与已排好序的元素逐一比较
        while (j >= 0 && nums[j] > base)
        {
            // 如果比已排序的元素大就继续往前走
            nums[j + 1] = nums[j];
            j--;
        }
        // 最终会在首个小于或者等于base的位置停下 将其插入其后即可
        nums[j + 1] = base;
    }
}
