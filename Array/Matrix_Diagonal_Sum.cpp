class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int i=0,j=0,sum=0;
        while(i<m && j<n){
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=i-1;
        j=0;
        while(i>=0 && j<n){
            if(i!=j)
                sum+=mat[i][j];
            i--;
            j++;
        }
        return sum;
    }
};