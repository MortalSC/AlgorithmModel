#include<iostream>
#include<vector>
using namespace std;

/* 左闭右闭模板 */
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // 左闭右闭：left：指向首元素，right：指向尾元素；
            int left = 0, right = nums.size() - 1;
            // 注意循环条件：<=
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > target) right = mid - 1;
                else if (nums[mid] < target) left = mid + 1;
                else return mid;
            }
            return -1;
        }
};

/* 左闭右开模板 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 左闭右开：left：指向首元素，right：指向尾元素下一个位置；
        int left = 0, right = nums.size();
        // 注意循环条件：<
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};
