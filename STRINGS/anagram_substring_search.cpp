#include<bits/stdc++.h>
#define MAX 256
using namespace std;
bool compare(char a1[],char a2[]){
    for(int i=0;i<MAX;i++)
        if(a1[i]!=a2[i])
            return false;
    return true;
}
void searchh(char *pat,char *txt){
    int m=strlen(pat),n=strlen(txt);
    char cp[MAX]={0},ct[MAX]={0};
    for(int i=0;i<m;i++){
        cp[pat[i]]++;
        ct[txt[i]]++;
    }
    for(int i=m;i<n;i++){
        if(compare(cp,ct))
            cout<<"Pattern found at index: "<<i-m<<endl;
        ct[txt[i]]++;
        ct[txt[i-m]]--;
    }
    if(compare(cp,ct))
        cout<<"Pattern found at index: "<<n-m<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    char txt[n],pat[m];
    cin>>txt>>pat;
    searchh(pat,txt);
    return 0;
}
