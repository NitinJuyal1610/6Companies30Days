
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
		
        int flag=0;
        int n=transactions.size();
        vector<string>name;
        vector<int>time;
        vector<int>amount;
        vector<string>city;
        vector<string>ans;
        
        for(auto str:transactions){
            stringstream ss(str);
            string st;
            vector<string>temp;
            while(getline(ss,st,',')){
                temp.push_back(st);
            }  
            name.push_back(temp[0]);
            time.push_back(stoi(temp[1]));
            amount.push_back(stoi(temp[2]));
            city.push_back(temp[3]);                
        }
        
        int j=0;
        for(auto it:amount){
            if(it>1000){
                ans.push_back(transactions[j]);                
            }
            j++;
        }
		
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(name[i]==name[j] && city[i]!=city[j]){
                    if(abs(time[i]-time[j])<=60){
                        if(amount[i]<=1000){
                            ans.push_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
		
		
        return ans;
    }
};
