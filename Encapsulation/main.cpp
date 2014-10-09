#include <iostream>

using namespace std;

class Time_v1 {
public:	//NB No data hiding!
	//int m_hours;
	//int m_minutes;
	//int m_seconds;
	//this is bad because any client can set these values to anything, and if we refractor this class then all external code is broken
	int m_time[3];
};

class Time_v2 {
private:
	//int m_hours;
	//int m_minutes;
	//int m_seconds;
	//now if we refractor these 3 int into one array, we only have to change local code, no external code is broken! HUZZAH!
	int m_time[3];

	//declaration of friend function
	friend ostream & operator<<(ostream & os, Time_v2 const & time);

	//insertor is a private member function
	ostream & insertor(ostream & os) const {
		os	<< "\tTIME"
			<< "\nHours: " << m_time[0]
			<< "\nMinutes: " << m_time[1]
			<< "\nSeconds: " << m_time[2] << endl;

			return os;
	}

public:
	Time_v2(int h = 0, int m = 0, int s = 0) /*:
			m_hours(h), m_minutes(m), m_seconds(s)*/
	{
		m_time[0] = h;
		m_time[1] = m;
		m_time[2] = s;
	}

	void setHour(int h) {
		//m_hours = ( h < 0 || h > 23) ? 0 : h;
		m_time[0] = (h < 0 || h > 23) ? 0 : h;
	}

	int getHour() const { return m_time[0]; }

	
};

	//important not to return void!
	//return a reference to ostream so that cout << time1 << time2... is legal. (time1 is inserted into cout, then time2 is inserted into whatever's returned, i.e. the ostream cout)
	ostream & operator<<(ostream & os, Time_v2 const & time)
	{
		return time.insertor(os);
	}

int main() {
	//some client code
	//Time_v1 badTime;
	//badTime.m_hours = 24;	//if we decide to rafractor our class to use an array instead of separate ints, then all external code is broken!

	Time_v2 goodTime;
	goodTime.setHour(24);	//What happens?		->		m_hours is set to zer0 because 24 is > 23 (see function implementation)

	cout << goodTime;
	system("pause");
}