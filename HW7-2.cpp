//HW7-2
/*
cin:
6 3 3 n m k(k條路徑)
2 5 4 X(m個 
5 4 2 Y
2 3 2 R
2 1 2 P
1 1 4 1 (1,1)to(4,1)
1 1 4 5
6 1 2 5
*/
#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main()
{
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	
	int* X = new int[m];
	int* Y = new int[m];
	int* R = new int[m];
	int* P = new int[m]; //p表威脅程度
	for(int i = 0; i < m; i++)
		cin >> X[i];
	for(int i = 0; i < m; i++)
		cin >> Y[i];
	for(int i = 0; i < m; i++)
		cin >> R[i];
	for(int i = 0; i < m; i++)
		cin >> P[i]; 
		
	int** route = new int* [k];
	for(int i = 0; i < k; i++)
	{
		route[i] = new int [4];
		for(int j = 0; j < 4; j++)
			cin >> route[i][j];
	}
	
	double* risk = new double[k];
	for(int num = 0; num < k; num++)//route num
	{
		double length = sqrt(pow(route[num][0]-route[num][2],2) + pow(route[num][1]-route[num][3],2));
		//cout << length <<" ";
		int times = static_cast<int>(length);
		//cout << length <<" " << times <<"\n";
		if(times == length)
			times -= 1; 
		for(int t = 1; t <= times; t++)//dot num
		{
			double x = route[num][0] + (route[num][2]-route[num][0]) / length * t;
			double y = route[num][1] + (route[num][3]-route[num][1]) / length * t;
			for(int b = 0; b < m; b++)//bomb num
			{
				double d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));
				if(R[b] - d > 0)
				{
					risk[num] += P[b] * (R[b] - d) / R[b];
					//cout <<"bomb" << b <<":" << P[b] * (R[b] - d) / R[b] <<"\n";
				}
					
			}
		}
		//cout << num <<" " << risk[num] <<"\n";
	}
	
	//find max,min
	double max = risk[0], min = risk[0];
	int ansMax = 1, ansMin = 1;
	for(int i = 0; i < k; i++)
	{
		if(risk[i] > max)
			max = risk[i], ansMax = i+1;
		if(risk[i] < min)
			min = risk[i], ansMin = i+1; 
	}
	cout << ansMin <<" " << ansMax;
		
	return 0;	
}
