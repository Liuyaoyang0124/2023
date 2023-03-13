#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
// Ҫ�󣺱��������ڹ������ͨ����Ϣ
// ����Ҫ��ʵ�֣���ӡ�ɾ�����޸ġ���ʾ��ϵ�˻�����Ϣ��������ְ��ְ�ơ��ֻ���Email�ȣ�
// ������ң�����ʵ���κ��������ݵĲ��ң��������򣨰����������������¼��Ϣ��

// ְ���ܾ��� ���� ����
// ְ�ƣ����߼� ���߼� �м� ���� ����Ա

typedef struct Data // ������Ϣ
{
    char name[20];
    char post[50];
    char post_title[50];
    char tel[20];
    char email[30];
} Data;

typedef struct List // ͨѶ¼�б�
{
    Data list[MAXSIZE];
    int length;
} List;

void menu()
{
    printf("--------------------\n");
    printf("1->�����ϵ��\n");
    printf("2->ɾ����ϵ��\n");
    printf("3->�޸���ϵ��\n");
    printf("4->���������ϵ��\n");
    printf("5->�������������\n");
    printf("0->�˳�\n");
    printf("--------------------\n");
}

void Add(List *L) // �����ϵ��
{
    Data d;
    if (L->length == MAXSIZE)
    {
        printf("ͨѶ¼����\n");
        printf("\n");
        return;
    }
    printf("������������");
    fflush(stdin);
    gets(d.name);
    for (int i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, d.name) == 0)
        {
            printf("�Ѿ��д���ϵ����Ϣ\n");
            printf("\n");
            return;
        }
    }
    printf("������ְ��");
    gets(d.post);
    printf("������ְ�ƣ�");
    gets(d.post_title);
    printf("�������ֻ���");
    gets(d.tel);
    printf("������Email:");
    gets(d.email);
    L->list[L->length++] = d;
    printf("��ӳɹ���\n");
    printf("\n");
    system("pause");
    system("cls");
    return;
}

void Del(List *L) // ɾ����ϵ��
{
    int Find_name(List * L, char name[]);
    if (L->length == 0)
    {
        printf("ͨѶ¼�ѿգ��޷�ɾ����\n");
        printf("\n");
        return;
    }
    char name[20];
    printf("������Ҫɾ����ϵ�˵����֣�\n");
    scanf("%s", &name);
    int i = 0;
    int temp = 0;
    int pos;
    for (i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, name) == 0)
        {
            printf("ɾ������ϵ����Ϣ��\n����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
            printf("�Ƿ�ɾ������ϵ�ˣ�(1.ɾ�� 0.ȡ��)\n");
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
                printf("ɾ���ɹ�!\n");
                printf("\n");
            }
            else
            {
                printf("ȡ���ɹ���\n");
                system("pause");
                system("cls");
                return;
            }
            temp = 1;
        }
    }
    if (temp == 0)
    {
        printf("���޴���\n");
        printf("\n");
    }
    system("pause");
    system("cls");
    return;
}

int Find_name(List *L, char name[]) // ������ϵ�ˣ������֣�
{
    for (int i = 0; i < L->length; i++)
    {
        if (strcmp(L->list[i].name, name))
        {
            return i; // ���ز鵽����ϵ�˵����
        }
    }
    return -1; // û�ҵ�����-1
}

