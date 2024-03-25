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
    bool VIP;//是否为VIP
    char name[20];
    char ID_card[19];//18位身份证
    char contact_information[12];//联系方式
    char Password[20];//密码


    char fancy[50];//旅客偏好
    records PersonalLog;//历史记录
}Passenger;  //this is also the basic part
typedef struct //管理员个人信息
{
    char name[20];
    char contact_information[12];//联系方式
    char Password[20];//密码

}Administrator;  //this is also the radical part



enum TicketPrice //座位价格
{
    first_class_price = 2000,   //头等舱价格
    business_class_price = 1000,//商务舱价格
    economy_class_price = 500   //经济舱价格
};

typedef struct
{
    bool booked;          //该座位是否被预定
    enum TicketPrice price;  //该座位等级及价格
    Passenger Infor;  //该座位乘客信息
}seat_information;

typedef struct 
{
    char FlightNumber[20];//航班号
    char departure[20];//起飞地
    char destination[20];//目的地
    char departureTime[20];//起飞时间
    char arrivalTime[20];//到达时间

    bool sunny_slope;//是否向阳


    seat_information seats[MAX_ROWS][MAX_COLS];//该架次航班座位信息  一排6位 共40排
    //暂定四排头等舱 八排商务舱 剩余为经济舱 
    int availableSeats;//剩余可用座位
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




