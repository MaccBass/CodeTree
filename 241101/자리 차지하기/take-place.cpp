#include <iostream>
#include <set>

using namespace std;
set<int> seats;

int main() {
    int n, m;
    int cnt=0;
    cin>>n>>m;

    // 전체 위치를 넣고 빈 곳을 이미 앉은 자리로 함.
    for (int i=1; i<=m; i++){
        seats.insert(i);
    }

    for (int i=0;i<n;i++) {
        int seat; cin>>seat;

        set<int>::iterator it = seats.upper_bound(seat);
        if (it != seats.begin()){
            it--;
            seats.erase(*it);
            cnt++;
        }
        else{
            break;
        }
    }

    cout<<cnt;
    
    return 0;
}