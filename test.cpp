﻿#include "include/Address.h"
#include "include/File.h"
#include "include/FullName.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/lib.h"

int main()
{
    File file;
#if 0
    vector<vector<string>> parsedStrings = file.readCSV("data/students.csv");

    Students students(parsedStrings);
    cout << students.toString() << endl;

    FullName name("Le", "Minh", "Quan");
    cout << name.toString() << endl;
#endif

    RandomFullName fullNameRng;
    RandomAddress addressRng;
    RandomEmail emailRng;

    for (int i = 0; i < 10; i++)
    {
        FullName name = fullNameRng.next();
        cout << name.toString() << endl;
        cout << addressRng.next().toString() << endl;
        cout << emailRng.next(name) << endl;
    }

    return 0;
}