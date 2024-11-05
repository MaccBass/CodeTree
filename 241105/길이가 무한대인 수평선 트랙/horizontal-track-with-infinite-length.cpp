#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>> runners;
int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // n: 사람수, t: t분동안 달림
    int n, t;
    cin>>n>>t;
    int cnt = n;

    while(n){
        
        int start, speed; cin>>start>>speed;
        runners.insert(make_pair(start, speed));
        n--;
    }

    /*
    발상 1: 뒤에있는 사람(start가 작은 사람)은 앞에 있는 사람보다 느리면
    죽었다깨나도 못 추월한다.
    그런데 뒤에있는 사람은 따라잡을 시 무조건 같이 뛰어야 됨(가장 느림 사람 속력으로 변함)
    
    -> 바로 앞 사람보다 speed가 느리거나, 빨라도 t분 이후 추월하지 못할 경우를 찾는다.
    -> set을 스캔하면서 바로 앞 사람의 second를 파악하기.
    -> 만약 위의 경우가 발생 시 카운트 증가. 따라잡을 수 있으면 그냥 continue
    */

    for (auto it = runners.begin(); it != prev(runners.end()); it++) {
        
        pair<int, int> behind = *it;
        pair<int, int> front = *(next(it));

        // 앞사람이 더 빠르면 무시 (못따라잡으니 그룹 생성이 안됨.)
        if (front.second >= behind.second) continue;
        
        // t분 내에 따라잡을 수 있는지 확인.
        long long result_dist_behind = (long long)behind.second * (long long)t +  (long long)behind.first;
        long long result_dist_front = (long long)front.second * (long long)t +  (long long)front.first;

        if (result_dist_front > result_dist_behind) continue;
        else cnt--;
    }

    /*
    발상 2: 앞의 사람을 따라잡을 수 있는 경우, 뒷사람 데이터를 삭제하고 남은 원소 개수를 세기?
    */

    cout<<cnt;
    return 0;
}