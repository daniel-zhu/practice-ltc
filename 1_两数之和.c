/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int *array = NULL;

    if (NULL == nums) {
        return NULL;
    }

    for (i = 0; i < numsSize; i++) {
        for (j = i+1; j < numsSize; j++) {
            if ((nums[i] + nums[j]) == target) {
                array = malloc(2 * sizeof(int));
                if (NULL == array) {
                    return NULL;
                }

                array[0] = i;
                array[1] = j;

                if (returnSize != NULL) {
                    *returnSize = 2;
                }

                return array;
            }
        }
    }

    return NULL;
}