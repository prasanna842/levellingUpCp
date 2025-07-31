#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string str; cin>>str;
        int ans=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(str[i]=='1') one++;
        }
        ans=(n-1)*one+(n-one);
        cout<<ans<<endl;
    }
}