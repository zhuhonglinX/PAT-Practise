#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
int road[10001][10001] = {0};
int visit[10001];
set<int> depst;
int maxdeep = 0;
int flag = 0;

void right(int id) {
    visit[id] = 1;
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1 || road[id][i] == 0) continue;
        right(i);
    }
}

void dfs(int rootid, int id, int deep) {
    visit[id] = 1;
    for (int i = 1; i <= N; i++) {
        if (road[id][i] == 1 && visit[i] == 0) {
            dfs(rootid, i, deep + 1);
        }
    }
    if (deep > maxdeep) {
        maxdeep = deep;
        depst.clear();
        depst.insert(rootid);
    } else if (deep == maxdeep) {
        depst.insert(rootid);
    }
}


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        road[x][y] = road[y][x] = 1;
    }

    int cnt = 0;
    fill(visit, visit + 10001, 0);
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1) continue;
        right(i);
        cnt++;
    }
    if (cnt != 1) {
        printf("Error: %d components\n", cnt);
    } else {
        for (int i = 1; i <= N; i++) {
            flag = 0;
            fill(visit, visit + 10001, 0);
            dfs(i, i, 0);
        }
        set<int>::iterator it;
        for (it = depst.begin(); it != depst.end(); it++) {
            printf("%d\n", *it);
        }
    }

    return 0;
}