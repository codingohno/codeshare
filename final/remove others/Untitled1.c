//
//#include <stdio.h>
//#include <iostream>
//
//#include <algorithm>
//#include <map>
//#include <set>
//#include <vector>
//#include <iterator>
//
//using namespace std;
//
//
//void test(int N, int K) {
//    vector<pair<int, int>> V(N);
//
//    int tmp, a1, a2;
//
//    for(int i = 0; i < N; i++) {
//        scanf("%d", &tmp);
//        get<0>(V[i]) = tmp;
//        get<1>(V[i]) = i+1;
//    }
//    sort(V.begin(), V.end());
//
//    while(K--) {
//        scanf("%d%d%d", &a1, &a2, &tmp);
//        auto it1 = V.lower_bound(make_pair(tmp, a1));
//        auto it2 = V.upper_bound(make_pair(tmp, a2));
//        //cout << *it1 << *it2;
//        printf("%d\n", a2 - a1 + 1 - (it2 - it1));
//    }
//    printf("\n");
//}
//
//int main() {
//    int T, N, K;
//    scanf("%d", &T);
//    while(T--) {
//        scanf("%d%d", &N, &K);
//        test(N, K);
//    }
//}
