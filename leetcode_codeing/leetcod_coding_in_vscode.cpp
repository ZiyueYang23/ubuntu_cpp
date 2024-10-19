#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int flag = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                // ==
                flag = mid;
            }
        }
        return flag;
    }
};