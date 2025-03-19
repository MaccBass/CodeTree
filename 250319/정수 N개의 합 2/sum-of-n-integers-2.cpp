#include <iostream>
#include <climits>
using namespace std;

int arr[100001] = {0, };
int prefix[100001] = {0, };

int main() {

    int n, k;
    int ans = INT_MIN;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }

    for (int i=k; i<=n; i++){
        int tmp = prefix[i] - prefix[i-k];
        if (tmp > ans) ans=tmp;
    }
    cout<<ans;

    return 0;
}