#include <iostream>
#include <malloc.h>
#include <conio.h>
#define True 1
#define False 0
using namespace std;

typedef int typeinfo;
typedef struct typequeue *typeptr;
struct typequeue
{
    typeinfo info;
    typeptr next;
};
typeptr qdepan, qbelakang;
void buatqueue();
int queuekosong();
void enqueue(typeinfo IB);
void dequeue();
void cetakqueue();
int banyak = 0;

int main()
{
    buatqueue();
    int i = 0, pilih, num;
    char kembali = 'y';
    do
    {
        system("cls");
        cout << "Antrian Service Center : " << endl;
        cout << "===================" << endl;
        cout << "1. Ambil antrian" << endl;
        cout << "2. Panggil antrian" << endl;
        cout << "3. Lihat antrian" << endl;
        cout << "4. Exit" << endl;
        cout << "\nPilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            i++;
            enqueue(i);
            cout << "Antrian ke-" << i << endl;
            cout << "Antrian yang belum dipanggil: " << banyak << endl;
            getch();
            break;

        case 2:
            dequeue();
            getch();
            break;

        case 3:
            cetakqueue();
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

void buatqueue()
{
    qdepan = (typequeue *)malloc(sizeof(typequeue));
    qdepan = NULL;
    qbelakang = qdepan;
}

int queuekosong()
{
    if (qdepan == NULL)
        return (True);
    else
        return (False);
}

void enqueue(typeinfo IB)
{
    typeptr NB;
    NB = (typequeue *)malloc(sizeof(typequeue));
    NB->info = IB;
    if (qdepan == NULL)
        qdepan = NB;
    else
        qbelakang->next = NB;
    qbelakang = NB;
    qbelakang->next = NULL;
    banyak++;
}

void dequeue()
{
    typeptr hapus;
    if (queuekosong())
    {
        cout << "Antrian masih kosong !";
    }
    else
    {
        hapus = qdepan;
        qdepan = hapus->next;
        cout << "Antrian yang dipanggil: Antrian ke-" << hapus->info;
        free(hapus);
        banyak--;
    }
}

void cetakqueue()
{
    if (queuekosong())
    {
        cout << "Antrian masih kosong !";
    }
    else
    {
        cout << "Antrian : ";
        typeptr bantu;
        bantu = qdepan;
        do
        {
            cout << " " << bantu->info;

            cout << " ";
            bantu = bantu->next;
        } while (bantu != NULL);
    }
}