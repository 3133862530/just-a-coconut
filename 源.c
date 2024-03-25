#include<stdio.h>
#include<stdbool.h>

#include"statement.h"


Flight NEU[20];//NEU航空的二十个航班
Administrator NEUer[5];//五个管理员
Passenger FBI[500];//五百个乘客
int main(void)
{
	
}



void initializeAirplane(int FlightNumber)// 初始化飞机座位状态
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            NEU[FlightNumber].seats[i][j].booked = false;
        }
    }
}

void displayAirplaneStatus(int FlightNumber) // 显示飞机座位状态
{
    printf("Airplane Seating Arrangement:\n");
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (NEU[FlightNumber].seats[i][j].booked)
            {
                printf("[X] "); // X表示已预定
            }
            else
            {
                printf("[ ] "); // 空格表示可预定
            }
        }
        printf("\n");
    }
}





void bookSeat(int row, int col, int FlightNumber) // 预订座位
{
    if (!NEU[FlightNumber].seats[row][col].booked)
    {
        NEU[FlightNumber].seats[row][col].booked = true;
        printf("Seat at Row %d, Column %d booked successfully.\n", row, col);
    }
    else
    {
        printf("Seat at Row %d, Column %d is already booked.\n", row, col);
    }
}

void cancelSeat(int row, int col, int FlightNumber) // 取消预订座位
{
    if (NEU[FlightNumber].seats[row][col].booked)
    {
        NEU[FlightNumber].seats[row][col].booked = false;
        printf("Seat at Row %d, Column %d canceled successfully.\n", row, col);
    }
    else
    {
        printf("Seat at Row %d, Column %d is not booked.\n", row, col);
    }
}


//这里调用了航班信息与个人信息 
// 因为题目要求包含对两种信息查询与修改的需求 功能都写上 用不上没事
//最后应该都要加上将结构体中的数据读写到文件中 这个还不会 之后再加上 先把现在能写的函数写好
void Register(Passenger wyl, Flight NEU[])//初次注册信息 直接把结构体拉进来加数据
{
    //注册，录入自己的信息，包括姓名、联系电话等；
    //内容格式参考Passenger部分进行填充
}
void ReRegister(Passenger wyl, Flight NEU[])//修改个人信息 直接把结构体拉进来改数据
{
    //对自己的信息进行修改
}
void Inquire(Passenger wyl, Flight NEU[])//查询及预定航班
{
    //对各种信息（包括航班预订信息）进行查询，包括简单、组合、模糊查询，
    // 例如查询某天某个航班是否有空余座位、查询自己的所有预订情况等
}
void Rank(Passenger wyl, Flight NEU[])//信息排序
{
    //对各种信息（包括航班预订信息）进行排序，包括按单一属性、按多属性排序等，
    // 尽可能对查询结果进行多种排序（例如对查询出来的航班按照价格进行升序排序）

}
void Count(Passenger wyl, Flight NEU[])//信息统计
{
    //对各种信息（包括航班预订信息）进行统计，
    // 包括按单一属性、按多属性统计、预设统计、按条件统计等
    // （例如统计自己总的乘机次数、自己每年的乘机花费等）
}


void Ad_regulation(Administrator NEUer[],Flight NEU[])//管理员对航班信息的管理
{
    //对航线、航班、仓位等级等信息进行管理，包括增加、修改、删除等。
}
void SystemMaintenance(Administrator NEUer[], Flight NEU[])//维护 这里应该要用到文件的读写部分 我还没理清楚 不急
{
    //对自己的密码进行维护、数据备份、数据恢复
}
void displayMenu()
{
    //菜单暂定
}
