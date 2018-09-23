int n;
const int maxn = 10000;
int a[maxn];
int ans[maxn];


int Find(int l,int r,int e)//binary search.
{
    if(l == r || r - l == 1)
    {
        return l;
    }
    int mid = (l + r) /2;

    if(ans[mid] <= e)return Find(mid,r,e);
    else return Find(l,mid,e);
}

int LIS()//return the length of longest increase sequence
{
    int len = 1;
    ans[0] = a[0];
    for(int i = 1;i < n;i++)
    {
        if(a[i] > ans[len - 1])
        {
            ans[len++] = a[i];
        }
        else
        {
            int tmp = Find(0,len - 1,a[i]) ;
            if(ans[tmp] < a[i])tmp++;
            ans[tmp] = a[i];
        }
    }
    return len;
}


int main()
{
    ifile.open( "output.txt");
    srand((unsigned)time(0));
    int t = 100;
    n = 10;
    while(t--)
    {

        for(int i = 0;i<n;i++)cin>>a[i];
           // a[i] = rand() % 10 + 1;
        int length1 = LIS();
        int length2 = lis();
        if(length1 == length2)continue;
		cout<<length1<<" "<<length2<<endl;
        cout<<LIS()<<endl;;
    }
    return 0;
}


