#include <iostream>
#include <set>
#define MAX 2147000000

using namespace std;
set<int> s;

int main() {

    int n, m;
    int ans = MAX;
    cin >> n >> m;

    while (n){
        int tmp; cin>>tmp;
        s.insert(tmp);
        n--;
    }

    for (auto it=s.begin(); it != s.end(); it++){
        auto it2 = s.lower_bound(*it+m);
        if (it2 == s.end()) break;

        int tmp = *it2 - *it;
        if (tmp == m) {
            ans = m;
            break;
        }

        if (tmp < ans) ans=tmp;
    }

    cout<<ans;
}