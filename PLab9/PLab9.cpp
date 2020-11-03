// PLab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Конструкторы, мелкое/глубокое копирование и перегрузка оператора присваивания

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <cstdlib>

using namespace std;

#define nmax 100
#define str_0 "unknown"

class special //бонусы
{
    int bonus_num; //число бонусов
    char* definition; //наименование бонусов
public:
    special() //конструктор без параметров
    {
        this->bonus_num = 5;
        definition = new char[10];
        strcpy(this->definition, "");
    }
    special(int a) //конструктор с параметром
    {
        this->bonus_num = a;
    }
    special(char* b, int c) //конструктор с параметрами
    {
        definition = new char[10];
        strcpy(definition, b);
        bonus_num = c;
    }
    special(const special& spec_offer) //конструктор копирования + мелкое копирование
    {
        this->definition = spec_offer.definition;
        this->bonus_num = spec_offer.bonus_num;
    }
    special& operator = (special& spec_offer) //перегрузка оператора присваивания + глубокое копирование
    {
        int k;
        if (definition)
        {
            delete definition; // очистка памяти
        }
        definition = NULL;
        this->bonus_num = spec_offer.bonus_num; // копирование обычного поля
        k = strlen(spec_offer.definition) + 1;
        definition = new char[k];  // выделение памяти для новой копии памяти для наименования
        strcpy(this->definition, spec_offer.definition);  // копирование в новую выделенную область
        return *this;
    }
    void output() //вывод общий
    {
        printf("\nNumber of bonuses: %d\nDefinition: %s\n", bonus_num, definition);
    }
    void output1() //вывод исла бонусов
    {
        printf("%d ", bonus_num);
    }
    void change_def(char* a) //изменение наименования
    {
        strcpy(this->definition, a);
    }
    void change_bonus_num(int a) //изменение числа бонусов
    {
        this->bonus_num = a;
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
        definition = new char[10];
        strcpy(this->definition, str_0);
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
    book_store(special spec_offer[nmax]); //конструктор параметром
    book_store(string str1, string str2, string str3, int a, int b, int c, int d, special spec_offer[nmax]); //конструктор с параметрами
    book_store(string str1); //конструктор параметром
    void get();
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
    printf("\nEmpty book created\n");
};

book_store::book_store(string str) //конструктор с параметром для создания массива
{
    this->title = str;
    this->author = str_0;
    this->genre = str_0;
    this->price = 100;
    this->num_stock = 10;
    this->popularity = 15;
    this->n = 1;
    this->spec_offer[1].set_default();
}

book_store::book_store(string str1, string str2, string str3, int a, int b, int c, int d, special spec_offer[nmax]) //конструктор с параметрами
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
        spec_offer[i].output1();
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
    string s1, s2, s3; //массивы

    //статическая переменная

    puts("\nWorking with a single static variable");
    special spec_offer1[1]; //вызов конструктора по умолчанию (без параметров) статический 
    puts("Input information about the 1 book\n");
    printf("Input title: ");
    cin >> s1;
    printf("Input author: ");
    cin >> s2;
    printf("Input genre: ");
    cin >> s3;
    printf("Input price: ");
    cin >> x;
    printf("Input number in stock: ");
    cin >> y;
    printf("Input popularity: ");
    cin >> z;
    book_store book1(s1, s2, s3, x, y, z, 1, spec_offer1); //вызов конструктора с параметрами статический
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
    special* spec_offer2 = new special(); //вызов конструктора по умолчанию (без параметров) динамический 
    puts("\nInput information about the 2 book\n");
    printf("Input title: ");
    cin >> s1;
    printf("Input author: ");
    cin >> s2;
    printf("Input genre: ");
    cin >> s3;
    printf("Input price: ");
    cin >> x;
    printf("Input number in stock: ");
    cin >> y;
    printf("Input popularity: ");
    cin >> z;
    book_store* book2 = new book_store(s1, s2, s3, x, y, z, 1, spec_offer2); //вызов конструктора с параметрами динамический
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
    special spec_offer3[nmax / 10]; //вызов конструктора по умолчанию (без параметров) статический
    puts("Input number of specials\n");
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        spec_offer3[i].set_default();
    } 
    puts("\nInput information about 3 book\n");
    printf("Input title: ");
    cin >> s1;
    printf("Input author: ");
    cin >> s2;
    printf("Input genre: ");
    cin >> s3;
    printf("Input price: ");
    cin >> x;
    printf("Input number in stock: ");
    cin >> y;
    printf("Input popularity: ");
    cin >> z;
    book_store* book3 = new book_store(s1, s2, s3, x, y, z, n, spec_offer3); //вызов конструктора с параметрами динамический
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
    
    //массив с помощью конструктора с параметром

    printf("\nMassive using constructor with a single parameter\n");
    special spec_offer5[1];
    string title1 = "rrrr";
    string title2 = "ffff";
    book_store book5[2] = {title1,title2};
    for (int i = 0; i < 2; i++)
    {
        book5[i].output();
    }

    //мелкое копирование

    printf("\nShallow copying\n");
    char* ptr1;
    ptr1 = new char[10];

    strcpy(ptr1, "iii");
    special spec_offer6(ptr1, 10); //вызов конструктора с параметрами статический
    special spec_offer7 = spec_offer6; //вызов конструктора копирования

    printf("\nspec_offer6\n");
    spec_offer6.output();
    printf("\nspec_offer7\n");
    spec_offer7.output();
    
    strcpy(ptr1, "jjj");
    spec_offer6.change_def(ptr1);
    spec_offer6.change_bonus_num(5);
    printf("\nspec_offer6\n");
    spec_offer6.output();
    printf("\nspec_offer7\n");
    spec_offer7.output();

    //глубокое копирование

    printf("\nDeep copying and overload\n");
    special* spec_offer_1;
    char* ptr;
    ptr = new char[10];
    strcpy(ptr, "ppp");
    spec_offer_1 = new special(ptr, 10);
    special* spec_offer_2;
    strcpy(ptr, "kkk");
    spec_offer_2 = new special(ptr, 15);
    printf("\nspec_offer_1\n");
    spec_offer_1->output();
    printf("\nspec_offer_2\n");
    spec_offer_2->output();
    *spec_offer_2 = *spec_offer_1;
    printf("\nspec_offer_1\n");
    spec_offer_1->output();
    printf("\nspec_offer_2\n");
    spec_offer_2->output();
    spec_offer_1->set_default();
    strcpy(ptr, "jjj");
    spec_offer_1->change_def(ptr);
    printf("\nspec_offer_1\n");
    spec_offer_1->output();
    printf("\nspec_offer_2\n");
    spec_offer_2->output();
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
