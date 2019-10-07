#include <iostream>

using namespace std;

struct ShaFaTie
{
    ShaFaTie()
    {
        cout << "哈哈，抢到沙发，笑抚二楼头。" << std::endl;
    }

    ~ShaFaTie()
    {
        cout << "我是一楼，结贴。" << std::endl;
    }
};

struct BanDengTie : public ShaFaTie
{
    BanDengTie()
    {
        cout << "\t" << "[回复]抢到板凳。一楼你好舒服啊！笑看三楼。" << std::endl;
    }

    ~BanDengTie()
    {
        cout << "\t" << "我是二楼，结贴。" << std::endl;
    }
};

struct DibanTie : public BanDengTie
{
    DibanTie()
    {
        cout << "\t\t" << "[回复]三楼怎么啦，席地而坐，凸显不同。" << std::endl;
    }

    ~DibanTie()
    {
        cout <<  "\t\t" << "我是三楼，结贴。" << std::endl;
    }
};

int main()
{
    ShaFaTie l1;
    cout << "==============================" << std::endl;

    BanDengTie l2;
    cout << "==============================" << std::endl;

    DibanTie l3;
    cout << "==============================" << std::endl;

    return 0;
}
