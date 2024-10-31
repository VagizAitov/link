#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

void addFilm(Film_linear film, std::fstream& add, std::fstream& rows, int& rows_count) {
    cout << "������� �������� ������: ";
    cin >> film.name;
    cout << "������� ������ ������: ";
    cin >> film.budget;
    cout << "������� ���� ������: ";
    cin >> film.price;
    cout << "������� ���������� ��������� ����: ";
    cin >> film.quantity;
    cout << "������� ���������� �����������: ";
    cin >> film.age_limit;
    add.open("bin.bin", ios::out | ios::binary | ios::app);
    add.write((char*)&film, sizeof(Film_linear));
    add.close();
    rows_count++;
    rows.open("rows.bin", ios::out | ios::binary);
    rows.write((char*)&rows_count, sizeof(int));
    rows.close();
}