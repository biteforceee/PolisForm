#pragma once
#include <string>
#include <iostream>
using namespace std;
class zapis{
private:
	string name;
	double val;
public:
	zapis(string _name = "", double _val = 0.0) {
		name = _name;
		val = _val;
	}
	double getVal() { return val;}
	string getName() { return name; }
	/*friend ostream& operator << (ostream& out, const zapis& tmp) {
		out << tmp.name << "	" << tmp.val;
		return out;
	}*/
	void setVal(double _val = 0.0) { val = _val; }
};

