#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Ssang {
    int num1;
    int num2;
    int arr2_idx;

    Ssang(int a, int b, int c) : num1(a), num2(b), arr2_idx(c) {}
};

/* compare: 매개변수: 우선순위를 높게(왼쪽) 잡고싶은 거
 * 큰걸 우선순위로 잡을라면 <, 작은거는 >
*/
struct compare {
    bool operator()(Ssang a, Ssang b) {
        return a.num1 + a.num2 > b.num1 + b.num2;
    }
};
priority_queue<Ssang, vector<Ssang>, compare> pq;

// 크기가 각각 n, m인 배열 2개
int arr1[100000];
int arr2[100000];
int n, m, k;
int ans;

int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    for (int i = 0; i < n; i++) {
        pq.push(Ssang(arr1[i], arr2[0], 0));
    }

    for (int i = 0; i < k; i++) {
        Ssang tmpSsang = pq.top();
        pq.pop();
        ans = tmpSsang.num1 + tmpSsang.num2;

        pq.push(Ssang(tmpSsang.num1, arr2[tmpSsang.arr2_idx + 1], tmpSsang.arr2_idx + 1));
    }

    cout << ans;

    return 0;
}