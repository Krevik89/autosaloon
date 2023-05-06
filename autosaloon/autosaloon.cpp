#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>

#include "Autosalon.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Autosalon list; // Создание массива.

    // Проверка на пустой/отсутствующий файл.
    ifstream in("data.txt");
    if (!(in.peek() == ifstream::traits_type::eof())) // Если вернет true, то файл пустой или его нету. 
        list.Load();
    in.close();

    while (true)
    {
        system("cls");
        cout << "\tГлавное меню." << endl
            << "\n1. Добавить автомобиль."
            << "\n2. Удалить автомобиль."
            << "\n3. Печать автомобилей."
            << "\n4. Редактировать автомобиль."
            << "\n5. Поиск автомобиля."
            << "\n6. Сортировка автомобиля."
            << "\n7. Выход" << endl;
        int choice_mainMenu{};
        int number{};
        cout << "\n >>> : ";
        cin >> choice_mainMenu;
        switch (choice_mainMenu)
        {
        case 1:                                                     // 1. Добавить автомобиль. 
            system("cls");
            cout << "Главное меню."
                "\n\t1. Добавить автомобиль."
                << endl;
            list.AddAuto();
            cout << "\nГотово !" << endl
                << "\nДля продолжения нажмите любую клавишу." << endl;
            _getch();
            break;
        case 2:                                                     // 2. Удалить автомобиль. 
            system("cls");
            cout << "Главное меню."
                "\n\t2. Удалить автомобиль."
                << endl;
            if (list.get_size() > 0)
            {
                list.PrintAll();
                cout << "\nВведите номер элемента в списке для удаления: ";
                cin >> number;
                list.Delete(number);
                cout << "\nГотово !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            else
            {
                cout << endl << "Список пуст !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            break;
        case 3:                                                     // 3. Печать автомобилей. 
            system("cls");
            cout << "Главное меню."
                "\n\t3. Печать автомобилей."
                << endl;
            if (list.get_size() > 0)
            {
                cout << "\n1. Печать всего списка автомобилей."
                    << "\n2. Печать всех Volvo."
                    << "\n3. Печать всех Zaporozhets." << endl;
                int choice{ 0 };
                cout << "\n >>> : ";
                cin >> choice;
                switch (choice)
                {
                case 1:                                             // 1. Печать всего списка автомобилей.
                    system("cls");
                    cout << "Главное меню."
                        "\n\t3. Печать автомобилей."
                        "\n\t\t1. Печать всего списка автомобилей."
                        << endl;
                    list.PrintAll();
                    cout << "\nГотово !" << endl
                        << "\nДля продолжения нажмите любую клавишу." << endl;
                    _getch();
                    break;
                case 2:                                             // 2. Печать всех Volvo.
                    system("cls");
                    cout << "Главное меню."
                        "\n\t3. Печать автомобилей."
                        "\n\t\t2. Печать всех Volvo."
                        << endl;
                    list.PrintSelective(choice);
                    cout << "\nГотово !" << endl
                        << "\nДля продолжения нажмите любую клавишу." << endl;
                    _getch();
                    break;
                case 3:                                             // 3. Печать всех Zaporozhets.
                    system("cls");
                    cout << "Главное меню."
                        "\n\t3. Печать автомобилей."
                        "\n\t\t3. Печать всех Zaporozhets."
                        << endl;
                    list.PrintSelective(choice);
                    cout << "\nГотово !" << endl
                        << "\nДля продолжения нажмите любую клавишу." << endl;
                    _getch();
                    break;
                default:
                    cout << "Ошибка !" << endl;
                    break;
                }
            }
            else
            {
                cout << endl << "Список пуст !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            break;
        case 4:                                                     // 4. Редактировать автомобиль.
            system("cls");
            cout << "Главное меню."
                "\n\t4. Редактировать автомобиль."
                << endl;
            if (list.get_size() > 0)
            {
                list.PrintAll();
                cout << "\nВведите номер элемента в списке: ";
                cin >> number;
                list.Change(number);
                cout << "\nГотово !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            else
            {
                cout << endl << "Список пуст !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            break;
        case 5:                                                     // 5. Поиск автомобиля.
            system("cls");
            cout << "Главное меню."
                "\n\t5. Поиск автомобиля."
                << endl;
            if (list.get_size() > 0)
            {
                list.Search();
                cout << "\nГотово !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            else
            {
                cout << endl << "Список пуст !" << endl
                    << "\nДля продолжения нажмите любую клавишу." << endl;
                _getch();
            }
            break;
        case 6:                                                     // 6. Сортировка 
            if (list.get_size() > 0)
            {
                list.Sort();
                cout << "\nДанные успешно отсортированы в файл !" << endl;
            }
            return 0;
        case 7:                                                     // 7. Выход 
            if (list.get_size() > 0)
            {
                list.Save();
                cout << "\nДанные успешно сохранены в файл !" << endl;
            }
            return 0;
        default:
            cout << "Ошибка !" << endl;
            break;
        }
    }
}