#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>  
using namespace std;
struct mobile
{
string name,processor,image,price;
float rating,Size_Cm,Size_Inch;
int price1,R1_Cam_MP,R2_Cam_MP,R3_Cam_MP,R4_Cam_MP,Battery,ram,rom,Expandable_GB;
};
std::vector<mobile> my_records;
;
class classifiers{
public:
    std::vector<mobile>filtered_records;
    void display(mobile a){
        cout<<"Name:"<< a.name<<")"<<endl;
        cout<<"Rating:"<<a.rating<<endl;
        cout<<"Price:"<<a.price<<endl;
        cout<<"RAM:"<<a.ram<<endl;
        cout<<"ROM:"<<a.rom<<endl;
        cout<<"Exapandable memory:"<<a.Expandable_GB<<endl;
        cout<<"Size in cm:"<<a.Size_Cm<<"cm"<<endl;
        cout<<"Size in inches:"<<a.Size_Inch<<"inches"<<endl;
        cout<<"Rear cam 1:"<<a.R1_Cam_MP<<"MP"<<endl;
        cout<<"Rear cam 2:"<<a.R2_Cam_MP<<"MP"<<endl;
        cout<<"Rear cam 3:"<<a.R3_Cam_MP<<"MP"<<endl;
        cout<<"Rear cam 4:"<<a.R4_Cam_MP<<"MP"<<endl;
        cout<<"Battery(in mAh):"<<a.Battery<<"mAh"<<endl;
        cout<<"Processor:"<<a.processor<<endl;
        cout<<"Click to view:"<<a.image<<endl;
        cout<<"\n";
    }
    vector<mobile> rating(vector<mobile>x,float a=0, float b=5){
        for (auto& it : x) {
        if(a<it.rating && it.rating<b){
            filtered_records.push_back(it);
        }
    }
    return filtered_records;
    }
    vector<mobile> battery(vector<mobile>x,float a=0, float b=7000){
        for (auto& it : x) {
        if(a<it.Battery && it.Battery<b){
            filtered_records.push_back(it);

        }
        
    }
    return filtered_records;
    }
    vector<mobile> ram(vector<mobile>x,float a=0, float b=15){
        for (auto& it : x) {
        if(a<it.ram && it.ram<b){
            filtered_records.push_back(it);

        }
        
    }
    return filtered_records;
    }
    vector<mobile> rom(vector<mobile>x,float a=0, float b=600){
        for (auto& it : x) {
        if(a<it.rom && it.rom<b){
            filtered_records.push_back(it);
        }
        
    }
    return filtered_records;
    }
    vector<mobile> price(vector<mobile>x,float a=0,float b=200000){
        for (auto& it : x) {
        it.price.erase(std::remove(it.price.begin(), it.price.end(), '"'), it.price.end());
        it.price.erase(std::remove(it.price.begin(), it.price.end(), ','), it.price.end());
        it.price1=std::stof(it.price);  
        if(a<it.price1 && it.price1<b){
            filtered_records.push_back(it);
        }}
        return filtered_records;
        }
    };
class CSV_reader:public classifiers{
    public:
    CSV_reader(){
    ifstream data("mobile.csv");
    if (!data.is_open())
    {
        exit(EXIT_FAILURE);
    }
    string str;
    getline(data, str);
    while (getline(data, str))
{
    mobile record;
    istringstream iss(str);
    string token;
    
    getline(iss, record.name, ')');
    
    getline(iss, token, ',');
    getline(iss, token, ',');
    record.rating = atof(token.c_str());

    getline(iss, token, '"');
    getline(iss, record.price, '"');

    getline(iss, token, ',');
    getline(iss, token, ',');
    record.ram = atoi(token.c_str());

    getline(iss, token, ',');
    record.rom = atoi(token.c_str());

    getline(iss, token, ',');
    record.Expandable_GB = atoi(token.c_str());

    getline(iss, token, ',');
    record.Size_Cm = atof(token.c_str());

    getline(iss, token, ',');
    record.Size_Inch = atof(token.c_str());

    getline(iss, token, ',');
    record.R1_Cam_MP = atoi(token.c_str());

    getline(iss, token, ',');
    record.R2_Cam_MP = atoi(token.c_str());

    getline(iss, token, ',');
    record.R3_Cam_MP = atoi(token.c_str());

    getline(iss, token, ',');
    record.R4_Cam_MP = atoi(token.c_str());

    getline(iss, token, ',');
    record.Battery = atoi(token.c_str());

    getline(iss, record.processor, ',');

    getline(iss, record.image, ',');

    my_records.push_back(record);
}
}};
int main()
{   int x,y,b,c,d,e,f,g,h,i,j,k;
    CSV_reader dataset;
    classifiers a;
    std::vector<mobile> list;
    for(int i=0;i<2;i++){
        cout<<"******************************************************************"<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"|                                                                |"<<endl;
    }
        cout<<"|               Welcome to Techway  !!!                          |"<<endl;
    for(int i=0;i<5;i++){
        cout<<"|                                                                |"<<endl;
    }
    for(int i=0;i<2;i++){
        cout<<"******************************************************************"<<endl;
    }

    cout<<"We here to help you!!"<<endl;
    cout<<"Apply filters:"<<endl;
    cout<<"1.Ratings"<<endl;
    cout<<"Enter rating range or skip:";
    cin>>b;
    cout<<"-";
    cin>>c;

    cout<<"2.Price"<<endl;
    cout<<"Enter price range or skip:";
    cin>>d;
    cout<<"-";
    cin>>e;
    
    cout<<"3.RAM"<<endl;
    cout<<"Enter RAM range or skip:";
    cin>>f;
    cout<<"-";
    cin>>g;
   
    cout<<"4.ROM"<<endl;
    cout<<"Enter ROM range or skip:";
    cin>>h;
    cout<<"-";
    cin>>i;
    
    cout<<"5.Battery"<<endl;
    cout<<"Enter Battery range or skip:";
    cin>>j;
    cout<<"-";
    cin>>k;

    list=a.rating(my_records,b,c);
    list=a.price(list,d,e);
    list=a.ram(list,d,e);
    list=a.rom(list,d,e);
    list=a.battery(list,d,e);
    a.filtered_records=list;
    for (auto& it : a.filtered_records) {
        a.display(it);
    }
return 0;   
}
