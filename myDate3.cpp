/**
*Alexandre Schein
*CECS 282- 07
*2/19/2019
*Program 2- myDate 
**/

#include "myDate3.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int Greg2Julian (int month, int day, int year){
	//pass in the Month, Day, Year and return Julian Number
	int I=year;
	int J=month;
	int K=day;
	int JD;	//julian date
	JD = K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
	return JD;		//returning the Julian Number
}

void Julian2Greg(int &JD, int &month, int &day, int &year){
	//pass in the Julian date and get the correct month, day, and year through the parameter list- pass by reference
	int L;
	int N;
	int I=year;
	int J=month;
	int K=day;
	
	L=JD+68569;		//fortran code
	N=4*L/146097;
	L=L-(146097*N+3)/4;
	I= 4000*(L+1)/1461001;
	L=L-1461*I/4+31;
	J=80*L/2447;
	K=L-2447*J/80;
	L=J/11;
	J=J+2-12*L;
	I=100*(N-49)+I+L;
	year=I;
	month=J;
	day=K;
		
}

myDate::myDate(){
	month = 5;	//intialzing values in the default constructor
	day = 11;		//day =11
	year = 1959;		//year = 1959
}

myDate::myDate(int M, int D, int Y){
//	month = M;
//	day = D;
//	year = Y;
	int JD = Greg2Julian(M,D,Y);
	int m1;
	int d1;
	int y1;
	Julian2Greg(JD,m1,d1,y1);
	
	if (M==m1&&D==d1&&Y==y1){
		month=M;		//setting month,day,and year in overloaded constructor
		day=D;
		year=Y;
	}
	else{
		month=5;		//default values from default constructor
		day=11;
		year=1959;
	}

}

void myDate:: display(){		//EDIT
	//cout<<"Month, Day , Year"; 
	if (month == 1){
		cout<<"Jan "<<day<<","<<year;		//displaying corect month,day,and year
	}
	else if(month==2){
		cout<<"Feb "<<day<<","<<year;
	}
	else if(month==3){
		cout<<"Mar "<<day<<","<<year;
	}
	else if(month==4){
		cout<<"Apr "<<day<<","<<year;
	}
	else if(month==5){
		cout<<"May "<<day<<","<<year;
	}
	else if(month==6){
		cout<<"Jun "<<day<<","<<year;
	}
	else if(month==7){
		cout<<"July "<<day<<","<<year;
	}
	else if(month==8){
		cout<<"Aug "<<day<<","<<year;
	}
	else if(month==9){
		cout<<"Sep "<<day<<","<<year;
	}
	else if(month==10){
		cout<<"Oct "<<day<<","<<year;
	}
	else if(month==11){
		cout<<"Nov "<<day<<","<<year;
	}
	else if(month==12){
		cout<<"Dec "<<day<<","<<year;
	}
	
}

void myDate:: increaseDate(int N){
	//increment the date by N days
	int JD=Greg2Julian(month,day,year);
	JD+=N;
	Julian2Greg(JD,month,day,year);
}

void myDate::decreaseDate(int N){
	//decrement the date by N days
	int JD=Greg2Julian(month,day,year);
	JD-=N;
	Julian2Greg(JD,month,day,year);
}

int myDate::daysBetween(myDate D){
	//return number of days between this date and D
	int JD=Greg2Julian(month,day,year);
	int date_d=Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
	int between=date_d-JD;
	return between;		//number of days between
	
}

int myDate::getMonth(){
	//return the month in integer form
	return month;
}

int myDate::getDay(){
	//return the day of the month
	return day;
}

int myDate::getYear(){
	//return the year 
	return year;
}

int myDate::dayOfYear(){
	//return the number of days since the current year began
	int jan_one=Greg2Julian(1,1,year);	//january first
	
	int JD = Greg2Julian(month,day,year);	//current date
	
	int num_days= (JD - jan_one)+1;
	return num_days;

}

string myDate::dayName() {
	//returns Monday, tuesday, etc according to the day of the week
	int JD=Greg2Julian(month,day,year);	//converting to julian	
	if (JD%7==0){		//using modulo 7 for 7 days in week
		return "Monday";
	}
	else if(JD%7==1){
		return "Tuesday";
	}
	else if(JD%7==2){
		return "Wednesday";		//returns wednesday 
	}
	else if (JD%7==3){
		return "Thursday";
	}
	else if (JD%7==4){
		return "Friday";
	}
	else if (JD%7==5){
		return "Satuday";
	}
	else if (JD%7==6){
		return "Sunday";
	}
	else
		return "";
}

