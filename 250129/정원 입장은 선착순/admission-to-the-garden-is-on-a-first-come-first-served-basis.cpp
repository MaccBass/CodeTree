#include <iostream>
#include <queue>
using namespace std;

struct People {
    int number;
    int arrive;
    int time;
    People(int n, int a, int t) : number(n), arrive(a), time(t) {}
};

struct cmp_arrive {
    bool operator()(People a, People b) {
        return a.arrive > b.arrive;
    }
};
struct cmp_number {
    bool operator()(People a, People b) {
        return a.number > b.number;
    }
};
// 도착 시간 기준 pq
priority_queue<People, vector<People>, cmp_arrive> pq_arrive;
// 입장한 사람이 있을 때 방문한 경우 여기로 이동함. 대기열 역할
priority_queue<People, vector<People>, cmp_number> pq_number;
// 현재 들어온 사람이 나가는 시간 
int endtime = 0;
int ans = 0;

/*
 * 사람이 도착한 순서대로 일단 정렬하고, 정원이 비어있으면 pq_arrive에서 pop하고 바로 들어감.
 * 만약 정원에 사람이 있는데 들어간 경우 (endtime이 arrive보다 큰 경우)
 * pq_number로 들어감. 여러명이 대기중인 경우 arrive에 관계없이 number가 큰 사람이 먼저 들어감.
 * pq_number가 empty()가 아닌 경우 무조건 pq_number에서 먼저 pop함.
 * 정원에 사람이 들어갈 때마다 endtime을 갱신, ans를 계산함.
*/
int main() {

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, t;
        cin >> a >> t;
        pq_arrive.push(People(i, a, t));
    }

    while (!pq_arrive.empty() || !pq_number.empty()) {
        People people(0, 0, 0);
        int waittime = 0;

        if (!pq_number.empty()) {
            people = pq_number.top();
            pq_number.pop();
        }
        else {
            people = pq_arrive.top();
            pq_arrive.pop();
        }

        if (people.arrive < endtime) {
            waittime = endtime - people.arrive;
            if (waittime > ans) {
                ans = waittime;
            }
            endtime = endtime + people.time;
        }
        else {
            endtime = people.arrive + people.time;
        }

        while (!pq_arrive.empty()) {
            if (pq_arrive.top().arrive < endtime) {
                pq_number.push(pq_arrive.top());
                pq_arrive.pop();
            }
            else break;
        }
    }

    cout << ans;

    return 0;
}