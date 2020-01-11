#include <iostream>
#include <string>
#include <cstdlib> //for system

#include <mysql++.h>

using namespace std;

int main()
{
    mysqlpp::Connection con(false);

    con.set_option(new mysqlpp::SetCharsetNameOption("gbk"));

    cout << "请输入数据库(root用户)连接密码：";
    string pwd;
    getline(cin, pwd);

    if (!con.connect("d2school", "localhost", "root", pwd.c_str()))
    {
        cout << "无法连接上数据，请检查密码是否正确!" << endl;
        return -1;
    }


//    mysqlpp::Query q1 = con.query("SET character_set_connection='gb2312'");
//    q1.execute();
//
//    mysqlpp::Query q2 =  con.query("SET character_set_client ='gb2312'");
//    q2.execute();
//
//    mysqlpp::Query q3 = con.query("SET character_set_results = 'gb2312'");
//    q3.execute();

    mysqlpp::Query query = con.query("SELECT abs_index, day_index, name"
        ", province, sex, item, score FROM champions_2008 ORDER BY abs_index");

    mysqlpp::StoreQueryResult res = query.store();

    if (!res)
    {
        cout << "查无记录？请检查程序中query语句是不是写错了！" << endl;
        return -1;
    }

    for (unsigned int i = 0; i < res.num_rows(); ++i)
    {
        cout << "第" << res[i]["abs_index"] << "金";
        cout << "\t收获于第" << res[i]["day_index"] << "天" << endl;

        cout << "金牌获得者：" << res[i]["name"];

        cout << "\t性别：" << ((res[i]["sex"] == "0")? "女" : "男") << endl;

        cout << "冠军来自：" << res[i]["province"] << endl;
        cout << "获奖项目：" << res[i]["item"] << endl;

        cout << "成绩：";
        if (res[i]["score"].is_null())
        {
            cout << "N/A" << endl;
        }
        else
        {
            cout << res[i]["score"] << endl;
        }

        cout << "-----------------------------------------------" << endl;
        system("pause");
    }
}


