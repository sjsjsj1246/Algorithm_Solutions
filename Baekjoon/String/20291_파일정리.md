---
layout: post
type: algorithms
title: "백준 20291번: 파일 정리"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/20291"
tag: ["Algorithms", "String"]
comments: true
rating: sirver3
---

문자열을 처리하고 등장하는 원소의 개수를 구하는 문제입니다.
STL map을 이용해 간단히 풀 수 있습니다.

```C++
#include <iostream>
#include <algorithm>
#include <map>
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    FAST;
    int n;
    cin >> n;
    map<string, int> m;

    for(int i=0; i<n; i++) {
        string temp;
        cin >> temp;
        m[temp.substr(temp.find(".") + 1, temp.length())]++;
    }

    for(auto x: m) cout << x.first << " " << x.second << "\n";
}
```
