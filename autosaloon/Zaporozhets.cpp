#include "Zaporozhets.h"

#include <iostream>
#include <fstream>

// Конструктор без параметров.
Zaporozhets::Zaporozhets() :Car(), m_numberOfOwners(0) { m_title = "Zaporozhets"; }

Zaporozhets::Zaporozhets(string title, int yearOfIssue, double engineVolume, double price, int m_numberOfOwners)
    :Car(title, yearOfIssue, engineVolume, price), m_numberOfOwners(m_numberOfOwners) {
    m_title = "Zaporozhets";
}

// Деструктор.
Zaporozhets::~Zaporozhets() = default;

// Установить значение поля "Скорость".
void Zaporozhets::set_numberOfOwners(int numberOfOwners) { m_numberOfOwners = numberOfOwners; }

// Получить значение поля "Скорость".
int Zaporozhets::get_numberOfOwners() { return m_numberOfOwners; }

// Печать объекта "Zaporozhets".
void Zaporozhets::Print()
{
    cout << endl;
    Car::Print();
    cout << "Количество владельцев: " << m_numberOfOwners << endl;
}

// Запись объекта "Zaporozhets" в текстовый файл.
void Zaporozhets::Write(ofstream& out)
{
    Car::Write(out);
    out << m_numberOfOwners << "\n";
}

// Чтение объекта "Zaporozhets" из текстового файла.
void Zaporozhets::Read(ifstream& in)
{
    Car::Read(in);
    in >> m_numberOfOwners;
}