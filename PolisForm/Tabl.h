#pragma once
#include "zapis.h"
#include <iostream>
using namespace std;
class Tabl{
private:
	zapis* Mem;
	int size, count;
	
public:
	int search(string key){
		int res = -1;
		int i = 0;
		while ((res == -1) && (i < count)){
			if (key == Mem[i].getName()){
				res = i;
			}
			i++;
		}
		return res;
	}
	Tabl(int _size = 0){
		size = _size;
		count = 0;
		Mem = new zapis[size];
		for (int i = 0; i < size; i++){
			Mem[i] = zapis("",0.00);
		}
	}
	~Tabl(){delete[]Mem;}
	Tabl(const Tabl& tmp){ 
		size = tmp.size;
		count = tmp.count;
		Mem = new zapis[size];
		for (int i = 0; i < size; i++){
			Mem[i] = tmp.Mem[i];
		}
	}
	Tabl& operator=(const Tabl tmp) {
		if (size != tmp.size){
			if (size != 0){
				delete[]Mem;
			}
			size = tmp.size;
			Mem = new zapis[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++){
			Mem[i] = tmp.Mem[i];
		}
		return *this;
	}
	/*friend ostream& operator <<(ostream& out, Tabl tmp) {
		for (int i = 0; i < tmp.count; i++) {
			cout << tmp.Mem[i]<<endl;
		}
		return out;
	}*/
	void add(zapis tmp){
		int L = search(tmp.getName());
		if ((L == -1) && (count < size)){
			Mem[count++] = tmp;
		}
		else {
			Mem[L] = tmp;
		}
	}
	int getCount() { return count; }
	void add(string name, float value) {
		add(zapis(name, value));
	}
	zapis del(string key){
		zapis res;
		int L = search(key);
		if (L >= 0){
			res = Mem[L];
			count--;
			Mem[L] = Mem[count];
		}
		return res;
	}
	zapis operator[](int k) {
		zapis res;
		if ((k <= count) && (k > -1)) {
			return  Mem[k];
		}
		return res;
	}
	int isEmpty() {
		if (count == 0){return 1;}
		else{return 0;}
	}
	int isFull(){
		if (count == size){return 1;}
		else{return 0;}
	}
	double searchD(string key){
		double res = -1;
		int l = -1, i = 0;
		while ((l == -1) && (i < count)){
			if (key == Mem[i].getName()){
				l = i;
				res = Mem[i].getVal();
			}
			i++;
		}
		return res;
	}
	void showTabl(){
		for (int i = 0; i < count; i++){
			cout << Mem[i].getName() << "	" << Mem[i].getVal();
			cout << endl;
		}
	}
	void setVar(int n, float k) {
		Mem[n].setVal(k);
	}
};

