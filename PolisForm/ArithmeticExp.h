#pragma once
#include <iostream>
#include "Poliz.h"
#include "Tabl.h"
#include "TStack.h"
#include "Zapis.h"
#include <string>
#include <cmath>

class arithmetic {
private:
	poliz pol;
	Stack<double>st;
public:

	arithmetic(string str = "")
	{
		pol = poliz(str);
	}
	~arithmetic() {}
	arithmetic(const arithmetic& tmp){
		pol = tmp.pol;
		st = tmp.st;
	}
	arithmetic& operator=(arithmetic tmp)
	{
		pol = tmp.pol;
		st = tmp.st;
		return *this;
	}
	double calculate(){
		double right, res, left;
		Tabl table = pol.getOperands();
		/*for (int i = 0; i < poli.GetCount(); i++)
		{
			cout << poli[i] << endl;
		}*/
		Stack <double> st(pol.getCountPol());
		for (int i = 0; i < pol.getCountPol(); i++){
			res = table.searchD(pol[i]);
			if (res != -1){
				st.push(res);
			}
			else {
				right = st.pop();
				left = st.pop();
				if (pol[i] == "+"){
					st.push(left + right);
				}
				if (pol[i] == "-"){
					st.push(left - right);
				}
				if (pol[i] == "*"){
					st.push(left * right);
				}
				if (pol[i] == "/"){
					st.push(left / right);
				}
				if (pol[i] == "^"){
					st.push(pow(left, right));
				}
			}
		}
		return st.pop();
	}

	void SetVar(string key, float k){
		int n = pol.getOperands().search(key);
		if (n > -1){
			pol.setVar(n, k);
		}
	}
	void SetVar(int n, float k){
		if (n > -1){
			pol.setVar(n, k);
		}
	}
	Tabl GetTablevarials(){
		return pol.getOperands();
	}
	poliz GetA() {
		return pol;
	}

};






/*#include <iostream>
#include "Stec.h"
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	Stec<int> a(25);
	int i = 0;
	cout <<"Полный:" << a.is_full() << endl;
	cout << "Пустой:" << a.is_empty() << endl;

	while (!a.is_full())
	{
		a.pushback(i++);
	}

	cout << "Заполнили А"<<endl;

	Stec<int> B;
	B = a;

	Stec<int> C(a);
	cout << "Полный:" << a.is_full() << endl;
	cout << "Пустой:" << a.is_empty() << endl;

	while (!a.is_empty())
	{
		cout << "A:"<<a.top() << ' ';
		cout << a.pop() << endl;
	}

	while (!B.is_empty())
	{
		cout <<"B:"<< B.top() << ' ';
		cout << B.pop() << endl;
	}

	while (!C.is_empty())
	{
		cout <<"C:"<< C.top() << ' ';
		cout << C.pop() << endl;
	}
}*/
/*
#include <iostream>
#include "Tabl.h"
#include "Stack.h"
#include "Zapis.h"
#include "Poliz.h"
#include <string>
int main()
{
	setlocale(LC_ALL, "RUS");
	Tabl A(5);

	cout<<"Проверяем на запоненность:" << endl;

	cout << A.isEmpty()<<endl;
	cout << A.isFull()<< endl;

	cout << "Заполняем..." << endl;

	A.add(zapis("name1",2.3));
	A.add(zapis("name2",4.5));
	A.add(zapis("name3", 6.7));
	A.add(zapis("name4", 8.9));
	A.add(zapis("name1", 10.11));
	for (int i = 0; i < A.getCount(); i++)
	{
		zapis retrieved4 = A[i];
		cout << retrieved4.GetName() << " (" << retrieved4.GetValue() << ")" << endl;
	}

	cout << "Проверяем на запоненность:" << endl;

	cout << A.isEmpty() << endl;
	cout << A.isFull() << endl;

	cout << "Находим Value первого элемента:" << endl;

	cout << A.searchI("name1") << endl;;

	Tabl B(5);
	cout << "B=A:" << endl;
	B = A;

	cout << "Удаляем 1 элемент и gытаемся найти его:" << endl;

	A.del("name1");
	cout << A.searchI("name1") << endl;

   // Tabl B(5);
   // cout << "B=A:" << endl;
	//B = A;

	cout << B.isEmpty() << endl;
	cout << B.isFull() << endl;

	for (int i = 0; i < B.getCount(); i++)
	{
		zapis retrieved3 = B[i];
		cout << retrieved3.GetName() << " (" << retrieved3.GetValue() << ")" <<endl;
	}
	string s;
	cin >> s;
	polis F(s);

	cout << F.GetStringPolis() << endl;

	polis V = F;

	cout << V.GetStringPolis() << endl;
	F.SetVar(1,1000);
	Tabl g = F.Getvariables();
	for (int i = 0; i < g.getCount(); i++)
	{
		cout << g[i].GetName() << " (" << g[i].GetValue() << ")" << endl;
	}
}*/