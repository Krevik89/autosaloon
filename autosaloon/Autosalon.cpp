#include "Autosalon.h"

#include <algorithm>
#include <fstream>
#include <iostream>

#include "Volvo.h"
#include "Zaporozhets.h"
#include "Car.h"

using std::cout;
using std::cin;
using std::endl;

// Получить размер вектора.
int Autosalon::get_size() { return m_v.size(); }

// Добавление автомобиля.
void Autosalon::AddAuto()
{
    int autoCount{ 0 }; // Добавляемое кол-во.
    do
    {
        cout << "\nВведите количество автомобилей для добавления в список: ";
        cin >> autoCount;
        cin.get();
    } while (autoCount <= 0);

    int inputNumOfAuto{ 1 }; // Порядковый номер воодимого авто.

    for (int i = 0; i < autoCount; i++)
    {
        cout << "\nВыберите " << inputNumOfAuto << " автомобиль: ";
        inputNumOfAuto++;

        cout << "\n(1 - Volvo, 2 - Zaporozhets): ";
        int type;
        cin >> type;
        cin.get();
        switch (type)
        {
        case 1:
        {
            Volvo* volvo = new Volvo;

            cout << "Год выпуска: ";
            int yearOfIssue{ 0 };
            cin >> yearOfIssue;
            volvo->set_yearOfIssue(yearOfIssue);

            cout << "Объем двигателя: ";
            double engineVolume{ 0.0 };
            cin >> engineVolume;
            volvo->set_engineVolume(engineVolume);

            cout << "Цена: ";
            double price{ 0.0 };
            cin >> price;
            volvo->set_price(price);

            cout << "Скорость: ";
            double speed{ 0.0 };
            cin >> speed;
            volvo->set_speed(speed);

            m_v.push_back(volvo);
            break;
        }
        case 2:
        {
            Zaporozhets* zap = new Zaporozhets;

            cout << "Год выпуска: ";
            int yearOfIssue{ 0 };
            cin >> yearOfIssue;
            zap->set_yearOfIssue(yearOfIssue);

            cout << "Объем двигателя: ";
            double engineVolume{ 0.0 };
            cin >> engineVolume;
            zap->set_engineVolume(engineVolume);

            cout << "Цена: ";
            double price{ 0.0 };
            cin >> price;
            zap->set_price(price);

            cout << "Количество владельцев: ";
            int numberOfOwners{ 0 };
            cin >> numberOfOwners;
            cin.get();
            zap->set_numberOfOwners(numberOfOwners);

            m_v.push_back(zap);
            break;
        }
        default:
            break;
        }
    }
}

// Печать всего списка автомобилей.
void Autosalon::PrintAll() const
{
    vector<Car*>::const_iterator it = m_v.begin();
    int count{ 1 };
    for (; it != m_v.end(); it++)
    {
        cout << endl << "Автомобиль № " << count++ << endl;
        (*it)->Print();
        cout << "-------------------------------------------------------" << endl;
    }
}

// Печать выборки из списка автомобилей.
void Autosalon::PrintSelective(int choice) const
{
    int autoPrinted{ 0 };
    vector<Car*>::const_iterator it = m_v.begin();
    int i{ 1 };
    for (; it != m_v.end(); it++)
    {
        if (typeid(**it) == typeid(Volvo) && choice == 2) // Печать только Volvo.           
        {
            autoPrinted++;
            cout << endl << "Порядковый номер в списке: " << i << endl << endl
                << "-------------------------------------------------------";
            (*it)->Print();
            cout << "-------------------------------------------------------" << endl;
        }

        if (typeid(**it) == typeid(Zaporozhets) && choice == 3) // Печать только Zaporozhets.           
        {
            autoPrinted++;
            cout << endl << "Порядковый номер в списке: " << i << endl << endl
                << "-------------------------------------------------------";
            (*it)->Print();
            cout << "-------------------------------------------------------" << endl;
        }

        i++;
        /* или проще, по идее тоже должно работать.
         *if (dynamic_cast<DVD*>(m_mediaList[i])->get_speed() == temp)
            m_mediaList[i]->PrintAll();*/
    }
    cout << endl << "Всего распечатано " << autoPrinted << " автомобилей." << endl;
}

// Удаление автомобиля по номеру.
void Autosalon::Delete(int number)
{
    number = number - 1;
    vector<Car*>::iterator it = m_v.begin();
    it += number;
    m_v.erase(it);
    m_v;
}

// Изменение по номеру параметров автомобиля.
void Autosalon::Change(int number)
{
    number = number - 1;
    cout << endl << "Что будем изменять ?"
        << "\n1 - Год выпуска."
        << "\n2 - Объем двигателя."
        << "\n3 - Цена."
        << "\n4 - Скорость / Количество владельцев."
        << "\nВведите номер поля для изменения, затем его значение >>> : ";
    int var;
    cin >> var;
    cin.get();

    vector<Car*>::iterator it = m_v.begin();
    it += number;

    switch (var)
    {
    case 1: // Год выпуска.
    {
        int temp;
        cin >> temp;
        (*it)->set_yearOfIssue(temp);
        break;
    }
    case 2: // Объем двигателя.
    {
        double temp;
        cin >> temp;
        (*it)->set_engineVolume(temp);
        break;
    }
    case 3: // Цена.
    {
        double temp;
        cin >> temp;
        (*it)->set_price(temp);
        break;
    }
    case 4: // Скорость / Количество владельцев.
    {
        if (typeid(**it) == typeid(Volvo))
        {
            double temp;
            cin >> temp;
            dynamic_cast<Volvo*>(*it)->set_speed(temp);
        }

        if (typeid(**it) == typeid(Zaporozhets))
        {
            int temp;
            cin >> temp;
            dynamic_cast<Zaporozhets*>(*it)->set_numberOfOwners(temp);
        }

        break;
    }
    default:
        cout << "Ошибка!" << endl;
        break;
    }
}

