#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <windows.h>
void animate()
{
    char chars[] = {'-', '\\', '|', '/'};
    unsigned int i;
    for (i = 0; i < 15; ++i)
    {
        printf("%c\r", chars[i % sizeof(chars)]);

        fflush(stdout);
        Sleep(100);
    }
}
class trainName
{
public:
    int no;
    std::string name;
    float ttime;
    std::string days;
    int dtime, arrtime, stops;
    int sl, a3, a2, a1;
    int slp, a3p, a2p, a1p;
    // trainName() {}
};
class passenger
{
public:
    char sex;
    std::string name;
    int age;
};
int isGoing(std::string s, std::string from, std::string to)// checking stations
{
    int q = 1;
    int pos = s.find("::");
    std::string str = s.substr(pos + 2);
    int len = str.length();
    int e = 0;
    while (len != 0)
    {
        pos = str.find(",");
        std::string a = str.substr(0, pos);
        if (a == from)
        {
            e = 1;
            q = 0;
            // continue;
        }
        if (a == to and e == 1)
        {
            return q;
        }
        q++;
        str = str.substr(pos + 1);
        len = str.length();
    }
    return 0;
}
int nostaions(std::string s, std::string to)
{
    int q = 0;
    int pos = s.find("::");
    std::string str = s.substr(pos + 2);
    int len = str.length();
    int e = 0;
    while (len != 0)
    {
        pos = str.find(",");
        std::string a = str.substr(0, pos);
        if (a == to)
        {
            return q;
        }
        q++;
        str = str.substr(pos + 1);
        len = str.length();
    }
    return false;
}
int dayofweek(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 +
            y / 400 + t[m - 1] + d) %
           7;
}
bool isRunning(trainName t, int dd, int mm, int yy)
{
    int q = dayofweek(dd, mm, yy);
    if (t.days[q] == '1')
    {
        return true;
    }
    return false;
}
int random(int range)
{
    srand((unsigned)time(NULL));
    return (rand() % range) + 1;
}
void board1()
{
    std::cout << std::endl;
    std::cout << "*********************** Welcome to INDIAN RAILWAYS **********************" << std::endl
              << std::endl;
    std::cout << "                            Train Route Map" << std::endl
              << std::endl;
    std::cout << "                                                       <-> GDR <-> MAS" << std::endl;
    std::cout << "                                                     /" << std::endl;
    std::cout << "HWH <-> KGP <-> BBS <-> KUR <-> VZN <-> VSKP <-> BZA " << std::endl;
    std::cout << "    \\                                                 \\" << std::endl;
    std::cout << "     <-> ASN <-> DHN <-> PNME <-> GAYA <-> DDU         <-> RU <-> KPD -> SMVT" << std::endl;
    std::cout << "                                              \\     " << std::endl;
    std::cout << "                                               <-> PRYJ <-> CNB <-> NDLS     " << std::endl
              << std::endl
              << std::endl;
    // Main Menu
    std::cout << "************************ IRCTC Ticket RESERVATION ************************ " << std::endl
              << std::endl;
}
bool digit_check(std::string n, int d)
{
    int i;
    int r = 0;
    int q = n.length();
    for (i = 0; i < q; i++)
    {
        if ((n[i] >= '0' && n[i] <= '9') and q == d)
        {
            r = 1;
        }
        else
        {
            r = 0;
        }
    }
    if (r == 1)
    {
        return true;
    }
    return false;
}
void payment(int price)
{
    system("cls");
    std::cout << "************************** Payment Gateway ******************************" << std::endl
              << std::endl;
    std::cout << "Total Amount to be paid: " << price << std::endl;
    std::cout << "Please enter your card details" << std::endl;
    while (1)
    {
        std::cout << "Card Number: ";
        std::string card;
        std::cin >> card;
        if (!digit_check(card, 16))
        {
            std::cout << "Invalid Card Number" << std::endl;
            continue;
        }
        std::cout << "Expiry Date: MMYY  : ";
        std::string exp;
        std::cin >> exp;
        if (!digit_check(exp, 4))
        {
            std::cout << "Invalid Card Number" << std::endl;
            continue;
        }
        std::cout << "CVV: ";
        std::string cvv;
        std::cin >> cvv;
        if (!digit_check(cvv, 3))
        {
            std::cout << "Invalid Card Number" << std::endl;

            continue;
        }
        break;
    }
    system("cls");
    std::cout << "Please wait, we are Proccessing your request to the Concerned bank" << std::endl;
    animate();
    animate();
    system("cls");
    std::cout << "         RAZOR PAY\n"
              << std::endl;
    while (1)
    {
        std::cout << "Enter your 6-digit OTP: ";
        std::string otp;
        std::cin >> otp;
        if (!digit_check(otp, 6))
        {
            std::cout << "Invalid OTP" << std::endl;
            continue;
        }
        break;
    }
    system("cls");
    std::cout << "Please wait, we are Proccessing your request ..." << std::endl;
    animate();
    animate();
    system("cls");
    std::cout << "Payment Successful" << std::endl;
    Sleep(1000);
}
int main()
{
    const int n = 10;
    // system("color 0");
    std::string a;
    while (1)
    {
        std::cout << "***************  Welcome TO IRCTC  **************" << std::endl;
        std::cout << "\n\nEnter 1 to login :";
        std::cin >> a;
        if (a == "1")
        {
            std::string user, pass;
            std::ifstream fin("password.txt");
            fin >> user >> pass;
            fin.close();
            std::string user1, pass1;
            std::cout << "Enter your username : ";
            std::cin >> user1;
            std::cout << "Enter your password : ";
            std::cin >> pass1;
            if (user1 == user and pass == pass1)
            {
                std::cout << "Login Suuccessful";
                break;
            }
            else
            {
                system("CLS");
                std::cout << "***************  Welcome TO IRCTC  **************" << std::endl;
                std::cout << "\nError, Incorrect Username or Password\n\n";
                animate();
                system("CLS");
            }
        }
        else
        {
            system("CLS");
            std::cout << "***************  Welcome TO IRCTC  **************" << std::endl;
            std::cout << "\nInvalid Input , Try Again  \n"
                      << std::endl;
            animate();
            system("CLS");
        }
    }

    trainName train[n];
    train[0].no = 12245;
    train[0].name = "HWH-SMVT DURONTO EXP ::HWH,BBS,VZN,BZA,RU,SMVT,";
    train[0].ttime = 29 * 60;
    train[0].days = "1101110";
    train[0].dtime = 710;
    train[0].arrtime = 950;
    train[0].stops = 5;
    train[0].sl = 13;
    train[0].a1 = 9;
    train[0].a2 = 6;
    train[0].a3 = 9;
    train[0].slp = 200;
    train[0].a1p = 400;
    train[0].a2p = 600;
    train[0].a3p = 900;

    train[1].no = 12246;
    train[1].name = "SMVT-HWH DURONTO EXP ::SMVT,RU,BZA,VZN,BBS,HWH,";
    train[1].ttime = 1770;
    train[1].days = "1110110";
    train[1].dtime = 680;
    train[1].arrtime = 1110;
    train[1].stops = 5;
    train[1].sl = 9;
    train[1].a1 = 3;
    train[1].a2 = 6;
    train[1].a3 = 6;
    train[1].slp = 200;
    train[1].a1p = 400;
    train[1].a2p = 600;
    train[1].a3p = 900;

    train[2].no = 12839;
    train[2].name = "HWH-MAS MAIL EXP ::HWH,KGP,BBS,KUR,VZN,VSKP,BZA,GDR,MAS,";
    train[2].ttime = 1620;
    train[2].days = "1111111";
    train[2].dtime = 1435;
    train[2].arrtime = 180;
    train[2].stops = 8;
    train[2].sl = 9;
    train[2].a1 = 4;
    train[2].a2 = 3;
    train[2].a3 = 2;
    train[2].slp = 77;
    train[2].a1p = 203;
    train[2].a2p = 292;
    train[2].a3p = 496;

    train[3].no = 12840;
    train[3].name = "MAS-HWH MAIL EXP ::MAS,GDR,BZA,VSKP,VZN,KUR,BBS,KGP,HWH,";
    train[3].ttime = 1665;
    train[3].days = "1111111";
    train[3].dtime = 1145;
    train[3].arrtime = 1380;
    train[3].stops = 8;
    train[3].sl = 6;
    train[3].a1 = 2;
    train[3].a3 = 4;
    train[3].a2 = 8;
    train[3].slp = 77;
    train[3].a1p = 203;
    train[3].a2p = 292;
    train[3].a3p = 496;

    train[4].no = 12863;
    train[4].name = "HWH SMVB EXP ::HWH,KGP,BBS,KUR,VZN,VSKP,BZA,RU,KPD,SMVT,";
    train[4].ttime = 1908;
    train[4].days = "1111111";
    train[4].dtime = 1380;
    train[4].arrtime = 405;
    train[4].stops = 9;
    train[4].sl = 9;
    train[4].a1 = 6;
    train[4].a2 = 5;
    train[4].a3 = 2;
    train[4].slp = 77;
    train[4].a1p = 203;
    train[4].a2p = 292;
    train[4].a3p = 496;

    train[5].no = 12864;
    train[5].name = "SMVT-HWH EXP ::SMVT,KPD,RU,BZA,VSKP,VZN,KUR,BBS,KGP,HWH,";
    train[5].ttime = 2000;
    train[5].days = "1111111";
    train[5].dtime = 635;
    train[5].stops = 9;
    train[5].arrtime = 1195;
    train[5].sl = 2;
    train[5].a1 = 8;
    train[5].a2 = 5;
    train[5].a3 = 6;
    train[5].slp = 77;
    train[5].a1p = 203;
    train[5].a2p = 292;
    train[5].a3p = 496;

    train[6].no = 12301;
    train[6].name = "RAJDHANI EXPRESS ::HWH,ASN,DHN,PNME,GAYA,DDU,PRYJ,CNB,NDLS,";
    train[6].ttime = 1035;
    train[6].days = "0111111";
    train[6].dtime = 1010;
    train[6].stops = 8;
    train[6].arrtime = 605;
    train[6].sl = 0;
    train[6].a1 = 8;
    train[6].a2 = 5;
    train[6].a3 = 6;
    train[6].slp = 77;
    train[6].a1p = 308;
    train[6].a2p = 420;
    train[6].a3p = 673;

    train[7].no = 12302;
    train[7].name = "RAJDHANI EXPRESS ::NDLS,CNB,PRYJ,DDU,GAYA,PNME,DHN,ASN,HWH,";
    train[7].ttime = 1025;
    train[7].days = "1111101";
    train[7].dtime = 1010;
    train[7].stops = 8;
    train[7].arrtime = 555;
    train[7].sl = 0;
    train[7].a1 = 8;
    train[7].a2 = 5;
    train[7].a3 = 6;
    train[7].slp = 77;
    train[7].a1p = 308;
    train[7].a2p = 420;
    train[7].a3p = 673;

    train[8].no = 12259;
    train[8].name = "BKN DURONTO EXPRESS ::HWH,DHN,DDU,PRYJ,CNB,NDLS,";
    train[8].ttime = 18 * 60;
    train[8].days = "1011001";
    train[8].dtime = 17 * 60;
    train[8].stops = 5;
    train[8].arrtime = 11 * 60;
    train[8].sl = 0;
    train[8].a1 = 8;
    train[8].a2 = 5;
    train[8].a3 = 6;
    train[8].slp = 77;
    train[8].a1p = 2785 / 6;
    train[8].a2p = 3805 / 6;
    train[8].a3p = 4760 / 6;

    train[9].no = 12260;
    train[9].name = "HWH DURONTO EXPRESS ::NDLS,CNB,PRYJ,DDU,DHN,HWH,";
    train[9].ttime = 17 * 60 + 30;
    train[9].days = "1101100";
    train[9].dtime = 19 * 60 + 45;
    train[9].stops = 5;
    train[9].arrtime = 13 * 60 + 15;
    train[9].sl = 0;
    train[9].a1 = 8;
    train[9].a2 = 5;
    train[9].a3 = 6;
    train[9].slp = 77;
    train[9].a1p = 2950 / 6;
    train[9].a2p = 4080 / 6;
    train[9].a3p = 5070 / 6;
    // train[6].o
    system("CLS");
    board1();
    std::string from, to;
    while (1)
    {
        std::cout << "1. Book a Ticket" << std::endl;
        std::cout << "2. Cancel Ticket" << std::endl;
        std::cout << "3. Change Password" << std::endl;
        std::cout << "4. Log Out" << std::endl;
        std::string ch;
        int choice;
        try
        {
            std::cout << "Enter your Choice : ";
            std::cin >> ch;
            choice = stoi(ch);
        }
        catch (...)
        {
            system("CLS");
            board1();
            continue;
        }
        // if(choice > 4  )
        // {
        //     system("CLS");
        //     board1();
        //     continue;
        // }
        std::cout << std::endl
                  << std::endl;
        if (choice == 1)
        {
            std::cout << "Enter Originating Station  :  ";
            std::cin >> from;
            std::cout << "\nEnter Arriving Station :  ";
            std::cin >> to;
            int dd, mm, yy, st;
            std::cout << "\nEnter the Date of Travel in the form of DD MM YYYY : ";
            std::cin >> dd >> mm >> yy;
            for (auto &c : from)
                c = toupper(c);
            for (auto &c : to)
                c = toupper(c);
            std::cout << std::endl
                      << "Train No.    Train Name       Departure Time          Arrival Time     \t\t SL\t\t3A\t\t2A\t\t1A" << std::endl
                      << std::endl;
            bool trainfound = false;
            int dept, arrt;
            int count = 0;
            std::string day;
            for (int i = 0; i < n; i++)
            {
                int r = isGoing(train[i].name, from, to);
                if (r > 0 && isRunning(train[i], dd, mm, yy))
                {
                    count++;
                    std::string str = train[i].name;
                    int pos = str.find("::");
                    str = str.substr(0, pos);
                    trainfound = true;
                    std::string next = " ";
                    int timeperstation = ceil(train[i].ttime / train[i].stops); // in minutes
                    int no = nostaions(train[i].name, from);
                    st = r;
                    int dep = no * timeperstation;
                    dep += train[i].dtime;
                    int arr = r * timeperstation + dep;
                    std::cout << std::endl;
                    if (dep >= 1440)
                    {
                        dep %= 1440;
                    }

                    if (arr >= 1440)
                    {
                        arr %= 1440;
                        next = "Next Day";
                    }
                    dept = dep;
                    arrt = arr;
                    if (dep % 60 > arr % 60)
                    {
                        next = "Next Day";
                    }
                    day = next;
                    std::cout.width(8);
                    std::cout << std::left << train[i].no;
                    std::cout.width(25);
                    std::cout << std::left << str << " ";
                    std::cout << std::setw(2) << std::right << std::setfill('0') << (dep / 60) << ":";
                    std::cout << std::setw(2) << std::left << std::setfill('0') << (dep % 60) << "             ";
                    std::cout << std::setw(2) << std::right << std::setfill('0') << (arr / 60) << ":";
                    std::cout << std::setw(2) << std::right << std::setfill('0') << arr % 60 << " ";
                    std::cout.width(10);
                    std::cout << std::setfill(' ') << next << "\t\t  " << train[i].sl << "\t\t" << train[i].a3 << "\t\t" << train[i].a2 << "\t\t" << train[i].a1 << std::endl;
                }
                else
                {
                    continue;
                }
            }
            if (count == 0)
            {
                system("CLS");

                std::cout << "No Trains Found" << std::endl;
                Sleep(1000);
                system("CLS");
                board1();

                continue;
            }
            std::cout << std::endl;
            std::cout << "Enter the Train No you want to book : ";
            int trno, pno;
            std::cin >> trno;
            for (int i = 0; i < n; i++)
            {
                int r = isGoing(train[i].name, from, to);
                if (r > 0 && train[i].no == trno)
                {
                    count++;
                    std::string str = train[i].name;
                    int pos = str.find("::");
                    str = str.substr(0, pos);
                    trainfound = true;
                    std::string next = " ";
                    int timeperstation = ceil(train[i].ttime / train[i].stops); // in minutes
                    int no = nostaions(train[i].name, from);
                    st = r;
                    int dep = no * timeperstation;
                    dep += train[i].dtime;
                    int arr = r * timeperstation + dep;
                    std::cout << std::endl;
                    if (dep >= 1440)
                    {
                        dep %= 1440;
                    }

                    if (arr >= 1440)
                    {
                        arr %= 1440;
                        next = "Next Day";
                    }
                    dept = dep;
                    arrt = arr;
                    if (dep % 60 > arr % 60)
                    {
                        next = "Next Day";
                    }
                    day = next;
                }
            }
            std::string sc;
            while (1)
            {
                std::cout << "\nEnter the class you want to book (1A for First CLass , 2A for 2Tier AC , 3A for 3 Tier AC , 4 for Sleeper Class : ";
                std::cin >> sc;
                if (sc == "1A" || sc == "2A" || sc == "3A" || sc == "SL")
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid Class" << std::endl;
                }
            }

            std::cout << "\nEnter the no of passengers : ";
            std::cin >> pno;
            std::vector<passenger> p;
            for (int i = 0; i < pno; i++)
            {
                passenger q;
                std::string s;
                std::cout << "Enter Passenger Name : ";
                std::getline(std::cin >> std::ws, s);
                q.name = s;
                std::cout << "Enter Sex : ";
                std::cin >> q.sex;
                std::cout << "Enter your Age : ";
                std::cin>>q.age;
                p.push_back(q);
            }
            std::cout << "Donee......" << std::endl
                      << std::endl;

            system("CLS");
            std::cout << "\n\n Wait a moment while we are processing your request....\n\n";
            int price = 0;
            // std::cout << price << " " << st << std::endl;
            for (int i = 0; i < n; i++)
            {
                if (train[i].no == trno)
                {
                    std::string coach;
                    int seat, capa;
                    st += 1;
                    std::vector<int> seats;
                    for (int j = 0; j < pno; j++)
                    {

                        if (sc == "1A")
                        {
                            price = (train[i].a3p * st);
                            coach = "H" + std::to_string(random(2));
                            seat = random(22);
                            capa = 22;
                        }
                        else if (sc == "2A")
                        {
                            price = (train[i].a2p * st);
                            coach = "A" + std::to_string(random(3));
                            seat = random(52);
                            capa = 52;
                        }
                        else if (sc == "3A")
                        {
                            price = (train[i].a1p * st);
                            coach = "B" + std::to_string(random(10));
                            seat = random(72);
                            capa = 72;
                        }
                        else if (sc == "SL")
                        {
                            price = (train[i].slp * st);
                            coach = "S" + std::to_string(random(5));
                            seat = random(80);
                            capa = 80;
                        }
                        // std::cout << price << " " << st << std::endl;
                        animate();
                        seats.push_back(seat);
                    }
                    price *= pno;
                    payment(price);
                    system("CLS");
                    std::cout << "Wait a bit..." << std::endl;
                    animate();
                    system("CLS");
                    std::cout << "            RESERVATION TICKET          " << std::endl;
                    std::cout << "                                        " << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "TRAIN No : " << train[i].no << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "TRAIN NAME : " << train[i].name.substr(0, train[i].name.find("::")) << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "ORIGINATING STATION : " << from << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "DESTINATION STATION : " << to << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "DEPARTURE TIME : " << (dept / 60) << ":" << (dept % 60) << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "ARRIVAL TIME : " << (arrt / 60) << ":" << arrt % 60 << " " << day << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "CLASS : " << sc << std::endl;
                    std::cout.width(30);
                    std::cout << std::left << "DATE : " << dd << "/" << mm << "/" << yy << std::endl;
                    std::cout.width(30);

                    for (int j = 0; j < pno; j++)
                    {
                        std::cout.width(30);
                        std::cout << std::left << "PASSENGER NAME " << j + 1 << " : " << p[j].name << "  " << p[j].sex << "  "<<p[j].age<< "  " << coach << "-" << seats[j] << std::endl;
                    }
                    std::cout.width(30);
                    std::cout << std::left << "TOTAL AMOUNT : "
                              << "INR " << price << std::endl;
                    std::cout.width(30);
                    std::cout << "Wishing You a Happy and Safe Journey....\n"
                              << std::endl;
                    std::cout << "Enter 1 to print the ticket , 2 to cancel :";
                    int pp;
                    std::cin >> pp;
                    if (pp == 1)
                    {
                        std::ofstream fout("Ticket.txt");
                        fout.width(30);
                        fout << "            RESERVATION TICKET          " << std::endl;
                        fout << "                                        " << std::endl;
                        fout << std::left << "TRAIN No : " << train[i].no << std::endl;
                        fout.width(30);
                        fout << std::left << "TRAIN NAME : " << train[i].name.substr(0, train[i].name.find("::")) << std::endl;
                        fout.width(30);
                        fout << std::left << "ORIGINATING STATION : " << from << std::endl;
                        fout.width(30);
                        fout << std::left << "DESTINATION STATION : " << to << std::endl;
                        fout.width(30);
                        fout << std::left << "DEPARTURE TIME : " << (dept / 60) << ":" << (dept % 60) << std::endl;
                        fout.width(30);
                        fout << std::left << "ARRIVAL TIME : " << (arrt / 60) << ":" << arrt % 60 << " " << day << std::endl;
                        fout.width(30);
                        fout << std::left << "CLASS : " << sc << std::endl;
                        fout.width(30);
                        fout << std::left << "DATE : " << dd << "/" << mm << "/" << yy << std::endl;
                        fout.width(30);
                        fout << std::left << "COACH NO - SEAT : " << coach << "-" << seat << std::endl;
                        for (int j = 0; j < pno; j++)
                        {
                            fout.width(30);
                            fout << std::left << "PASSENGER NAME " << j + 1 << " : " << p[j].name << "  " << p[j].sex << "  " << p[j].age << "  " << coach << "-" << seats[j] << std::endl
                                 << std::endl;
                        }
                        fout.width(30);
                        fout << std::left << "TOTAL AMOUNT : "
                             << "INR " << price << std::endl;
                        fout.width(30);
                        fout << "\nWishing You a Happy and Safe Journey....\n"
                             << std::endl;
                        fout.close();

                        std::cout << std::endl
                                  << std::endl
                                  << "Ticket Printed Succssfully !!!!" << std::endl;
                    }
                }
            }
            std::cout << "Thank you for booking with us !!!!" << std::endl
                      << std::endl;
            if (!trainfound)
                std::cout << "No Trains Found :)" << std::endl
                          << std::endl;
            ;
        }
        else if (choice == 2)
        {
            std::ofstream fout("ticket.txt");
            fout.clear();
            std::cout << "Ticket Cancelled Successfully !!!!" << std::endl
                      << std::endl;
        }
        else if (choice == 3)
        {

            std::ofstream fout("password.txt");
            std::string user, pass;
            std::cout << "Enter new username : ";
            std::cin >> user;
            std::cout << "Enter new password : ";
            std::cin >> pass;
            fout << user << "\t" << pass;
            fout.close();
            std::cout << std::endl
                      << std::endl;
        }
        else if (choice == 4)
        {
            std::cout << "Logged Off Successfully !!" << std::endl;
            return 0;
        }
        else
        {
            system("cls");
            board1();
        }
    }
    return 0;
}
