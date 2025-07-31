#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> ind;
        vector<int> ans;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        bool ansi=false;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            mini=min(mini,a[i]);
            maxi=max(maxi,a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]==-1) ind.push_back(i);
            else ans.push_back(a[i]+b[i]);
        }
        if(ind.size()<n){
            int ans1=ans[0];
            for(int i=0;i<ans.size();i++){
                if(ans[i]!=ans1) {
                    cout<<"0"<<endl;
                    break;
                }
                if(i==ans.size()-1){
                    int in=0;
                    if(ind.empty()) {
                        cout<<"1\n";
                        break;
                    }
                    for(int i=0;i<n && in<ind.size();i++){
                        if(i==ind[in]){
                            if(ans1-a[i]>k || ans1-a[i]<0){
                                ansi=true;
                                break;
                            }
                            in++;
                        }
                    }
                    if(ansi) cout<<"0\n";
                    else cout<<"1\n";
                }
            }
        }else{
            int l=maxi-mini;
            int anss=k-l+1;
            cout<<anss<<endl;
        }
    }
}