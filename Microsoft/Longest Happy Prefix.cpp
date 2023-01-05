class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        //KMP Prefix function
        //TC O(N)
        vector<int>prefix(n,0);
        for(int i=1;i<n;i++){
            int j=prefix[i-1];
            while(j>0 && s[i]!=s[j]){
                j=prefix[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            prefix[i]=j;
        }

        
        string ans="";
        for(int l=0;l<prefix[n-1];l++){
            ans+=s[l];
        }
        return ans;
    }
};