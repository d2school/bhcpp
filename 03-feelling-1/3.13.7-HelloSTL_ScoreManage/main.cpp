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
        bool found = false;
        
        for (list<Score>::const_iterator iter = scores.begin(); 
            iter != scores.end(); 
            ++iter)
        {
            if (iter->number == number)
            {
                found = true; //找到了
                
                cout << "成绩：" << iter->mark << endl;
                
                break;
            }
        }
        
        if (found == false) //没找到??
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
