#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IPAddress{
public:
	IPAddress(const string address) : address(address) {}
	IPAddress(const IPAddress& other) : address(other.address) {}
	void print () {
		cout << endl << address;
	}
protected:
	string address;
};

class IPAddressChecked :public IPAddress{
public:
	IPAddressChecked(const string& address) : IPAddress(address), isCorrect(check()) {}
	IPAddressChecked(const IPAddress& other) : IPAddress(other), isCorrect(check()) {}
	bool check(){
		stringstream splited(address);
		string s;
		int partsCount = 0;
		while (std::getline(splited, s, '.')){
			if (3 < s.length() || s.length() < 1)
				return false;
			if (partsCount > 4)
				return false;
			for (int i = 0; i < s.length(); i++){
				if (!isdigit(s[i]))
					return false;
			}
			int partValue = atoi(s.c_str());
			if (partValue > 255)
				return false;
			partsCount++;
		}
		if (partsCount != 4)
			return false;
		return true;
	}
	void print(){
		IPAddress::print();
		cout << (isCorrect ? " - Correct" : " - Not Correct");
	}
protected:
	bool isCorrect;
};


int main(){
	string inputData;
	
	cout << "Input first IP address" << endl;
	cin >> inputData;
	IPAddress firstIP(inputData);
	
	cout << "Input second IP address" << endl;
	cin >> inputData;
	IPAddressChecked secondIP(inputData);
	
	cout << "Input third IP address" << endl;
	cin >> inputData;
	IPAddressChecked thirdIP(inputData);


	firstIP.print();
	secondIP.print();
	thirdIP.print();
	cout << endl;
	return 0;
}