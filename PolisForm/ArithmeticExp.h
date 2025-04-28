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