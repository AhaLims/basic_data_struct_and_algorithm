#include<iostream>
#include<deque>
using namespace std;
//SPFA+SLF�Ż�
/*
SPFA�����Լ����и�Ȩֵ��ͼ�������ж��Ƿ��и���
����
���Ƚ�Դ��������
ÿ��ȡ����ͷ �Ը�������ɳڲ���
����ɳڹ��ĵ㲻�ڶ����У���������
SLF�Ż���
���Ż��ĵط����ɳڹ��ĵ�j ����ǰ����ͷ�ĵ�Ϊ i ,���dis[j] < dis[i],��j����뵽����ͷ�����򣨸�SPFAһ�������뵽����β
�����dis[t]
�жϸ���������ĳ������ӳ���n�Σ���˵���и���
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
