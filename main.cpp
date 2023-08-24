#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#define MAX_User 100

using namespace std;
class user{
	private :
		string taskname[MAX_User],atasknum[MAX_User],taskduedate[MAX_User],taskpriorities[MAX_User],final[MAX_User];
		int total;
		public:
			user() : total(0){}
			void tasknum();
			void addtask();
			void displaytask();
			void searchtask();
			void updatetask();
			void deletetask();
			void exit();
};
void user::tasknum() {
	tsknum:
    cout << "===========================\n";
    cout << "\nEnter the task you want to add\n\n";
    cout << "Number of Task: " << total << "\n\n"; // Print the current total
    cout << "===========================\n";
	cin.ignore();
    cout << "Enter task number: ";
    getline(cin, atasknum[total]);

    for (int i = 0; i < total; i++) {
    	string newTask = atasknum[total];
        if (newTask == atasknum[i]) {
            cout << "Task already exists\n";
            goto tsknum;  // Exit the method without adding the task
        }
    }
}
void user :: addtask(){
	int tsknm=0;
	tsknm++;
	
	for (int i= total; i<tsknm+total;i++){
		cout << "Enter task name: ";
		getline(cin, taskname[i]);
		cout << "Enter due date: ";
		getline(cin, taskduedate[i]);
		cout << "Add priorities: ";
		getline(cin, taskpriorities[i]);
	}
	total=tsknm+total;
	cout << "Adding Successfully\n";
}
void user :: displaytask(){
	if(total==0){
		cout << "No Task added" << endl;
	} 
	for(int i=0; i<total;i++){
		cout << "_____________________________________\n";
		cout << "Task Number: " << atasknum[i] << endl;
		cout << "Task: " << taskname[i]<< endl;
		cout << "Task Due date: " << taskduedate[i] << endl;
		cout << "Priorities: " << taskpriorities[i] << endl;
		cout << "_____________________________________\n";
	}
}
void user :: searchtask(){
	if(total == 0){
		cout << "No task entered" << endl;	
	}else{
		string tasknum;
		cout << "Enter the task number: ";
		cin >> tasknum;
		for(int i=0; i<total;i++){
			if(tasknum == atasknum[i]){
				cout << "_____________________________________\n";
				cout << "Task number: " << atasknum[i] << endl;
				cout << "Task: " << taskname[i] << endl;
				cout << "Task Due Date: " << taskduedate[i] << endl;
				cout << "Priorities: " << taskpriorities[i] << endl;
				cout << "_____________________________________\n";
			}
		}
	}
}
void user :: updatetask(){
	if(total == 0){
		cout << "No task is added" << endl;
	}else{
		string tasknum;
		cout << "Enter the number of the task you want to update: ";
		cin >> tasknum;
		for(int i = 0; i<total; i++){
			if(tasknum == atasknum[i]){
				cout << "=====================================\n";
				cout << "Previous task" << endl<< endl;
				cout << "Task Informations\n";
				cout << "=====================================\n";
				cout << "Task number: " << atasknum[i] << endl;
				cout << "Task: " << taskname[i] << endl;
				cout << "Task Due Date: " << taskduedate[i] << endl;
				cout << "Priorities: " << taskpriorities[i] << endl;
				
				cout << "Enter the New Information of task" << endl << endl;
				cout << "=====================================\n";
				cin.ignore();
				cout << "Enter task name: ";
				getline(cin, taskname[i]);
				cout << "Enter due date: ";
				getline(cin, taskduedate[i]);
				cout << "Add priorities: ";
				getline(cin, taskpriorities[i]);
			}
		}
	}
}
void user :: deletetask(){
	if(total == 0){
		cout << "No Task is Added\n";
	}else{
		int a;
		cout << "Enter 1 to delete all task" << endl;
		cout << "Enter 2 to delete specific task" << endl;
		cout << "Enter: ";
		cin >> a;
		if(a==1){
			total=0;
			cout << "All Task Deleted..!!\n";
		}else if(a == 2){
			string tasknum;
			cout<<"______________________________________________\n";
			cout << "Enter Number Of Task You Want To Delete: ";
			cin >> tasknum;
			for (int i = 0; i<total; i++){
				if(tasknum == atasknum[i]){
					for(int j= i; j<total;j++){
						taskname[j]=taskname[j+1];
						atasknum[j]=atasknum[j+1];
						taskduedate[j]=taskduedate[j+1];
						taskpriorities[j]=taskpriorities[j+1];
					}
					total--;
					cout<<"Your Task is deleted..!!\n";
				}
			}
		}else{
			cout <<"Invalid Input";
		}
	}
}
void user :: exit(){
	cout << "Thank You For Using Our System!"<< endl;
	system("exit");
}

int main(int argc, char** argv) {

	user usr;
	int optn;
	char yn;
	 while(true){
	 	system("cls");
	 	cout<< "=====================================\n\n";
	 	cout << setw(20)<<"Task Manager"<<endl<<endl;
	 	cout<< "=====================================\n\n";
	 	cout <<"1."<<setw(10)<<"Add Task\n";
	 	cout <<"2."<<setw(11)<<"View Task\n";
	 	cout <<"3."<<setw(13)<<"Search Task\n";
	 	cout <<"4."<<setw(13)<<"Update Task\n";
	 	cout <<"5."<<setw(13)<<"Delete Task\n";
	 	cout <<"6."<<setw(8)<<"Exit\n";
	cout << "=====================================\n";
	cout << "Enter Transaction: ";
	cin>>optn;
	switch (optn){
		case 1:
		again:
			system("cls");
			usr.tasknum();
			usr.addtask();
			ask:
		cout << "Do you want to add a task again y/n: ";
		cin >>yn;
		if(yn=='Y'||yn == 'y'){
			system("cls");
			goto again;
		}else if (yn =='N' || yn== 'n'){
			system("cls");
		}else{
			goto ask;
		}
		break;
		case 2:
			system("cls");
			usr.displaytask();
			system("pause");
			break;
		case 3:
			system("cls");
			usr.searchtask();
			system("pause");
			break;
		case 4:
			system("cls");
			usr.updatetask();
			system("pause");
			break;
		case 5:
			system("cls");
			usr.deletetask();
			system("pause");
			break;
		case 6:	
			usr.exit();
			return 0;
			system("cls");
		default:
			cout << "Invalid Input";
			break;	
	   }
	 }
	return 0;
}
