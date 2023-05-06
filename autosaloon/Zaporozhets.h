#pragma once
#include "Car.h"

class Zaporozhets : public Car
{
    int m_numberOfOwners; // Количество владельцев.
public:
    // Конструктор без параметров.
    Zaporozhets();

    // Конструктор со всеми параметрами.
    Zaporozhets(string title, int yearOfIssue, double engineVolume, double price, int m_numberOfOwners);

    // Деструктор.
    ~Zaporozhets() override;

    // Установить значение поля "Количество владельцев".
    void set_numberOfOwners(int speed);

    // Получить значение поля "Количество владельцев".
    int get_numberOfOwners();

    // Печать объекта "Zaporozhets".
    void Print() override;

    // Запись объекта "Zaporozhets" в текстовый файл.
    void Write(ofstream& out) override;

    // Чтение объекта "Zaporozhets" из текстового файла.
    void Read(ifstream& in) override;
};
