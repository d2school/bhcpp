#include <cstdio>  // C-style-std-IO
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void testCStyleFormatIO()
{
    char c = '$';
    printf("c = %c\n", c);

    char name[10]; // ���9����ĸ��+1 ������ '\0'
    int age;

    printf("please input your name: ");
    scanf("%9s", name);

    printf("please input your age: ");
    scanf("%d", &age);

    printf("hello %s, you are %d", name, age);

    printf("\nc = %c\n", c);
}

void testCPPInputSetW()
{
    string name;
    int age;

    cout << "please input your name: ";
    cin >> setw(80) >> name;

    if (name.length() > 9)
    {
        cerr << "bad input" << endl;
        return;
    }

    cout << "please input your age: ";
    cin >> age;

    cout << "hello " << name << ", you are " << age << endl;
}

void testCPPInputSkipWS()
{
    int i,j;
    cin >> i >> j;
    cout << i << ',' << j << endl;
}


void testCPPInputNoSkipWS()
{
    int i, j;
    char c;

    cin >> noskipws >> i >> c >> j;
    cin >> skipws;

    cout << i << ',' << c << ',' << j << endl;
}

void testOutputSetWAndFill()
{
    printf("%d,%4d,%04d\n", 11, 12, 13);

    cout << 11 << ',' << setw(4) << 12 << ',' << setw(4) << setfill('0') << 13 << ','
            << setw(4) << setfill('#') << 14 << endl;
}

void testOutputPrecision()
{
    double pi = 3.14159; // C - presition 5, c++ - 6

    printf("%.2f\n", pi); // 3.14
    printf("%.4f\n", pi); // 3.1416
    printf("%.6f\n", pi); // 3.141590


    cout << setprecision(3) << pi << '\n';
    cout << setprecision(5) << pi << '\n';
    cout << setprecision(7) << pi << '\n';
}

// ����C++��ʮ���ƣ�ʮ�����ƣ��˽����������
void testCPPOutputDecHexOct()
{
    int v = 2023;

    cout << dec << v << endl;
    cout << hex << v << endl;
    cout << oct << v << endl;

    cout << dec;
    cout << 100 << endl;
}

void testCPPOutputBoolAlpha()
{
    cout << true << ',' << false << endl; // 1,0

    cout << boolalpha << true << ',' << false << endl; // true,false
    cout << noboolalpha << true << ',' << false << endl;
}

void testCPPQuoted()
{
    string name;
    int age;

    cout << "please input your name and age: "; //�������: Tom 5 �� "Peppa Pig" 8
    cin >> quoted(name) >> age;

    cout << "hello " << name << ", you are " << age << endl;
    cout << "hello " << quoted(name) << ", you are " << age << endl;
}

int main()
{
    testCStyleFormatIO();
    //testCPPInputSetW();
    //testCPPInputSkipWS();
    //testCPPInputNoSkipWS();
    //testOutputSetWAndFill();
    //testOutputPrecision();
    //testCPPOutputDecHexOct();
    //testCPPOutputBoolAlpha();
    //testCPPQuoted();
}
