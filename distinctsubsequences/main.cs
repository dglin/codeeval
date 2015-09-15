class Solution {
public:
    void cond(vector<vector<int> > &table, int &res){
        int row = table.size();
        vector<vector<int> > r(row);
        for (int i=0;i<table[0].size();i++){
            r[0].push_back(1);
        }        
        for (int i=1;i<table.size();i++){
            int tmp=0;
            int bf=0;
            for (int j=0;j<table[i].size();j++){
                for (int k=bf;k<table[i-1].size();k++){
                    if (table[i][j]>table[i-1][k]){
                tmp=tmp+r[i-1][k];
                         bf=k+1;
                    }else{break;}
                }            
                r[i].push_back(tmp);
            }
        }
        for (int i=0;i<table[row-1].size();i++){
            res = res+r[row-1][i];
        }
    }
     
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.empty()||T.empty()){return 0;}
        int res=0;
        vector<vector<int> > table(T.size());
        map<char,vector<int> >mp;
        vector<int> r;
        for(int i=0;i<T.size();i++){mp[T[i]]=r;}
        for (int i=0;i<S.size();i++){mp[S[i]].push_back(i);}
     for(int i=0;i<T.size();i++){table[i]=mp[T[i]];}
  
     cond(table,res);
        return res;
    }
};
