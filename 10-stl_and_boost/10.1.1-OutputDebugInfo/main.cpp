#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void OutputDebugInfo(ostream& os, std::string const& debug_info)
{
    os << "����Ϣ����" << debug_info << endl;
}

int main()
{
    ofstream ofs("log.txt");

    OutputDebugInfo(ofs, "�������������磡");
    cout << "��ã����磡" << endl;

    ostringstream oss;
    OutputDebugInfo(oss, "����Ҫ������Ŷ����");
    OutputDebugInfo(oss, "������ĳ����ˣ�");
    OutputDebugInfo(oss, "ԭ����û�г�����");
    cout << oss.str() << endl;

    OutputDebugInfo(ofs, "������������磡");

    OutputDebugInfo(cout, "���ڲ���ʹ��������ȫ����ˡ�");

    return 0;
}
