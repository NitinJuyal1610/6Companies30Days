class Solution {
public:
    
    int numberOfSubstrings(string s) {
       int n=s.length();
       vector<int>v={-1,-1,-1};
       int ans=0;
       for(int i=n-1;i>=0;i--){
           v[s[i]-'a']=i;
           if(v[0]==-1 || v[1]==-1 || v[2]==-1){
               continue;
           }
           int maxi=max(v[0],v[1]);
           maxi=max(maxi,v[2]);
           ans+=n-maxi;
       }
       return ans;
    }
};