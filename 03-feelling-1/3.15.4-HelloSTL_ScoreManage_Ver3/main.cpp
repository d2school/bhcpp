#include <iostream>
#include <list> 
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

//学生
struct Student 
{
  unsigned int number; //学号
  string name; //姓名
};

//成绩
struct Score
{
   unsigned int number; //学号
   float mark; //分数
};


//学生成绩管理类
struct StudentScoreManager
{
public:
    void InputStudents(); //录入学生基本信息（录入前自动清空原有数据） 
    void SaveStudents() const; // 保存学生基体信息到文件
    void LoadStudents(); //从文件中读入学生基本信息。
       
    void InputScores(); //录入成绩（录入前不清空原有数据）
    void ClearScores(); //清空成绩数据
    
    void OutputScoresByNumber() const; //以学号次序，输出每个学生信息，包括成绩
    void OutputScoresByMark() const; //以分数排名，输出每个成绩，包括学生基本信息
    
    void FindStudentByNumber() const; //通过学号，查找学生，显示姓名，学号，成绩
    void FindStudentByName() const; //通过姓名，查找学生，显示姓名，学号，成绩
    
private:
    //内部调用的函数:
    //给定一个学号，在scores中查找，并输出其分数
    void FindScoreByNumber(unsigned int number) const;

    vector<Student> students;
    list<Score> scores;
};

//检查是否输入有误，如有，则清除出错状态，并返回“真”.
bool CheckInputFail()
{
    if (cin.fail ()) //检查 cin是不是出错了？
    {
        //出错了...
        cin.clear(); //清除cin当前可能处于错误状态
        cin.sync(); //再清除当前所有未处理的输入
        
        cout << "输入有误，请重新处理。" << endl;
        
        return true;
    }
    
    return false;
}

//输入学生成绩
void StudentScoreManager::InputStudents()
{
    //检查是否已经有数据:
    if (students.empty() == false)
    {
        cout << "确信要重新录入学生基本信息吗？(y/n)";
        char c;
        cin >> c;
        
        if (c != 'y')
        {
            return;
        }
        
        cin.sync(); //吃掉回车键.
    }
    
    //因为允许用户重新录入，所以现在需要清除原有数据
    students.clear(); 
    
    unsigned int number = 1; //学号从1开始
    
    while(true)
    {
        cout << "请输入学生姓名(输入x表示结束), " << number << "号：";
        
        string name;
        
        getline(cin, name);
        
        if (name == "x")
        {
            break;
        }
        
        Student student;
        student.number = number;
        student.name = name;
        
        students.push_back(student);
        
        ++number;
    }    
}

//保存学生基本信息到特定的文件中：
void StudentScoreManager::SaveStudents() const
{
    ofstream ofs;
    ofs.open(".\\students_base_info.txt");
    
    if (!ofs)
    {
        cout << "打开成绩输出文件失败！" << endl;
        return;
    }
    
    //特意输入学员个数，方便于后面的读文件过程
    unsigned int count = students.size();
    ofs << count << endl;
    
    for (unsigned int i=0; i<count; ++i)
    {
        ofs << students[i].number << endl; 
        ofs << students[i].name << endl; 
    }
    
    ofs.close(); 
    
    cout << "保存完毕，共保存" << count << "位学生基本信息。" << endl;
}

//从特定的文件中，读入学生基本信息：
void StudentScoreManager::LoadStudents() 
{
    ifstream ifs;
    ifs.open(".\\students_base_info.txt");
    
    if (!ifs)
    {
        cout << "打开成绩输入文件失败！" << endl;
        return;
    }
    
    students.clear(); //清除原来的学生数据
    
    unsigned int count = 0;
    ifs >> count; //读入个数

    for (unsigned int i=0; i<count; ++i)
    {
        Student stu; 
        
        ifs >> stu.number; 
        
        ifs.ignore(); //替后续的getline跳过：学号之后的换行符
        getline(ifs, stu.name);  //读入姓名
       
        students.push_back(stu); //加入
    }
    
    cout << "加载完毕，共加载：" << count << "位学生的基本信息。" << endl;
}

//比较器：比较姓名是否相等
//用于在students中查找指定姓名的学生
struct CompareByName4Find
{
    bool operator () (Student student) const
    {
        return student.name == name;
    }
    
    //待查找的姓名
    string name;
};

//比较器：比较成绩中的学号是否相等
//用于在 scores中查找指定学号的成绩
struct CompareByNumber_Equal4Find
{
    bool operator () (Score s) const
    {
        return (s.number == number);
    }
    
    unsigned int number;
};

//内部调用的函数:
//给定一个学号，在scores中查找，并输出其分数
void StudentScoreManager::FindScoreByNumber(unsigned int number) const
{
    CompareByNumber_Equal4Find cbne;
    cbne.number = number;
    
    list<Score>::const_iterator itScore = find_if(scores.begin(), scores.end(), cbne);
    
    if (itScore == scores.end()) 
    {
       //找不到成绩：
       cout << "，成绩：查无成绩。"; 
    }
    else
    {
        //查到成绩了，显示：
        cout << "，成绩：" << itScore->mark;
    }
}

