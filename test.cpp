﻿#include "include/lib.h"
#include "include/File.h"
#include "include/Random.h"
#include "include/Student.h"
#include "include/RandomDOB.h"
#include "include/RandomTelephone.h"
#include "include/RandomAddress.h"

int main()
{
    RandomAddress rng;
    Address add = rng.next();
    cout << add.toString() << endl;
    return 0;
}