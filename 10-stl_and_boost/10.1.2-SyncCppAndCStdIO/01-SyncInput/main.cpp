#include <cstdio> // C ���Եı�׼���������
#include <iostream>

using namespace std;

int main()
{
    // �����ڶԱȣ� ͬ������ͬ����
    ios_base::sync_with_stdio(false); // ��ͬ��������

    int i, j;

    /*
        �����ڶԱȵ����뷽ʽ��
        1- ����C��ʽ���룺
            scanf("%d", &i);
            scanf("%d", &j);

        2- ����C++��ʽ���룺
            cin >> i;
            cin >> j;

        3- ������룬���£�
    */

    scanf("%d", &i); //��C�ķ�ʽ����  i
    cin >> j; // ��C++�ķ�ʽ���� j

    cout << i << ", " << j << endl;

    return 0;
}
