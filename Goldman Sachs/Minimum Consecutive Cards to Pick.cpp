class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=1e9;
        int s=0,e=0;
        unordered_map<int,int>mpp;
        mpp[cards[s]]=0;

        while(e<cards.size()-1){
            
            if(mpp.find(cards[e+1])!=mpp.end()){
                e++;
                cout<<(e-mpp[cards[e]]+1)<<endl;
                ans=min(ans,(e-mpp[cards[e]]+1));
                mpp[cards[e]]=e;
            }else{
                e++;
                mpp[cards[e]]=e;
            }
        }

        return ans==1e9?-1:ans;

    }
};