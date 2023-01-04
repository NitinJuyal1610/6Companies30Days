class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int>st;
        int l=INT_MAX;
        //
        for(int i=0;i<nums.size();i++){
                while(!st.empty() && nums[i]<nums[st.top()]){
                    l=min(l,st.top());
                    st.pop();
                }
                st.push(i);
        }
       
        //

        int r=INT_MIN;
        while(!st.empty()){
            st.pop();
        }
        for(int i=nums.size()-1;i>=0;i--){
                while(!st.empty() && nums[i]>nums[st.top()]){
                    r=max(r,st.top());
                    st.pop();
                }
                st.push(i);
        }

        if(l==INT_MAX || r==INT_MIN)return 0;
        return r-l+1;
    }
};