//通过学号查到详细信息
void StudentScoreManager::FindStudentByNumber() const 
{
    cout << "请输入要查找的学号：";
    
    unsigned int number;
    cin >> number;
    
    //用户输入非数字字符时，此时检查出错误
    if (CheckInputFail()) 
    {
        return;
    }
    
    //检查是不是在合法范围内的学号:
    unsigned int maxNumber = students.size();
    
    if (number > maxNumber)
    {
        cout << "学号只允许在 1~" << maxNumber << " 之间！" << endl;
        return;
    }
    
    cout << "学号：" << number;
    cout << "，姓名：" << students[number - 1].name;
    
    //继续查：用学号查分数:
    FindScoreByNumber(number);
    
    cout << endl;
}

//通过姓名查找到学生基本信息，然后再通过学号找到学生成绩。
//逐步显示查到的结果。如果有多个同名学生，则全部输出。
void StudentScoreManager::FindStudentByName() const
{
    cout << "请输入待查找的学员姓名：";
    
    string name;
    
    getline(cin, name);
    
    CompareByName4Find cmp;
    cmp.name = name;
    
    int foundCount = 0; //已经查找到几个人了？
    
    vector<Student>::const_iterator itStu = students.begin(); //从哪里查起
    
    while(itStu != students.end())
    {
        //查找学生，注意查找范围为: itStu ~ students.end()
        itStu = find_if(itStu, students.end(), cmp);
        
        if (itStu == students.end())
        {
            break; //找不到人了...结束循环
        }
        
        //查到该学生了...
        ++foundCount; //找到的人数加1。
        
        //显示学生基本信息：
        cout << "姓名：" << name;
        cout << "，学号：" << itStu->number;
        
        //继续查：用学号查分数:
        FindScoreByNumber(itStu->number);

        cout << endl;
       
        //重要：将itStu前进到下一个位置，
        //意思是：下次查找时，将从当前找到的那学生的下一个位置开始找起
        itStu++;
    }
    
    cout << "总共查到" << foundCount << "位学生，名为：" << name << endl;
}

//根据学号的次序输出学生成绩，没有成绩的学员，显示“查无成绩”
void StudentScoreManager::OutputScoresByNumber() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number;
        cout << "，姓名：" << students[i].name;
                
        //查找成绩:
        CompareByNumber_Equal4Find cmp;
        cmp.number = number;
  
        list<Score>::const_iterator iter = find_if(scores.begin(), scores.end(), cmp);
        
        if (iter != scores.end())
        {
            cout << "，成绩：" << iter->mark << endl;
        }
        else //没找到
        {
             cout << "，成绩：" << "查无成绩。" << endl;
        }
    }    
}

//比较器：比较成绩中的分数高低
//在InputScores()中，录入成绩之后，会立即使用本比较对成绩进行排序
struct CompareByMarkBigger
{
    bool operator () (Score s1, Score s2) const
    {
        return (s1.mark > s2.mark);
    }
};

//录入学生成绩，录入完成后即行排序
void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;
        
        cout << "请输入学号（输入0表示结束）：";
        
        cin >> number;
        
        //检查用户输入是不是合法的数字
        if (CheckInputFail())
        {
            continue;
        }
        
        if (number == 0)
        {
            break;
        }
        
        //判断学号大小是否在合法的范围内：        
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue; 
        }
        
        float mark;
        cout << "请输入成绩(" << students[number-1].name << ")："; //本版此处新增了姓名提示
        cin >> mark;
        
        //检查用户输入是不是合法的浮点数
        if (CheckInputFail())
        {
            continue;
        }

        Score score;
        score.number = number;
        score.mark = mark;
        
        scores.push_back(score);
    }
    
    //本版新增功能：录入成绩后，立即按分数高低排序
    //保证scores中的元素永远是有序的
    CompareByMarkBigger cmp;
    scores.sort(cmp);    
}

//清空成绩
void StudentScoreManager::ClearScores()
{
    cout << "您确信要清空全部成绩数据？ (y/n)";
    
    char c;
    cin >> c;
    
    if (c == 'y')
    {
        scores.clear();
        cout << "成绩数据清除完毕！" << endl;
    }
    
    cin.sync();
}

//按分数高低，输出每个成绩，包括学生姓名，没有参加考试学员，将不会被输出
void StudentScoreManager::OutputScoresByMark() const
{
    //在每次录入成绩之后，我们都会调用sort立即为所有成绩进行排序
    //所以scores中的所有成绩，已经是按高低分排序了
    //问题是：分数相同时必须处理“名次并列”的情况。
    
    int currentIndex = 1; //当前名次,排名从1开始
    int sameMarkCount = 0; //相同分数个数
    double lastMark= -1; //上一次分数，刚开始时，初始化为一个不可能的分数
    
    for (list<Score>::const_iterator it = scores.begin();
        it != scores.end();
        ++it)
    {
        if (lastMark != it->mark)
        {
            lastMark = it->mark;
            currentIndex += sameMarkCount;
            sameMarkCount = 1;
        }
        else //分数相同
        {
            ++sameMarkCount; 
        }
        
        cout << "名次：" << currentIndex;
        cout << "，姓名：" << students[it->number - 1].name; //通过学号得到名字
        cout << "，学号：" << it->number;
        cout << "，成绩：" << it->mark << endl;        
    }
}

