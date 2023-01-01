class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                secret[i]='*';
                guess[i]='*';
                bull++;
            }
        }

        unordered_map<char,int>s1;
        unordered_map<char,int>s2;
        for(auto c:secret){
           if(c!='*') s1[c]++;
        }

        for(auto c:guess){
            if(c!='*')s2[c]++;
        }

        for(auto c:s1){
            cow+=min(s1[c.first],s2[c.first]);
        }

        cout<<cow<<endl;

        string ans="";
        ans+=to_string(bull);
        ans+="A";
        ans+=to_string(cow);
        ans+="B";
        return ans;
    }
};