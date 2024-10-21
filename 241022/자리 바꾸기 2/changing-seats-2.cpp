#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
vector<pair<int, int>> methods;
vector<unordered_set<int>> logs;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin>>n>>k;

    for (int i=0; i<=n; i++){
        unordered_set<int> tmp;
        tmp.insert(i);
        v.push_back(i);
        logs.push_back(tmp);
    }
    for (int i=0;i<k;i++){
        int a, b;
        cin>>a>>b;
        methods.push_back(make_pair(a, b));
    }

    for (int i=0;i<3;i++){
        for (const auto& p: methods){
            int a=p.first, b=p.second;

            swap(v[a], v[b]);
            logs[v[a]].insert(a);
            logs[v[b]].insert(b);
        }
    }

    for (int i=1; i<=n; i++){
        cout<<logs[i].size()<<'\n';
    }

    return 0;
}