#include "Car.h"

#include <fstream>
#include <iostream>

using namespace std;

// Конструктор без параметров.
Car::Car() :m_title("unknown"), m_yearOfIssue(0), m_engineVolume(0.0), m_price(0.0) {}

// Конструктор cо всеми параметрами.
Car::Car(string title, int yearOfIssue, double engineVolume, double price) :
    m_title(title), m_yearOfIssue(yearOfIssue), m_engineVolume(engineVolume), m_price(price) {}

// Деструктор.
Car::~Car() = default;

// Установить значение поля "Имя производителя".
void Car::set_title(string title) { m_title = title; }

// Установить значение поля "Год выпуска".
void Car::set_yearOfIssue(int yearOfIssue) { m_yearOfIssue = yearOfIssue; }

// Установить значение поля "Объем двигателя".
void Car::set_engineVolume(double engineVolume) { m_engineVolume = engineVolume; }

// Установить значение поля "Цена".
void Car::set_price(double price) { m_price = price; }

// Получить значение поля "Название автомобиля".
string Car::get_title() { return m_title; }

// Получить значение поля "Год выпуска".
int Car::get_yearOfIssue() { return m_yearOfIssue; }

// Получить значение поля "Объем двигателя".
double Car::get_engineVolume() { return m_engineVolume; }

// Получить значение поля "Цена".
double Car::get_price() { return m_price; }

// Печать объекта "Car".
void Car::Print()
{
    cout << "Название автомобиля: " << m_title << endl
        << "Год выпуска: " << m_yearOfIssue << endl
        << "Объем двигателя: " << m_engineVolume << endl
        << "Цена: " << m_price << endl;
}

// Запись объекта "Car" в текстовый файл.
void Car::Write(ofstream& out)
{
    out << m_title << "\n" // Пишем первым, для понимания что мы будем вычитывать из файла.
        << m_yearOfIssue << "\n"
        << m_engineVolume << "\n"
        << m_price << "\n";
}

// Чтение объекта "Car" из текстового файла.
void Car::Read(ifstream& in)
{
    in.get(); // Убираем "\n", который записан после количества записываемых в файл объектов.
    in >> m_yearOfIssue;
    in >> m_engineVolume;
    in >> m_price;
}
