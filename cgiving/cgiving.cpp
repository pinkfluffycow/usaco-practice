// Kevin Jiang (kjiang6205@gmail.com)
// December 6, 2016
// USACO Feb10 - Chocolate Giving

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector< pair<int,int> > adj[50001];
priority_queue< pair<int,int> > pq;
int d[50001];
bool visited[50001];

int main()
{
    int pastures, paths, bulls;
    cin >> pastures >> paths >> bulls;
    for(int i=0; i<paths; i++)
    {
        int a, b, len;
        cin >> a >> b >> len;
        adj[a-1].push_back(make_pair(b-1,len));
        adj[b-1].push_back(make_pair(a-1,len));
    }
    for(int i=0; i<pastures; i++)
    {
        d[i] = 100000000;
        visited[i] = false;
    }
    d[0] = 0;

    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        int p = pq.top().second;
        pq.pop();
        if (!visited[p])
        {
            visited[p] = true;
            for (int i=0; i<adj[p].size(); i++)
            {
                if (d[p]+adj[p][i].second<d[adj[p][i].first])
                {
                    d[adj[p][i].first] = d[p] + adj[p][i].second;
                    pq.push(make_pair(-d[adj[p][i].first], adj[p][i].first));
                }
            }
        }
    }

    for (int i=0; i<bulls; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << d[a-1]+d[b-1] << endl;
    }
    return 0;
}
