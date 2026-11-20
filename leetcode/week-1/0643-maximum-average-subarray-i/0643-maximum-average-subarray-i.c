double findMaxAverage(int* nums, int numsSize, int k) {
    int sum=0, max=0;
    for(int i=0;i<=numsSize-k;i++){
        if(i==0){
            for(int j=0;j<k;j++){
                sum+=nums[j];
            }
            max=sum;
        }
        else if(i!=0){
            sum=sum-nums[i-1]+nums[i+k-1];
        }
        if(sum>max){
            max=sum;
        }
    }
    return (double)max/k;
}