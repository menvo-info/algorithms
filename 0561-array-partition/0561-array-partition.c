void quickSort(int* nums, int left, int right) {
    if (left>=right) return;
    int pivot=nums[right];
    int i=left;
    for (int j=left;j<right;j++) {
        if (nums[j]<pivot) {
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
        }
    }
    int temp=nums[i];
    nums[i]=nums[right];
    nums[right]=temp;
    quickSort(nums, left, i-1);
    quickSort(nums, i+1, right);
}

int arrayPairSum(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize-1);
    int sum=0;
    for (int i=0;i<numsSize;i+=2) {
        sum+=nums[i];
    }
    return sum;
}
