#include <stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* nums, int left, int right, int target){
    while(left <= right){
        int mid = left + (right - left)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), cmp);

    int capacity = numsSize * numsSize;
    int **res = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    *returnSize = 0;

    for(int i = 0; i < numsSize - 2; i++){

        if(i > 0 && nums[i] == nums[i-1])
            continue;

        for(int j = i + 1; j < numsSize - 1; j++){

            if(j > i + 1 && nums[j] == nums[j-1])
                continue;

            int target = -(nums[i] + nums[j]);

            int k = binarySearch(nums, j+1, numsSize-1, target);

            if(k != -1){
                res[*returnSize] = malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[j];
                res[*returnSize][2] = nums[k];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
            }
        }
    }

    return res;
}