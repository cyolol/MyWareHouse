#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//���Ʒֶα�׼�ĺ���
double resect(double a, double b)
{
    if(abs(a - b)/max(a,b) <= 0.02)return 1;
    else return 0;
}
//��͸�ʵļ��㺯��
//�������ν��С��ϲ������ϲ���ĳ��������ֳ���֮�ͣ��ϲ������͸��ֵΪ
//������͸�ʵľ����Ȩƽ��ֵ�����ϲ���͸��K=��ki*Li+kj*Lj��/(Li+Lj)
double calc(double data[13][2], double (*res)(double, double))
{
    for(int i = 0; i < 13; i++)
    {
        //����û������j��0�����ȣ�1������͸��
        if(res(data[i][1],data[i+1][1]))
        {
            data[i][0] = data[i][0] + data[i+1][0];
            data[i][1] = (data[i][1]*data[i][0] + data[i+1][1]*data[i+1][0])/(data[i][0]+data[i+1][0]);
            for(int t=i+2; t < 13; t++)
            {
                data[t-1][0] = data[t][0];
                data[t-1][1] = data[t][1];
            }
            --i;
        }
    }
}
int main()
{
    double data[13][2] = {
        {2, 3.5},
        {2.4, 4.3},
        {4, 5.4},
        {2.7, 5.3},
        {3.9, 5.35},
        {2.9, 7.1},
        {3.2, 7.2},
        {2.22, 3.3},
        {3.2, 7.3},
        {4, 9},
        {5, 9.1},
        {2.5, 3.4},
        {2.9, 3.3}
    };
    /*for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            static_cast<double>(data[i][j]);
        }
    }*/
    calc(data, resect);
    cout << "���" << "\t" << "����L" << "\t" << "��͸��K" << endl;
    for(int i=0;i < 13;i++)
    {
        cout << i+1 << endl;
        for(int j=0;j < 2;j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
