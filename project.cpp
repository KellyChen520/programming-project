#include <iostream>
using namespace std;
int main()
{
	int n = 0, m = 0, w = 0, d = 0;
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0;
	cin >> n >> m >> w >> d;
	
	int *X = new int[m];
	for(int i = 0; i < m, i++)
	{
		cin >> X[i];
	}
	
	int *Y = new int[m];
	for(int i = 0; i < m, i++)
	{
		cin >> Y[i];
	}
	
	int *R = new int[m];
	for(int i = 0; i < m, i++)
	{
		cin >> R[i];
	}
	
	int *P = new int[m];
	for(int i = 0; i < m, i++)
	{
		cin >> P[i];
	}
	
	cin >> Xs >> Ys >> Xt >> Yt;
	
}
