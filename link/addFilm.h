#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

void addFilm(Film_linear film, std::fstream& add, std::fstream& rows, int& rows_count) {
    cout << "¬ведите название фильма: ";
    cin >> film.name;
    cout << "¬ведите бюджет фильма: ";
    cin >> film.budget;
    cout << "¬ведите цену билета: ";
    cin >> film.price;
    cout << "¬ведите количество свободных мест: ";
    cin >> film.quantity;
    cout << "¬ведите возрастное ограничение: ";
    cin >> film.age_limit;
    add.open("bin.bin", ios::out | ios::binary | ios::app);
    add.write((char*)&film, sizeof(Film_linear));
    add.close();
    rows_count++;
    rows.open("rows.bin", ios::out | ios::binary);
    rows.write((char*)&rows_count, sizeof(int));
    rows.close();
}