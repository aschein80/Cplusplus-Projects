/**
*Alexandre Schein
*CECS 282-07
*Program 6- luggage
*5/3/2019
**/


#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include <cstring>

using namespace std;

	class luggage{ //base class
		protected:
			string type;			//protected string, accessible by inheritance
			
		public:
			lugagge(){				//luggage base
				type="luggage";
				cout<<"Creating luggage\n";
			};
			
			string getType(){	//returns the type
				return type;
			}
			
			virtual double volume()=0;		//virutal methods for volume + displayinh
			
			virtual void display()=0;
	};

	class box:public luggage{				//   1)  BOX
		private:
			double width; //width
			double height; //height
			double length; //length
		public:
			box(double _width, double _height, double _length){ 
				type = "Box";
				width= _width;			//declaring the parameters and type
				height = _height;
				length =_length;
			}
		
			double volume(){
				double volume = width * length * height;		//volume for a box
				return volume;
			}
		
			void display(){  
				cout<<"Luggage Type:"<<type;   //printing type and volume
				cout<<" Volume: "<<volume()<<endl;
			}
	};
	
	class sphere:public luggage{ 			// 2) Sphere
		private:
			double radius;
			
		public:
			sphere(double _radius){
				type ="Sphere"; 
				radius = _radius; //sphere radius
			}
			double volume(){
				double volume= ((4.0/3.0)*3.14*radius*radius*radius); //formular for sphere
				return volume;
			}
			
			void display(){
				cout<<"Luggage Type: "<<type;
				cout<<" Volume: "<<volume()<<endl;
			}
	};
	
	class cube: public luggage{				// 3) cube
		
		private:
			double width;
		public:
			cube(double _width)
			{
				type= "Cube"; //type
				width=_width;
			}
			double volume()
			{
				double volume= width*width*width; //volume of cube
				return volume;
			}
			void display()
			{
				cout<<"Luggage Type: "<<type;
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
	
	class pyramid: public luggage{			//       4) pyramid
		private:
			double base;
			double height;
		public:
			pyramid(double _base, double _height)
			{
				type= "Pyramid";
				base= _base;
				height= _height;
			}
			double volume()
			{
				double volume= ((base*base*height)/3.0); //volume
				return volume;
			}
			void display()
			{
				cout<<"Luggage Type: "<<type;   //printing luggage type and volume
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
	
	class cylinder: public luggage{			//   5) cylinder
		private:
			double radius;
			double length;

		public:
			cylinder(double _radius, double _length)
			{
				type= "Cylinder";
				radius= _radius;
				length= _length;   
			}
			double volume()
			{  
				double volume= ((3.14*radius*radius)*length);  //volume
				return volume;
			}
			void display()
			{
				cout<<"Luggage Type: "<<type;   //display
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
	//mainn 5 done
	
	class cone: public luggage{						//   6) CONE
		private:
			double radius;
			double height;
		public:
			cone(double _radius, double _height)
			{
				type= "Cone";
				radius = _radius; //radius
				height= _height;  //height
			}
			double volume()
			{
				double volume= (3.14*radius*radius*(height/3.0));  //formula for cone
				return volume;
			}
			void display()
			{
				cout<<"Luggage Type: "<<type;
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
		
	class tetrahedron: public luggage{		//       7) tetrahedron
		private:
			double side;
		public:
			tetrahedron(double _side)
			{
				type= "Tetrahedron";  
				side= _side;
			}
			double volume()
			{
				double volume= ((side*side*side)/ (6.0*sqrt(2.0)) );  //volume of tetrahedron
				return volume;
			}
			void display()
			{
				cout<<"Luggage Type: "<<type;
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
	
	class triangular_prism: public luggage{			//8)     triangle prism
		private:
			double base;
			double height;
			double length;
			
		public:
			triangular_prism(double _base, double _height, double _length)
			{
				type= "Triangular Prism";
				base=_base;
				height=_height;
				length=_length;
			}
			
			double volume()
			{
				double volume= ((0.5)*base*length*height);  
				return volume;//volume 
			}
			
			void display()
			{
				cout<<"Luggage Type: "<<type;
				cout<<" Volume: "<<volume()<<endl;
			}
			
	};
	
	
int main(){
	
	vector<luggage*> storage;    //vector containing luggage pointers
	
	int user_input;  //user selection
	int lug_type;  //type of luggage
	double width;
	double length;
	double height;
	double radius;
	double side;
	double base;
	
	static int counter;			//static counter to keep track of storage
	cout<<"Hello, Welcome to Luggage Program!"<<endl;			//greeting
	cout<<"Please choose from the following options: "<<endl;

	while(true){
		
		cout<<endl;
		cout<<"1) Add Luggage to storage container"<<endl;				//options
		cout<<"2) Remove Luggage from storage container"<<endl;
		cout<<"3) Show all Luggage"<<endl;
		cout<<"4) Quit"<<endl;
		cout<<"Choice: ";
		cin>>user_input; //getting user input
		cout<<endl;
		
		if(user_input==1){
			
			cout<<"You chose to add Luggage."<<endl;
			counter++;
			cout<<"Luggage:\n1) Box\n2) Sphere\n3) Cube\n4) Pyramid\n5) Cylinder\n6) Cone\n7) Tetrahedron\n8) Trianglular Prism"<<endl; //options to choose from for adding
			cout<<endl;
			cin>>lug_type;
			
			if(lug_type==1){
				
				cout<<"Dimensions of the Box:\n"<<endl;  //getting values 
				cout<<"Width:";
				cin>>width;
				cout<<"Length: ";
				cin>>length;
				cout<<"Height: ";
				cin>>height;
				storage.push_back(new box(width,height,length));	//adding to storage
			}
			
			else if(lug_type==2)  									//sphere
			{
				cout<<"Dimensions of the Sphere: "<<endl;
				cout<<"Radius: ";
				cin>>radius;
				storage.push_back(new sphere(radius));
			}
			
			else if(lug_type==3)  									//cube
			{				
				cout<<"Dimensions of the Cube: "<<endl;	
				cout<<"Side: ";
				cin>>width;
				storage.push_back(new cube(width));
			}
			
			else if(lug_type==4) 									//pyramid
			{
				cout<<"Dimensions of the Pyramid:"<<endl;
				cout<<"Base: "; //getting values
				cin>>base;
				
				//cout<<endl;
				cout<<"Height: ";
				cin>>height;
				//cout<<endl;
		
				//cout<<endl;
				storage.push_back(new pyramid(base,height)); //adding to storage
			}
			
			else if(lug_type==5)						//cylinder
			{
				cout<<"Dimensions of the Cylinder: "<<endl;
				cout<<"Radius: "; //radius
				cin>>radius;
			//	cout<<endl;
				cout<<"Length: ";
				cin>>length;
			//	cout<<endl;
				storage.push_back(new cylinder(radius, length)); //adding to storage
			}
			
			else if(lug_type==6)						//cone
			{
				cout<<"Dimensions of Cone:"<<endl;
				cout<<"Radius: ";
				cin>>radius;
		//		cout<<endl;
				cout<<"Height: "<<endl;
				cin>>height;
		//		cout<<endl;
				storage.push_back(new cone(radius,height));
				
			}
			
			else if(lug_type==7)						//tetrahedron
			{
				cout<<"Dimensions of Tetrahedron: "<<endl;
				cout<<"Side: ";
				cin>>side;
		//		cout<<endl;
				storage.push_back(new tetrahedron(side));
			}
			
			else if(lug_type==8)						//triangular prism			
			{
				cout<<"Dimensions of Triangular Prism"<<endl;
				cout<<"Base: ";
				cin>>base;
		//		cout<<endl;
				cout<<"height: ";
				cin>>length;
		//		cout<<endl;
				cout<<"Length: ";
				cin>>length;
				storage.push_back(new triangular_prism(base,height,length));
				
			}	
		}
		
		else if(user_input==2){			//user wants to remove from storage
			counter--;
			cout<<"Remove Luggage"<<endl;
			
			for(int i=0; i<storage.size();i++){
				cout<<i+1<<") ";		//displaying index
				storage[i]->display();				//using virtual methods defined in the classes
			}
			
			cout<<"Which luggage to delete: ";
			cin>>lug_type;			//getting luggage type
			storage.erase(storage.begin()+ (lug_type-1));//erase
			
		}
		
		else if(user_input==3){		//show
			double volume=0;
			cout<<"Show Luggage: "<<endl;
			
			vector<luggage *> :: iterator it=storage.begin(); //using iterator for vector 
			
			for(it; it!=storage.end(); it++)
			{
				volume+= (*it)->volume();		//adding to total volume
				
				(*it)->display();
			}
			
			cout<<"Total Number of Items: "<<counter<<endl;
			cout<<"Total Volume of Storage: "<<volume<<endl;
			
		}
		else if (user_input==4){			//exit program
		
			cout<<"See you next Time!"<<endl;
			return false;
		
		}
		
		else{
			cout<<"Error, Please Make a Valid Selection"<<endl;
			
		}	
			}
		
		
return 0;
}
