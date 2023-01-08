class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
     //just counting slopes and using strings for simplicity 
      if(points.size()==1)return 1;
      int maxi=0;
      for(int i=0;i<points.size();i++){
          unordered_map<string,int>mpp;
          for(int j=i+1;j<points.size();j++){
              string s="";
              int x=points[j][0]-points[i][0];
              int y=points[j][1]-points[i][1];
              
              int gcd=__gcd(x,y);
              x/=gcd;
              y/=gcd;
              if((x<=0 && y<=0) || (x>=0 && y>=0)){
                  s+=to_string(x);
                  s+="/";
                  s+=to_string(y);
              }
              else if(!(x<0 && y<0)){
                  s+="-";
                  s+=to_string(abs(x));
                  s+="/";
                  s+=to_string(abs(y));
              }
              mpp[s]++;
              maxi=max(maxi,mpp[s]+1);
          }
      }
     

      return maxi;

    }
};