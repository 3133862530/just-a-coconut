#pragma once
#define MAX_COLS 6
#define MAX_ROWS 40

typedef struct
{
    int Number_of_flights;//���д���
    float total_cost;//�ۼƻ���
    float total_mileage;//�����
}records;//��ʷ��¼

typedef struct //�˿͸�����Ϣ
{
    bool VIP;//�Ƿ�ΪVIP
    char name[20];
    char ID_card[19];//18λ���֤
    char contact_information[12];//��ϵ��ʽ
    char Password[20];//����


    char fancy[50];//�ÿ�ƫ��
    records PersonalLog;//��ʷ��¼
}Passenger;  //this is also the basic part
typedef struct //����Ա������Ϣ
{
    char name[20];
    char contact_information[12];//��ϵ��ʽ
    char Password[20];//����

}Administrator;  //this is also the radical part



enum TicketPrice //��λ�۸�
{
    first_class_price = 2000,   //ͷ�Ȳռ۸�
    business_class_price = 1000,//����ռ۸�
    economy_class_price = 500   //���òռ۸�
};

typedef struct
{
    bool booked;          //����λ�Ƿ�Ԥ��
    enum TicketPrice price;  //����λ�ȼ����۸�
    Passenger Infor;  //����λ�˿���Ϣ
}seat_information;

typedef struct 
{
    char FlightNumber[20];//�����
    char departure[20];//��ɵ�
    char destination[20];//Ŀ�ĵ�
    char departureTime[20];//���ʱ��
    char arrivalTime[20];//����ʱ��

    bool sunny_slope;//�Ƿ�����


    seat_information seats[MAX_ROWS][MAX_COLS];//�üܴκ�����λ��Ϣ  һ��6λ ��40��
    //�ݶ�����ͷ�Ȳ� ��������� ʣ��Ϊ���ò� 
    int availableSeats;//ʣ�������λ
}Flight;    //������Ϣ     this is the basic part

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




