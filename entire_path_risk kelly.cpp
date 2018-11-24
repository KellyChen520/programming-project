float totalLineRisk (int *allPoints, int *X, int *Y, int *R, int *P, int m, int k)
{
	float eachPathRisk = 0;
	float totalRisk = 0;
	
	float Xnew = 0;   //新的起點的x座標 
	float Ynew = 0;   //新的起點的y座標
	
	float Xstart = 0;
	float Ystart = 0;
	float Xend = 0;
	float Yend = 0;
	
	for(int i =0; i <= 2*k + 4; i += 2)
	{
		if(allPoints[i] != -1)
		{
	        float length = sqrt(pow(allPoints[i] - allPoints[i+2],2) + pow(allPoints[i+1] - allPoints[i+3],2));
	        
	        int times = static_cast<int>(length);   //轉折點個數 
	        
	        if(i == 0 )
	        {
	        	Xnew = allPoints[i];
	        	Ynew = allPoints[i+1];
			}
			else
			{
				Xstart = allPoints[i];
				Ystart = allPoints[i+1];
				Xend = allPoints[i+2];
				Yend = allPoints[i+3];
				
				float lengthInt = static_cast<float>(times);   
	            float restLenghth = 1 - (length - lengthInt);   //下一個起點離轉折點的距離 
	            
	            Xnew = newStart(restLenghth, Xstart,  Xend);   //新的起點的x座標 
	            Ynew = newStart(restLenghth, Ystart,  Yend);   //新的起點的y座標
			}
	        
	        if(times == length)
		    times -= 1;
		    
		    if(Xnew != allPoints[0] && Ynew != allPoints[1])
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
		}
		
		totalRisk += eachPathRisk;
	}
	
	
	return totalRisk;
}

float newStart(int distance, float start, float end)
{
	float newPoint = start + (end - start)/distance;
	
	return newPoint;
}
