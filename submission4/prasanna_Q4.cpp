#include <bits/stdc++.h>
using namespace std;
using ll =long long;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<ll> a(n);
        for ( int i=0;i<n;i++) cin >> a[i];
        vector<ll> b(m);
        for(int i=0;i<m;i++) cin >> b[i];
        vector<int> pre(m+1),suf(m+2);
        pre[0]=0;
        int p=0;
        for(int i=1;i<=m;i++){
            while(p<n&&a[p]<b[i-1]) p++;
            pre[i]=(p<n? p+1:n+1);
            if(p<n) p++;
        }
        if (pre[m]<=n){
            cout<<0<<"\n";
            continue;
        }
        suf[m+1]=n+1;
        p=n-1;
        for(int i=m;i>=1;i--){
            while(p>=0 && a[p]<b[i-1]) p--;
            suf[i]=(p>=0 ? p+1:0);
            if(p>=0) p--;
        }
        ll ans=LLONG_MAX;
        for(int i=1;i<=m;i++){
            if(pre[i-1]<suf[i+1]){
                ans=min(ans,b[i-1]);
            }
        }
        if (ans==LLONG_MAX) cout<< -1<< "\n";
        else cout<<ans<<"\n";
    }
    return 0;
}