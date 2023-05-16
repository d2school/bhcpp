#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void OutputDebugInfo(ostream& os, std::string const& debug_info)
{
    os << "【信息】：" << debug_info << endl;
}

int main()
{
    ofstream ofs("log.txt");

    OutputDebugInfo(ofs, "即将输出你好世界！");
    cout << "你好，世界！" << endl;

    ostringstream oss;
    OutputDebugInfo(oss, "估计要出错了哦……");
    OutputDebugInfo(oss, "好像还真的出错了！");
    OutputDebugInfo(oss, "原来并没有出错啊！");
    cout << oss.str() << endl;

    OutputDebugInfo(ofs, "完成输出你好世界！");

    OutputDebugInfo(cout, "终于不辱使命，即将全身而退。");

    return 0;
}
