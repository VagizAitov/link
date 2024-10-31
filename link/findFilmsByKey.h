#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>


struct Film_linear {
    char name[50];
    char budget[30];
    double price;
    int quantity;
    int age_limit;
};

void findFilmsByKey(std::fstream& read, int& rows_count) {
    int s_move;
    std::cout << "[1] По совпадению с названием\n[2] По интервалу цены билета\n";
    std::cin >> s_move;
    read.open("bin.bin", ios::in | ios::binary);
    string name;
    string sub_str;
    switch (s_move) {
    default:
        break;
    case 1:
        std::cout << "Введите строковый атрибут: ";
        std::cin >> sub_str;
        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));
            name = temp.name;

            std::cout << std::left << setw(20) << "Название " << setw(20) << "| Описание " << setw(10) << "| Цена " << setw(10) << "| Своб.места " << setw(10) << "| Воз.огр" << endl;
            if (name.find(sub_str) != std::string::npos) {
                std::cout << std::left << setw(20) << temp.name << "| " << setw(18) << temp.budget << "| " << setw(8) << temp.price << "| " << setw(8) << temp.quantity << "   | " << setw(8) << temp.age_limit << endl;
            }
        }
        read.close();
        break;
    case 2:
        int a, b;

        std::cout << "Введите первое значение интервала: ";
        std::cin >> a;
        std::cout << "Введите второе значение интервала: ";
        std::cin >> b;


        for (int i = 0; i < rows_count; i++) {
            Film_linear temp{};

            read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));
            if ((temp.price >= a) && (temp.price <= b)) {
                std::cout << temp.name << " " << temp.budget << " " << temp.price << " " << temp.quantity << " " << temp.age_limit << endl;
            }
        }
        read.close();
    }
}