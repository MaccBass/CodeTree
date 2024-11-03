#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m; cin>>n>>m;
    for (int i=0;i<n;i++){
        int num; cin>>num; s.insert(num);
    }

    for (int i=0;i<m;i++){
        int num; cin>>num;
        auto it = s.lower_bound(num);

        // 집합에 있으면 그대로
        if (*it == num){
            cout<<num<<'\n';
            s.erase(num);
        }
        else{
            // 집합에 없는데 맨처음이다 -> num보다 더 작거나 같은게 없음.
            if (it == s.begin()){
                cout<<-1<<'\n';
            }
            // num 이상의 수 중 가장 작은 수의 위치이므로, 그 왼쪽에는 num 이하 수 중 가장 큰게 있음.
            else{
                it--;
                cout<<*it<<'\n';
                s.erase(*it);
            }
        }
    }
    return 0;
}