// Поиск по заданному критерию.
void Autosalon::Search()
{
    int autoFound{ 0 }; // Общее найденное количество автомобилей.
    cout << endl << "Что будем искать ?"
        << "\n1 - Название автомобиля."
        << "\n2 - Год выпуска."
        << "\n3 - Объем двигателя."
        << "\n4 - Цена."
        << "\n5 - Скорость."
        << "\n6 - Количество владельцев."
        << "\nВведите номер критерия для поиска, затем его значение >>> : ";
    int var;
    cin >> var;
    cin.get();

    vector<Car*>::const_iterator it = m_v.begin();
    int i{ 0 };

    switch (var)
    {
    case 1:
    {
        string temp;
        getline(cin, temp);
        for (; it != m_v.end(); it++)
        {
            i++;
            if ((*it)->get_title() == temp) // Название автомобиля
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    case 2:
    {
        int temp;
        cin >> temp;
        for (; it != m_v.end(); it++)
        {
            i++;
            if ((*it)->get_yearOfIssue() == temp) // Год выпуска.
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    case 3:
    {
        double temp;
        cin >> temp;
        for (; it != m_v.end(); it++)
        {
            i++;
            if ((*it)->get_engineVolume() == temp) // Объем двигателя.
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    case 4:
    {
        double temp;
        cin >> temp;
        for (; it != m_v.end(); it++)
        {
            i++;
            if ((*it)->get_price() == temp) // Цена.
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    case 5:
    {
        double temp;
        cin >> temp;
        for (; it != m_v.end(); it++)
        {
            i++;
            if (typeid(**it) == typeid(Volvo) && dynamic_cast<Volvo*>(*it)->get_speed() == temp) // Скорость Volvo.
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    case 6:
    {
        int temp;
        cin >> temp;
        for (; it != m_v.end(); it++)
        {
            i++;
            if (typeid(**it) == typeid(Zaporozhets) && dynamic_cast<Zaporozhets*>(*it)->get_numberOfOwners() == temp) // Количество владельцев Zaporozhets.
            {
                autoFound++;
                cout << endl << "Порядковый номер в списке: " << i + 1 << endl << endl
                    << "-------------------------------------------------------";
                (*it)->Print();
                cout << "-------------------------------------------------------" << endl;
            }
        }
        break;
    }
    default:
        cout << "Ошибка!" << endl;
        break;
    }
    cout << endl << "Всего найдено " << autoFound << " автомобилей." << endl;
}

// Сохранение в файл.
void Autosalon::Save()
{
    // Создаём выходной файловый поток и присоединяем к нему файл, который открывается на запись в текстовом режиме.
    ofstream out("data.txt", ios_base::out | ios_base::trunc);
    if (!out.is_open()) // Если открытие файла завершилось неудачей - выходим.
    {
        cout << "Error!\n";
        return;
    }

    out << m_v.size() << "\n"; // Записываем количество елементов в векторе.

    vector<Car*>::const_iterator it = m_v.begin();

    for (; it != m_v.end(); it++)
        (*it)->Write(out);

    out.close(); // Закрываем файловый поток.
}

// Загрузка из файла.
void Autosalon::Load()
{
    // Создаём входной файловый поток и присоединяем к нему файл, который открывается на чтение в текстовом режиме.
    ifstream in("data.txt");
    if (!in.is_open()) // Если открытие файла завершилось неудачей - выходим.
    {
        cout << "Error!\n";
        return;
    }

    int size{ 0 };
    in >> size; // Считываем количество записанных объектов в файле.

    m_v.reserve(size); // Выделяем память под все записанные объекты, для сохранения актуальности итераторов.

    string title{}; // Наименование.

    for (int i = 0; i < size; i++)
    {
        getline(in, title);
        in >> title;

        if (title == "Volvo")
        {
            m_v.insert(m_v.end(), new Volvo);
            m_v[i]->Read(in);
            continue;
        }
        if (title == "Zaporozhets")
        {
            m_v.insert(m_v.end(), new Zaporozhets);
            m_v[i]->Read(in);
        }
    }
    in.close();
}

// Сортировка по "1 - Название автомобиля".
bool compare()
{

}

// Сортировка по заданному критерию.
void Autosalon::Sort()
{
    cout << endl << "По какому критерию будем сортировать ?"
        << "\n1 - Название автомобиля."
        << "\n2 - Год выпуска."
        << "\n3 - Объем двигателя."
        << "\n4 - Цена."
        << "\n5 - Скорость."
        << "\n6 - Количество владельцев."
        << "\nВведите номер критерия для сортировки >>> : ";
    int var;
    cin >> var;

    vector<Car*>::const_iterator it = m_v.begin();
    int i{ 0 };

    switch (var)
    {
    case 1: // 1 - Название автомобиля.
    {
        for (; it != m_v.end(); it++)
        {


        }

        PrintAll();
        break;
    }
    case 2: // 2 - Год выпуска.
    {

        break;
    }
    case 3: // 3 - Объем двигателя.
    {

        break;
    }
    case 4: // 4 - Цена.
    {

        break;
    }
    case 5: // 5 - Скорость.
    {

        break;
    }
    case 6: // 6 - Количество владельцев.
    {

        break;
    }
    default:
        cout << "Ошибка!" << endl;
        break;
    }
}