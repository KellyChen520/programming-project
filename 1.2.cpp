#include <iostream>
#include <math.h>
using namespace std;
double max(double, double);
double distance(double,double, double, double);
int main(){
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	// m: number of dangerous points
	// n: n * n coordinates
	// k: number of routes
	double* X = new double[m];
	double* Y = new double[m];
	double* R = new double[m];
	int* P = new int[m];
	for(int i = 0; i < m; i++)
		cin >> X[i];
	for(int i = 0; i < m; i++)
		cin >> Y[i];
	for(int i = 0; i < m; i++)
		cin >> R[i];
	for(int i = 0; i < m; i++)
		cin >> P[i];

	//declare a 2D array route
	//starting point: (route[i][0], route[i][1])
	//destinaion point: (route[i][2], route[i][3])
	double** route = new double*[k];
	for(int i = 0; i < k; i++)
    	route[i] = new double[4];
    for(int i = 0; i < k; i++){
    	for(int j = 0; j < 4; j++){
    		cin >> route[i][j];  
    	}
    }

    //a 2D array storing the risk of each segmemtation point
    double** risk = new double*[k];
    for(int i = 0; i < k; i++){
    	risk[i] = new double[101];
    }

    //let all elements in the risk array to be 0
    for(int i = 0; i < k; i++){
    	for(int j = 0; j < 101; j++){
    		risk[i][j] = 0;
    	}
    }

    //an array storing the total risk of each route
    double* totalRisk = new double[k];
    for(int i = 0; i < k; i++){
    	totalRisk[i] = 0;
    }

    //find how many segmentation points
    //the number of segmentation points is int_distance
    for(int i = 0; i < k; i++){
    	double distanceWhole = 0;
    	distanceWhole = distance(route[i][0], route[i][2], route[i][1], route[i][3]);
    	int int_distance = 0;
    	if(distanceWhole - floor(distanceWhole) == 0)
    		int_distance = distanceWhole - 1;
    	if(distanceWhole - floor(distanceWhole) != 0)
    		int_distance = floor(distanceWhole);

    	//a 2D array storing the coordinates of each segmentation point
    	double** seg_point = new double*[int_distance];
    	for(int u = 0; u < int_distance; u++){
    		seg_point[u] = new double[2];
    	}

    	//dx: the amount each x coordinate needs to increase to find segmentation point
    	//dy: the amount each y coordinate needs tp increase to find segmentation point
    	double dx = (route[i][2] - route[i][0]) / distanceWhole;
	    double dy = (route[i][3] - route[i][1]) / distanceWhole;
	    // cout << dx << "\n" << dy << endl;
	    seg_point[0][0] = route[i][0] + dx, seg_point[0][1] = route[i][1] + dy;
	    for(int q = 1; q < int_distance; q++){	
			seg_point[q][0] = seg_point[q - 1][0] + dx;
			seg_point[q][1] = seg_point[q - 1][1] + dy;
	    }

	    // for(int u = 0; u < int_distance; u++){
	    // 	cout << seg_point[u][0] << " " << seg_point[u][1] << endl;
	    // }

	    //find the total risk of each segmentation point
	    for(int j = 0; j < int_distance; j++){
	    	for(int u = 0; u < m; u++){	
	    		// cout << distance(seg_point[j][0], X[u], seg_point[j][1], Y[u]) << " ";
				double temp = max(1 - distance(seg_point[j][0], X[u], seg_point[j][1], Y[u]) / R[u], 0) * (double)P[u];
				risk[i][j] = risk[i][j] + temp;
				temp = 0;
			}
	    }

	 //    for(int j = 0; j < int_distance; j++){	
		// 	cout << risk[i][j] << " ";
		// }
		
		for(int j = 0; j < 101; j++){
			totalRisk[i] += risk[i][j];
		}
		// cout << totalRisk[i] << " ";
    }
   
    double MinRisk = totalRisk[0];
    int minNum = 1;
    for(int i = 1; i < k; i++){
    	if(totalRisk[i] < MinRisk){
    		MinRisk = totalRisk[i];
    		minNum = i + 1;
    	}	
    }
    cout << minNum << " ";

    double MaxRisk = totalRisk[0];
    int maxNum = 1;
    for(int i = 1; i < k; i++){
    	if(totalRisk[i] > MaxRisk){
    		MaxRisk = totalRisk[i];
    		maxNum = i + 1;
    	}
    }
    cout << maxNum << endl;



	return 0;

}

double distance(double x1, double x2, double y1, double y2){
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

double max(double num1, double num2){
	if(num1 > num2)
		return num1;
	else
		return num2;
}
