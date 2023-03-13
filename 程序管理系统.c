#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
// 要求：本程序用于管理个人通信信息
// 功能要求实现：添加、删除、修改、显示联系人基本信息（姓名、职务、职称、手机、Email等）
// 分类查找（可以实现任何属性内容的查找；）、排序（按姓名排序并输出各记录信息）

// 职务：总经理 经理 主任
// 职称：正高级 副高级 中级 助理 技术员

typedef struct Data // 个人信息
{
    char name[20];
    char post[50];
    char post_title[50];
    char tel[20];
    char email[30];
} Data;

typedef struct List // 通讯录列表
{
    Data list[MAXSIZE];
    int length;
} List;

void menu()
{
    printf("--------------------\n");
    printf("1->添加联系人\n");
    printf("2->删除联系人\n");
    printf("3->修改联系人\n");
    printf("4->分类查找联系人\n");
    printf("5->按姓名排序并输出\n");
    printf("0->退出\n");
    printf("--------------------\n");
}

void Add(List *L) // 添加联系人
{
    Data d;
    if (L->length == MAXSIZE)
    {
        printf("通讯录已满\n");
        printf("\n");
        return;
    }
    printf("请输入姓名：");
    fflush(stdin);
    gets(d.name);
    for (int i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, d.name) == 0)
        {
            printf("已经有此联系人信息\n");
            printf("\n");
            return;
        }
    }
    printf("请输入职务：");
    gets(d.post);
    printf("请输入职称：");
    gets(d.post_title);
    printf("请输入手机：");
    gets(d.tel);
    printf("请输入Email:");
    gets(d.email);
    L->list[L->length++] = d;
    printf("添加成功！\n");
    printf("\n");
    system("pause");
    system("cls");
    return;
}

void Del(List *L) // 删除联系人
{
    int Find_name(List * L, char name[]);
    if (L->length == 0)
    {
        printf("通讯录已空，无法删除！\n");
        printf("\n");
        return;
    }
    char name[20];
    printf("请输入要删除联系人的名字：\n");
    scanf("%s", &name);
    int i = 0;
    int temp = 0;
    int pos;
    for (i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, name) == 0)
        {
            printf("删除的联系人信息：\n姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
            printf("是否删除该联系人？(1.删除 0.取消)\n");
            int num;
            scanf("%d", &num);
            if (num == 1)
            {
                pos = i;
                for (i = pos; i < L->length - 1; i++)
                {
                    L->list[i] = L->list[i + 1];
                }
                L->length--;
                printf("删除成功!\n");
                printf("\n");
            }
            else
            {
                printf("取消成功！\n");
                system("pause");
                system("cls");
                return;
            }
            temp = 1;
        }
    }
    if (temp == 0)
    {
        printf("查无此人\n");
        printf("\n");
    }
    system("pause");
    system("cls");
    return;
}

int Find_name(List *L, char name[]) // 查找联系人（按名字）
{
    for (int i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, name))
        {
            return i; // 返回查到的联系人的序号
        }
    }
    return -1; // 没找到返回-1
}

void revise(List *L) // 修改某个联系人
{
    if (L->length == 0)
    {
        printf("通讯录为空!\n");
        printf("\n");
        return;
    }
    char name[20];
    printf("请输入需要修改的联系人的名字：\n");
    scanf("%s", name);
    if (Find_name(L, name) == -1)
    {
        printf("没有找到此联系人!\n");
        printf("\n");
        return;
    }
    else
    {
        int x;
        do
        {
            int pos;
            for (int i = 0; i < L->length; i++)
            {
                if (strcmp(L->list[i].name, name) == 0)
                {
                    pos = i;
                    printf("被修改联系人信息：\n");
                    printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                }
            }
            printf("请输入你想修改此联系人的信息:\n");
            printf("1:姓名\n2:职务\n3:职称\n4:手机\n5:email\n0:退出\n");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                printf("请输入修改后的姓名:\n");
                scanf("%s", L->list[pos].name);
                printf("修改成功！\n");
                break;
            case 2:
                printf("请输入修改后的职务:\n");
                scanf("%s", L->list[pos].post);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入修改后的职称:\n");
                scanf("%s", &(L->list[pos].post_title));
                printf("修改成功！\n");
                break;
            case 4:
                printf("请输入修改后的手机:\n");
                scanf("%s", L->list[pos].tel);
                printf("修改成功！\n");
                break;
            case 5:
                printf("请输入修改后的email:\n");
                scanf("%s", L->list[pos].email);
                printf("修改成功！\n");
                break;
            case 0:
                printf("退出修改\n");
                printf("\n");
                break;
            default:
                printf("数字错误！\n");
                printf("\n");
                break;
            }
        } while (x);
    }
    system("pause");
    system("cls");
    return;
}

