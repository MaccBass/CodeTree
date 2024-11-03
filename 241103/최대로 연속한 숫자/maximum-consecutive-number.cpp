#include <iostream>
#include <set>
#include <map>
#define MAX 2147000000
using namespace std;

set<pair<int, int>> s;
// key: size, value: s내의 개수
map<int, int, greater<int>> counts;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    int ans;

    s.insert(make_pair(0, n));
    counts[n+1]++;
    ans = counts.begin()->first;
    // dummy
    s.insert(make_pair(n + 1, n + 1));

    for (int i = 0; i < m; i++) {
        int ans = 0;
        int sizetmp;
        int num; cin >> num;

        // num이 들어간 부분집합 찾기
        auto itmp = s.upper_bound(make_pair(num, 0));
        pair<int, int> p = *itmp;
        // num으로 시작하는게 아니라면 그 직전꺼에 포함됨.
        if (num != p.first) {
            p = *(prev(itmp));
        }
        // 짜를 집합의 사이즈
        sizetmp = p.second - p.first + 1;


        // 집합 자르기
        if (p.first == num) {
            s.insert(make_pair(num + 1, p.second));
            s.erase(p);

            counts[sizetmp]--;
            if (counts[sizetmp] == 0) counts.erase(sizetmp);
            counts[sizetmp-1]++;
        }
        if (p.second == num) {
            s.insert(make_pair(p.first, num - 1));
            s.erase(p);
            
            counts[sizetmp]--;
            if (counts[sizetmp] == 0) counts.erase(sizetmp);
            counts[sizetmp-1]++;
        }
        if (p.first < num && num < p.second) {
            s.insert(make_pair(p.first, num - 1));
            s.insert(make_pair(num + 1, p.second));
            s.erase(p);

            counts[sizetmp]--;
            if (counts[sizetmp] == 0) counts.erase(sizetmp);
            int small = num-1 - p.first + 1;
            int big = p.second - (num+1) + 1;
            counts[small]++;
            counts[big]++;
        }

        
        ans = counts.begin()->first;

        cout << ans << '\n';
    }

    return 0;
}