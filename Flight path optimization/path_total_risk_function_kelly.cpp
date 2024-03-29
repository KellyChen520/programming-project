float totalLineRisk (int Xstart, int Xend, int Ystart, int Yend, int *X, int *Y, int *R, int *P)
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

