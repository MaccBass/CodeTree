#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
unordered_map<int, int> um;

int main() {

    int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp; v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = n - 3; i > -1; i--) {
        int diff = k - v[i];

        for (int j = i + 2; j < n; j++) {

            um[v[i + 1] + v[j]]++;
        }
        ans += um[diff];
    }

    cout << ans;
    return 0;
}