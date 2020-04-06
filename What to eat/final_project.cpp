#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

int randomInt(int countAvailable); /* 梅森旋轉演算法 (input an int n , return int from zero to n randomly)*/

class restaurant
{
public:
    string name;
    string place;
    string type;
    string budget;
    string address;
    int index;
};

int findAvailable(string budget , string type , string place , restaurant* all_Restaurant)
{
    int budgetWordCnt = 0;
    int typeWordCnt = 0 ;
    int placeWordCnt = 0;
    char delim[] = ",";
    string budget_cut[4] = {"", "", "", ""};
    string word;

    stringstream stream_budget(budget);
    while(getline(stream_budget, word, ','))
    {
        budget_cut[budgetWordCnt] = word;
        budgetWordCnt++;
    }

    stringstream stream_type(type);
    string type_cut[20] = {"","","","","","","","","","","","","","","","","","","",""};
    while(getline(stream_type, word, ','))
    {
        type_cut[typeWordCnt] = word;
        typeWordCnt++;
    }

    stringstream stream_place(place);
    string place_cut[6] = {"","","","","",""} ;
    while(getline(stream_place, word, ','))
    {
        place_cut[placeWordCnt] = word;
        placeWordCnt++;
    }
    
    int countAvailable = 0;
    int available[205] = {0} ;
    for(int i = 0 ; i <  budgetWordCnt ; i++)
    {
        for(int j = 0 ; j < 205 ; j++)
        {
            if(budget_cut[i] == all_Restaurant[j].budget)
            {
                for(int k = 0 ; k < typeWordCnt ; k++)
                {
                    if(all_Restaurant[j].type  == type_cut[k])
                    {
                        for(int u = 0; u < placeWordCnt; u++)
                        {
                            if(all_Restaurant[j].place == place_cut[u])
                            {
                                available[countAvailable] = j ;
                                countAvailable++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(countAvailable == 0){
        return -1;
    }

    int ans = randomInt(countAvailable) ;
    return all_Restaurant[ans].index;
}

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
	  all_Restaurant[i].index = i;
	  i++;
	}    
}

int main()
{   
    string type;
    string budget;
    string place;
    cout << "請選擇想要的餐\廳\類型" << "\n";
    cout << "A1：速食、A2：自助、A3：台式、A4義式、A5美式、A6港式、A7日式、A8泰式、A9其他（小點心：潤餅、炭烤、鹽酥雞等) 飯後：A10甜點、A11冰品、A12飲料" << "\n";
    cin >> type; //以逗點隔開
    cout << "請輸入午餐\預\算" << "\n";
    cout << "B1（1～150）、B2（151～250）、B3（251～500）、B4（501～infinity）" << "\n";
    cin  >> budget; //以逗點隔開
    cout << "請輸入餐\廳\地點" << "\n";
    cout << "C1校內、C2新生南路側、C3辛亥路側、C4基隆路側、C5羅斯福路側、C6遙遠的彼方" << "\n";
    cin >> place; //以逗點隔開
    
    
    
    restaurant all_Restaurant[1000];
    load_Csv("table.csv", all_Restaurant);
    
    int ansIndex = findAvailable(budget, type, place, all_Restaurant);
    if(ansIndex == -1){
        cout << "NO RESTAURANT";
    }
    else
        cout << all_Restaurant[ansIndex].name << "\n" << all_Restaurant[ansIndex].address <<endl;
    return 0;
}

// input an int n , return int from zero to n randomly
int randomInt(int countAvailable)
{
    random_device rd;
    
    /* 梅森旋轉演算法 */
    mt19937_64 generator( rd() );
    
    uniform_real_distribution< > dis(0 , countAvailable + 1) ;
    int x = dis(generator);
    return x;
}

