#include <iostream>
using namespace std;

int main() {

    int N, Q;
    int line[1000001] = {0,};
    int prefix[1000001] = {0,};
    int LINE_MAX=0;
    cin>>N>>Q;

    for (int i=0; i<N; i++){
        int tmp; cin>>tmp;
        line[tmp]=1;

        if (tmp > LINE_MAX) LINE_MAX = tmp;
    }

    prefix[0] = line[0];
    for (int i=1; i<=LINE_MAX; i++){
        prefix[i] = line[i] + prefix[i-1];
    }

    for (int i=0; i<Q; i++){
        int start, end, ans; 
        cin>>start>>end;

        ans = prefix[end]-prefix[start]+line[start];
        cout<<ans<<'\n';
    }

    return 0;
}