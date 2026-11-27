
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* nums, int left, int right) {
    if (left >= right) return;

    // Median of Three
    int mid = left + (right - left) / 2;

    if (nums[left] > nums[mid])
        swap(&nums[left], &nums[mid]);

    if (nums[left] > nums[right])
        swap(&nums[left], &nums[right]);

    if (nums[mid] > nums[right])
        swap(&nums[mid], &nums[right]);

    swap(&nums[mid], &nums[right]);

    // Partition
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }

    swap(&nums[i], &nums[right]);

    // Recursion
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

bool containsDuplicate(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1])
            return true;
    }

    return false;
}
