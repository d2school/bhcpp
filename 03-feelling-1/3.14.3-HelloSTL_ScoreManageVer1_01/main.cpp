#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

//学生
struct Student
{
  unsigned int number; //学号
  string name;
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
    void InputStudents();
    void InputScores();
    void OutputScores() const;

private:
    vector<Student> students;
    list<Score> scores;
};

void StudentScoreManager::InputStudents()
{
    unsigned int number = 1; //学号从1开始

    while(true)
    {
        cout << "请输入" << number << "号学生姓名(输入x表示结束)：";

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

struct CompareByNumber_Equal
{
   unsigned int number; //学号

   bool operator () (unsigned int current_number) const
   {
        return current_number == number;
   }
};

//将 find “泛化”，让它可以针对不同容器，以及不同的容器元素，都可以作查找
template <typename T>
T find (T beg, T end, CompareByNumber_Equal cmp)
{
    for (T iter = beg; iter != end; ++iter)
    {
        if (cmp (iter->number))
        {
            return iter;
        }
    }

    //没找到,返回end
    return end;
}

void StudentScoreManager::InputScores()
{
    while(true)
    {
        unsigned int number;

        cout << "请输入学号（输入0表示结束）：";

        cin >> number;

        if (number == 0)
        {
            break;
        }

        //简单判断学号是否正确：
        if (number > students.size())
        {
            cout << "错误：学号必须位于: 1 ~ " << students.size() << " 之间。" << endl;
            continue;
        }

        float mark;
        cout << "请输入该学员成绩：";
        cin >> mark;

        Score score;
        score.number = number;
        score.mark = mark;

        scores.push_back(score);
    }
}

void StudentScoreManager::OutputScores() const
{
    for (unsigned int i=0; i<students.size(); ++i)
    {
        unsigned int number = students[i].number; //学号

        cout << "学号：" << number << endl;
        cout << "姓名：" << students[i].name << endl;

        //查找成绩:
        CompareByNumber_Equal cmp;
        cmp.number = number;

        list<Score>::const_iterator iter = find(scores.begin(), scores.end(), cmp);

        if (iter != scores.end())
        {
            cout << "成绩：" << iter->mark << endl;
        }
        else //没找到
        {
             cout << "成绩：" << "查无成绩。" << endl;
        }
    }
}

int main()
{
    StudentScoreManager ssm;

    ssm.InputStudents();
    ssm.InputScores();
    ssm.OutputScores();

    return 0;
}
