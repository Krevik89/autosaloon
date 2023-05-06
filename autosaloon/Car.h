#pragma once

#include <string>

using namespace std;

class Car abstract
{
protected:
    string m_title;         // Название автомобиля.
    int m_yearOfIssue;      // Год выпуска.
    double m_engineVolume;  // Объем двигателя.
    double m_price;         // Цена.
public:
    // Конструктор без параметров.
    Car();

    // Конструктор cо всеми параметрами.
    Car(string title, int yearOfIssue, double engineVolume, double price);

    // Деструктор.
    virtual ~Car();

    // Установить значение поля "Имя производителя".
    void set_title(string title);

    // Установить значение поля "Год выпуска".
    void set_yearOfIssue(int yearOfIssue);

    // Установить значение поля "Объем двигателя".
    void set_engineVolume(double engineVolume);

    // Установить значение поля "Цена".
    void set_price(double price);

    // Получить значение поля "Название автомобиля".
    string get_title();

    // Получить значение поля "Год выпуска".
    int get_yearOfIssue();

    // Получить значение поля "Объем двигателя".
    double get_engineVolume();

    // Получить значение поля "Цена".
    double get_price();

    // Печать объекта "Car".
    virtual void Print();

    // Запись объекта "Car" в текстовый файл.
    virtual void Write(ofstream& out);

    // Чтение объекта "Car" из текстового файла.
    virtual void Read(ifstream& in);
};



