#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

void readFilms(std::fstream& read, int& rows_count) {
    read.open("bin.bin", ios::in | ios::binary);
    for (int i = 0; i < rows_count; i++) {
        Film_linear temp{};
        read.read(reinterpret_cast<char*>(&temp), sizeof(Film_linear));
        cout << temp.name << " " << temp.budget << " " << temp.price << " " << temp.quantity << " " << temp.age_limit << endl;
    }
    cout << " 123";
    read.close();
}
