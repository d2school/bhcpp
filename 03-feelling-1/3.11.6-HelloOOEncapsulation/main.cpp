#include <iostream>
#include <string>

using namespace std;

struct Person
{
public:
    Person()
    {
        cout << "Wa~Wa~" << endl;
        cout << "为这个哇哇哭的人，起个名字吧：";
        getline(cin, name);
    }

    virtual ~Person()
    {
        cout << "Wu~Wu~" << endl;
    }

    string GetName() const //变化在这里，加了const
    {
        //name = "王二麻子";  //没办法在问名时莫明地修改名字了……
        return name;
    }

    virtual void Introduction()
    {
        cout << "Hi, my name is " << name << "." << endl;
    }
private:
    std::string name;
};

struct Beauty : public Person
{
    ~Beauty() override
    {
        cout << "wu~wu~人生似蚍蜉、似朝露；似秋天的草，似夏日的花……" << endl;
    }

    void Introduction() override
    {
        cout << "大家好，我是美女: " << GetName() << "，请多多关照！" << endl;
    }
};

int main()
{
    while(true)
    {
        Person *someone;

        cout << "请选择(1/2/3)：" << endl
            << "1----普通人" << endl
            << "2----美人" << endl
            << "3----退出" << endl;

        int sel = 0;
        cin >> sel;

        if (cin.fail())
        {
            cin.clear();
        }

        cin.sync();

        if (3 == sel)
        {
            break;
        }

        if (1 == sel)
        {
            someone = new Person;
        }
        else if (2 == sel)
        {
            someone = new Beauty;
        }
        else //用户输入的，即不是１，也不是２，也不是３...
        {
            cout << "输入有误吧？请重新选择。" << endl;
            continue;
        }

        cout << someone->GetName() << "的自我介绍：" << endl;
        someone->Introduction();

        delete someone;
    }

    return 0;
}
