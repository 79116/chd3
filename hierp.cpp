#include<bits/stdc++.h>
using namespace std;
int n;
int ms=1;
int ts=1;
string gen1;
string gen2;
string genans;
int type(char a1, char a2) {
    //cout<<"a1 a2 "<<a1<<" "<<a2<<endl;
    if(a1>='a') return 2; // aa
    if(a2>='a') return 1; // Aa
    return 0; // AA
}
pair<int,int> fr(int type1, int type2, char ans) {
    int ts=1;
    int ms=1;
    //cout<<type1<<" "<<type2<<" "<<ans<<endl;
    if(type1==0) ts=0;
    if(type1==1) ms*=2;
    if(type2==0) ts=0;
    if(type2==1) ms*=2;
    int ucln=__gcd(ts,ms);
    ts/=ucln;
    ms/=ucln;
    if(ans<='Z') return make_pair(ms-ts,ms);
    else return make_pair(ts,ms);
}
signed main() {
    cin>>n;
    cin>>gen1>>gen2>>genans;
    char c11,c12,c21,c22,cans;
    int type1;
    int type2;
    for(int i=0 ; i<n ; i++) {
        c11=gen1[i*2];
        c12=gen1[i*2+1];
        c21=gen2[i*2];
        c22=gen2[i*2+1];
        type1=type(c11,c12);
        type2=type(c21,c22);
        cans=genans[i];
        pair<int,int> tmp=fr(type1,type2,cans);
        //cout<<"tmp = "<<tmp.first<<" "<<tmp.second<<endl;
        ts*=tmp.first;
        ms*=tmp.second;
    }
    int ucln=__gcd(ts,ms);
    ts/=ucln;
    ms/=ucln;
    cout<<(ms/ts)+(ms%ts!=0);
}
/*
AaBbCc
aabbcc
AbC
*/
