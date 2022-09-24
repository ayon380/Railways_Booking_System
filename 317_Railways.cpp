#include <bits/stdc++.h>
using namespace std;
class trainName
{
public:
    int no;
    string name;
    float ttime;
    string days;
    int dtime, arrtime, stops;
    int sl, a3, a2, a1;
    trainName() {}
};
class passenger
{
public:
    char sex;
    string name;
    string bdate;
};
int isGoing(string s, string from, string to)
{
    int q = 1;
    int pos = s.find("::");
    string str = s.substr(pos + 2);
    int len = str.length();
    int e = 0;
    while (len != 0)
    {
        pos = str.find(",");
        string a = str.substr(0, pos);
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
    return false;
}
int nostaions(string s, string to)
{
    int q = 0;
    int pos = s.find("::");
    string str = s.substr(pos + 2);
    int len = str.length();
    int e = 0;
    while (len != 0)
    {
        pos = str.find(",");
        string a = str.substr(0, pos);
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
int main()
{
    int n = 8;
    // Train List
    // fout<<"fuck youu"<<endl;
    int a;
    while (1)
    {
        cout << "***************  Welcome TO IRCTC  **************" << endl<<endl;
        cout << "Enter 1 to login :";
        cin >> a;
        if (a == 1)
        {
            string user, pass;
            ifstream fin("password.txt");
            fin >> user >> pass;
            fin.close();
            string user1, pass1;
            cout << "Enter your username : ";
            cin >> user1;
            cout << "Enter your password : ";
            cin >> pass1;
            if (user1 == user and pass == pass1)
            {
                cout << "Login Suuccessful";
                break;
            }
            else
            {
                cout << "Error";
            }
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
    train[0].sl = 5;
    train[0].a1 = 9;
    train[0].a2 = 6;
    train[0].a3 = 3;

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

    train[6].no = 12301;
    train[6].name = "RAJDHANI EXPRESS ::HWH,ASN,DHN,PNME,GAYA,DDU,PRYJ,CNB,NDLS,";
    train[6].ttime = 1035;
    train[6].days = "0111111";
    train[6].dtime = 1010;
    train[6].stops = 8;
    train[6].arrtime = 605;
    train[6].sl = 2;
    train[6].a1 = 8;
    train[6].a2 = 5;
    train[6].a3 = 6;

    train[7].no = 12302;
    train[7].name = "RAJDHANI EXPRESS ::NDLS,CNB,PRYJ,DDU,GAYA,PNME,DHN,ASN,HWH,";
    train[7].ttime = 1025;
    train[7].days = "1111101";
    train[7].dtime = 1010;
    train[7].stops = 8;
    train[7].arrtime = 555;
    train[7].sl = 2;
    train[7].a1 = 8;
    train[7].a2 = 5;
    train[7].a3 = 6;
    // train[6].o
    system("CLS");
    cout << endl;
    cout << "*********************** Welcome to INDIAN RAILWAYS **********************" << endl
         << endl;
    cout << "                            Train Route Map" << endl
         << endl;
    cout << "                                                       <-> GDR <-> MAS" << endl;
    cout << "                                                     /" << endl;
    cout << "HWH <-> KGP <-> BBS <-> KUR <-> VZN <-> VSKP <-> BZA " << endl;
    cout << "    \\                                                 \\" << endl;
    cout << "     <-> ASN <-> DHN <-> PNME <-> GAYA <-> DDU         <-> RU <-> KPD -> SMVT" << endl;
    cout << "                                              \\     " << endl;
    cout << "                                               <-> PRYJ <-> CNB <-> NDLS     " << endl
         << endl
         << endl;
    // Main Menu
    cout << "************************ IRCTC Ticket RESERVATION ************************ " << endl
         << endl;
    string from, to;
    while (1)
    {
        cout << "1. Book a Ticket" << endl;
        cout << "2. Cancel Ticket" << endl;
        cout << "3. Change Password" << endl;
        cout << "4. Log Out" << endl;
        int choice;
        cout << "Enter your Choice : ";
        cin >> choice;
        cout << endl
             << endl;
        if (choice == 1)
        {
            cout << "Enter Originating Station  :  ";
            cin >> from;
            cout << "Enter Arriving Station :  ";
            cin >> to;
            int dd, mm, yy;
            cout << "Enter the Date of Travel in the form of DD MM YYYY : ";
            cin >> dd >> mm >> yy;
            for (auto &c : from)
                c = toupper(c);
            for (auto &c : to)
                c = toupper(c);
            cout << endl
                 << "Train No.    Train Name       Departure Time          Arrival Time      SL\t\t3A\t\t2A\t\t1A" << endl
                 << endl;
            bool trainfound = false;
            int dept, arrt;
            string day;
            for (int i = 0; i < n; i++)
            {
                int r = isGoing(train[i].name, from, to);
                if (r > 0 && isRunning(train[i], dd, mm, yy))
                {
                    string str = train[i].name;
                    int pos = str.find("::");
                    str = str.substr(0, pos);
                    trainfound = true;
                    string next = " ";
                    int timeperstation = ceil(train[i].ttime / train[i].stops); // in minutes
                    int no = nostaions(train[i].name, from);
                    int dep = no * timeperstation;
                    dep += train[i].dtime;
                    int arr = r * timeperstation + dep;
                    cout << endl;
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
                    cout.width(8);
                    cout << left << train[i].no;
                    cout.width(25);
                    cout << left << str << " ";
                    cout << setw(2) << right << setfill('0') << (dep / 60) << ":";
                    cout << setw(2) << right<< setfill('0') << (dep % 60) << "             ";
                    cout << setw(2) << right<< setfill('0') << (arr / 60) << ":";
                    cout << setw(2) << right<< setfill('0') << arr % 60 << " ";
                    cout.width(10);
                    cout << setfill(' ') << next << "  " << train[i].sl << "\t\t" << train[i].a3 << "\t\t" << train[i].a2 << "\t\t" << train[i].a1 << endl;
                }
                else
                {
                    continue;
                }
            }
            cout << endl;
            cout << "Enter the Train No you want to book : ";
            int trno, pno;
            cin >> trno;
            cout << "Enter the class you want to book (1A for First CLass , 2A for 2Tier AC , 3A for 3 Tier AC , 4 for Sleeper Class : ";
            string sc;
            cin >> sc;
            cout << "Enter the no of passengers : ";
            cin >> pno;
            passenger p[pno];
            for (int i = 0; i < pno; i++)
            {
                cout << "Enter Passenger Name : ";
                getline(cin >> ws, p[i].name);
                cout << "Enter Sex : ";
                cin >> p[i].sex;
                cout << "Enter Birth Date : ";
                getline(cin >> ws, p[i].bdate);
            }
            cout << "Donee......" << endl
                 << endl;
            system("CLS");
            cout << "            RESERVATION TICKET          " << endl;
            cout << "                                        " << endl;

            for (int i = 0; i < n; i++)
            {
                if (train[i].no == trno)
                {
                    cout.width(30);
                    cout << left << "TRAIN No : " << train[i].no << endl;
                    cout.width(30);
                    cout << left << "TRAIN NAME : " << train[i].name.substr(0, train[i].name.find("::")) << endl;
                    cout.width(30);
                    cout << left << "ORIGINATING STATION : " << from << endl;
                    cout.width(30);
                    cout << left << "DESTINATION STATION : " << to << endl;
                    cout.width(30);
                    cout << left << "DEPARTURE TIME : " << (dept / 60) << ":" << (dept % 60) << endl;
                    cout.width(30);
                    cout << left << "ARRIVAL TIME : " << (arrt / 60) << ":" << arrt % 60 << " " << day << endl;
                    cout.width(30);
                    cout << left << "CLASS : " << sc << endl;
                    cout.width(30);
                    cout << left << "DATE : " << dd << "/" << mm << "/" << yy << endl;
                    cout.width(30);
                    string coach;
                    int seat;
                    if (sc == "1A")
                    {
                        coach = "H" + to_string(random(2));
                        seat = random(22);
                    }
                    else if (sc == "2A")
                    {
                        coach = "A" + to_string(random(3));
                        seat = random(52);
                    }
                    else if (sc == "3A")
                    {
                        coach = "B" + to_string(random(10));
                        seat = random(72);
                    }
                    else if (sc == "SL")
                    {
                        coach = "S" + to_string(random(5));
                        seat = random(72);
                    }
                    else
                    {
                        coach = "GS" + to_string(random(2));
                        seat = random(106);
                    }
                    cout << left << "COACH NO - SEAT : " << coach << "-" << seat << endl;
                    for (int j = 0; j < pno; j++)
                    {
                        cout.width(30);
                        cout << left << "PASSENGER NAME " << j + 1 << " : " << p[j].name << "  " << p[j].sex << "  " << p[j].bdate << endl
                             << endl;
                    }
                    cout << "Wishing You a Happy and Safe Journey...." << endl;
                    cout << "Enter 1 to print the ticket , 2 to cancel :";
                    int pp;
                    cin >> pp;
                    if (pp == 1)
                    {
                        ofstream fout("Ticket.txt");
                        fout.width(30);
                        fout << "            RESERVATION TICKET          " << endl;
                        fout << "                                        " << endl;
                        fout << left << "TRAIN No : " << train[i].no << endl;
                        fout.width(30);
                        fout << left << "TRAIN NAME : " << train[i].name.substr(0, train[i].name.find("::")) << endl;
                        fout.width(30);
                        fout << left << "ORIGINATING STATION : " << from << endl;
                        fout.width(30);
                        fout << left << "DESTINATION STATION : " << to << endl;
                        fout.width(30);
                        fout << left << "DEPARTURE TIME : " << (dept / 60) << ":" << (dept % 60) << endl;
                        fout.width(30);
                        fout << left << "ARRIVAL TIME : " << (arrt / 60) << ":" << arrt % 60 << " " << day << endl;
                        fout.width(30);
                        fout << left << "CLASS : " << sc << endl;
                        fout.width(30);
                        fout << left << "DATE : " << dd << "/" << mm << "/" << yy << endl;
                        fout.width(30);
                        fout << left << "COACH NO - SEAT : " << coach << "-" << seat << endl;
                        for (int j = 0; j < pno; j++)
                        {
                            fout.width(30);
                            fout << left << "PASSENGER NAME " << j + 1 << " : " << p[j].name << "  " << p[j].sex << "  " << p[j].bdate << endl
                                 << endl;
                        }
                        fout << "Wishing You a Happy and Safe Journey...." << endl;
                        fout.close();
                    }
                    cout << endl
                         << endl
                         << "Ticket Printed Succssfully !!!!" << endl;
                }
            }
            cout << "Thank you for booking with us !!!!" << endl
                 << endl;
            if (!trainfound)
                cout << "No Trains Found :)" << endl
                     << endl;
            ;
        }
        else if(choice == 2)
        {
            ofstream fout("ticket.txt");
            fout.clear();
            cout<<"Ticket Cancelled Successfully !!!!"<<endl<<endl;
        }
        else if (choice == 3)
        {

            ofstream fout("password.txt");
            string user, pass;
            cout << "Enter new username : ";
            cin >> user;
            cout << "Enter new password : ";
            cin >> pass;
            fout << user << "\t" << pass;
            fout.close();
            cout << endl
                 << endl;
        }
        else if (choice == 4)
        {
            cout << "Logged Off Successfully !!" << endl;
            return 0;
        }
    }
    return 0;
}
