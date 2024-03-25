#include<stdio.h>
#include<stdbool.h>

#include"statement.h"


#define FLIGHT 10

int main(void)
{
	
}

Flight NEU[20];//NEU���յĶ�ʮ������
Administrator NEUer[5];//�������Ա
Passenger FBI[500];//��ٸ��˿�


void initializeAirplane(int FlightNumber)// ��ʼ���ɻ���λ״̬
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            NEU[FlightNumber].seats[i][j].booked = false;
        }
    }
}

void displayAirplaneStatus(int FlightNumber) // ��ʾ�ɻ���λ״̬
{
    printf("Airplane Seating Arrangement:\n");
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (NEU[FlightNumber].seats[i][j].booked)
            {
                printf("[X] "); // X��ʾ��Ԥ��
            }
            else
            {
                printf("[ ] "); // �ո��ʾ��Ԥ��
            }
        }
        printf("\n");
    }
}





void bookSeat(int row, int col, int FlightNumber) // Ԥ����λ
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

void cancelSeat(int row, int col, int FlightNumber) // ȡ��Ԥ����λ
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


//��������˺�����Ϣ�������Ϣ 
// ��Ϊ��ĿҪ�������������Ϣ��ѯ���޸ĵ����� ���ܶ�д�� �ò���û��
//���Ӧ�ö�Ҫ���Ͻ��ṹ���е����ݶ�д���ļ��� ��������� ֮���ټ��� �Ȱ�������д�ĺ���д��
void Register(Passenger wyl, Flight NEU[])//����ע����Ϣ ֱ�Ӱѽṹ��������������
{
    //ע�ᣬ¼���Լ�����Ϣ��������������ϵ�绰�ȣ�
    //���ݸ�ʽ�ο�Passenger���ֽ������
}
void ReRegister(Passenger wyl, Flight NEU[])//�޸ĸ�����Ϣ ֱ�Ӱѽṹ��������������
{
    //���Լ�����Ϣ�����޸�
}
void Inquire(Passenger wyl, Flight NEU[])//��ѯ��Ԥ������
{
    //�Ը�����Ϣ����������Ԥ����Ϣ�����в�ѯ�������򵥡���ϡ�ģ����ѯ��
    // �����ѯĳ��ĳ�������Ƿ��п�����λ����ѯ�Լ�������Ԥ�������
}
void Rank(Passenger wyl, Flight NEU[])//��Ϣ����
{
    //�Ը�����Ϣ����������Ԥ����Ϣ���������򣬰�������һ���ԡ�������������ȣ�
    // �����ܶԲ�ѯ������ж�����������Բ�ѯ�����ĺ��ఴ�ռ۸������������

}
void Count(Passenger wyl, Flight NEU[])//��Ϣͳ��
{
    //�Ը�����Ϣ����������Ԥ����Ϣ������ͳ�ƣ�
    // ��������һ���ԡ���������ͳ�ơ�Ԥ��ͳ�ơ�������ͳ�Ƶ�
    // ������ͳ���Լ��ܵĳ˻��������Լ�ÿ��ĳ˻����ѵȣ�
}


void Ad_regulation(Administrator NEUer[],Flight NEU[])//����Ա�Ժ�����Ϣ�Ĺ���
{
    //�Ժ��ߡ����ࡢ��λ�ȼ�����Ϣ���й����������ӡ��޸ġ�ɾ���ȡ�
}
void SystemMaintenance(Administrator NEUer[], Flight NEU[])//ά�� ����Ӧ��Ҫ�õ��ļ��Ķ�д���� �һ�û����� ����
{
    //���Լ����������ά�������ݱ��ݡ����ݻָ�
}
