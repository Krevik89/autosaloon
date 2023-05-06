#include "Volvo.h"

#include <iostream>
#include <fstream>

// Конструктор без параметров.
Volvo::Volvo() :Car(), m_speed(0) { m_title = "Volvo"; }

Volvo::Volvo(string title, int yearOfIssue, double engineVolume, double price, double speed)
    :Car(title, yearOfIssue, engineVolume, price), m_speed(speed) {
    m_title = "Volvo";
}

// Деструктор.
Volvo::~Volvo() = default;

// Установить значение поля "Скорость".
void Volvo::set_speed(double speed) { m_speed = speed; }

// Получить значение поля "Скорость".
double Volvo::get_speed() { return m_speed; }

// Печать объекта "Volvo".
void Volvo::Print()
{
    cout << endl;
    Car::Print();
    cout << "Скорость: " << m_speed << endl;
}

// Запись объекта "Volvo" в текстовый файл.
void Volvo::Write(ofstream& out)
{
    Car::Write(out);
    out << m_speed << "\n";
}

// Чтение объекта "Volvo" из текстового файла.
void Volvo::Read(ifstream& in)
{
    Car::Read(in);
    in >> m_speed;
}