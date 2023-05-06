#pragma once
#include <string>
#include <vector>
#include "Car.h"

using namespace std;

class Autosalon
{
    vector<Car*> m_v;
public:
    // Получить размер вектора.
    int get_size();

    // Добавление автомобиля.
    void AddAuto();

    // Печать всего списка автомобилей.
    void PrintAll() const;

    // Печать выборки из списка автомобилей.
    void PrintSelective(int choice) const;

    // Удаление автомобиля по номеру.
    void Delete(int number);

    // Изменение по номеру параметров автомобиля.
    void Change(int number);

    // Поиск по заданному критерию.
    void Search();

    // Сохранение в файл.
    void Save();

    // Загрузка из файла.
    void Load();

    // Сортировка по заданному критерию.
    void Sort();
};
