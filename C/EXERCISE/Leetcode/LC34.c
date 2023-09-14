/****https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array****/
/*给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。*/

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize=2;
    int *returnvalue;
    returnvalue = malloc(sizeof(int)*(*returnSize));

    int left = 0;
    int right = numsSize-1;
    int middle = (left+right)/2;

    int targetleft = -1;
    int targetright = -1;

    if(numsSize==0)
        goto end;

    while(left < right)
    {
        if(nums[middle]==target)
            break;
        else if(nums[middle] > target)
        {
            right = middle - 1;
            middle = (left+right)/2;
        }
        else if(nums[middle] < target)
        {
            left = middle + 1;
            middle = (left+right)/2;
        }
    }
    
    if(nums[middle]==target)
    {
        targetleft=middle;
        targetright=middle;
        
        while(nums[targetleft]==target)
        {
            if(targetleft==0)
                break;
            targetleft--;
            if(nums[targetleft]<target)
            {
                targetleft++;
                break;
            }
        }
        while(nums[targetright]==target)
        {
            if(targetright==numsSize-1)
                break;
            targetright++;
            if(nums[targetright]>target)
            {
                targetright--;
                break;
            }
        }
    }
    
    end:
    *returnvalue=targetleft;
    *(returnvalue+1)=targetright;
    return returnvalue;
}
