#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
using namespace std;

int randomInt(int count); /* 梅森旋轉演算法 (input an int n , return int from zero to n randomly)*/

class restaurant
{
public:
    string name;
    string place;
    string type;
    string budget;
    string address;
};

//readfile
void load_Csv(char filename[], restaurant* all_Restaurant)
{
  fstream file;
  file.open("table.csv");
  string line;
  int i = 0;
  while (getline( file, line,'\n'))  //讀檔讀到跳行字元
    {
	  istringstream templine(line); // string 轉換成 stream
	  string data;
	  getline(templine, data,','); //讀檔讀到逗號
	  all_Restaurant[i].name = data;
      getline(templine, data,','); //讀檔讀到逗號
	  all_Restaurant[i].budget = data;
	  getline(templine, data,','); //讀檔讀到逗號
	  all_Restaurant[i].type = data;
	  getline(templine, data,','); //讀檔讀到逗號
	  all_Restaurant[i].place = data;
	  getline(templine, data,','); //讀檔讀到逗號
	  all_Restaurant[i].address = data;
	  i++;
	}    
}

int main()
{   
//    string type;
//    string budget;
//    string place;
//    cout << "請選擇想要的餐廳類型" << "\n";
//    cout << "A1：速食、A2：自助、A3：台式、A4義式、A5美式、A6港式、A7日式、A8泰式、A9其他（小點心：潤餅、炭烤、鹽酥雞等) 飯後：A10甜點、A11冰品、A12飲料" << "\n";
//    cin >> type;
//    cout << "請輸入午餐預算" << "\n";
//    cout << "B1（1～150）、B2（151～250）、B3（251～500）、B4（501～infinity）" << "\n";
//    cin  >> budget;
//    cout << "請輸入餐廳地點" << "\n";
//    cout << "C1校內、C2新生南路側、C3辛亥路側、C4基隆路側、C5羅斯福路側、C6遙遠的彼方" << "\n";
//    cin >> place;
//    
//    cout << restaurant.name << "\n" << restaurant.address <<endl;
    
    restaurant all_Restaurant[1000];
    load_Csv("table.csv", all_Restaurant);
    cout << all_Restaurant[0].name;
    return 0;
}

// input an int n , return int from zero to n randomly
int randomInt(int count)
{
    random_device rd;
    
    /* 梅森旋轉演算法 */
    mt19937_64 generator( rd() );
    
    uniform_real_distribution< > dis(0 , count + 1) ;
    int x = dis(generator);
    return x;
}
