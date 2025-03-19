#include <iostream>
#include <climits>
using namespace std;

int arr[501][501] = {0,};
int prefix[501][501] = {0,};

int main() {
    
    int n, k;
    int ans = INT_MIN;
    cin>>n>>k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin>>arr[i][j];
            prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    for (int i=k; i<=n; i++){
        for (int j=k; j<=n; j++){
            int tmp;
            tmp = prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k];
            if (tmp > ans) ans = tmp;
        }
    }

    cout<<ans;

    return 0;
}