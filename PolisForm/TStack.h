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