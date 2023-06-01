#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString{
	private:
		string m_str;
	public:
		myString(string s){
			m_str = s;
		}
};

class ReadClass{
	private:
		string classNum;
		int count;
	public:
		ReadClass(){
			count=0;
		}
		void showClass(){
			string str;
			ifstream in("main.cpp");
			while(!in.eof()){
				getline(in, str);
				string sub = str.substr(0,5);
				if(sub == "class"){
					str[str.size()-1] = '\0';
					classNum.append(str);
					classNum[classNum.size()-1] = '\n';
					count++;
				}
			}
			cout<<count<<" class in main.cpp\n"<<classNum;
		}
};

int main(){
	ReadClass rfile;
	rfile.showClass();
	return 0;
}
