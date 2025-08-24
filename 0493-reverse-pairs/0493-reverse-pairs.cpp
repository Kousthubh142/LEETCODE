class Solution {
public:
    int mergesort(vector<int>& nums,int left, int right) {
        if(left>=right) return 0;

        //recursion step
        int mid=left+(right-left)/2;
        int count=mergesort(nums,left,mid)+mergesort(nums,mid+1,right);

        //count pairs
        int j=mid+1;
        for(int i=left;i<=mid;i++) {
            while(j<=right && (long long)nums[i]>2LL*nums[j]) j++;

            count+=(j-(mid+1));
        }

        //merging the pairs
        vector<int> temp;
        int i=left;
        j=mid+1;

        while(i<=mid && j<=right) {
            if(nums[i]<nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=right) temp.push_back(nums[j++]);

        //where we need to return it to the original vector from temp:
        for(int k=left;k<=right;k++) {
            nums[k]=temp[k-left];
        }

        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};