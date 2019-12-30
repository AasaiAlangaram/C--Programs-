/*
* File Name: "cosgraph.cpp"
* Description:
* - This program is input the values of amplitude, frequency, phase, and to display
*                   the cosine graph on console window.
* Programmed by Ye-Jun Jang,
* Last updated: Version 1.3, March 13, 2011 (by Ye-Jun Jang).
*
* ========================================================
* Version Control (Explain updates in detail)
* ========================================================
* Name          YYYY/MM/DD Version Remarks
* 
* Ye-Jun Jang   2011/03/12 1.0 Design an program to input the values of amplitude, frequency, phase, and to display
*                              the cosine graph on console window.
* Ye-Jun Jang   2011/03/12 1.1 Addtional comments.
* Ye-Jun Jang   2011/03/13 1.2 Add to else if(cos_value=0)
* Ye-Jun Jang   2011/03/13 1.3 In case Amplitude>1
* ========================================================
*/
#include <iostream>
#include <iomanip>//setprecision�� setw()�� ����ϱ� ���� iomanip ���̺귯�� ����
#include <cmath>//cos�Լ��� ����ϱ� ���� cmath ���̺귯�� ����

#define PI 3.141592 //PI ���� 3.141592�� ����

using namespace std;

double cosine(double amp, double freq, double time, double phase)//cosine �Լ� ����
{
	double result;

	result=amp*cos(2*PI*freq*time+phase);

	return result;
}

int main(void)
{
	double a, f, st, et, pha;
	double cos_value;

	cout << "enter the amp:";
	cin >> a;
	cout << "enter the frequency:";
	cin >> f;
	cout << "enter the phase:";
	cin >> pha;
	cout << "enter the start time:";
	cin >> st;
	cout << "enter the end time:";
	cin >> et;

	
	cout << "===============================================================================" << endl;
	cout << " time    cos(x) Value " << setw(34) << "cos(x) Graph" << endl; //setw( )�Էµ� ����ŭ ������ �������.
	cout << "===============================================================================" << endl;
	cout << setw(24) << -a << setw(26) << "0" << setw(27) << a << endl;
	cout << "                    " << "-----------------------------------------------------------" << endl;
	cout << fixed << setprecision(2);
	for(double i=st; i<=et+0.05; i+=0.05) //���� �ð����� 0.00~ 1.00���� ����ϱ� ���� for ��
	{
		cos_value=cosine(a,f,i,pha); //cos_value ������ consine�Լ��� ����� ����
		
		if(cos_value>0.01) //cos_value���� 0���� Ŭ �� ���� ������ ��
		{
			cout << " " << i << "        " << cos_value << setw(33) << "|" << setw(27*cos_value/a) << "*" << endl;
		}
		else if(cos_value<-0.01) //cos_value���� 0���� ���� �� ���� ������ ��
		{
			cout << " " << i << "       " << cos_value << setw(34+27*cos_value/a) << "*" <<  setw(-27*cos_value/a) << "|" << endl;
		}
		else if(cos_value=0) //cos_value���� 0�� �� ���� ������ ��
		{
			cout << " " << i << "        " << cos_value << setw(33)  << "*" << endl;
		}
		else
		{
			cout << " " << i << "        " << cos_value << setw(33)  << "*" << endl;
		}

	}

	return 0;	

}