void revise(List *L) // �޸�ĳ����ϵ��
{
    if (L->length == 0)
    {
        printf("ͨѶ¼Ϊ��!\n");
        printf("\n");
        return;
    }
    char name[20];
    printf("��������Ҫ�޸ĵ���ϵ�˵����֣�\n");
    scanf("%s", name);
    if (Find_name(L, name) == -1)
    {
        printf("û���ҵ�����ϵ��!\n");
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
                    printf("���޸���ϵ����Ϣ��\n");
                    printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                }
            }
            printf("�����������޸Ĵ���ϵ�˵���Ϣ:\n");
            printf("1:����\n2:ְ��\n3:ְ��\n4:�ֻ�\n5:email\n0:�˳�\n");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                printf("�������޸ĺ������:\n");
                scanf("%s", L->list[pos].name);
                printf("�޸ĳɹ���\n");
                break;
            case 2:
                printf("�������޸ĺ��ְ��:\n");
                scanf("%s", L->list[pos].post);
                printf("�޸ĳɹ���\n");
                break;
            case 3:
                printf("�������޸ĺ��ְ��:\n");
                scanf("%s", &(L->list[pos].post_title));
                printf("�޸ĳɹ���\n");
                break;
            case 4:
                printf("�������޸ĺ���ֻ�:\n");
                scanf("%s", L->list[pos].tel);
                printf("�޸ĳɹ���\n");
                break;
            case 5:
                printf("�������޸ĺ��email:\n");
                scanf("%s", L->list[pos].email);
                printf("�޸ĳɹ���\n");
                break;
            case 0:
                printf("�˳��޸�\n");
                printf("\n");
                break;
            default:
                printf("���ִ���\n");
                printf("\n");
                break;
            }
        } while (x);
    }
    system("pause");
    system("cls");
    return;
}

void Find(List *L) // �������
{
    int x;
    if (L->length == 0)
    {
        printf("ͨѶ¼Ϊ��\n");
    }
    printf("��ʲô���Ͳ���\n");
    printf("-------------\n");
    printf("1->����\n");
    printf("2->ְ��\n");
    printf("3->ְ��\n");
    printf("4->�ֻ�\n");
    printf("5->email\n");
    printf("�������������˳�\n");
    printf("-------------\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
    {
        char name[20] = {0};
        printf("����Ҫ������ϵ�˵�������\n");
        scanf("%s", &name);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].name, name) == 0)
            {
                printf("����ϵ����Ϣ��\n");
                printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("û���ҵ���ϵ��\n");
            printf("\n");
        }
        break;
    }
    case 2:
    {
        char post[50] = {0};
        printf("����Ҫ������ϵ�˵�ְ��\n");
        scanf("%s", &post);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].post, post) == 0)
            {
                printf("����ϵ����Ϣ��\n");
                printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("û���ҵ���ϵ��\n");
            printf("\n");
        }
        break;
    }
    case 3:
    {
        char post_title[50] = {0};
        printf("����Ҫ������ϵ�˵�ְ�ƣ�\n");
        scanf("%s", &post_title);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].post_title, post_title) == 0)
            {
                printf("����ϵ����Ϣ��\n");
                printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("û���ҵ���ϵ��\n");
            printf("\n");
        }
        break;
    }
    case 4:
    {
        char tel[11] = {0};
        printf("����Ҫ������ϵ�˵��ֻ���\n");
        scanf("%s", &tel);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].tel, tel) == 0)
            {
                printf("����ϵ����Ϣ��\n");
                printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("û���ҵ���ϵ��\n");
            printf("\n");
        }
        break;
    }
    case 5:
    {
        char email[30] = {0};
        printf("����Ҫ������ϵ�˵�email: \n");
        scanf("%s", &email);
        int t = 0;
        for (int i = 0; i < L->length; i++)
        {
            if (strcmp(L->list[i].email, email) == 0)
            {
                printf("����ϵ����Ϣ��\n");
                printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
                t = 1;
            }
        }
        if (t == 0)
        {
            printf("û���ҵ���ϵ��\n");
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
void Sort(List *L) // �������(����������ĸ����)
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
    printf("��ϵ���б�\n");
    for (i = 0; i < L->length; i++)
        printf("����:%s\tְ��:%s\tְ��:%s\t�ֻ�:%s\temail:%s\n", L->list[i].name, L->list[i].post, L->list[i].post_title, L->list[i].tel, L->list[i].email);
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
        printf("���������\n");
        scanf("%d", &x);
        if (x <= 0 || x >= 10)
        {
            menu();
            printf("�������������������\n");
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