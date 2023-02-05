
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
        map<int,vector<int> > treeMap;
        set<int> vertex;
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