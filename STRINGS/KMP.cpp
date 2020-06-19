#include<bits/stdc++.h>
using namespace std;
void compute(char *pat,int M,int *lps){
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void strsearch(char *pat,char *txt){
    int M=strlen(pat);
    int N=strlen(txt);
    int lps[M];
    compute(pat,M,lps);
    int i=0;
    int j=0;
    while(i<N){
        if(pat[j]==txt[i]){
            j++;
            i++;
        }
        if(j==M){
            cout<<"Pattern found at index "<<i-j<<endl;
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    char txt[n],pat[m];
    cin>>txt>>pat;
    strsearch(pat,txt);
    //char txt[] = "ABABDABACDABABCABAB";
    //char pat[] = "ABABCABAB";
    //strsearch(pat, txt);
    return 0;
}
