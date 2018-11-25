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


改善:
1.不回頭 
2.正方形 ->if better,菱形 
3.挑點走 不要每個走 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

float straightLineRisk (int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P, int m);
float newStart(int distance, float start, float end, float tempL);
float totalLineRisk (int *allPoints, int *X, int *Y, int *R, int *P, int m, int k);
void findMinCost(float d,int m, int w, int k,int turntimes,bool **inD, float lowcost, int circleMinX,int circleMaxX,int circleMinY,
					int circleMaxY,int* turnPlace,int &ansturn,int *ansXY , float *distance, int* X, int* Y, int* R, int* P);
bool repeat(int x,int y, int k, int *turnPlace, int turnTimes);
bool turnback(int x, int y, int k, int* turnPlace, int turnTimes);
int main()
{
	//cin
	int n = 0, m = 0; //格子點0~n m個威脅點
	float w = 0, d = 0; //d距離限制 
	cin >> n >> m >> w >> d;
	
	int *X = new int[m]; //威脅點座標X 
	for(int i = 0; i < m; i++)
		cin >> X[i];
	
	int *Y = new int[m]; //威脅點座標Y 
	for(int i = 0; i < m; i++)
		cin >> Y[i];
	
	int *R = new int[m]; //Radius 
	for(int i = 0; i < m; i++)
		cin >> R[i];
	
	int *P = new int[m]; //風險乘數 
	for(int i = 0; i < m; i++)
		cin >> P[i];
	
	int Xs = 0, Ys = 0, Xt = 0, Yt = 0; //start(Xs, Ys) terminal(Xt, Yt) 
	cin >> Xs >> Ys >> Xt >> Yt;
	
	//算0轉折點risk
	float risk0 = straightLineRisk(Xs, Xt, Ys, Yt, X, Y, R, P, m);
	
	//算長度範圍
	float midX = (Xs + Xt) / 2;
	float midY = (Ys + Yt) / 2;
	
	//inD找出在長度範圍內的點(橢圓形面積內整數點) 
	int circleMaxX = midX + d/2; //圓形切線maxX座標 
	int circleMinX = midX - d/2; //圓形切線minX座標
	int circleMaxY = midY + d/2; //圓形切線maxY座標
	int circleMinY = midY - d/2; //圓形切線minY座標
	
	
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
	
	int turnTimes = risk0;//轉折點次數 
	if(risk0 > 10)
	{
		if(w >= 1)
			turnTimes = risk0 / w + 1;
		else
			turnTimes = 150; //check!!
	}
	
	
	int* turnPlace = new int[2*turnTimes+5]; //存起點XY、各轉折點XY、終點XY 
	turnPlace[0] = Xs, turnPlace[1] = Ys;
	turnPlace[2*turnTimes+2] = Xt,turnPlace[2*turnTimes+3] = Yt;
	for(int i = 2; i <= 2*turnTimes+1; i++) //第k個轉折點的 X座標 = turnPlace[2k],Y座標 = turnPlace[2k+1] 
		turnPlace[i] = -1;
	
	float minCost = risk0;
	int ansK = 0;
	int* ansXY = new int[2*turnTimes+4]; //最後要輸出的座標 
	for(int i = 0; i < 2*turnTimes+4; i++)
		ansXY[i] = -1; //-1不輸出 
		
	float lowCost = risk0;//lowcost是不轉的風險 
	float *distance = new float [turnTimes+1];
	for(int i = 0; i < turnTimes+1; i++)
		distance[i] = 0 ;

	findMinCost(d, m, w, 1, turnTimes, inD, lowCost, circleMinX, circleMaxX, circleMinY, circleMaxY, turnPlace, 
				ansK, ansXY, distance, X, Y, R, P);

	
	if(ansK == 0)
		cout << 0;
	else
	{
		cout << ansK <<" ";
		for(int i=0; i<ansK;i++){
			if(i==ansK-1)
				cout<<ansXY[2*i]<<" "<<ansXY[2*i+1];
			else
				cout<<ansXY[2*i]<<" "<<ansXY[2*i+1]<<" ";
		}
		 
	}


	 
	
	delete[] X;
	delete[] Y;
	delete[] R;
	delete[] P;
	for(int i = 0; i < circleMaxY +1; i++)
		delete[] inD[i];
	
	return 0;
}

