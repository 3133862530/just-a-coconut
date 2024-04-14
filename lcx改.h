#pragma once
#define MAX_COLS 6
#define MAX_ROWS 40

typedef struct
{
    int Number_of_flights;//飞行次数
    float total_cost;//累计花销
    float total_mileage;//总里程
}records;//历史记录

typedef struct //乘客个人信息
{
    char name[20];
    char idcard[19];//18位身份证
    char contact_information[12];//联系方式
    char password[20];//密码
    int Registration_number[20];//注册编号 UID
    char fancy[50];//旅客偏好
    char seat[2][3];//座位 例：13 A
    Passenger* next;
}Passenger;  //this is also the basic part
typedef struct //管理员个人信息
{
    char name[20];//直接身份证号
    char phnum[12];//联系方式
    char password[10];//密码，规定一下长度
    administrator* next;
}administrator;  //this is also the radical par
typedef struct
{
    bool booked;          //该座位是否被预定
    enum TicketPrice price;  //该座位等级及价格
    Passenger Infor;  //该座位乘客信息
}seat_information;
enum TicketPrice //座位价格
{
    first_class_price = 2000,   //头等舱价格
    business_class_price = 1000,//商务舱价格
    economy_class_price = 500   //经济舱价格
};//建议删除直接加到函数中直接打印，或者直接算

typedef struct //航班信息
{
    char flightnumber;//航班号
    char departure;//起飞地
    char destination;//目的地
    int departureTime;//起飞时间//输入时用【时分秒】的形式输入（每个单位两位，没有的用0）
    int arrivalTime;//到达时间//直接用%s输入
    int  mile;//距离
    int  headseat;//头等舱数量
    int  economyseat;//经济舱数量
    int  business;//商务舱数量
    int availableSeats;//剩余可用座位
    seat_information seats[MAX_ROWS][MAX_COLS];//该架次航班座位信息  一排6位 共40排
    //暂定四排头等舱 八排商务舱 剩余为经济舱    
    Flight* next;
}Flight;    //航班信息     this is the basic part

void initializeAirplane(int FlightNumber);
void displayAirplaneStatus(int FlightNumber);

void bookSeat(int row, int col, int FlightNumber);
void cancelSeat(int row, int col, int FlightNumber);

void Register(Passenger wyl, Flight NEU[]);
void ReRegister(Passenger wyl, Flight NEU[]);
void Inquire(Passenger wyl, Flight NEU[]);
void Rank(Passenger wyl, Flight NEU[]);
void Count(Passenger wyl, Flight NEU[]);
void Ad_regulation(Administrator NEUer[], Flight NEU[]);
void SystemMaintenance(Administrator NEUer[], Flight NEU[]);
void displayMenu();



