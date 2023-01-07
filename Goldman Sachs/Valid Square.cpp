class Solution {
public:
    
    int dis(vector<int>&p1,vector<int>&p2){
        return ((p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    
       unordered_set<int>st;
       st.insert(dis(p1,p2));
       st.insert(dis(p1,p3));
       st.insert(dis(p1,p4));
       st.insert(dis(p2,p3));
       st.insert(dis(p2,p4));
       st.insert(dis(p3,p4));
       if(st.count(0))return false;
       return st.size()==2;
    }
};