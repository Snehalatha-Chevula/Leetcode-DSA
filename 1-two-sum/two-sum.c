/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int i,j;
    int *p=(int*)malloc(2*(sizeof(int)));
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                p[0]=i;
                p[1]=j;
                break;
            }

        }
        if(j!=numsSize)
        break;
    }
    return p;
    
}