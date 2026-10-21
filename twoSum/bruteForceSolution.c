#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[j] == target - nums[i]) {
        int *result = malloc(sizeof(int) * 2);
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        return result;
      }
    }
  }
  *returnSize = 0;
  return malloc(sizeof(int) * 0);
}

int main() {
  int a[] = {2, 7, 11, 15};
  int rs, target = 9;
  int *p = NULL;

  p = twoSum(a, sizeof(a) / sizeof(a[0]), target, &rs);

  if (rs == 0) {
    printf("Target was not found!\n");
  } else {
    printf("Target found at indices %d and %d\n", p[0], p[1]);
    free(p);
  }

  return 0;
}
