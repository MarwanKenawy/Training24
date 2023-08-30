#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int id;
    char* description;
    bool completed;
}Task;

//Global variables
vector<Task*> v; //vector of pointers instead of an array
int ids_of_tasks = 0; //As the ids are unique, for example if task 1 is removed and added a new a task it will be of id 2 not 1

//Function prototype
void menu();
void add();
void view();
void remove_task();
void mark_completed();
void view_status();
vector<Task*>::iterator search(int);

int main()
{
    menu();
    return 0;
}

void menu()
{
    while(true)
    {
        cout<<"\n====Minions Task Manager====\n"
            "1.Add Task\n"
            "2.View Tasks\n"
            "3.Remove Task\n"
            "4.Mark as completed\n"
            "5.View Tasks status\n"
            "6.Exit\n"
            "\nSelect an option: ";
        char option;
        cin>>option;
        while(!(option>='1' && option<='6')) //validation of input
        {
            cout<<"Invalid option!\nSelect an option: ";
            cin>>option;
        }
        switch (option)
        {
            case '1':
                add();
                break;
            case '2':
                view();
                break;
            case '3':
                remove_task();
                break;
            case '4':
                mark_completed();
                break;
            case '5':
                view_status();
                break;
            case '6':
                cout<<"\nExiting Minions Task Manager... Have a great day!\n\n";
                return;
        }
    }   
}
Task*init(int id,char*description)
{
    //initializing node
    Task*t = (Task*)malloc(sizeof(Task));
    t->description = (char*)malloc(strlen(description)+1);
    t->id = id;
    strcpy(t->description, description);
    t->completed = false;
    return t;
}
void add()
{
    char description[1000];
    cout<<"\nEnter task description: ";
    scanf(" %[^\n]s",description);
    int id = ++ids_of_tasks;
    Task*t = init(id,description);
    v.push_back(t);
    cout<<"Task added successfully!\n";
}
void view()
{
    if(!v.empty())
    {
        cout<<"\nCurrent Tasks:\nID\t\tDescription\n";
        vector<Task*>::iterator it;
        for(it = v.begin();it < v.end();it++)
        {
            cout<<(*it)->id<<"\t\t"<<(*it)->description<<endl;
        }
    }
    else
    {
        cout<<"No Tasks required\n";
    }
}
void remove_task()
{
    int idtofind;
    cout<<"\nEnter task ID to remove: ";
    cin>>idtofind;
    vector <Task*>::iterator it = search(idtofind);
    if(it!=v.end())
    {
        free(*it);
        v.erase(it);
        cout<<"Task removed successfully!\n";
    }
    else
        cout<<"Not Found!\n";
}
vector<Task*>::iterator search(int id)
{
    vector<Task*>::iterator it;
    for(it = v.begin();it<v.end();it++)
    {
        if((*it)->id==id)
            return it;
    }
    return v.end();
}
void mark_completed()
{
    int idtofind;
    cout<<"\nEnter task ID to edit to \"completed\": ";
    cin>>idtofind;
    vector <Task*>::iterator it = search(idtofind);
    if(it!=v.end())
    {
        (*it)->completed = true;
        cout<<"Task removed successfully!\n";
    }
    else
        cout<<"Not Found!\n";
}
void view_status()
{
    if(!v.empty())
    {
        cout<<"\nCurrent Tasks:\n\nID\tStatus\t\tDescrption\n";
        vector<Task*>::iterator it;
        for(it = v.begin();it < v.end();it++)
        {
            cout<<(*it)->id;
            if((*it)->completed == true)
                cout<<"\tCompleted\t";
            else
                cout<<"\tIncomplete\t";
            cout<<(*it)->description<<endl;
        }
    }
    else
    {
        cout<<"No Tasks required\n";
    }
}