 #include<iostream>
using namespace std;

void generate_subsequence(int  *in,int  *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<*(out)<<endl;
        return;
    }
    //rec.case
    out[j]=in[i];
    generate_subsequence(in,out,i+1,j+1);
    generate_subsequence(in,out,i+1,j);
}

int main(){
    int input[]={8,9,10};
    int output[10];

    generate_subsequence(input,output,0,0);
    return 0;
}