void About()
{
    system("cls");
    
    cout << "学生成绩管理系统 Ver 3.0" << endl;
    cout << "copyright 2008~?" << endl;
    cout << "作者：丁小聪" << endl;
    cout << "来自：www.d2school.com/白话C++" << endl; 
}

void Help()
{
    system("cls");
    
    cout << "1#录入学生基本信息：" << endl 
        << "请注意，重新录入时，原有数据会清空！" << endl 
        << endl;
    
    cout << "2#录入成绩：" << endl 
        << "请注意，会在原有成绩数据上录入，如果需要清空成绩，请使用：清空成绩。" << endl 
        << endl; 
        
    cout << "3#清空成绩：" << endl 
        << "之前录入的成绩将被清除，本操作不可恢复。" << endl 
        << endl;
    
    cout << "4#按学号次序显示成绩：" << endl 
        << "按学号从小到大输出成绩，包括姓名。未参加考试或还录入成绩学员，将显示查无成绩。" << endl 
        << endl;

    cout << "5#按分数名次显示成绩：" << endl 
        << "按分数从高到低输出成绩，包括名次，学号，姓名等。" << endl
        << "忠告：教育部禁止学校公布成绩排名。" << endl
        << endl;
        
    cout << "6#按学号查找学生：" << endl 
        << "输入学号，查找到指定学生的学生信息，包括成绩。" << endl 
        << endl;
        
    cout << "7#按姓名查找学生：" << endl 
        << "输入姓名，查到到该名字的学生，并输出其信息，包括成绩，如有重名，连续输出。" << endl 
        << endl;
        
    cout << "8#加载学生基本信息：" << endl
        << "如果曾经保存学生基本信息，则从该文件读出学生基本信息，注意：当前已有的学生信息将丢失！"
        << endl << endl;
        
    cout << "9#保存学生基本信息：" << endl 
        << "保存当前学生基本信息到文件，如果已经原有文件，则原有文件内容将被刷新！" 
        << endl << endl;
    
    cout << "10#关于：关于本软件的一些信息。" << endl << endl;
    cout << "11#帮助：显示本帮助信息。" << endl << endl;

    cout << "0#退出：输入0，退出本程序。" << endl << endl;
}

int Menu()
{
    cout << "---------------------------" << endl;
    cout << "----学生成绩管理系统 Ver3.0----" << endl;
    cout << "---------------------------" << endl;
    
    cout << "请选择：(0~1)" << endl;
    
    cout << "1--#录入学生基本信息" << endl;
    cout << "2--#录入成绩" << endl;
    cout << "3--#清空成绩" << endl;

    cout << "---------------------------" << endl;
    cout << "4--#按学号次序显示成绩" << endl;
    cout << "5--#按分数名次显示成绩" << endl;
    
    cout << "---------------------------" << endl;
    cout << "6--#按学号查找学生" << endl;
    cout << "7--#按姓名查找学生" << endl;

    cout << "---------------------------" << endl;
    cout << "8--#加载学生基本信息" << endl;
    cout << "9--#保存学生基本文件" << endl;
    
    cout << "---------------------------" << endl;
    cout << "10--#关于" << endl;
    cout << "11--#帮助" << endl;
    
    cout << "---------------------------" << endl;
    cout << "0--#退出" << endl;
    
    int sel;
    cin >> sel;
        
    if (CheckInputFail())
    {
        return -1;
    }
    
    cin.sync(); //清掉输入数字之后的 回车键

    return sel;
}

int main()
{
    StudentScoreManager ssm;

    while(true)
    {
        int sel = Menu();
                
        if (sel == 1)
        {
            ssm.InputStudents();
        }
        else if (sel == 2)
        {
            ssm.InputScores();
        }
        else if (sel == 3)
        {
            ssm.ClearScores();
        }
        else if (sel == 4)
        {
            ssm.OutputScoresByNumber();
        }
        else if (sel == 5)
        {
            ssm.OutputScoresByMark();
        }
        else if (sel == 6)
        {
            ssm.FindStudentByNumber();
        }
        else if (sel == 7)
        {
            ssm.FindStudentByName();
        }
        else if (sel == 8)
        {
            ssm.LoadStudents();
        }
        else if (sel == 9)
        {
            ssm.SaveStudents();
        }
        else if (sel == 10)
        {
            About();
        }
        else if (sel == 11)
        {
            Help();
        }
        else if (sel == 0)
        {
            break;
        }
        else //什么也不是..
        {
            cout << "请正确输入选择：范围在 0 ~ 11 之内。" << endl; 
        }
        
        system("Pause"); 
    }
    
    cout << "bye~bye~" << endl;
    
    return 0;
}