//Function1:直線 
float straightLineRisk (int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P, int m)
{
	float totalRisk = 0;
	float length = sqrt(pow(Xstart - Xend,2) + pow(Ystart - Yend,2));
		
	int times = static_cast<int>(length);   //轉折點個數 
		
	if(times == length)
		times -= 1;
	 
	for(int t = 1; t <= times; t++)//dot num
	{
		float x = Xstart + (Xend-Xstart) / length * t;  //下一個的x座標 
		float y = Ystart + (Yend-Ystart) / length * t;  //下一個的y座標 
			
		for(int b = 0; b < m; b++)//bomb num
		{
			float d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));   //分割點和炸彈的距離 
				
			if(R[b] - d > 0)
			{
				totalRisk += P[b] * (R[b] - d) / R[b];
			}
					
		}
	}
	
	return totalRisk;
}

//Function2:算risk 
float totalLineRisk (int *allPoints, int *X, int *Y, int *R, int *P, int m, int k, int turnTimes)
{
	float eachPathRisk = 0;
	float totalRisk = 0;
	
	float Xnew = 0;   //新的起點的x座標 
	float Ynew = 0;   //新的起點的y座標
	
	float Xstart = 0;
	float Ystart = 0;
	float Xend = 0;
	float Yend = 0;
	/*for(int qw=0;qw<=3;qw++)
			cout<<k<<"K "<<allPoints[2*qw]<<" "<<allPoints[2*qw+1]<<" ";
				cout<<endl;*/
	for(int i =0; i <= 2*k; i += 2)
	{
		float length = 0;
		if(i != 2*k)
	        length = sqrt(pow(allPoints[i] - allPoints[i+2],2) + pow(allPoints[i+1] - allPoints[i+3],2));
	    else
	        length = sqrt(pow(allPoints[i] - allPoints[2*turnTimes +2],2) + pow(allPoints[i+1] - allPoints[2*turnTimes +3],2));
	        
	    int times = static_cast<int>(length);   //分割點個數 
	        
		if(i == 0 )
		{
			Xnew = allPoints[i];
			Ynew = allPoints[i+1];
			Xend = allPoints[i+2];
			Yend = allPoints[i+3];
		}
		else
		{
			Xstart = allPoints[i];
			Ystart = allPoints[i+1];
			if(i == 2*k)
			{
				Xend = allPoints[2*turnTimes +2];
				Yend = allPoints[2*turnTimes +3];
			}
			else
			{
				Xend = allPoints[i+2];
				Yend = allPoints[i+3];
			}
				

			float lengthInt = static_cast<float>(times);   
			float restLenghth = 1 - (length - lengthInt);   //下一個起點離轉折點的距離 

            float tempL = sqrt(pow(Xstart - Xend, 2) + pow(Ystart - Yend, 2));
			Xnew = newStart(restLenghth, Xstart,  Xend, tempL);   //新的起點的x座標 
			Ynew = newStart(restLenghth, Ystart,  Yend, tempL);   //新的起點的y座標
		}

		if(times == length)
			times -= 1;

		if(Xnew != allPoints[0] && Ynew != allPoints[1])//起點
		{
			for(int b = 0; b < m; b++)//bomb num
			{
				float d = sqrt(pow((Xnew - X[b]), 2) + pow((Ynew - Y[b]), 2));   //分割點和炸彈的距離 

				if(R[b] - d > 0)
				{
					eachPathRisk += P[b] * (R[b] - d) / R[b];
				}

			} 
		}
		
		length = sqrt(pow(Xnew - Xend, 2) + pow(Ynew - Yend, 2));    
	 
	    for(int t = 1; t <= times; t++)//dot num
	    {
			float x = Xnew + (Xend-Xnew) / length * t;  //下一個的x座標 
			float y = Ynew + (Yend-Ynew) / length * t;  //下一個的y座標 
					
			for(int b = 0; b < m; b++)//bomb num
			{
				float d = sqrt(pow((x - X[b]), 2) + pow((y - Y[b]), 2));   //分割點和炸彈的距離 
						
				if(R[b] - d > 0)
				{
					eachPathRisk += P[b] * (R[b] - d) / R[b];
				}
							
			}
	    }
		
		//cout<<eachPathRisk<<" ";
		totalRisk += eachPathRisk;
	}
	
	//cout << totalRisk << '\n';
	return totalRisk;
}

