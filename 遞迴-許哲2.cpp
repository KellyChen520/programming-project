float lowcost=risk0;//lowcost是不轉的風險 
int *turnplace = new int [2*turntimes+5],ansturn=0;
find(1,turntimes,inD,circleMinX, circleMaxX, circleMinY, circleMaxY, turnPlace,ansturn);


void find(int d,int k,int turntimes,int **inD,int circleMinX,int circleMaxX,
				int circleMinY,,int circleMaxY,int* turnPlace,int &ansturn)
{//轉k次 	
	int distance=0;
	if(k>turntimes)
		return ;
	for(int y = circleMinY; y <= circleMaxY; y++)
	{
		for(int x = circleMinX; x <= circleMaxX; x++)
		{
			
			if(inD[y][x] == 1 )
			{
				turnPlace[2*k] = x;
				turnPlace[2*k+1] = y;
				distance += sqrt(pow((turnPlace[2*k-2]-turnPlace[2*k]),2)+pow((turnPlace[2k-1]-turnPlace[2*k+1]),2));
				if(distance>d)
					continue;
				float cost= risk function(轉折點(x,y))+w(k-1);
				if(cost<lowcost){
					ansturn=k;
					lowcost=cost;
					
				}
				find(d,k+1,turntimes,inD,circleMixX, circleMaxX, circleMixY circleMaxY, turnPlace, ansturn);
						
			}
		} 
	}
	 
	
}




