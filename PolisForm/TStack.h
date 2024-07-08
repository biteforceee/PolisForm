#pragma once
using namespace std;
template <typename T>
class Stack
{
private:
	T* mem;
	int size;
	int count; 
public:
	Stack(int _size = 20){
		size = _size;
		count = 0;
		mem = new T[size];
		//T tmp = T(0);
		for (int i = 0; i < size; i++){
			mem[i] = T();
		}
	}
	~Stack(){
		delete[]mem;
	}
	Stack(const Stack& tmp) {
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];
		for (int i = 0; i < size; i++){
			mem[i] = tmp.mem[i];
		}
	}
	Stack& operator=(Stack tmp){
		if (size != tmp.size){
			if (size != 0){
				delete[]mem;
			}
			size = tmp.size;
			mem = new T[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++){
			mem[i] = tmp.mem[i];
		}
		return *this;
	}
	void push(T val){
		if (count == size) {
			T* tmpMem = new T[size * 2];
			//copy(mem, mem + size, tmpMem);
			for (int i = 0; i < size; i++) {
				tmpMem[i] = mem[i];
			}
			delete[]mem;
			mem = tmpMem;
			size *= 2;
		}
		if (count != size) {
			mem[count++] = val;
		}
	}
	T pop(){
		if (count > 0){return mem[--count];}
		T res = T(0);
		return res;
	}
	T top(){
		if (count > 0){return mem[count - 1];}
		T res = T(0);
		return res;
	}
	int isEmpty(){
		if (count == 0){return 1;}
		else{return 0;}
	}
	int isFull(){
		if (size == count){ return 1;}
		else { return 0; }
	}
};
/*class Stack{
private:
	T* mem;
	int top;
	size_t memSize;// count
public:
	Stack(size_t _size = 20)
	{
		memSize = _size;
		top = 0;
		mem = new T[memSize];
		for (int i = 0; i < memSize; i++)
		{
			mem[i] = T(0);
		}
	}
	~Stack() { delete[] mem; }
	Stack(const Stack& tmp) //конструктор копирования
	{
		top = tmp.top;
		memSize = tmp.memSize;
		mem = new T[size];
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}
	Stack& operator=(Stack tmp){ //оператор присваивания
		if (memSize != tmp.memSize){
			if (memSize != 0){
				delete[]mem;
			}
			memSize = tmp.memSize;
			mem = new T[top];
		}
		top = tmp.top;
		for (int i = 0; i < memSize; i++){
			mem[i] = tmp.mem[i];
		}
	}
	size_t size() const { return top + 1; }
	bool isEmpty()const { return top == -1; }
	T pop() {
		if (memSize > 0){
			return mem[memSize - 1];
		}
		T res = T(0);
		return res;
	}
	void push(const T& val) {
		if (top == memSize - 1) {
			T* tmpMem = new T[memSize * 2];
			copy(mem, mem + memSize, tmpMem);
			delete[]mem;
			mem = tmpMem;
			memSize *= 2;

		}
		mem[++top] = val;
		memSize++;
	}
};*/

