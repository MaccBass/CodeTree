#include <iostream>
#include <queue>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if (a.first + a.second == b.first + b.second) {
            return a.first > b.first;
        }
        return a.first+a.second > b.first+b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m; cin>>n>>m;
    pair<int, int> ans;
    while (n){
        int x, y; cin>>x>>y;
        pq.push(make_pair(x, y));

        n--;
    }

    while (m){
        pair<int, int> tmp = pq.top();
        pq.pop();

        tmp.first += 2;
        tmp.second += 2;
        pq.push(tmp);

        m--;
    }

    ans = pq.top();
    cout<<ans.first<<' '<<ans.second;
    return 0;
}