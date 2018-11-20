#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	
	int X[10] = {0};   
	int Y[10] = {0};    
	int R[10] = {0};
	int P[10] = {0};
	float distance = 0;   //各點到威脅點的距離 
	float eachDanger = 0;   //各點對單一威脅點的風險 
	float maxRisk = 0;   //所有點中的最大風險 
	int maxRiskI = 0;   //所有點中最大風險的x座標 
	int maxRiskJ = 0;   //所有點中最大風險的y座標 
	
	for(int i = 0; i < m; i++)
	{
		cin >> X[i];
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> Y[i];
	}
	
	for(int i=0; i<m; i++)
	{
		cin >> R[i];
	}
	
	for(int i = 0; i < m; i++)
	{
		cin >> P[i];
	}
	
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			float pointRisk = 0;   //各點的總風險 
			for(int k = 0; k < m ;k++)
			{
				distance = sqrt (pow (i - X[k], 2) + pow (j - Y[k], 2));   //計算此點和一個威脅點的距離 
				eachDanger = ((R[k] - distance) / R[k]) * P[k];    //計算此點對單一威脅點的風險 
				
				if(eachDanger < 0)   //若風險為負數(即此點非在威脅點的威脅範圍)，則令它為零 
				{
					eachDanger = 0;
				}
				
				pointRisk += eachDanger;   //計算此點和各個威脅點的風險的和 
				
				if(pointRisk == maxRisk)   //若總風險等於目前的最大風險時 
				{
					if(i <= maxRiskI)   //先比較此點和目前的最大風險的x座標，若此點的x座標小於等於最大風險的x座標，則再進行y座標的比較 
					{
						if(j < maxRiskJ)   //若此點的y座標小於前的最大風險的y座標，則將此點令為目前最大風險的點 
						    maxRiskI=i;
					        maxRiskJ=j;
					}
				}
				
				if(pointRisk > maxRisk)   //若總風險大於目前的最大風險時，令此點為目前最大風險的點 
				{
					maxRisk = pointRisk;
					maxRiskI = i;
					maxRiskJ = j;
				}
			}
		}
	}
	
	cout << maxRiskI << " " << maxRiskJ;

	
	
	return 0;
} 
