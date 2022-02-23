---
layout: post
type: algorithms
title: "백준 14620번: 꽃길"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/14620"
tag: ["Algorithms", "Brute_Force"]
comments: true
rating: gold5
---

입력의 수가 적으므로 모든 경우를 탐색하면 됩니다.
dfs를 통해 방문 체크를 적절히 하여 모든 경우를 종합한 뒤 최소값을 찾으면 되겠습니다.

```C++
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int arr[11][11], n;
bool visit[11][11];
int dx[5] = {1,-1,0,0, 0};
int dy[5] = {0,0,1,-1, 0};

int dfs(int cnt) {
    if(cnt == 3) return 0;

    int result = 1e9;

    for(int a=1; a<n-1; a++) {
        for(int b=1; b<n-1; b++) {
            bool flag = false;
            for(int j=0; j<5; j++) if(visit[a+dx[j]][b+dy[j]]) flag = true; //이미 꽃이 있는 부분 cut
            if(flag) break;

            int fee = 0;
            for(int j=0; j<5; j++) visit[a+dx[j]][b+dy[j]] = true;
            for(int j=0; j<5; j++) fee += arr[a+dx[j]][b+dy[j]];
            result = min(result, fee + dfs(cnt + 1));
            for(int j=0; j<5; j++) visit[a+dx[j]][b+dy[j]] = false;
        }
    }

    return result;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> arr[i][j];

    cout << dfs(0);
}
```
