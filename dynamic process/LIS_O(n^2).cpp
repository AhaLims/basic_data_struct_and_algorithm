#include<iostream>
using namespace std;
//LIS O(n^2)
const int maxn = 1000;//set by the question
int n;//number amount
int number[maxn];
int sub_number[maxn];

void LIS(int & maxLen, int & index)
{
	maxLen = 1;
	index = 0;
	sub_number[0] = 1;
	for (int i = 1; i < n; i++)
	{
		sub_number[i] = 1;
		for (int j = 0; j < i; j++)
		{
			iif(number[j] < number[i] && sub_number[i] < sub_number[j] + 1)
				sub_number[i] = sub_number[j] + 1;//state transition equation
		}
		if (sub_number[i] > maxLen)
		{
			maxLen = sub_number[i];
			index = i;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)cin >> number[i];
	int maxL, index;
	LIS(maxL, index);
	cout << maxL << endl;
}
