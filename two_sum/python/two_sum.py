#!/usr/bin/env python3
# coding: utf-8

# https://leetcode.com/problems/two-sum/


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        for i in range(length):
            for j in range(i + 1, length):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def twoSum2(self, nums, target):
        diff_dict = {}
        for i, num in enumerate(nums):
            if num in diff_dict.keys():
                return [diff_dict[num], i]
            else:
                diff_dict[target - num] = i


def main():
    pass


if __name__ == '__main__':
    main()
