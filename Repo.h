#pragma once
#include <vector>
#include <string>
template <class T> 
class Repo {
	private:
		vector<T> z;
public:
	Repo();
	Repo(vector<T> z);
	Repo(const Repo& x);
	~Repo();
	vector<T> getAll();
	void addElem(T v);
	string toString();
	void delElem(T v);
};
template <class T> string Repo<T>::toString() {
	string s = "";
	string strr;
	char* b = new char[50];
	for (int i = 0; i < z.size(); i++)
	{
		snprintf(b, 10, "%d",i+1);
		strr = string(b);
		s +=strr+". "+ z[i].toString()+"\n";

	}
	delete[] b;
	b = NULL;
	return s;
}
template <class T> Repo<T>::Repo() {}
template <class T> Repo<T>::Repo(vector<T> z) {
	this->z = z;
}
template <class T> Repo<T>::Repo(const Repo& x) {
	this->z = x.z;
}
template <class T> Repo<T>::~Repo(){}
template <class T> vector<T> Repo<T>::getAll() {
	return z;
}
template <class T> void Repo<T>::addElem(T v) {
	z.push_back(v);
}
template <class T> void Repo<T>::delElem(T v) {
	for (int i = 0; i < z.size(); i++)
		if (z[i] == v)
			z.erase(z.begin()+i);
}