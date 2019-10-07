#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "请输入姓名：";
        getline(cin, name);
        
        cout << "请输入年龄：";
        cin >> age;
    }
    
    virtual ~Person()
    {
    }
    
    string GetName() const
    {
        return name;
    }
    
    int GetAge() const
    {
        return age;
    }
    
private:
    string name;
    int age;
};

struct Beauty : public Person
{
public:
    Beauty ()
    {
        cout << "请输入国籍：";
        cin.sync();
        getline(cin, nationality);
        
        cout << "请输入三围数据（胸、腰、臀），数据以空格隔开，回车确认：";
        cin >> bust >> waist >> hips;
        
        cout << "请输入自我介绍内容：";
        cin.sync();
        getline(cin, introduction);
    }
    
    string GetNationality() const
    {
        return nationality;
    }

    int GetBust() const
    {
        return bust;
    }
    
    int GetWaist() const
    {
        return waist;
    }
    
    int GetHips() const
    {
        return hips;
    }
        
    void Introduction() const
    {
        cout << introduction << endl;
    }
    
private:
    std::string nationality; //国籍
    
    int bust;   //胸围
    int waist;  //腰围
    int hips;   //臀围
    
    std::string introduction; //自我介绍内容
};

//美女管理类
struct BeautiesManager
{
public:
    void Input();  //输入新的美女
    void Find() const; //按姓名查找美女
    
    void Count() const //显示当前美女总数
    {
        cout << "当前美女个数：" << beauties.size() << endl;
    }
    
    void Introduction() const; //所有美女依次自我介绍
    void Clear(); //清空当前所有美女
    
private:
    vector<Beauty> beauties;
};

void BeautiesManager::Input()
{
    Beauty b;    
    beauties.push_back(b);
}

void BeautiesManager::Find() const
{
    cout << "请输入要查找的美女姓名：";
    string name;
    
    getline(cin, name);
    
    int found = 0;
    
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        if (beauties[i].GetName() == name)
        {
            ++found;
            
            cout << "找到啦！该美女的索引是: " << i << endl;
            
            cout << "姓名：" << beauties[i].GetName() << endl
                << "年龄：" << beauties[i].GetAge() << endl
                << "国籍：" << beauties[i].GetNationality() << endl
                << "三围：" << beauties[i].GetBust() << ", "
                    <<  beauties[i].GetWaist() << ", " << beauties[i].GetHips() << endl; 
        }
    }
    
    cout << "共找到：" << found << "位名为：" << name << "的美女！" << endl; 
}

void BeautiesManager::Introduction() const
{
    for (unsigned int i=0; i<beauties.size(); ++i)
    {
        cout << "现在出场的是：" << beauties[i].GetName() << endl;
        beauties[i].Introduction();
    }
}

void BeautiesManager::Clear()
{
    cout << "您确认要清除所有美女数据吗？该操作不可恢复！ (y/n)：";
    
    char c;
    cin >> c;
    
    cin.sync();
    
    if (c == 'y')
    {
        beauties.clear();
        cout << "数据已清除！" << endl;
    }
}

//显示主菜单:
int ShowMenu()
{
    cout << "请选择：" << endl;
    cout << "1----美女信息录入" << endl
        << "2----美女信息查找" << endl
        << "3----检查美女总数" << endl
        << "4----美女出场自我介绍" << endl
        << "5----清空全部美女数据" << endl
        << endl
        << "6----关于本程序" << endl
        << "7----退出" << endl;
        
    int sel = 0;
    cin >> sel;
    cin.sync();
    
    return sel;
}

void About()
{
    cout <<  "《ＸＸＸ国际美女大赛信息管理系统 Ver 1.0》" << endl
        << "作者：丁小明 Copyright 2008~???" << endl;
}

int main()
{
    enum {sel_input = 1, sel_find, sel_count, sel_introduction, sel_clear, sel_about, sel_exit};
 
    cout << "XXX国际美女大赛欢迎您！" << endl;
 
    BeautiesManager bm;
       
    while(true)
    {
        int sel = ShowMenu();
                
        if ( sel_input == sel)
        {
            bm.Input();
        }        
        else if (sel_find == sel)
        {
            bm.Find();
        }
        else if (sel_count == sel)
        {
            bm.Count();
        }
        else if (sel_introduction == sel)
        {
            bm.Introduction();
        }
        else if (sel_clear == sel)
        {
            bm.Clear();
        }
        else if (sel_about == sel)
        {
            About();
        }
        else if (sel_exit == sel)
        {
            break;
        }
        else //什么也不是?
        {
            if (cin.fail ())
            {
                cin.clear(); //清除cin当前可能处于错误状态，需清除
                cin.sync();
            }
            
            cout << "选择有误，请重选。" << endl;
        }
    }
    
    return 0;
}
