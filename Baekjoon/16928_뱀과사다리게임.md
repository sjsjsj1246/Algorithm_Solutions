---
layout: post
type: algorithms
title: "백준 16928번: 뱀과 사다리 게임"
date: 2021-06-11
excerpt: "https://www.acmicpc.net/problem/16928"
tag: ["Algorithms", "DP", "BFS"]
comments: true
rating: sirver1
---

이 문제는 흔한 탐색 문제이다. 최소 거리를 구하는 문제이므로 BFS를 이용하는 것이 제일 깔끔할 것이다.

```C++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

vector<int> arr(110, 0);
vector<int> memo(110, -1);

void solve(int here, int destination) {

    queue<int> q;
    q.push(here);
    memo[here] = 0;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=1; i<=6; i++) {
            int next = arr[here+i] ? arr[here+i] : here+i;
            // 뱀이나 사다리가 있으면 그곳으로 가야한다.
            if(next <= destination && memo[next] == -1) {
                memo[next] = memo[here] + 1;
                // 최단 거리를 메모이제이션 함과 동시에 방문 체크를 해준다.
                q.push(next);
            }
        }
    }
}

int main()
{
    FAST;
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n+m; i++) {
        int key, value;
        cin >> key >> value;
        arr[key] = value;
    }
    // 간선 만들기

    solve(1, 100);
    cout << memo[100];
    // memo[n]은 n까지의 최단거리이다.
}

```
