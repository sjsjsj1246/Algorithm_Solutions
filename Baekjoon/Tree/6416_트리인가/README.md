---
layout: post
type: algorithms
title: "백준 6416번: 트리인가?"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/6416"
tag: ["Algorithms", "Tree"]
comments: true
rating: silver2
---

트리의 조건을 먼저 생각해봅니다.

1. 정점의 개수 = 간선의 개수 - 1
2. 사이클이 있으면 안됨
3. 루트 노드는 하나여야 하며 트리가 분리돼서는 안된다.

1번 조건은 입력을 받으며 판단합니다.
2번 조건은 bfs로 탐색을 하여 2번 방문하는 정점이 있으면 트리가 아니게 됩니다.
3번 조건은 bfs로 탐색을 하지 않은 정점이 있을 경우로 판단합니다.

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

bool bfs(map<int,vector<int>> &treeMap){
    map <int,int> ckMap;

    for(auto t : treeMap)
        for(auto el : t.second)
            ckMap[el] = 1;

    int root = 0;
    for(auto t : treeMap)
        if(!ckMap[t.first])
            root = t.first;
    ckMap.clear();
    ckMap[root] = 1;
    queue <int> q;
    q.push(root);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < treeMap[x].size(); i++){
            int nx = treeMap[x][i];
            if(ckMap[nx] == 1) return false;
            ckMap[nx] = 1;
            q.push(nx);
        }
    }

    for(auto t : treeMap){
        for(auto el : t.second){
            if(!ckMap[el] || !ckMap[t.first]) return false;
        }
    }
    return true;
}

int main(){
    int testCase = 1;

    while(1){
        int edgeCnt = 0;
        map<int,vector<int>> treeMap;
        set <int> vertex;
        int a, b;

        while(1){
            cin >> a >> b;
            edgeCnt++;
            vertex.insert(a);
            vertex.insert(b);
            if(a == -1 && b == -1) return 0;
            if(a == 0 && b == 0) break;
            treeMap[a].push_back(b);
        }

        if(a && b && vertex.size() != edgeCnt + 1) cout << "Case " << testCase << " is not a tree.\n";
        else cout << "Case " << testCase << " is " <<( bfs(treeMap) ? "a tree.\n":"not a tree.\n");
        testCase++;
    }
}
```
