#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Staff
{
    int number;
    char name[20];
    char department[20];
    char sex;
    int age;
    char position[20];
    char password[20];
    time_t clockTime;
    int clock;
    int queqin;
    struct Staff* next;
};
struct student{
    int n;
    char name[20];
    char department[20];
    char sex;
    int age;
    char position[20];
    char password[20];
    int clock;
    int queqin;
};
int del[10];

struct Staff* creatNode(int n,char name[],char department[],char sex,int age,char position[],char password[])
{
    struct Staff* newNode = (struct Staff*)malloc(sizeof(struct Staff));
    newNode->number = n;
    strcpy(newNode->name,name);
    strcpy(newNode->department,department);
    newNode->sex = sex;
    newNode->age = age;
    strcpy(newNode->position,position);
    strcpy(newNode->password,password);
    newNode->clock = 0;
    newNode->queqin = 0;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Staff** head,int n,char name[],char department[],char sex,int age,char position[],char password[])
{
    struct Staff* newNode = creatNode(n,name,department,sex,age,position,password);
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Staff* temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reviseNode(struct Staff* head,int n,char name[],char department[],char sex,int age,char position[],char password[])
{
    struct Staff* newNode = head;
    while(newNode->number != n)
    {
        newNode = newNode->next;
    }
    strcpy(newNode->name,name);
    strcpy(newNode->department,department);
    newNode->sex = sex;
    newNode->age = age;
    strcpy(newNode->position,position);
    strcpy(newNode->password,password);
    newNode->clock = 0;
    newNode->queqin = 0;
}

void deleteNode(struct Staff** head,int n)
{
    struct Staff* temp = *head;
    struct Staff* prev = NULL;
    if(temp !=NULL&&temp->number==n)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->number!=n)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void bubbleSort(int arr[],int n)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < n - 1; i++)
    {
        for(j = 0;j< n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int ir = 0;
int j = 0;
struct Employee
{
    int number;
    char name[20];
    time_t clockIn;
}person[20];
int compare(const void *a, const void *b) 
{
    struct Employee *emp1 = (struct Employee *)a;
    struct Employee *emp2 = (struct Employee *)b;
    return difftime(emp1->clockIn, emp2->clockIn);
}
void timeLine(struct Employee test[],int n)
{
    int r = 0;
    for(r = 0;r < n; r++)
    {
        printf("%d %s %s\n",test[r].number,test[r].name,ctime(&test[r].clockIn));
    }
    printf("Press any key to continue");
    getchar();
}

struct company
{
    int count;
    int cacul;
    char depart[20];
};
void chushihua(struct company com[])
{
    int w = 0;
    for(w = 0;w<5;w++)
    {
        com[w].count = 0;
    }
}
char data[20][20];
int y = 0;
void findClock(struct Staff* head,int arr[],int m,struct student stu[],struct company com[])
{
    int t = 0;
    y = 0;
    int ai = 0;
    int oi = 0;
    bubbleSort(arr,m);
    while(head != NULL)
    {
        int bi = 0;
        if((ai+1)==del[oi])
        {
            ai++;
            oi++;
        }
        if(head->number !=  arr[t])
        {
            strcpy(data[y],head->name);
            y++;
            head->queqin++;
            stu[ai].queqin++;
            while(strcmp(head->department,com[bi].depart)!=0)
            {
                bi++;
            }
            com[bi].cacul++;
        }
        else if(head->number == arr[t])
        {
            stu[ai].clock++;
            t++;
        }
        head = head->next;
        ai++;
    }
}

void sreachClock(struct Staff* head,int arr[],int n,struct company com[])
{
    int t = 0;
    struct Staff* temp;
    while(head != NULL)
    {
        t = 0;
        if(head->number == n)
        {
            printf("%s clock successfully!\n",head->name);
            head->clockTime = time(NULL);
            person[j].number = head->number;
            strcpy(person[j].name,head->name);
            person[j].clockIn = head->clockTime;
            head->clock++;
            while(strcmp(head->department,com[t].depart)!=0)
            {
                t++;
            }
            com[t].count++;
            arr[ir] = n;
            ir++;
            j++;
            return;
        }
        head = head->next;
    }
    if(head == NULL)
    {
        printf("Please input the right number!\n");
        return;
    }    
}
void prnoclock()
{
    int t = 0;
    printf("There are some people who not clock:\n");
    for(t = 0;t < y; t++)
    {
        printf("%s\n",data[t]);
    }
    printf("%d people in all.\n",y);
    printf("Press any key to continue");
    getchar();
}

void sumCompany(struct company com[])
{
    int x = 0;
    for(x = 0;x < 5; x++)
    {
        printf("%s:%d\n",com[x].depart,com[x].count);
    }
    printf("Press any key to continue");
    getchar();
}
void sortNoclock(int deal,struct student stu[])
{
    int g = 0;
    int c = 0;
    int f = 0;
    int z = 0;
    struct student temp;
    for(g = 0;g < deal-1;g++)
    {
        for(c = 0;c < deal-g-1;c++)
        {
            if(stu[c].queqin<stu[c+1].queqin)
            {
                temp = stu[c];
                stu[c] = stu[c+1];
                stu[c+1] = temp;
            }    
        }
    }
    printf("Rank employees by number of absences:\n");
    for(c = 0;c<deal;c++)
    {
        if(stu[c].n==del[z])
        {
            z++;
            continue;
        }
        printf("%d %s %d\n",stu[c].n,stu[c].name,stu[c].queqin);
    }
}
void findcompany(struct company com[])
{
    int l = 0;
    struct company temp = com[0];
    for(l = 0;l < 5;l++)
    {
        if(temp.cacul<com[l].cacul)
        {
            temp = com[l];
        }
    }
    printf("The department with the highest number of absences:\n");
    printf("%s\n",temp.depart);
}

void printList(struct Staff* head)
{
    while(head != NULL)
    {
        printf("%d %s %s ",head->number,head->name,head->department);
        printf("%c %d %s ",head->sex,head->age,head->position);
        printf("%d %d %s\n",head->clock,head->queqin,ctime(&head->clockTime));
        head = head->next;
    }
}

int main()
{
    struct Staff* head = NULL;
    struct company com[5];
    struct student stu[20];
    int i ;
    int o = 16;
    int n[20];
    int froce = 0;
    char choice;
    char clockuse;
    char mingzi[20];
    char mima[20];
    FILE *fp;
    fp = fopen("staff.txt","rt");
    int u = 0;
    int v = 0;
    int m = 0;
    if(fp == NULL)
    {
        printf("不能打开此文件，按任意键退出\n");
        getchar();
        exit(1);
    }
    while(fscanf(fp,"%d %s %s %c %d %s %s",&stu[u].n,stu[u].name,stu[u].department,&stu[u].sex,&stu[u].age,stu[u].position,stu[u].password)!=EOF)
    {
        stu[u].clock = 0;
        stu[u].queqin = 0;
        insertNode(&head,stu[u].n,stu[u].name,stu[u].department,stu[u].sex,stu[u].age,stu[u].position,stu[u].password);
        u++;
    }
    fclose(fp);
    fp = fopen("gongsi.txt","rt");
    if(fp == NULL)
    {
        printf("不能打开此文件，按任意键退出\n");
        getchar();
        exit(1);
    }
    while(fscanf(fp,"%s",com[v].depart)!=EOF)
    {
        com[v].cacul = 0;
        com[v].count = 0;
        v++;
    }
    fclose(fp);
    printf("# --------------------------------------------------------- #\n");
    printf("* Welcome to sign in Employee Information Management System *\n");
    printf("# --------------------------------------------------------- #\n");
    printf("*                       *1-sign in*                         *\n");
    printf("*                       *2-sign up*                         *\n");
    printf("# --------------------------------------------------------- #\n");
    int sroa;
    printf("Please input your choice\n");
    scanf("%d",&sroa);
    if(sroa==1)
    {
        printf("* name:");
        scanf("%s",mingzi);
        printf("* pswd:");
        scanf("%s",mima);
        struct Staff* jian = head;
        while(jian != NULL)
        {
            if(strcmp(jian->password,mima)==0&&strcmp(jian->name,mingzi)==0)
            {
                printf("Sign in successfully!\n");
                break;
            }
            else 
            {
                jian = jian->next;
            }
            if(jian==NULL)
            {
                printf("Please input right information!\n");
                jian = head;
                scanf("%s %s",mingzi,mima);
            }
        }
    }
    else if(sroa==2)
    {
        printf("Please sign up your information:\n");
        char name[20];
        char department[20];
        char sex;
        int age;
        char position[20];
        char password[20];            
        printf("name:");
        scanf("%s",name);
        printf("department(xupt/xut/sust/cpu/chd):");
        scanf("%s",department);
        getchar();
        printf("sex:");
        scanf("%c",&sex);
        getchar();
        printf("age:");
        scanf("%d",&age);
        printf("position:");
        scanf("%s",position);
        printf("password:");
        scanf("%s",password);
        insertNode(&head,o,name,department,sex,age,position,password);
        stu[u].n = u + 1;
        strcpy(stu[u].name,name);
        strcpy(stu[u].department,department);
        stu[u].sex = sex;
        stu[u].age = age;
        strcpy(stu[u].position,position);
        strcpy(stu[u].password,password);
        stu[u].clock = 0;
        stu[u].queqin = 0;
        u++;
        printf("Sign up successfully!\n");
        printf("Your number is %d.\n",o++);
    }
    printf("#--------------------------------------------------#\n");
    printf("-Welcome to Employee Information Management System!-\n");
    while(1)
    {
        printf("#--------------------------------------------------#\n");
        printf("*                 *1-revise*                       *\n");
        printf("*                 *2-delete*                       *\n");
        printf("*                 *3-clock*                        *\n");
        printf("*                 *other number-exit*              *\n");
        printf("#--------------------------------------------------#\n");
        printf("-Please input your choice.\n");
        scanf("%d",&froce);
                
        if(froce==1)
        {
            printf("Please input your number which you want to revise:\n");
            scanf("%d",&i);
            char newna[20];
            char newde[20];
            char newse;
            int newag;
            char newpo[20];
            char newpa[20];
            printf("Please input your new information:\n");
            printf("name:");
            scanf("%s",newna);
            printf("department(xupt/xut/sust/cpu/chd):");
            scanf("%s",newde);
            getchar();
            printf("sex:");
            scanf("%c",&newse);
            getchar();
            printf("age:");
            scanf("%d",&newag);
            printf("position:");
            scanf("%s",newpo);
            printf("password:");
            scanf("%s",newpa);
            reviseNode(head,i,newna,newde,newse,newag,newpo,newpa);
            strcpy(stu[i-1].name,newna);
            strcpy(stu[i-1].department,newde);
            stu[i-1].sex = newse;
            stu[i-1].age = newag;
            strcpy(stu[i-1].position,newpo);
            strcpy(stu[i-1].password,newpa);
            printf("Revise successfully!\n");
        }
        else if(froce==2)
        { 
            printf("Please input your number which you want to delate:\n");
            scanf("%d",&i);
            del[m] = i;
            deleteNode(&head,i);
            u--;
            m++;
            printf("Delete successfully!\n");
        }
        else if(froce==3)
        {
            ir = 0;
            j = 0;
            for(int k = 0;k < 20; k++)
            {
                n[k] = 0;
            }
            do
            {
                printf("Please input number and Y/N to continue/break\n");
                scanf("%d %c",&i,&clockuse);
                sreachClock(head,n,i,com);
            }while(clockuse == 'Y');
            findClock(head,n,j,stu,com);
            int xuan;
            while(1)
            {
                        
                printf("1-sreach no clock   2-check clock time  3-check department clock  other-exit\n");
                printf("#--------------------------------------------------#\n");
                printf("*             *1-sreach no clock*                  *\n");
                printf("*             *2-check clock time*                 *\n");
                printf("*             *3-check department clock*           *\n");
                printf("*             *other number-exit*                  *\n");
                printf("#--------------------------------------------------#\n");
                printf("-Please input your choice\n");
                scanf("%d",&xuan);
                if(xuan==1)
                {
                    prnoclock();//输出未打卡的员工
                    printf("Press any key to continue");
                    getchar();
                }
                else if(xuan==2)
                {
                    printf("There are some people who have clocked:\n");
                    qsort(person, j, sizeof(struct Employee), compare);
                    timeLine(person,j);//按照打卡时间对员工排序
                    printf("Press any key to continue");
                    getchar();
                }
                else if(xuan==3)
                {
                    sumCompany(com);//输出部门打卡情况
                    printf("Press any key to continue");
                    getchar();
                }
                else if(xuan<1||xuan>3)
                {
                    break;
                }
            }
            chushihua(com);//初始化部门打卡情况
        }
        else if(froce>4||froce<1)
        {
            break;
        }
    }
    while(1)
    {
        printf("#--------------------------------------------------#\n");
        printf("*          *1-rank employees absences*             *\n");
        printf("*          *2-highest absences department*         *\n");
        printf("*          *3-attendance information*              *\n");
        printf("*          *other number-exit*                     *\n");
        printf("#--------------------------------------------------#\n");
        int last;
        printf("Please input your choice\n");
        scanf("%d",&last);
        if(last==1)
        {
            sortNoclock(u,stu);//按照缺勤次数对员工进行排序
        }
        else if(last==2)
        {
            findcompany(com);//输出缺勤次数最多的部门
        }
        else if(last==3)
        {
            printList(head);//输出考勤信息
        }
        else if(last<1||last>3)
        {
            break;
        }
    }
    FILE* file;
    file = fopen("zuizhong.txt","wt");
    if(file == NULL)
    {
        printf("不能打开此文件，按任意键退出。\n");
        getchar();
        exit(1);
    }
    struct Staff* temp;
    while(head != NULL)
    {
        temp = head;
        fprintf(file,"%d %s %s %c %d %s %s %d %d\n",temp->number,temp->name,temp->department,temp->sex,temp->age,temp->position,ctime(&temp->clockTime),temp->clock,temp->queqin);
        head = head->next;
        free(temp);
    }
    fclose(file);
    return 0;
}
