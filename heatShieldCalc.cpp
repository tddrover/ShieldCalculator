#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{

	int shield;
	float neutron;
	int direction;
	int neutroncount;
	int directioncount;
	float movement;
	int num2;
	int escaped=0;
	int destroyed=0;
	int test=0;
	int i=0;
	int randomnum=0;
	int totalrandom=0;
	int totaldirection=0;
	string  status;
	
	int num;
	unsigned int seed;

	seed=time(0);
	srand(seed);

	cout<<showpoint<<fixed<<setprecision(2);

	ofstream fp;

	fp.open("neutronData.txt");

	neutroncount=0;
	directioncount=0;

	cout<<"Enter the thickness of the shield: ";
	cin>>shield;
	
	cout<<"Enter the number of neutrons: ";
	cin>>neutron;

	cout<<"Enter the maximum number of direction changes: ";
	cin>>direction;

	cout<<"\n\nStarting Simulation...\n\n";

	fp<<"ID Number"<<setw(20)<<"Direction Changes"<<setw(20)<<"Random Motions"<<setw(20)<<"Status"<<endl;

	while (neutroncount<neutron){
		movement=0;
		directioncount=0;
		test=0;
		randomnum=0;
	//	cout<<"New neutron started!"<<endl;
		while (directioncount<=direction && test==0){
			num= 1+rand() %(1+4-1);
			randomnum+=1;

			if(movement>shield){
				escaped+=1;
				test=1;
				status="Escaped";
			//	cout<<"Neutron Escaped!"<<endl;
				
			}
			else{
	
				if (num==1){
					movement+=1;
					if(num2 !=1){
						directioncount+=1;
					//	cout<<"New direction!"<<endl;
					}
				//	cout<<"Moved forward!"<<endl;
				}
				else if(num==2){
					movement-=1;
					if(num2 !=2){
						directioncount+=1;
					//	cout<<"New direction!"<<endl;
					}
				//	cout<<"Moved backwards!"<<endl;
				}
				else if(num==3){
					if(num2 !=3){
						directioncount+=1;
					//	cout<<"New direction!"<<endl;
					}
				//	cout<<"Moved left!"<<endl;
				}
				else if(num==4){
					if(num2 !=4){
						directioncount+=1;
				//		cout<<"New direction!"<<endl;
					}
				//	cout<<"Moved right!"<<endl;
				}
				num2=num;

			}



		}
		if(directioncount>direction){
			destroyed+=1;
			status="Destroyed";
		//	cout<<"Neutron destroyed!"<<endl;
		}
	i+=1;
	fp<<i<<setw(20)<<directioncount<<setw(20)<<randomnum<<setw(30)<<status<<endl;
	neutroncount+=1;
	totalrandom+=randomnum;
	totaldirection+=directioncount;
	}

	cout<<"\n\nDestroyed: "<<destroyed<<"  Escaped "<<escaped<<endl;
	cout<<"Percentage of neutrons escaped: "<<float((escaped/neutron)*100.0)<<endl;
	cout<<"Total of direction changes: "<<totaldirection<<setw(20)<<"  Average of direction changes: "<<float(totaldirection/neutron*1.0)<<endl;
	cout<<"Total of random motions: "<<totalrandom<<setw(20)<<"  Average of random motions: "<<float(totalrandom/neutron*1.0)<<endl;

	return 0;
}
