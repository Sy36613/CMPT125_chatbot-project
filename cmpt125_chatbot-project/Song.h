#pragma once
#include <iostream>      
#include <fstream>      
#include <string>       
#include <algorithm>    
#include <cassert> 
#include "Menu.h"
#include "Database.h"

using namespace std;

class Song{
private:
    string songName;
    string lastName;
    string firstName;
    int year;

public:

    Song(){}

    Song(string song, string lastname, string firstname, int yearPublished):
    songName(song),lastName(lastname),firstName(firstname),year(yearPublished)
    {
        if(year<0){
            cout<<"Please enter valid year value";
        }
    }
    
    string song() const {return songName;}
    string artistFirstName() const {return firstName;}
    string artistLastName() const {return lastName;}
    int yearPublished() const {return year;}

    ~Song(){
        //cout<<"call Song destructor\n";
    };

    void print(){
        cout<<songName<<", "<<firstName<<" "<<lastName
        <<", "<<year<<endl;
    }
};