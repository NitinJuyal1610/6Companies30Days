class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto c:tokens){
            if(c=="+" || c=="/" || c=="*" || c=="-"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(c=="+")st.push(a+b);
                else  if(c=="-")st.push(a-b);
                else  if(c=="/")st.push(a/b);
                else  if(c=="*")st.push(a*b);
            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};