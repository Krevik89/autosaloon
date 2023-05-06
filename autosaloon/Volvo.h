#pragma once

#include "Car.h"

class Volvo : public Car
{
    double m_speed; // Скорость.
public:
    // Конструктор без параметров.
    Volvo();

    // Конструктор со всеми параметрами.
    Volvo(string title, int yearOfIssue, double engineVolume, double price, double speed);

    // Деструктор.
    ~Volvo() override;

    // Установить значение поля "Скорость".
    void set_speed(double speed);

    // Получить значение поля "Скорость".
    double get_speed();

    // Печать объекта "Volvo".
    void Print() override;

    // Запись объекта "Volvo" в текстовый файл.
    void Write(ofstream& out) override;

    // Чтение объекта "Volvo" из текстового файла.
    void Read(ifstream& in) override;
};

