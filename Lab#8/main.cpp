#include <iostream>
using namespace std;

class Fueltank{
	private:
		int m_FueltankCapacity;
		int m_Gas_grade;
	public:
		Fueltank(int FueltankCapacity=3000, int Gas=98){
			m_FueltankCapacity = FueltankCapacity;
			m_Gas_grade = Gas;
		}
		int fuel_up(int v, int gas){
			if(gas!=m_Gas_grade && v>m_FueltankCapacity){
				cout<<"Error: FueltankCapacity: "<<m_FueltankCapacity<<" but fuel up: "<<v<<endl;
				cout<<"Error: Gas_grade: "<<gas<<" Correct Gas_grade: "<<m_Gas_grade;
			}
			else if(v>m_FueltankCapacity){
				cout<<"Error: FueltankCapacity: "<<m_FueltankCapacity<<" but fuel up: "<<v<<endl;
				cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas;
			}
			else if(gas!=m_Gas_grade){
				cout<<"Error: Gas_grade: "<<gas<<" Correct Gas_grade: "<<m_Gas_grade;
			}
			else{
				cout<<"fuel_up: "<<v<<" Gas_grade: "<<gas;
			}
		}
		int set_Gas_grade(int Gas_grade){
			cout<<"Set Gas_grade: "<<Gas_grade<<endl;
			m_Gas_grade = Gas_grade;
		}
		int get_Gas_grade(){
			return m_Gas_grade;
		}
};
class Car{
	private:
		//Engine m_Engine;
		Fueltank m_Fueltank;
		int m_MaxSeating;
		string m_brand;
		string m_model;
		int m_year;
	public:
		Car(string x, string y, int z, int s){
			m_brand = x;
			m_model = y;
			m_year = z;
			m_MaxSeating = s;
		}
		int get_MaxSeating(){
			return m_MaxSeating;
		}
		string get_brand(){
			return m_brand;
		}
		int get_Gas_grade(){
			return m_Fueltank.get_Gas_grade();
		}
		int set_Gas_grade(int gas=98){
			return m_Fueltank.set_Gas_grade(gas);
		}
		int fuel_up(int v, int gas=98){
			return m_Fueltank.fuel_up(v,gas);
		}
};
class AUDI_Car : public Car{
	private:
		string m_DriveMode;
	public:
		AUDI_Car(string y, int z, int s) : Car("Audi", y, z, s){
			cout<<"Constructing AUDI_Car\n";
			m_DriveMode = "Front-wheel";
		}
		string get_DriveMode(){
			return m_DriveMode;
		}
};

int main(){
	AUDI_Car car_2("A1",2021,2);
	cout<<car_2.get_brand()<<" : Gas_grade = "<<car_2.get_Gas_grade()<<endl;
	car_2.set_Gas_grade(95);
	cout<<car_2.get_brand()<<" : Gas_grade = "<<car_2.get_Gas_grade()<<endl;
	car_2.fuel_up(300,95);
	return 0;
}
