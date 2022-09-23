#pragma once
#include "Database.h"
#include "Song.h"
#include <iostream>      
#include <fstream>      
#include <string>       
#include <algorithm>    
#include <cassert>

using namespace std;

template<typename Database>

class menu{

private:

    Database* data;
   
public:

    menu()
    :data(new Database)
    {}

    ~menu(){
        cout<<"call destructor\n";
    };
    
    Database database(){
        return *data;
    }

    void menuList(){
        cout<< "(A)dd a song."<<endl;
        cout<< "(F)ind a song."<<endl;
        cout<< "(D)elete a song."<<endl;
        cout<< "(L)ist songs."<<endl;
        cout<< "(Q)uit"<<endl;
        choose();
    }

    void addSong(){
        cout<<"Please enter the name of Song:"<<endl;
        string song;
        cin>>song;
        cout<<"Please enter the last name of Artist:"<<endl;
        string lastname;
        cin>>lastname;
        cout<<"Please enter the first name of Artist:"<<endl;
        string firstname;
        cin>>firstname;
        cout<<"please enter the published year:"<<endl;
        int year;
        cin>>year;
        while (year<0){
            cout<<"Please enter valid number:"<<endl;
            cin>>year;
        }
        Song s(song,lastname,firstname,year);
        data->append(s);
        menuList();
    }

    void choose(){
        char choice;

        while (true){
            cout<<"Please enter your choice:\n";
            cout<<"(Enter the capital letter of the options)\n";
            cin>>choice;
            switch (choice){
                case 'A':
                    addSong();
                    break;
                case 'F':
                    break;
                case 'D':
                    break;
                case 'L':
                    break;
                case 'Q':
                    exitMenu();
                    break;
                default:
                    cout<<"Please enter valid option\n";
                    cin>>choice;
                    break;
            }   
        }
    }

    void exitMenu(){
        cout<<"Thank you for using !\n";
        exit(0);        
    }
};