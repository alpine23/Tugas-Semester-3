#include <iostream>
#include <conio.h>
using namespace std;

struct typeStack
{
    int info;
    // pointer
    typeStack *prev, *next;
};

typeStack *top, *bottom, *hapus, *newNode, *bantu;

void createStack();
int countStack();
void push(int IB);
void pop();
void printStack();

int main()
{
    createStack();
    int pilih, num;
    char kembali = 'y';
    do
    {
        system("cls");
        cout << "Menu Stack : " << endl;
        cout << "===================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Lihat" << endl;
        cout << "4. Exit" << endl;
        cout << "[ TOP ] = " << countStack() << endl;
        cout << "\nPilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Input Number : ";
            cin >> num;
            push(num);
            cout << "DATA ADDED!";
            getch();
            break;

        case 2:
            pop();
            cout << "STACK TOP DELETED!" << endl;
            getch();
            break;

        case 3:
            printStack();
            getch();
            break;

        case 4:
            exit(0);
            break;

        default:
            break;
        }
    } while (kembali == 'y');

    return 0;
}

void createStack()
{
    top = NULL;
    bottom = NULL;
}

int countStack()
{
    if (top == NULL)
        return 0;
    else
    {
        int banyak = 0;
        bantu = top;
        while (bantu != NULL)
        {
            bantu = bantu->prev;
            ++banyak;
        }
        return banyak;
    }
}

void push(int IB)
{
    newNode = new typeStack();
    newNode->info = IB;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (countStack() == 0)
    {
        top = newNode;
        bottom = newNode;
    }
    else
    {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }
}

void pop()
{
    if (countStack() == 0)
        cout << "STACK EMPTY!";
    else
    {
        hapus = top;
        top = top->prev;
        delete hapus;
        top->next = NULL;
    }
}

void printStack()
{
    bantu = top;

    cout << "          Stack : ";
    cout << "\n===========================" << endl;
    while (bantu != NULL)
    {
        cout << "          [ " << bantu->info << " ]     " << endl;
        bantu = bantu->prev;
    }
    cout << "===========================" << endl;
}
