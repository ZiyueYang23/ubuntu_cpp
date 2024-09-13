// @ 选择排序的核心代码
// ~ 需要使用swap函数头文件是utility 或者自己写一个
// ~ 时间复杂度是n的二次方
// ~ 空间复杂度是1
// ~ 默认是小到大

// void SelectSort(vector<int> &nums)
// {
//     int size = nums.size();
//     // 最后一个元素不需要排序
//     // 外循环 ：需要排序[0,n-1]的元素
//     for (int i(0); i < size - 1; i++)
//     {
//         // 从起始位置开始
//         int tmp = i;
//         // 内循环： 找到[i,n]中最小的元素
//         for (int j(i + 1); j < size; j++)
//         {
//             if (nums[j] < nums[tmp])
//             {
//                 // tmp最终是最小元素的索引
//                 tmp = j;
//             }
//         }
//         // 交换函数 头文件是ntility
//         swap(nums[i], nums[tmp]);
//     }
// }

// @ 示例

#include <iostream>
#include <vector>
// swap 函数所需要使用的头文件
#include <utility>

using namespace std;

void SelectSort(vector<int> &nums);

int main(void)
{
    vector<int> nums{9, 3, 5, 2, 4, 1, 5, 6, 2, 4, 9};
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    SelectSort(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
void SelectSort(vector<int> &nums)
{
    int size = nums.size();
    // 最后一个元素不需要排序
    // 外循环 ：需要排序[0,n-1]的元素
    for (int i(0); i < size - 1; i++)
    {
        // 从起始位置开始
        int tmp = i;
        // 内循环： 找到[i,n]中最小的元素
        for (int j(i + 1); j < size; j++)
        {
            if (nums[j] < nums[tmp])
            {
                // tmp最终是最小元素的索引
                tmp = j;
            }
        }
        // 交换函数 头文件是ntility
        swap(nums[i], nums[tmp]);
    }
}