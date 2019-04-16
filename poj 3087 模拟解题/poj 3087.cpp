//判定-1：拆分下去的子串S1，S2一定会达到最开始输入的状态，
//那么判断一下最新的S1是不是和原来的S1一样就OK了。
//如果出现一样且未达到条件就直接break，输出-1。
//可以使用set来查重，模拟效果更佳。不过我这样的也过了。
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
    int T;
    cin>>T;
    int casee=1;
    while(T--){
        int check=0;
        int n;
        string s1;
        string s2;
        string s12;
        cin>>n;
        cin>>s1;
        cin>>s2;
        cin>>s12;
        for(int i=1;i<=50;i++){
            string s;
            for(int j=0;j<n;j++){
                s=s+s2[j];
                s=s+s1[j];
            }
            //cout<<s<<endl;
            if(s==s12){
               check=i;
               break;
            }
            for(int j=0;j<2*n;j++){
                if(j<n) s1[j]=s[j];
                if(j>=n) s2[j-n]=s[j];
            }
            //cout<<"s1= "<<s1<<endl<<"s2= "<<s2<<endl;
        }
        cout<<casee<<" ";
        casee++;
        if(check!=0) cout<<check<<endl;
        if(check==0) cout<<-1<<endl;
    }
    return 0;
}