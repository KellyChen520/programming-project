
#include <iostream>
#include <cmath>
using namespace std;

float totalLineRisk (int bombNum, int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P);
int main()
{
	//turnTimes個迴圈
	for(int k = 1; k <= turnTimes; k++) //轉 k 次 
	{
		int* turnPlace = new int[2*k+1];
		for(int i = 0; i < 2*k+1; i++) //第k個轉折點的 X座標 = turnPlace[2(k-1)],Y座標 = turnPlace[2(k-1)+1] 
			turnPlace[i] = -1;
		//function find
		for(int times = 1; times <= k; times++)
		{
			for(int y = circleMinY; y <= circleMaxY; y++)
			{
				for(int x = circleMinX; x <= circleMaxX; x++)
				{
					if(inD[y][x] == 1)
					{
						turnPlace[2*times-2] = x;
						turnPlace[2*times-1] = y;
						//risk function(轉折點(x,y))
						//存min risk,x,y				
					}
				} 
			} 
		}		
	} 
	
		
	
	
	return 0;
	
)


	
void find(int k,int turntimes,int **inD,int circleMinX,int circleMaxX,
				int circleMinY,,int circleMaxY,int* turnPlace)
{//轉k次 	
	if(k>turntimes)
		return 0;
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			if(inD[y][x] == 1)
			{
				turnPlace[2*k-2] = x;
				turnPlace[2*k-1] = y;
						//risk function(轉折點(x,y))
						//存min risk,x,y
				find(k+1,turntimes,inD,circleMixX, circleMaxX, circleMixY circleMaxY, turnPlace);
				
			}
		} 
	}
	 
	
}



