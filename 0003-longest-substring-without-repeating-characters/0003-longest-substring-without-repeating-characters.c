int lengthOfLongestSubstring(char* s) {
    int seen[128]={0};
    int max=0;
    int start=0;
    for(int i=0;s[i]!='\0';i++){
        seen[s[i]]++;
        while(seen[s[i]]>1){
            seen[s[start]]--;
            start++;
        }
        int length=i-start+1;
        if(length>max) max=length;
    }
    return max;
}