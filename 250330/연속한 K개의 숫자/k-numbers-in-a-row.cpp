#include <iostream>
using namespace std;


int N, K, B, ans=999999;
int arr[100001] = {0,};
int prefix[100001] = {0,};

int main() {

    cin>>N>>K>>B;
    for (int i=0; i<B; i++){
        int del; cin>>del;
        arr[del] = 1;
    }

    for (int i=1; i<=N; i++){
        prefix[i] = prefix[i-1]+arr[i];
    }

    for (int i=K; i<=N; i++){
        int tmp = prefix[i] - prefix[i-K];
        if (tmp < ans) ans=tmp;
        
        if (ans==0) break;
    }

    cout<<ans;

    return 0;
}