#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void input_passenger(void);
void check_passenger(void);

struct Passenger //乘客个人信息
{
    char name[20];//名字
    char idcard[19];//18位身份证
    char contact_information[12];//联系方式
    char password[20];//密码

    char Registration_number;//注册编号 UID
    char fancy[50];//旅客偏好
    char seat[2][3];//座位 例：13 A
    struct Passenger* next;
};

int appendPassengerNode(struct Passenger** headRef);
void printList(struct Passenger* head);
void freeList(struct Passenger* head);
void writeListToFile(struct Passenger** head, const char* filename);
void readListFromFile(struct Passenger** head, const char* filename);
void writeListToNode(struct Passenger** head, int number);


int main(void)
{
    int i;

	while(1){
		printf("                 @@@@@***************************欢迎使用航班订票系统***************************@@@@@\n");
		printf("                 ###                              1 录 入 乘 客 信 息                             ###\n");
        printf("                 @@@                              2 查 看 航 班 信 息                             @@@\n");
		printf("                 #####!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#####\n");
		printf("请选择: ");
		scanf("%d",&i);
		switch(i){
			case 1:input_passenger();break;
            case 2:check_passenger(); break;
            default:break;
		}
	}




    
    
    
}
void input_passenger()
{
    struct Passenger** WNEUer = NULL;
    int number = appendPassengerNode(&WNEUer);//创建链表
    writeListToNode(&WNEUer, number);//将乘客数据写入链表
    writeListToFile(&WNEUer, "乘客数据.txt");//将链表写入文件
    system("cls");
    //freeList(WNEUer);//释放过程还有问题 暂未解决
}
void check_passenger()
{
    system("cls");
    struct Passenger** RNEUer = NULL;
    readListFromFile(&RNEUer, "乘客数据.txt");
    printList(RNEUer);
    //freeList(RNEUer);
}



void writeListToNode(struct Passenger** head, int number)
{
    struct Passenger* current = *head;
    
    for (int i = 0; i < number; i++)
    {
        scanf("%s", current->name);
        scanf("%s", current->idcard);
        scanf("%s", current->contact_information);
        scanf("%s", current->password);
        scanf("%s", current->Registration_number);
        scanf("%s", current->fancy);
        scanf("%s %s", current->seat[0], current->seat[1]);
        current = current->next;
    }
    
}

int appendPassengerNode(struct Passenger** headRef)//简而言之 
{//输入链表的头指针 和要加入的结构体即可 即可创建n个链表
    printf("输入添加乘客数量：");
    int n;
    scanf("%d", &n);
    for (int i =0; i < n; i++)
    {
        struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
        newPassenger->next = NULL;
        if (*headRef == NULL)//检查传递进来的链表头指针是否为零 若是 
        {
            *headRef = newPassenger;//则建立第一个节点
            continue;//终止
        }
        struct Passenger* current = *headRef;
        while (current->next != NULL)//一路畅通拉下去到头
        {
            current = current->next;
        }
        current->next = newPassenger;//拉到头了 加到尾巴上
    }

    return n;
}

void printList(struct Passenger* head) 
{
    struct Passenger* current = head;
    while (current != NULL) 
    {
        printf("Name: %s\n", current->name);
        printf("ID Card: %s\n", current->idcard);
        printf("Contact Information: %s\n", current->contact_information);
        printf("Password: %s\n", current->password); 
        printf("Fancy: %s\n", current->Registration_number);
        printf("Fancy: %s\n", current->fancy);
        printf("Seat: %s %s\n", current->seat[0], current->seat[1]);
        printf("\n");
        current = current->next;
    }
}
void freeList(struct Passenger* head)
{
    struct Passenger* current = head;
    while (current != NULL) 
    {
        struct Passenger* temp = current;
        current = current->next;
        free(temp->name);
        free(temp->idcard);
        free(temp->contact_information);
        free(temp->password);
        free(temp->Registration_number);
        free(temp->fancy);
        free(temp);
    }
}

void readListFromFile(struct Passenger** head, const char* filename)
{//输入一个头指针 然后把文件数据都读到链表中
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    struct Passenger temp;
    while (fread(&temp, sizeof(struct Passenger), 1, file) != 0)
    {
        struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
        if (newPassenger == NULL)
        {
            printf("Memory allocation failed.\n");
            //fclose(file);
            return;
        }

        *newPassenger = temp;
        newPassenger->next = NULL;
        if (*head == NULL)
        {
            *head = newPassenger;
        }
        else
        {
            struct Passenger* current = *head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newPassenger;
        }
        
    }
    fclose(file);
}

    
void writeListToFile(struct Passenger** head, const char* filename)
{
    //输入一个链表 把链表数据都写到文件中
    FILE* file = fopen(filename, "wb");
    struct Passenger* temp = *head;
    while (temp != NULL)//没写完就一直写
    {
        fwrite(temp, sizeof(struct Passenger), 1, file);
        temp = temp->next;
    }
    fclose(file);
}
