// PLab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Статические поля и методы

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>>

#define nmax 100

class special //бонусы
{
    int bonus_num; //число бонусов
public:
    special() //конструктор
    {
        this->bonus_num = 5;
    }
    void reduce_bonus() //сокращение числа бонусов
    {
        puts("\nDecreasing number of bonuses");
        this->bonus_num -= 2;
        puts("Number of bonuses decreased on 2");
    }
    void set_default() //установка значений по умолчанию
    {
        this->bonus_num = 5;
    }
    special operator + (int a) //перегрузка + постфиксная
    {
        special spec_offer;
        spec_offer.bonus_num = this->bonus_num + a;
        return spec_offer;
    }
    friend special operator + (int a, special spec_offer0) //перегрузка + префиксная
    {
        special spec_offer;
        spec_offer.bonus_num = a + spec_offer0.bonus_num;
        return spec_offer;
    }
    special operator ++(int unused) //перегрузка ++ постфиксная
    {
        special spec_offer = *this;
        ++* this;
        return spec_offer;
    }
    special& operator ++() //перегрузка ++ префиксная
    {
        this->bonus_num++;
        return *this;
    }
};

class book_store //основной класс
{
    special spec_offer[nmax]; //ассоциативный класс
    int n;
    std::string title = ""; //название
    std::string author = ""; //автор
    std::string genre = ""; //жанр
    int price; //цена
    int popularity; //популярность в условных единицах
public:
    int num_stock; //количество в магазине
    book_store(special spec_offer[nmax]);
    book_store(char str1[nmax], char str2[nmax], char str3[nmax], int a, int b, int c, int d, special spec_offer[nmax]);
    //~book_store();
    void get();
    void input(char str1[nmax], char str2[nmax], char str3[nmax], int a, int b, int c, int d);
    void output();
    void sell();
    void price_rise();
    void rearrange();
    void archivate();
    void genre_compare(book_store book);
    static int genre_len(book_store book); //статический метод - определение длины жанра
    int predictable_profit(int* a);
    int predictable_profit(int& a);
    friend int predictable_popularity(book_store book);
    int summarize(int a);
    static int space_left; //статическое поле - оставшееся место в магазине
    void reduce_bonus();
};

int book_store::space_left = 50;

book_store::book_store(special spec_offer[nmax]) //конструктор с параметром
{
    title = "";
    author = "";
    genre = "";
    n = 0;
    price = 0;
    num_stock = 0;
    popularity = 0;
    for (int i = 0; i < n; i++)
    {
        this->spec_offer[i] = spec_offer[i];
    }
    printf("Empty book created\n");
};

book_store::book_store(char str1[nmax], char str2[nmax], char str3[nmax], int a, int b, int c, int d, special spec_offer[nmax]) //конструктор с параметрами
{
    this->title = str1;
    this->author = str2;
    this->genre = str3;
    this->price = a;
    this->num_stock = b;
    this->popularity = c;
    this->n = d;
    for (int i = 0; i < n; i++)
    {
        this->spec_offer[i] = spec_offer[i];
    }
    printf("New book initialized (with parameters)\n");
};

/*book_store::~book_store() //деструктор
{
    printf("Book deleted\n");
}*/

void book_store::input(char str1[nmax], char str2[nmax], char str3[nmax], int a, int b, int c, int d) //ввод
{
    title = str1;
    author = str2;
    genre = str3;
    price = a;
    num_stock = b;
    popularity = c;
    n = d;
}

void book_store::get() //установка значений
{
    this->title;
    this->author;
    this->genre;
    this->price;
    this->num_stock;
    this->popularity;
    this->n;
    for (int i = 0; i < n; i++)
    {
        this->spec_offer[i];
    }
}

void book_store::output() //вывод
{
    std::cout << "\nTitle: " << title << "\nAuthor: " << author << "\nGenre: " << genre << "\nPrice: " << price << "\nNumber in stock: " << num_stock << "\nPopularity: " << popularity << '\n';
    printf("Number of bonuses: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", spec_offer[i]);
    }
    printf("\n");
}

void book_store::sell() //продажа
{
    puts("\nPutting book on sale");
    num_stock = num_stock - 1;
    popularity = popularity + 5;
    puts("Ony copy sold, popularity increased on 5");
}

void book_store::price_rise() //повышение цены
{
    puts("\nRising the price");
    price = price + 50;
    puts("Price risen on 50");
    return;
}

void book_store::rearrange() //перестановка
{
    puts("\nRearranging books");
    popularity = popularity + 10;
    puts("Books rearranged, popularity increased on 10");
}

void book_store::archivate() //отправка на склад
{
    puts("\nSending 4 books to the archive");
    num_stock = num_stock - 4;
    puts("4 books now stored in archive");
}

void book_store::genre_compare(book_store book) //сравнение жанров двух книг
{
    if (this->genre.compare(book.genre) == 0)
        printf("\nGenres are the same\n");
    else
        printf("\nGenres are different\n");
}

int book_store::summarize(int a) //сложение количества двух книг
{
    return this->num_stock + a;
}

int book_store::genre_len(book_store book) //вычисление длины строки 'жанр'
{
    return book.genre.length();
}

int book_store::predictable_profit(int* a) //подсчет ожидаемой прибыли по указателю
{
    *a = num_stock * price;
    return *a;
}

int book_store::predictable_profit(int& a) //подсчет ожидаемой прибыли по ссылке
{
    a = num_stock * price;
    return a;
}

int predictable_popularity(book_store book) //подсчет ожидаемой популярности от продажи (дружественная функция)
{
    return book.num_stock * 5 + book.popularity;
}

/*int book_store::reduce_space_left(book_store book)
{
    return book.
}*/

