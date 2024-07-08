#pragma once
#include "TStack.h"
#include "Tabl.h"
#include "Zapis.h" 
#include <string>
using namespace std;
class poliz
{
private:
	string* pol;//mem
	string* lex;
	int sizePol, countPol;//size,count
	int sizeLex, countLex;//sizeLex,countLex
	Stack<zapis>st;
	Tabl operand, PriorityTable;
	void madeTablPrior() {
		PriorityTable = Tabl(5);
		PriorityTable.add(zapis("+", 1.00));
		PriorityTable.add(zapis("-", 1.00));
		PriorityTable.add(zapis("*", 2.00));
		PriorityTable.add(zapis("/", 2.00));
		PriorityTable.add(zapis("^", 3.00));
	}
	void stringPursing(string str, int& k, string* w){
		string zn = "+-*^/()";
		k = 0;
		str += " ";
		for (int i = 0; i < str.length(); i++) {
			int l = zn.find(str[i]);
			if (l >= 0 && l < zn.length()) {
				if (w[k].length() > 0) {
					k++;
				}
				w[k++] = str[i];
				//w[++k] = "";
			}
			else {
				if (str[i] == ' ') {
					if (w[k].length() > 0) {
						w[++k] = "";
					}
				}
				else {
					w[k] = w[k] + str[i];
				}
			}
		}
	}
	void workLeft() {
		st.push(zapis("(", 0.00));

	}
	void workRight() {
		while ((st.top().getName()) != "(") {
			//cout << st.top().getName()<<endl;
			pol[countPol++]=st.pop().getName();
			/*for (int i = 0; i < countPol; i++) {
				cout << pol[i]<<" ";
			}*/
			cout << endl;
		}
		st.pop().getName();
		//if (st.top().getName() == "(") {
		//	st.pop();
		//}
	}
	void workOperand(string tmp) {
		//pol[countPol++] = tmp;
		pol[countPol] = tmp;
		countPol++;
		if (tmp[0] < '0' || tmp[0]>'9') {
			operand.add(zapis(tmp,0.00));
		}
		else{
			operand.add(zapis(tmp, stod(tmp))); 
		}
	}
	void workOperator(zapis tmp) {
		while (st.isEmpty() == 0 && st.top().getVal()>=tmp.getVal()) {
			pol[countPol++] = st.pop().getName();
		}
		st.push(tmp);
	}
	void  workEndStr() {
		while (st.isEmpty() == 0) {
			pol[countPol++] = st.pop().getName();
		}
	}
	void madePoliz(string str) {//точка останова
		/*sizePol = str.length() + 1;
		pol = new string[sizePol];*/
		countPol = 0;/*
		sizeLex = sizePol + 1;
		lex = new string[sizeLex];*/
		countLex = 0;
		stringPursing(str,countLex,lex);
		for (int i = 0; i < countLex; i++) {
			if (lex[i] == "(") { workLeft();}
			else {
				if (lex[i] == ")") { workRight(); }
				else {
					double l = PriorityTable.searchD(lex[i]);
					if (l < 0) { workOperand(lex[i]); }
					else { workOperator(zapis(lex[i],l)); }
				}
			}
		}
		workEndStr();
		delete[]lex;
	}
public:
	poliz(string str = "") {
		sizePol = str.length() + 1;
		pol = new string[sizePol];
		countPol = 0;
		sizeLex = sizePol + 1;
		lex = new string[sizeLex];
		countLex = 0;
		st = Stack<zapis>(20);
		madeTablPrior();
		operand = Tabl(40);
		madePoliz(str);//ошибка bad alloc
	}
	poliz(const poliz& tmp) {
		//PriorityTable = tmp.PriorityTable;
		operand = tmp.operand;
		sizePol = tmp.sizePol;
		countPol = tmp.countPol;
		pol = new string[sizePol];
		for (int i = 0; i < sizePol; i++) {
			pol[i] = tmp.pol[i];
		}
		st = tmp.st;
	}
	~poliz() {
		delete[] pol;
	}
	string operator[](int k) {
		string str = "";
		if (k > -1 && k <= countPol) {
			str = pol[k];
		}
		return str;
	}
	poliz operator = (const poliz tmp ){
		if (sizePol != tmp.sizePol) {
			if (sizePol != 0) { delete[] pol; }
			sizePol = tmp.sizePol;
			pol = new string[sizePol];
		}
		countPol = tmp.countPol;
		for (int i = 0; i < sizePol; i++) {
			pol[i] = tmp.pol[i];
		}
		//PriorityTable = tmp.PriorityTable;
		st = tmp.st;
		operand = tmp.operand;
		return *this;
	}
	string getPol() {
		string str = "";
		for (int i = 0; i < sizePol;i++) {
			str += pol[i]+" ";
		}
		return str;
	}
	int getCountPol() { return countPol; }
	void setOperand(int n, float k) {
		operand.setVar(n, k);
	}
	Tabl getOperands() {
		return operand;
	}
	void setVar(int n, float k) {
		operand.setVar(n, k);
	}
};
////class polis {
////private:
////	void StringToWond(string str, int& k, string* w) {
////		string zn = "+-*/^()";
////		k = 0;
////		str += " ";
////		for (int i = 0; i < str.length(); i++) {
////			int l = zn.find(str[i]);
////			if (l >= 0 && l < zn.length()) {
////				if (w[k].length() > 0) {
////					k++;
////				}
////				w[k] = str[i];
////				w[++k] = "";
////			}
////			else {
////				if (str[i] == ' ') {
////					if (w[k].length() > 0) {
////						w[++k] = "";
////					}
////				}
////				else {
////					w[k] = w[k] + str[i];
////				}
////			}
////		}
////	}
////	string* lex;
////	int count, countlex, size, sizelex;
////	string* mem;
////	Stack<zapis> st;
////	Tabl PriorityTable;
////	Tabl variables;
////	void madePriorityTable() {
////		PriorityTable = Tabl(20);
////		PriorityTable.add("+", 0.0);
////		PriorityTable.add("-", 0.0);
////		PriorityTable.add("*", 1.0);
////		PriorityTable.add("/", 1.0);
////		PriorityTable.add("^", 2.0);
////	}
////	void workLeft() {
////		st.push(zapis("(", -1.0));
////	}
////	void workRight() {
////		while ((st.isEmpty() == 0) && (st.top().getName() != "(")) {
////			mem[count++] = st.pop().getName();
////		}
////		if (st.top().getName() == "(") {
////			st.pop();
////		}
////	}
////	void workOperand(string tmp) { 
////		mem[count++] = tmp;
////		if (tmp[0] >= '0' && tmp[0] <= '9') {
////			variables.add(tmp, stof(tmp));
////		}
////		else {
////			variables.add(tmp, 0.0);
////		}
////	}
////	void workOperator(string str, int p) { 
////		while ((st.isEmpty() == 0) && (st.top().getVal() >= p)) {
////			mem[count++] = st.pop().getName();
////		}
////		st.push(zapis(str, p));
////	}
////	void workEnd() {
////		while (st.isEmpty() == 0) {
////			mem[count++] = st.pop().getName();
////		}
////	}
////	void madePolis() {
////		count = 0;
////		for (int i = 0; i < countlex; i++) {
////			if (lex[i] == "(") { workLeft(); }
////			else {
////				if (lex[i] == ")") { workRight(); }
////				else {
////					int p = PriorityTable.searchD(lex[i]);
////					if (p > -1) { workOperator(lex[i], p); }
////					else { workOperand(lex[i]); }
////				}
////			}
////		}
////		workEnd();
////	}
////public:
////	polis(string str = "") {
////		size = str.length() + 1;
////		variables = Tabl(size);
////		mem = new string[size];
////		count = 0;
////		sizelex = size + 1;
////		lex = new string[sizelex];
////		countlex = 0;
////		StringToWond(str, countlex, lex);
////		madePriorityTable();
////		st = Stack<zapis>(20);
////		madePolis();
////	}
////	polis(const polis& tmp) {
////		size = tmp.size;
////		count = tmp.count;
////		mem = new string[size];
////		for (int i = 0; i < size; i++) {
////			mem[i] = tmp.mem[i];
////		}
////		PriorityTable = tmp.PriorityTable;
////		st = tmp.st;
////		variables = tmp.variables;
////	}
////	polis& operator =(polis tmp) {
////		if (size != tmp.size) {
////			if (size != 0) {
////				delete[]mem;
////			}
////			size = tmp.size;
////			mem = new string[size];
////		}
////		for (int i = 0; i < size; i++) {
////			mem[i] = tmp.mem[i];
////		}
////		count = tmp.count;
////		PriorityTable = tmp.PriorityTable;
////		st = tmp.st;
////		variables = tmp.variables;
////		return *this;
////	}
////	~polis() {
////		delete[]mem;
////	}
////	int GetCount() {
////		return count;
////	}
////	string operator[](int n) {
////		if (n >= 0 && n < count) {
////			return mem[n];
////		}
////		return "?";
////	}
////	string GetStringPolis() {
////		string str = "";
////		str += mem[0];
////		for (int i = 1; i < count; i++) {
////			str += " " + mem[i];
////		}
////		return str;
////	}
////	Tabl Getvariables() {
////		return variables;
////	}
////	void SetVar(int n, float k) {
////		variables.setVar(n, k);
////	}
////};
//#pragma once
//#include "TStack.h"
//#include "Tabl.h"
//#include "Zapis.h"
//#include <string>
//using namespace std;
//
//
//class poliz
//{
//private:
//	string* Pol;//полиз
//	int sizePol, countPol;
//	string* Lex;//массив лексем
//	int sizeLex, countLex;
//	Stack <zapis> ST;
//	Tabl operand, prioritet;
//	void Algoritm10(string str, int& k, string* W)
//	{
//		string zn = "+-/*^()";
//		k = 0;
//		str += " ";
//		for (int i = 0; i < str.length(); i++)
//		{
//			int l = zn.find(str[i]);
//			if (l >= 0 && l < zn.length())
//			{
//				if (W[k].length() > 0)
//				{
//					k++;
//				}
//				W[k++] = str[i];
//
//			}
//			else
//			{
//				if (str[i] == ' ')
//				{
//					if (W[k].length() > 0)
//					{
//						W[++k] = "";
//					}
//				}
//				else {
//					W[k] = W[k] + str[i];
//				}
//			}
//		}
//	}
//	void madeTablprior()
//	{
//		prioritet = Tabl(6);
//		prioritet.add(zapis("+", 1));
//		prioritet.add(zapis("-", 1));
//		prioritet.add(zapis("*", 2));
//		prioritet.add(zapis("/", 2));
//		prioritet.add(zapis("^", 3));
//	}
//	void Vecleft()
//	{
//		ST.push(zapis("(", 0));
//	}
//	void Vecrigth()
//	{
//		while (ST.top().getName() != "(")
//		{
//			Pol[countPol++] = ST.pop().getName();
//		}
//		ST.pop().getName();
//	}
//	void Vecoperand(string tmp)
//	{
//		Pol[countPol++] = tmp;
//		if ((tmp[0] < '0') || (tmp[0] > '9'))
//		{
//			operand.add(zapis(tmp, 0));
//		}
//		else
//		{
//			operand.add(zapis(tmp, stod(tmp))); //переведенное в число tmp////////////////////////
//		}
//	}
//	void Vecoperaci(zapis tmp)
//	{
//		while ((ST.isEmpty() == 0) && (ST.top().getVal() >= tmp.getVal()))
//		{
//			Pol[countPol++] = ST.pop().getName();
//		}
//		ST.push(tmp);
//	}
//	void VecKonecStr()
//	{
//		while (ST.isEmpty() == 0)
//		{
//			Pol[countPol++] = ST.pop().getName();
//		}
//	}
//	void madePolis(string str)
//	{
//		countPol = 0;
//		countLex = 0;
//		Algoritm10(str, countLex, Lex);
//		for (int i = 0; i < countLex; i++)
//		{
//			if (Lex[i] == "(")
//			{
//				Vecleft();
//			}
//			else
//			{
//				if (Lex[i] == ")")
//				{
//					Vecrigth();
//				}
//				else
//				{
//					double l = prioritet.search(Lex[i]);
//					if (l < 0)
//					{
//						Vecoperand(Lex[i]);
//					}
//					else
//					{
//						Vecoperaci(zapis(Lex[i], l));
//					}
//				}
//			}
//		}
//		VecKonecStr();
//		delete[]Lex;
//	}
//public:
//	poliz(string str = "")
//	{
//		ST = Stack<zapis>(20);
//		madeTablprior();
//		operand = Tabl(10);
//		sizePol = str.length() + 1;
//		Pol = new string[sizePol];
//		countPol = 0;
//		sizeLex = str.length() + 1;
//		Lex = new string[sizeLex];
//		madePolis(str);
//
//	}
//	poliz(const poliz& tmp)
//	{
//		operand = tmp.operand;
//		sizePol = tmp.sizePol;
//		countPol = tmp.countPol;
//		Pol = new string[sizePol];
//		for (int i = 0; i < sizePol; i++)
//		{
//			Pol[i] = tmp.Pol[i];
//		}
//		ST = tmp.ST;
//	}
//	~poliz()
//	{
//		delete[]Pol;
//	}
//	poliz& operator=(poliz tmp)
//	{
//		if (sizePol != tmp.sizePol)
//		{
//			if (sizePol != 0)
//			{
//				delete[]Pol;
//			}
//			sizePol = tmp.sizePol;
//			Pol = new string[sizePol];
//		}
//		countPol = tmp.countPol;
//		for (int i = 0; i < sizePol; i++)
//		{
//			Pol[i] = tmp.Pol[i];
//		}
//		ST = tmp.ST;
//		operand = tmp.operand;
//		return *this;
//	}
//	string Poltostring()
//	{
//		string k = "";
//		for (int i = 0; i < countPol; i++)
//		{
//			k = k + " " + Pol[i];
//		}
//		return k;
//	}
//	Tabl Getoperand()//возвращает 
//	{
//		return operand;
//	}
//	string operator[](int k)
//	{
//		string str = "";
//		if ((k <= countPol) && (k >= 0))
//		{
//			str = Pol[k];
//		}
//		return str;
//	}
//	int GetcountPol()
//	{
//		return countPol;
//	}
//	int GetsizePol()
//	{
//		return sizePol;
//	}
//};