//Function3
float newStart(int distance, float start, float end, float tempL)
{
	float newPoint = start + (abs(end - start)*distance)/tempL;
	
	return newPoint;
}

//Function4
void findMinCost(float d,int m, int w, int k,int turnTimes,bool **inD, float lowCost, int circleMinX,int circleMaxX,int circleMinY,
					int circleMaxY,int* turnPlace,int &ansK,int *ansXY , float *distance, int* X, int* Y, int* R, int* P)
{//轉k次 	
	if(k > turnTimes)
		return;
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{	
			bool checkR = repeat (x, y, k, turnPlace, turnTimes);
			bool checkT = turnback(x, y, k, turnPlace, turnTimes);
			
			if(checkR == 1)
				continue;
			if(checkT == 1)
				continue;
				
			if(inD[y][x] == 1)
			{
				turnPlace[2*k] = x;
				turnPlace[2*k+1] = y;
				
				float finalDis = 0, tempDis = 0;
				tempDis = sqrt(pow((turnPlace[2*k]-turnPlace[2*k-2]),2) + pow((turnPlace[2*k+1]-turnPlace[2*k-1]),2));
				finalDis = sqrt(pow((turnPlace[2*turnTimes+2]-turnPlace[2*k]),2) + pow((turnPlace[2*turnTimes+3]-turnPlace[2*k+1]),2));
				
				if(finalDis + distance[k-1] + tempDis > d)
					continue;
					
				distance[k] = distance[k-1] + tempDis;
				
				float cost = totalLineRisk(turnPlace, X, Y, R, P, m, k,turnTimes) ;//function(轉折點(x,y))+w(k-1);
				if(cost < lowCost)
				{
					ansK = k;
					lowCost = cost;
					for(int i = 2; i < 2*k+2; i++)
					{
						ansXY[i-2] = turnPlace[i];
						//cout<<turnPlace[i]<<" "<<ansXY[i-2]<<endl;
						//cout << endl << lowCost <<endl;
					}
				}
				
				findMinCost(d, m, w, k+1, turnTimes, inD, lowCost, circleMinX, circleMaxX, circleMinY, circleMaxY, turnPlace, 
							ansK, ansXY, distance, X, Y, R, P);		
			}
		} 
	}
}

//Function5
bool repeat(int x,int y, int k, int *turnPlace, int turnTimes)
{
	//終點XY turnPlace[2*turnTimes+2] = Xt,turnPlace[2*turnTimes+3] = Yt; 
	bool check = 0;
	for(int i = 0; i <= k; i++)
	{
		if (x == turnPlace[2*i] && y == turnPlace[2*i+1] )
			check = 1;
	}
	if(x == turnPlace[2*turnTimes+2] && y == turnPlace[2*turnTimes+3])
		check = 1;
	
	return check;
}

//Function6
bool turnback(int x, int y, int k, int* turnPlace, int turnTimes)
{
	//終點XY turnPlace[2*turnTimes+2] = Xt,turnPlace[2*turnTimes+3] = Yt; 
	//turnPlace[2*(k-1)](X,turnPlace[2*k-1] (Y
	int maxX = turnPlace[2*turnTimes+2];
	int minX = turnPlace[2*k-2];
	int maxY = turnPlace[2*turnTimes+3];
	int minY = turnPlace[2*k-1];
	
	if(maxX < minX)
		int temp = maxX, maxX = minX, minX = temp;
	if(maxY < minY)
		int temp = maxY, maxY = minY, minY = temp;
		
	bool Xout = 0, Yout = 0; 
	if(x > maxX || x < minX)
		Xout = 1;
	if(y > maxY || y < minY)
		Yout = 1;
	
	if(Xout == 1 || Yout ==1)
		return 1;
	else
		return 0;
}
