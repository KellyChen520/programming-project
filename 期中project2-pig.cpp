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
#include <cmath>
using namespace std;

int main()
{
	//cin
	int n = 0, m = 0; //格子點0~n m個威脅點
	float w = 0, d = 0; //d距離限制 
	cin >> n >> m >> w >> d;
	
	int *X = new int[m]; //威脅點座標X 
	for(int i = 0; i < m; i++)
	{
		cin >> X[i];
	}
	
	int *Y = new int[m]; //威脅點座標Y 
	for(int i = 0; i < m; i++)
	{
		cin >> Y[i];
	}
	
	int *R = new int[m]; //Radius 
	for(int i = 0; i < m; i++)
	{
		cin >> R[i];
	}
	
	int *P = new int[m]; //風險乘數 
	for(int i = 0; i < m; i++)
	{
		cin >> P[i];
	}
	
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0; //start(Xs, Ys) terminal(Xt, Yt) 
	cin >> Xs >> Ys >> Xt >> Yt;
	/*
	//算0轉折點risk
	float risk0 = //function;
	*/
	
	//算長度範圍
	float midX = (Xs + Xt) / 2;
	float midY = (Ys + Yt) / 2;
	
	//inD找出在長度範圍內的點(橢圓形面積內整數點) 
	int circleMaxX = midX + d; //圓形切線maxX座標 
	int circleMinX = midX - d; //圓形切線minX座標
	int circleMaxY = midY + d; //圓形切線maxY座標
	int circleMinY = midY - d; //圓形切線minY座標
	//若midX+d有小數點，則無條件進位 
	if(midX + d > circleMaxX)
		circleMaxX += 1;
	if(midY + d > circleMaxY)
		circleMaxY += 1;
	//確認沒超出矩陣邊界 
	if(circleMaxX > n)
		circleMaxX = n;
	if(circleMinX < 0)
		circleMinX = 0;
	if(circleMaxY > n)
		circleMaxY = n;
	if(circleMinY < 0)
		circleMinY = 0;
		
	//宣告紀錄該點是否在長度範圍內的矩陣inD 
	bool** inD = new bool* [circleMaxY + 1];
	for(int i = 0; i <= circleMaxY; i++)
	{
		inD[i] = new bool[circleMaxX + 1];
		for(int j = 0; j <= circleMaxX; j++)
			inD[i][j] = 0;
	}
	
	//檢驗圓形內每一點是否在長度範圍d內 
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(sqrt(pow(x-Xs, 2) + pow(y-Ys, 2)) + sqrt(pow(Xt-x, 2) + pow(Yt-y, 2)) <= d)
				inD[y][x] = 1;
		} 
	} 
	/* 
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(x == circleMaxX)
				cout << inD[y][x] <<"\n";
			else
				cout << inD[y][x] <<" ";	
		}
	} 
	*/
	
	//risk[i]表示i個轉折點時的最小risk
	float* risk = new float [risk0 / w + 1];
	for(int i = 0; i < risk0/w + 1; i++)
		risk[i] = -1;
	risk[0] = risk0; 
	//cout << risk[0];
	
	//一個轉折點 
	
	
	 
	
	delete[] X;
	delete[] Y;
	delete[] R;
	delete[] P;
	
	return 0;
}
