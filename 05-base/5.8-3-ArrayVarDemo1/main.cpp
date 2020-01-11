#include <iostream>

using namespace std;

//动态分配数组：
void demo_1()
{
    cout << "说明：录入若干个成绩，程序将找出其中第一个最高分" << endl;
    cout << "请输入成绩个数：";
   
    int score_count;
    cin >> score_count;
    
    if (score_count <= 0)
    {
        return;
    }
    
    unsigned int* scores = new unsigned int[score_count];
    
    cout << "请录入" << score_count << "个成绩(正整数)，" << endl;
    
    unsigned int top_score = 0;
    
    for (int i=0; i<score_count; ++i)
    {
        cout << "请录入第" << i+1 << "个成绩：";
        cin >> scores[i];
        
        if (scores[i] > top_score)
        {
            top_score = scores[i]; //取到当前最大的成绩
        }
    }
    
    //显示：
    cout << "您录入的成绩是：";
    for (int i=0; i<score_count; ++i)
    {
        cout << *(scores + i) << ", ";
    }
    
    cout << "其中最高分是：" << top_score << endl;
    
    cout << "下面，程序将输出" << score_count << "个元素的地址：" << endl;
    system("pause");
    for (int i=0; i<score_count; ++i)
    {
        cout << "第" << i << "个元素的地址：" << scores + i << endl;
    }
    
    delete [] scores; //别忘了
}

//栈数组
void demo_2()
{
    int cost[7]; 
    
    cout << "说明：请输入您最近7天来的每日花销（单位：元，不要录入小数）" << endl
        << "程序将计算出您一周来的每日平均花销是多少。" << endl;
    
    int total = 0;
    
    for (int i=0; i<7; ++i)
    {
        cout << "第" << i+1 << "天：";
        cin >> cost[i];
        
        total += cost[i];
    }
    
    //显示:
    cout << "您最近7天的每日花销是：";
    for (int i=0; i<7; ++i)
    {
        cout << cost[i] << "元, ";
    }
    
    int average_cost = total / 7;
    cout << "平均：" <<  average_cost << "元。" << endl;
    
    if (average_cost >= 1000)
    {
        cout << "你丫的也太奢侈了吧 :}" << endl;
    }
    
    cout << "下面，程序输出7个元素的地址：" << endl;
    system("pause");
    for (int i=0; i<7; ++i)
    {
        cout << "元素" << i << "，地址。方法一：" << &(cost[i])
            << "\t方法二：" << cost + i << endl;
    }
}

//二维数组
void demo_3()
{
    int cost[7][3];
    
    cout << "说明：请输入您最近7天来，每天三餐的花销" << endl
        << "程序将给出评价（仅供参考）" << endl;
        
    char* titles [3] = 
    {
        "早餐", "午餐", "晚餐",
    };
    
    for (int i=0; i<7; ++i)
    {
        cout << "第" << i+1 << "天:" << endl;
        
        for (int j=0; j<3; ++j)
        {
            cout << titles[j] << "花销：";
            cin >> cost[i][j]; //cin >> *(*(cost + i) + j);
        }
    }
    
    int total[3]; //三餐分开小计
    int total_all = 0; //全部餐次累加

    //外怯循环为改为餐次
    for (int j=0; j<3; ++j)
    {
        total[j] = 0;
        
        for (int i=0; i<7; ++i) //内层则是循环7天
        {
            total[j] += cost[i][j]; //i,j 位置 别反了 
        }
        
        total_all += total[j];
    }

    if (total[0] < ((total_all * 15 / 100) * 80 / 100)
        || total[0] > ((total_all * 15 / 100) * 120 / 100)
        || total[2] < ((total_all * 30 / 100) * 80 / 100)
        || total[2] > ((total_all * 30 / 100) * 120 / 100)
        )
    {
        cout << "您三餐花费安排得有点不合理噢。" << endl;
    }
    else
    {
        cout << "您三餐安排得很合理！" << endl;
    }
    
    cout << "下面，程序输出21个元素的地址：" << endl;
    system("pause");
    
    for (int i=0; i<7; ++i)
    {
        for (int j=0; j<3; ++j)
        {
            cout << "第" << i*7 + j << "个元素地址:" << &(cost[i][j])
                << "\t方法二：" << *(cost + i) + j << endl;
        }
    }
}

int main()
{
    cout << "示例1：一维堆数组示例" << endl;
    cout << "----------------传说中的分隔线----------------" << endl;
    demo_1();
    
    cout << "示例2：一维栈数组示例" << endl;
    cout << "----------------传说中的分隔线----------------" << endl;
    demo_2();
    
    cout << "示例3：二维栈数组示例" << endl;    
    cout << "----------------传说中的分隔线----------------" << endl;
    demo_3();
    
    return 0;
}
