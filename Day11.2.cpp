#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if (n == 1) return true;
        vector<bool> visited(n, false);
        visited[source] = true;
        bool flag = true;
        while (flag) {
            flag = false;
            for (const auto& edge : edges) {
                if (visited[edge[0]] != visited[edge[1]]) {
                    visited[edge[0]] = true;
                    visited[edge[1]] = true;
                    flag = true;
                }
                if (visited[destination]) return true;
            }
        }
        return false;
       
    }
    
int main(){
    vector<vector<int>>edges={{0,1},{1,2},{2,0}};
    int source=0;
    int destination=2;
    int n=edges.size();
    cout<<validPath(n,edges,source,destination);
    return 0;
}