void book_store::reduce_bonus() //сокращение числа бонусов
{
    for (int i = 0; i < n; i++)
    {
        this->spec_offer[i].reduce_bonus();
    }
}
int main()
{
    int x, y, z, n, m, k = 1, p; //переменные
    char s1[nmax], s2[nmax], s3[nmax], s4[nmax]; //массивы

    //статическая переменная

    puts("\nWorking with a single static variable\n");
    special spec_offer1[1];
    book_store book1(spec_offer1);
    puts("Input information about the 1 book\n");
    printf("Input title: ");
    rewind(stdin);
    gets_s(s1, nmax);
    printf("Input author: ");
    rewind(stdin);
    gets_s(s2, nmax);
    printf("Input genre: ");
    rewind(stdin);
    gets_s(s3, nmax);
    printf("Input price: ");
    scanf_s("%d", &x);
    printf("Input number in stock: ");
    scanf_s("%d", &y);
    printf("Input popularity: ");
    scanf_s("%d", &z);
    book1.input(s1, s2, s3, x, y, z, 1);
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    book1.sell();
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    book1.price_rise();
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    book1.rearrange();
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    book1.archivate();
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    book1.reduce_bonus();
    printf("\nFirst book\n");
    book1.get();
    book1.output();
    printf("\nLength of the 'genre' for the first book: %d\n", book_store::genre_len(book1));
    book1.predictable_profit(&k);
    printf("\nPredictable profit for the first book (using *): %d\n", k);
    p = predictable_popularity(book1);
    printf("\nPredictable popularity for the first book (friend fuction): %d\n", p);
    printf("\nSpace left in the store: %d\n", book1.space_left);

    //динамическая переменная

    puts("\nWorking with a single dynamic variable");
    special* spec_offer2 = new special;
    book_store* book2 = new book_store(spec_offer2);
    puts("\nInput information about the 2 book\n");
    printf("Input title: ");
    rewind(stdin);
    gets_s(s1, nmax);
    printf("Input author: ");
    rewind(stdin);
    gets_s(s2, nmax);
    printf("Input genre: ");
    rewind(stdin);
    gets_s(s3, nmax);
    printf("Input price: ");
    scanf_s("%d", &x);
    printf("Input number in stock: ");
    scanf_s("%d", &y);
    printf("Input popularity: ");
    scanf_s("%d", &z);
    book2->input(s1, s2, s3, x, y, z, 1);
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->sell();
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->price_rise();
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->rearrange();
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->archivate();
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->reduce_bonus();
    printf("\nSecond book\n");
    book2->get();
    book2->output();
    book2->genre_compare(book1);
    k = 1;
    book2->predictable_profit(k);
    printf("\nPredictable profit for the second book (using &): %d\n", k);
    printf("\nSummarizing nums of books\nSum = %d\n", book2->summarize(book1.num_stock));
    p = 0;
    p = predictable_popularity(*book2);
    printf("\nPredictable popularity for the second book (friend fuction): %d\n", p);
    book2->space_left = 40;
    printf("\nSpace left in the store (using 1 book): %d\n", book1.space_left);
    printf("\nSpace left in the store (using 2 book): %d\n", book2->space_left);
    delete book2;
    book2 = NULL;

    //статический массив

    puts("\nWorking with a static massive\n");
    special spec_offer3[nmax / 10];
    puts("Input number of specials\n");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        spec_offer3[i].set_default();
    }
    puts("\nInput information about 3 book\n");
    printf("Input title: ");
    rewind(stdin);
    gets_s(s1, nmax);
    printf("Input author: ");
    rewind(stdin);
    gets_s(s2, nmax);
    printf("Input genre: ");
    rewind(stdin);
    gets_s(s3, nmax);
    printf("Input price: ");
    scanf_s("%d", &x);
    printf("Input number in stock: ");
    scanf_s("%d", &y);
    printf("Input popularity: ");
    scanf_s("%d", &z);
    book_store* book3 = new book_store(s1, s2, s3, x, y, z, n, spec_offer3);
    printf("\nYour book\n");
    book3->get();
    book3->output();
    book3->sell();
    printf("\nThird book\n");
    book3->get();
    book3->output();
    book3->price_rise();
    printf("\nThird book\n");
    book3->get();
    book3->output();
    book3->rearrange();
    printf("\nThird book\n");
    book3->get();
    book3->output();
    book3->archivate();
    printf("\nThird book\n");
    book3->get();
    book3->output();
    puts("Decreasing number for all the specials");
    book3->reduce_bonus();
    book3->get();
    book3->output();
    k = 1;
    p = 0;
    book3->predictable_profit(&k);
    printf("\nPredictable profit for the third book (using *): %d\n", k);
    p = predictable_popularity(*book3);
    printf("\nPredictable popularity for the first book (friend fuction): %d\n", p);

    //перегрузки в классе special

    puts("\nWorking with a single variable of the special class (overloads)\n");
    special spec_offer0, spec_offer4;
    spec_offer0.set_default();
    printf("Number of bonuses: %d\n", spec_offer0);
    spec_offer0 = spec_offer0 + 5;
    printf("Number of bonuses (spec_offer0 + 5): %d\n", spec_offer0);
    spec_offer0.set_default();
    spec_offer4 = 10 + spec_offer0;
    printf("Number of bonuses (10 + spec_offer0): %d\n", spec_offer4);
    spec_offer0.set_default();
    spec_offer4.set_default();
    spec_offer4 = ++spec_offer0;
    printf("Number of bonuses (++ spec_offer0): %d\n", spec_offer4);
    spec_offer0.set_default();
    spec_offer4.set_default();
    spec_offer4 = spec_offer0++;
    printf("Number of bonuses (spec_offer0 ++): %d\n", spec_offer4);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
