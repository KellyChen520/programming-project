/*
假設一個轉折點
跑矩形裡的每個點 
檢驗長度是否超過 順便存下bool值 
否則算風險

for
假設兩個轉折點
跑bool = 1的點
...
假設三 

一直算到 (Risk0/w)+1個轉折點

比較總成本 = risk+ w(k - 1)
if R-d > 0,risk = (R-distance)/R; else Risk=0
distance = sqrt()
*/
#include <iostream>
using namespace std;
int main()
{
	//cin
	int n = 0, m = 0, w = 0, d = 0; //格子點0~n m個威脅點 d距離限制 
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0; //start(Xs, Ys) terminal(Xt, Yt) 
	cin >> n >> m >> w >> d;
	
	int *X = new int[m]; //威脅點座標X 
	for(int i = 0; i < m, i++)
	{
		cin >> X[i];
	}
	
	int *Y = new int[m]; //威脅點座標Y 
	for(int i = 0; i < m, i++)
	{
		cin >> Y[i];
	}
	
	int *R = new int[m]; //Radius 
	for(int i = 0; i < m, i++)
	{
		cin >> R[i];
	}
	
	int *P = new int[m]; //風險乘數 
	for(int i = 0; i < m, i++)
	{
		cin >> P[i];
	}
	
	cin >> Xs >> Ys >> Xt >> Yt;
	
	//算0轉折點risk
	 
	
}
