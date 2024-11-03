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
        auto it2 = next(it);
        int tmp;
        
        // 차가 m보다 처음으로 커질때까지 it2 증가
        while ((*it2 - *it) < m && it2 != s.end()){
            it2++;
        }

        // 끝까지 가도 m보다 큰 경우가 안나오므로, it보다 더 큰수와 맨 끝수를 빼도 m보다 작음.
        if (it2 == s.end()) break;
        
        // it를 증가시키며 it~it2 범위까지 가장 작은 차를 찾음
        for (it; (*it2-*it) >= m; it++){
            tmp = *it2 - *it;
        }
        // 갱신
        if (tmp < ans && tmp >= m) ans = tmp;
        if (ans == m) break;
        it = prev(it2);

    }

    if (ans == MAX) cout << -1;
    else cout << ans;

    return 0;
}