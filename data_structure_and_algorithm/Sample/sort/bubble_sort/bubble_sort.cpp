// @ 冒泡排序的核心代码
// ~ 时间复杂度是n的平方
// ~ 空间复杂度是1
// ~ 默认小到大
// void BubbleSort(std::vector<int> &nums)
// {
//     int size(nums.size());
//     // 优化算法
//     bool flag = false;
//     // 第一轮是[0,n],需要交换n次
//     // 第二轮是[0,n-1]，需要交换n-1次
//     // 依次递减 因此用i--
//     for (int i(size - 1); i > 0; i--)
//     {
//         // 每轮都是从最左端开始将此轮最大的元素送到右端
//         for (int j(0); j < i; j++)
//         {
//             // 左边比右边大就交换
//             if (nums[j] > nums[j + 1])
//             {
//                 swap(nums[j], nums[j + 1]);
//                 flag = true;
//             }
//         }
//         // 优化 如果这一轮没有发生交换则说明已经完成排序 后续不再需要进行循环了
//         if (flag == false)
//         {
//             break;
//         }
//     }
// }


// @ 示例

// @ bubble sort
#include <iostream>
#include <vector>
#include <utility>


void BubbleSort(std::vector<int> &nums);

int main(void)
{
    std::vector<int> nums{9, 3, 5, 2, 4, 1, 5, 6, 2, 4, 9};
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    BubbleSort(nums);
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
void BubbleSort(std::vector<int> &nums)
{
    int size(nums.size());
    // 优化算法
    bool flag = false;
    // 第一轮是[0,n],需要交换n次
    // 第二轮是[0,n-1]，需要交换n-1次
    // 依次递减 因此用i--
    for (int i(size - 1); i > 0; i--)
    {
        // 每轮都是从最左端开始将此轮最大的元素送到右端
        for (int j(0); j < i; j++)
        {
            // 左边比右边大就交换
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        // 优化 如果这一轮没有发生交换则说明已经完成排序 后续不再需要进行循环了
        if (flag == false)
        {
            break;
        }
    }
}
