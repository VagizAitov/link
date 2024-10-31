#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Film {
    string name;
    string budget;
    double price;
    int quantity;
    int age_limit;
};

int main()
{
    setlocale(LC_ALL, "ru");
    for (;;) {
        int n_films = 0;

        Film* films = new Film[n_films]{
        };
        fstream bin;
        fstream write;

        Film* films_to_add = new Film[n_films];
        Film* film = new Film;

        int f_move;
        cout << "[1] Добавить фильм\n[2] Посмотреть каталог фильмов\n[3] Поиск фильмов по атрибуту\n";
        cin >> f_move;

        string sub_str;
        string desc;
        string name;

        switch (f_move)
        {
        default:
            cout << ":(";
            break;
        case 1:
            cout << "Введите название фильма: ";
            cin.ignore();
            getline(cin, name);
            film->name = name;
            cout << "Введите бюджет фильма: ";
            getline(cin, desc);
            film->budget = desc;
            cout << "Введите цену билета: ";
            cin >> film->price;
            cout << "Введите количество свободных мест: ";
            cin >> film->quantity;
            cout << "Введите возрастное ограничение: ";
            cin >> film->age_limit;
            bin.open("bin.bin", std::ios::in | std::ios::binary);
            bin.read((char*)&n_films, sizeof(n_films));
            films = new Film[n_films]{};
            bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
            bin.close();

            films_to_add = new Film[n_films + 1]{};
            for (int i = 0; i < n_films; i++) {
                films_to_add[i] = { films[i].name, films[i].budget, films[i].price, films[i].quantity, films[i].age_limit };
            }
            films_to_add[n_films] = { film->name, film->budget, film->price, film->quantity, film->age_limit };
            n_films++;
            write.open("bin.bin", std::ios::out | std::ios::binary);
            write.write((char*)&n_films, sizeof(n_films));        // записать набор байтов
            write.write((char*)films_to_add, n_films * sizeof(Film));  // записать набор байтов
            write.close();
            delete[] films_to_add;
            break;
        case 2:
            bin.open("bin.bin", std::ios::in | std::ios::binary);
            bin.read((char*)&n_films, sizeof(n_films));
            films = new Film[n_films]{};
            bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
            bin.close();
            cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            for (int i = 0; i < n_films; i++) {
                cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price  << "| " << setw(8) << films[i].quantity <<  "   | " << setw(8) << films[i].age_limit << endl;
            }

            break;
        case 3:
            int s_move, a, b;

            cout << "[1] По совпадению с названием\n[2] По интервалу цены билета\n[3] По совпадению с описанием\n[4] По интервалу количества свободных мест\n[5] По интервалу возрастного ограничения";
            cin >> s_move;
            cout << endl;
            switch (s_move)
            {
            default:
                break;
            case 1:
                cout << "Введите строковый атрибут: ";
                cin >> sub_str;
                bin.open("bin.bin", std::ios::in | std::ios::binary);
                bin.read((char*)&n_films, sizeof(n_films));
                films = new Film[n_films]{};
                bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
                bin.close();
                cout << "Совпадения:" << endl;
                cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                for (int i = 0; i < n_films; i++) {
                    if (films[i].name.find(sub_str) != std::string::npos) {
                        cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price << "| " << setw(8) << films[i].quantity << "   | " << setw(8) << films[i].age_limit << endl;
                    }
                }
                cout << endl;
                break;
            case 2:
                

                cout << "Введите первое значение интервала: ";
                cin >> a;
                cout << "Введите второе значение интервала: ";
                cin >> b;
                bin.open("bin.bin", std::ios::in | std::ios::binary);
                bin.read((char*)&n_films, sizeof(n_films));
                films = new Film[n_films]{};
                bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
                bin.close();
                cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                for (int i = 0; i < n_films; i++) {
                    if ((films[i].price >= a) && (films[i].price <= b)) {
                        cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price << "| " << setw(8) << films[i].quantity << "   | " << setw(8) << films[i].age_limit << endl;
                    }
                }
                break;
            case 3:
                cout << "Введите строковый атрибут: ";
                cin >> sub_str;
                bin.open("bin.bin", std::ios::in | std::ios::binary);
                bin.read((char*)&n_films, sizeof(n_films));
                films = new Film[n_films]{};
                bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
                bin.close();
                cout << "Совпадения:" << endl;
                cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                for (int i = 0; i < n_films; i++) {
                    if (films[i].budget.find(sub_str) != std::string::npos) {
                        cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price << "| " << setw(8) << films[i].quantity << "   | " << setw(8) << films[i].age_limit << endl;
                    }
                }
                cout << endl;
                break;
            case 4:

                cout << "Введите первое значение интервала: ";
                cin >> a;
                cout << "Введите второе значение интервала: ";
                cin >> b;
                bin.open("bin.bin", std::ios::in | std::ios::binary);
                bin.read((char*)&n_films, sizeof(n_films));
                films = new Film[n_films]{};
                bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
                bin.close();
                cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                for (int i = 0; i < n_films; i++) {
                    if ((films[i].quantity >= a) && (films[i].quantity <= b)) {
                        cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price << "| " << setw(8) << films[i].quantity << "   | " << setw(8) << films[i].age_limit << endl;
                    }
                }
                break;
            case 5:

                cout << "Введите первое значение интервала: ";
                cin >> a;
                cout << "Введите второе значение интервала: ";
                cin >> b;
                bin.open("bin.bin", std::ios::in | std::ios::binary);
                bin.read((char*)&n_films, sizeof(n_films));
                films = new Film[n_films]{};
                bin.read((char*)films, n_films * sizeof(Film));  // считать набор байтов
                bin.close();
                cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
                for (int i = 0; i < n_films; i++) {
                    if ((films[i].age_limit >= a) && (films[i].age_limit <= b)) {
                        cout << std::left << setw(20) << films[i].name << "| " << setw(18) << films[i].budget << "| " << setw(8) << films[i].price << "| " << setw(8) << films[i].quantity << "   | " << setw(8) << films[i].age_limit << endl;
                    }
                }
                break;

            }
            break;
        }
    }
    return 0;
}
