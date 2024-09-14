// @ 快速排序的核心代码
// ~ 时间复杂度是n log n
// ~ 做了许多优化的部分 取三个数的中位数为基数
// ~ 以及尾递归优化 这个地方可以再仔细体会体会
// ~ 其中最重要的是哨兵划分部分的代码
// ~ 分治思想的运用 采用递归的方式
// int Partition(vector<int> &nums, int left, int right)
// {
//     // 先取到合适的基数 将其放到最左端作为基数
//     int mid = GetMedian(nums, left, (left + right) / 2, right);
//     Swap(nums, left, mid);
//     // 左右哨兵
//     int i = left;
//     int j = right;
//     while (i < j)
//     {
//         // 右边哨兵开始找第一个小于基数的元素 准备要把该元素换到右边去，如果大于或者等于就继续往左走
//         while (i < j && nums[j] >= nums[left])
//         {
//             j--;
//         }
//         // 左边哨兵开始找第一个大于基数的元素 准备与右哨兵进行交换
//         while (i < j && nums[i] <= nums[left])
//         {
//             i++;
//         }
//         // 当内循环结束时，左右哨兵处在各自方向上首个需要交换的位置
//         Swap(nums, i, j);
//         // 交换完后此时i j位置上元素符合标准则继续进行往后走
//     }
//     // 最终i与j处在同一个位置上，结束此次哨兵划分
//     // 由于右边哨兵先走 所以j一定是停留在首个小于基数的元素，最后的情况左边的哨兵会与右边哨兵重合i=j于是结束循环
//     // 而此时这个元素的值一定是小于基数的 因此交换i 与left，把基数换到中间去，这个元素去最左端
//     Swap(nums, i, left);
//     return i;
// }
// void QuickSort(vector<int> &nums, int left, int right)
// {
//     while (left < right)
//     {
//         // 分治策略 完成哨兵划分后 分别在进行左子数组与右子数组的哨兵划分
//         int mid = Partition(nums, left, right);
//         // 先处理较小的子数组 减少递归深度 可以仔细思考思考
//         if (mid - left < right - mid)
//         {
//             QuickSort(nums, left, mid - 1);
//             left = mid + 1;
//         }
//         else
//         {
//             QuickSort(nums, mid + 1, right);
//             right = mid - 1;
//         }
//     }
// }

// @ 示例
// @  quick sort

#include <iostream>
#include <vector>

using namespace std;

void Swap(vector<int> &nums, int i, int j);
// 优化算法 尽可能的选择不大不小的数作为基数
int GetMedian(vector<int> &nums, int left, int mid, int right);
// 哨兵划分 分成两个子数组
int Partition(vector<int> &nums, int left, int right);
// 递归
void QuickSort(vector<int> &nums, int left, int right);

int main(void)
{
    vector<int> nums{9, 3, 5, 2, 4, 1, 5, 6, 2, 4, 9};
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    QuickSort(nums, 0, nums.size() - 1);
    for (auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

void Swap(vector<int> &nums, int i, int j)
{
    // 也可以用三个异或 效率其实差不多 而且处理不了相等元素
    int temp(nums[i]);
    nums[i] = nums[j];
    nums[j] = temp;
}

int GetMedian(vector<int> &nums, int left, int mid, int right)
{
    // 非常巧妙的异或
    // 异或是0^0=1^1=0,0^1=1^0=1
    // 这个函数的目的是获得 传进来三个数的中位数
    // 当if语句成立时，必定是一个比left大一个比left小 因此直接return left
    if (nums[left] < nums[mid] ^ nums[left] < nums[right])
    {
        return left;
    }
    else if (nums[mid] < nums[left] ^ nums[mid] < nums[right])
    {
        return mid;
    }
    else
    {
        return right;
    }
}
int Partition(vector<int> &nums, int left, int right)
{
    // 先取到合适的基数 将其放到最左端作为基数
    int mid = GetMedian(nums, left, (left + right) / 2, right);
    Swap(nums, left, mid);
    // 左右哨兵
    int i = left;
    int j = right;
    while (i < j)
    {
        // 右边哨兵开始找第一个小于基数的元素 准备要把该元素换到右边去，如果大于或者等于就继续往左走
        while (i < j && nums[j] >= nums[left])
        {
            j--;
        }
        // 左边哨兵开始找第一个大于基数的元素 准备与右哨兵进行交换
        while (i < j && nums[i] <= nums[left])
        {
            i++;
        }
        // 当内循环结束时，左右哨兵处在各自方向上首个需要交换的位置
        Swap(nums, i, j);
        // 交换完后此时i j位置上元素符合标准则继续进行往后走
    }
    // 最终i与j处在同一个位置上，结束此次哨兵划分
    // 由于右边哨兵先走 所以j一定是停留在首个小于基数的元素，最后的情况左边的哨兵会与右边哨兵重合i=j于是结束循环
    // 而此时这个元素的值一定是小于基数的 因此交换i 与left，把基数换到中间去，这个元素去最左端
    Swap(nums, i, left);
    return i;
}
void QuickSort(vector<int> &nums, int left, int right)
{
    while (left < right)
    {
        // 分治策略 完成哨兵划分后 分别在进行左子数组与右子数组的哨兵划分
        int mid = Partition(nums, left, right);
        // 先处理较小的子数组 减少递归深度 可以仔细思考思考
        // ！后续可以再看看
        if (mid - left < right - mid)
        {
            QuickSort(nums, left, mid - 1);
            left = mid + 1;
        }
        else
        {
            QuickSort(nums, mid + 1, right);
            right = mid - 1;
        }
    }
}