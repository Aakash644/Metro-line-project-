#include <iostream>
#include <windows.h>
using namespace std;
struct node
{
    int data;
    int pos;
    struct node *next;
};
struct node *createnode(int index, int pos)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = index;
    ptr->pos = pos;
    return ptr;
} 
int getdistance(struct node *head, int index1, int index2);
int getprice(struct node *head, int index1, int index2)
{
  
    int dis=getdistance(head,index1,index2);
    int price ;
    if (dis>=0 &&dis <= 5)
    {
        price = 30;
        return price;
    }
    else if (dis >5 && dis <= 10)
    {
        price = 50;
        return price;
    }
    else if (dis >10 && dis <=15)
    {
        price = 60;
        return price;
    }
    else if (dis >15 && dis <=25)
    {
        price = 70;
        return price;
    }
    return price;
}
int getdistance(struct node *head, int index1, int index2)
{
    struct node *p = head;
    struct node *q = head;
    int i = 1;
    while (i != index1)
    {
        p = p->next;
        i++;
    }
    int j = 1;
    while (j != index2)
    {
        q = q->next;
        j++;
    }
    int dis = p->pos - q->pos;
    if (dis < 0)
    {
        dis = 0 - (dis);
    }
    return dis;
}
void printlist()
{
    cout << "1.Jahangirpuri" << endl;
    cout << "2.Model_Town" << endl;
    cout << "3.Gtb_Nagar" << endl;
    cout << "4.Vishwavidyalaya" << endl;
    cout << "5.Vidhan sabha" << endl;
    cout << "6.Civil lines" << endl;
    cout << "7.Chandni chowk" << endl;
    cout << "8.New Delhi" << endl;
    cout << "9.INA" << endl;
    cout << "10.AIIMS" << endl;
    cout << "11.Chhattarpur" << endl;
    cout << "12.Huda City Center" << endl;
}
int main()
{  
    system("color f0");
    struct node *jahangirpuri = createnode(0, 0);
    struct node *model_town = createnode(1, 1);
    struct node *gtb_nagar = createnode(2, 3);
    struct node *Vishwavidyalaya = createnode(3, 5);
    struct node *vidhan_sabha = createnode(4, 7);
    struct node *civil_lines = createnode(5, 8);
    struct node *chandni_chowk = createnode(6, 9);
    struct node *new_delhi = createnode(7, 12);
    struct node *ina = createnode(8, 14);
    struct node *AIIMS = createnode(9, 17);
    struct node *chhattarpur = createnode(10, 19);
    struct node *huda_city_center = createnode(11, 23);

    // connecting the lines
    jahangirpuri->next = model_town;//1
    model_town->next = gtb_nagar;//2
    gtb_nagar->next = Vishwavidyalaya;//3
    Vishwavidyalaya->next = vidhan_sabha;//4
    vidhan_sabha->next = civil_lines;//5
    civil_lines->next = chandni_chowk;//6
    chandni_chowk->next = new_delhi;//7
    new_delhi->next = ina;//8
    ina->next = AIIMS;//9
    AIIMS->next = chhattarpur;//10
    chhattarpur->next = huda_city_center;//11
    huda_city_center->next = NULL;//12

    // interactive program for user
    while (1)
    {
        system("cls");
        cout << "**Welcome to Delhi Metro**" << endl;
        cout << "Choose one of the options from below:" << endl;

        cout << "1.List of Metro stations" << endl;
        cout << "2.Distance between two metro stations(Kms) " << endl;
        cout << "3.Ticket Price(Rs) " << endl;
        cout << "4.Exit " << endl;

        int choice, index1, index2;
        cin >> choice;
        switch (choice)
        {
        case 1:
            printlist();
            Sleep(10000);
            break;
        case 2:
            printlist();
            cout << "Enter the index of first station:" << endl;
            cin >> index1;
            cout << "Enter the index of second station:" << endl;
            cin >> index2;

            cout << "Distance is " << getdistance(jahangirpuri, index1, index2) << " Km" << endl;
            Sleep(5000);

            break;
        case 3:
            printlist();
            cout << "Enter the index of first station:" << endl;
            cin >> index1;
            cout << "Enter the index of second station:" << endl;
            cin >> index2;
            cout << "Ticket price is RS " << getprice(jahangirpuri, index1, index2) << endl;
            Sleep(5000);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid input" << endl;
        }
    }

    return 0;
}