void Find(List *L) // 分类查找
{
    int x;
    if (L->length == 0)
    {
        printf("通讯录为空\n");
    }
    printf("按什么类型查找\n");
    printf("-------------\n");
    printf("1->姓名\n");
    printf("2->职务\n");
    printf("3->职称\n");
    printf("4->手机\n");
    printf("5->email\n");
    printf("输入其他数字退出\n");
    printf("-------------\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    {
        char name[20] = {0};
        printf("输入要查找联系人的姓名：\n");
        scanf("%s", &name);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].name, name) == 0)
            {
                printf("该联系人信息：\n");
                printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("没有找到联系人\n");
            printf("\n");
        }
        break;
    }
    case 2:
    {
        char post[50] = {0};
        printf("输入要查找联系人的职务：\n");
        scanf("%s", &post);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].post, post) == 0)
            {
                printf("该联系人信息：\n");
                printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("没有找到联系人\n");
            printf("\n");
        }
        break;
    }
    case 3:
    {
        char post_title[50] = {0};
        printf("输入要查找联系人的职称：\n");
        scanf("%s", &post_title);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].post_title, post_title) == 0)
            {
                printf("该联系人信息：\n");
                printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("没有找到联系人\n");
            printf("\n");
        }
        break;
    }
    case 4:
    {
        char tel[11] = {0};
        printf("输入要查找联系人的手机：\n");
        scanf("%s", &tel);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].tel, tel) == 0)
            {
                printf("该联系人信息：\n");
                printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("没有找到联系人\n");
            printf("\n");
        }
        break;
    }
    case 5:
    {
        char email[30] = {0};
        printf("输入要查找联系人的email: \n");
        scanf("%s", &email);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].email, email) == 0)
            {
                printf("该联系人信息：\n");
                printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("没有找到联系人\n");
            printf("\n");
        }
        break;
    }
    default:
        break;
    }
    system("pause");
    system("cls");
    return;
}
void Sort(List *L) // 排序输出(按姓名首字母排序)
{
    int i, j;
    Data temp;
    for (i = 0; i < L->length; i++)
    {
        temp = L->list[i];
        for (j = i + 1; j < L->length; j++)
        {
            if (strcmp(L->list[i].name, L->list[j].name) > 0)
            {
                temp = L->list[i];
                L->list[i] = L->list[j];
                L->list[j] = temp;
            }
        }
    }
    printf("联系人列表：\n");
    for (i = 0; i < L->length; i++)
        printf("姓名:%s\t职务:%s\t职称:%s\t手机:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
    system("pause");
    system("cls");
    return;
}
int main()
{
    List L;
    int x;
    L.length = 0;
    while (1)
    {
        menu();
        printf("输入操作：\n");
        scanf("%d", &x);
        if (x <= 0 || x >= 10)
        {
            menu();
            printf("错误！请重新输入操作：\n");
            printf("\n");
        }
        switch (x)
        {
        case 1:
            Add(&L);
            break;
        case 2:
            Del(&L);
            break;
        case 3:
            revise(&L);
            break;
        case 4:
            Find(&L);
            break;
        case 5:
            Sort(&L);
            break;
        case 0:
            return 0;
            system("pause");
            system("cls");
        default:
            break;
        }
    }
    return 0;
}