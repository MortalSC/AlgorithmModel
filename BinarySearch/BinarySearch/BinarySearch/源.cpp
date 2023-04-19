#include<iostream>
#include<vector>
using namespace std;

/* ����ұ�ģ�� */
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            // ����ұգ�left��ָ����Ԫ�أ�right��ָ��βԪ�أ�
            int left = 0, right = nums.size() - 1;
            // ע��ѭ��������<=
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > target) right = mid - 1;
                else if (nums[mid] < target) left = mid + 1;
                else return mid;
            }
            return -1;
        }
};

/* ����ҿ�ģ�� */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // ����ҿ���left��ָ����Ԫ�أ�right��ָ��βԪ����һ��λ�ã�
        int left = 0, right = nums.size();
        // ע��ѭ��������<
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};
