#include <iostream>
#include <set>
#define MAX 2147000000
using namespace std;

set<pair<int, int>> s;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;

    s.insert(make_pair(0, n));
    s.insert(make_pair(n + 1, n + 1));
    for (int i = 0; i < m; i++) {
        int ans = 0;
        int num; cin >> num;
        auto itmp = s.upper_bound(make_pair(num, 0));
        pair<int, int> p = *itmp;
        if (num != p.first) {
            p = *(prev(itmp));
        }

        if (p.first == num) {
            s.insert(make_pair(num + 1, p.second));
            s.erase(p);
        }
        if (p.second == num) {
            s.insert(make_pair(p.first, num - 1));
            s.erase(p);
        }
        if (p.first < num && num < p.second) {
            s.insert(make_pair(p.first, num - 1));
            s.insert(make_pair(num + 1, p.second));
            s.erase(p);
        }

        for (auto& p2 : s) {
            int tmp = p2.second - p2.first + 1;
            if (ans < tmp) ans = tmp;
        }

        cout << ans << '\n';
    }

    return 0;
}