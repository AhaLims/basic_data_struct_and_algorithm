#include<iostream>
#include<deque>
using namespace std;
//SPFA+SLF优化
/*
SPFA：可以计算有负权值的图，可以判断是否有负环
过程
首先将源点加入队列
每次取队列头 对各点进行松弛操作
如果松弛过的点不在队列中，则加入队列
SLF优化：
（优化的地方）松弛过的点j ，当前队列头的点为 i ,如果dis[j] < dis[i],则将j点插入到队列头，否则（跟SPFA一样）插入到队列尾
结果：dis[t]
判断负环：假如某个点入队超过n次，则说明有负环
*/

const int maxn = 1000;//change this value
int dis[maxn];
int w[maxn][maxn];//the distance from i to j
bool visit[maxn];//to mark whether the element is in the queue
int time[maxn];//the times of entries per element
//if time[i] >n ,it indicates that there is a negative ring
const int inf = 10e8;
int n;//n points

bool negative_ring = false;

void init()
{
    negative_ring = false;
    for(int i = 0;i<n;i++)
    {
        visit[i] = false;
        time[i] = 0;
        dis[i] = inf;
        for(int j = 0;j<n;j++)
        {
            w[i][j] = inf;
        }
    }

}

void spfa(int s)
{
    dis[s] = 0;
    visit[s] = true;
    time[s]++;
    deque<int>q;
    q.push_back(s);
    int current;
    int tmp;
    while(!q.empty())
    {
        current = q.front();
        q.pop_front();
        visit[current] = false;
        for(int i = 0;i<n;i++)
        {
            if( dis[i] > dis[current] + w[current][i])
            {

                time[i]++;
                dis[i] = dis[current] + w[current][i];
                if(time[i] >= n)
                {
                    negative_ring = true;
                    return;
                }

                if(visit[i] == false )
                {
                    if(q.empty())q.push_back(i);
                    else
                    {
                        tmp = q.front();
                        if(dis[tmp] > dis[i])
                            q.push_front(i);
                        else q.push_back(i);
                    }
                visit[i] = true;
                }
            }
        }
    }
}




int main()
{
    int m,a,b,c;
    int s ,t;
    while(cin>>n>>m)
    {
        init();
        for(int i = 0;i < m;i++)
        {
            cin>>a>>b>>c;
            if(w[a][b] > c)
            {
                w[a][b] = c;
                w[b][a] = c;
            }
        }
        cin>>s>>t;
        spfa(s);
        if(dis[t] != inf)
        {
            cout<<dis[t]<<endl;
        }
        else cout<<-1<<endl;
    }
}
