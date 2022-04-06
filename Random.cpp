#include "include/Random.h"
#include "include/DOB.h"
#include "include/Address.h"

/**
 * @brief Khởi tạo hạt giống thời gian
 */
Random::Random()
{
     srand(time(NULL));
}

/**
 * @brief Tạo ra một số ngẫu nhiên
 *
 * @return Số vừa tạo
 */
int Random::next()
{
     int num = rand();
     return num;
}

/**
 * @brief Tạo ra một số ngẫu nhiên trong đoạn [min, max]
 *
 * @param min cận dưới
 * @param max cận trên
 * @return Số vừa tạo
 */
int Random::next(int min, int max)
{
     int num = rand() % (max - min + 1) + min;
     return num;
}

/**
 * @brief Tạo một số ngẫu nhiên trong nửa khoảng [0, ceiling)
 *
 * @param ceiling khoảng tạo số ngẫu nhiên mong muốn
 * @return Số vừa tạo
 */
int Random::next(int ceiling)
{
     int num = rand() % ceiling;
     return num;
}

string RandomTelephone()
{
     Random rng;
     stringstream builder;
     builder << "09";
     for (int i = 0; i < 7; i++)
     {
          int x = rng.next(10);
          builder << x;
          if (i == 1 || i == 4)
          {
               builder << "-";
          }
     }
     string result = builder.str();
     return result;
}

Date RandomDOB::next()
{
     Date dob;
     int year = _rng.next(1905, 2022);
     int month = _rng.next(1, 12);

     dob.setMonth(month);
     dob.setYear(year);

     int dayInMonth = dob.dateInMonth();

     int day = _rng.next(1, dayInMonth);

     dob.setDay(day);

     return dob;
}

string RandomAddress::randomNumber()
{
     stringstream builder;

     int s1 = _rng.next(1, 50);
     int s2 = _rng.next(10, 40);

     builder << s1 << "/" << s2;

     string result = builder.str();

     return result;
}

RandomAddress::RandomAddress()
{
     _streets = {"Binh Hung Hoa", "Nam Ky Khoi Nghia", "Nguyen Van Cu", "Ton Duc Thang",
                 "Pham Ngoc Thach"};
     _wards = {
         "Ward 2",
         "Ward 3",
         "Son Ky Ward",
         "Tan Son Nhi Ward",
         "Da Kao Ward"};

     _districts = {"District 1", "District 2", "Tan Binh District", "Binh Thanh District", "Binh Tan District"};
}

Address RandomAddress::next()
{
     int temp1 = _rng.next(_streets.size());
     string street = _streets[temp1];

     int temp2 = _rng.next(_wards.size());
     string ward = _wards[temp2];

     int temp3 = _rng.next(_districts.size());
     string district = _districts[temp3];

     string number = this->randomNumber();

     Address add(number, street, ward, district, "Ho Chi Minh city");

     return add;
}
