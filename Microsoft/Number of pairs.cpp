class Solution {
public:
    long long int ans =0;
    
    void mergeSort(vector<int> &nums, int low, int high,int diff){
        if(low>=high){
            return;
        }
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid,diff);
        mergeSort(nums,mid+1,high,diff);
        int l=low,r=mid+1;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]+diff){
                ans+=high-r+1;
                l++;
            }
            else{
                r++;
            }
        }
        sort(nums.begin()+low, nums.begin()+high+1);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        for(int i=0;i<nums1.size();i++){
            nums1[i]-=nums2[i];
        }
        //now just find index such that their difference is LTE to diff
        //arr[i]-arr[j]<=diff 
        int n=nums1.size();
        mergeSort(nums1,0,n-1,diff);
        return ans;
    }
};