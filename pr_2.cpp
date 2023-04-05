#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Record
{
    char name[17];
    char propertyType[12];
    int area;
    unsigned short employCount;
    struct Date date;
};

void myCentr(string s, int wLine) {

    int w = s.length();
    int delta = (wLine - w) / 2;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    }
    else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    }
    else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}

void printWithZero4(int num, int width) {

    if (num < 10) {
        cout << "000" << num;
    }
    if (num > 9 and num < 100) {
        cout.width(width + 1);
        cout << "00" << num;
    }
    if (num > 99 and num < 1000) {
        cout.width(width);
        cout << "0" << num;
    }
    if (num > 999 and num < 10000) {
        cout << num;
    }

}

void Draw(struct Record* records, int size) {
    cout << endl;  cout.width(80); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(79);  cout << left << "|Сельскохозяйственные предприятия"; cout << "|" << endl;
    cout.width(80); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    cout << left << "|Название ";
    cout << left << "|Вид собственности";
    cout << left << "|Площадь земли (га)";
    cout << left << "|Кол. работников";
    cout << left << " |Дата документа";
    cout << "|" << endl;
    cout.width(80); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    for (int i = 0; i < size; i++) {
        cout << left << "|"; cout.width(9); cout << left << records[i].name;
        cout << left << "|"; cout.width(17); cout << left << records[i].propertyType;
        cout << left << "|";  cout << right; printWithZero4(records[i].area, 15);
        //cout.precision(2);
        cout << left << "|"; cout.width(16); cout << right << records[i].employCount;
        cout << left << "|";
        printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
        cout << "|" << endl;
    }
    cout.width(80); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(79);  cout << left << "|Вид собственности: Д - государственная, Ч - частная, К - кооперативная "; cout << "|" << endl;
    cout.width(80); cout.fill('-'); cout << "-" << endl;
}

Date getBiggerDate(struct Date d1, struct Date d2) {
    if (d1.year > d2.year) {
        return d1;
    }
    else if (d1.year < d2.year) {
        return d2;
    }
    if (d1.month > d2.month)
    {
        return d1;
    }
    else if (d1.month < d2.month) {
        return d2;
    }
    if (d1.day > d2.day)
    {
        return d1;
    }
    else {
        return d2;
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int records_size = 13;
    struct Record Table[13];
    Table[0] = { "Заря", "Д", 300, 120, {7,3,2022} };
    Table[1] = { "Росинка", "К", 174, 27, {3,7,2022} };
    Table[2] = { "Петренко", "Ч", 56, 6, {8,8,2021} };
    Table[3] = { "Имя2", "К", 174, 27, {3,7,2022} };
    Table[4] = { "Имя23", "Ч", 76, 6, {8,8,2021} };
    Table[5] = { "Имя3", "К", 17, 27, {3,7,2002} };
    Table[6] = { "Имя25", "Ч", 56, 6, {3,8,2021} };
    Table[7] = { "Имя4", "К", 174, 27, {2,7,2029} };
    Table[8] = { "Имя22", "Ч", 56, 6, {8,8,2021} };
    Table[9] = { "Имя00", "К", 4, 27, {3,7,2022} };
    Table[10] = { "Петре28", "Ч", 56, 6, {1,1,1999} };
    Table[11] = { "ПРИВ1", "Ч", 56, 6, {1,1,2007} };
    Table[12] = { "Название", "Ч", 56, 6, {1,1,2000} };

    cout << "ПЕРВАЯ ПРАКТИКА" << endl << endl;
    int max_area = 0;
    unsigned short max_employCount = 0;
    Date max_date = Date{ 0,0,0 };
    Table[3] = { "Новая", "Н", max_area, max_employCount, max_date };
    for (int i = 0; i < records_size; i++)
    {
        if (Table[i].area > max_area) { max_area = Table[i].area; }
        if (Table[i].employCount > max_employCount) { max_employCount = Table[i].employCount; }
        max_date = getBiggerDate(Table[i].date, max_date);
    }
    Table[3] = { "Новая", "Н", max_area,max_employCount,max_date };
    Draw(Table, records_size);
    cout << "ВТОРАЯ ПРАКТИКА" << endl << endl;
    Record* A = (Record*)malloc(records_size * sizeof(Record));
    if (A != NULL)
    {
        for (int i = 0; i < records_size; i++)
        {
            A[i] = Table[i];
        }

        Record** B;
        B = (Record**) new Record * [10];
        for (int i = 0; i < 10; i++)
        {
            B[i] = (Record*) new Record;
            *(B[i]) = A[i];
        }

        A = (Record*)realloc(A, 10 * sizeof(Record));

        cout << &Table[0] << " " << &A[0] << " " << &B[0] << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << "Адрес А[" << i << "] " << &A[i] << " Значение А[" << i << "] " << A[i].name;
            cout << " Адрес B[" << i << "] " << &B[i] << " Значение B[" << i << "] " << B[i]->name << endl;
        }


        free(A);
        delete[] B;
    }
}