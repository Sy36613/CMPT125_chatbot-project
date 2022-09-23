#pragma once
#include "Menu.h"
#include "Song.h"
#include <algorithm>

using namespace std;
//template<class Song>

class Database{

private:

    int cap;
    int sz;
    Song* arr;

public:


    Database()
    :cap(5),sz(0),arr(new Song[cap])
    {}

    ~Database(){
        delete [] arr;
        cout<<"database: destructor called\n";
    }

    int size() const {return sz;}
	int capacity() const{return cap;}

    void changeCap(int newCap){
        assert(newCap >=0);
        Song* newArr = new Song[newCap];
        for(int i = 0; i<sz;i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        cap = newCap;
    }

    void append(Song s){
        if(sz==cap){
            changeCap(cap*2);
        }
        arr[sz] = s;
        sz++;
    }

    string tolowercase(const string &s){
        string newString = s;
        for(int i = 0; i<newString.size();i++){
            if(newString[i]>=65&&s[i]<=90){
                newString[i]+=32;
            }
        }
        return newString;
    }

    void findBySongName(const string &s){
        string lowercaseS = tolowercase(s);
        Database findList;

        for(int i =0; i<sz;i++){
            if(this->arr[i].song() == lowercaseS){
               findList.append(this->arr[i]);
            }
        }
        if(findList.size()!=0){
            printList(findList);
        }
    }

    void findByName(const string &s){
        string lowercaseS = tolowercase(s);
        Database findList;

        for(int i =0; i<sz;i++){
            if(this->arr[i].artistFirstName()+  
                this->arr[i].artistLastName() == lowercaseS ||
                this->arr[i].artistFirstName() ==lowercaseS||
                this->arr[i].artistLastName()==lowercaseS){
               findList.append(this->arr[i]);
            }
        }
        if(findList.size()!=0){
            printList(findList);
        }
        
    }

    void findByyear(const int &year){
        Database findList;

        for(int i = 0; i<sz;i++){
            if(this->arr[i].yearPublished()== year){
                findList.append(this->arr[i]);
            }
        }
        print_notempty(findList);
    }

    void findByyear(const int &begin, const int &end){
        Database findList;
        assert(begin>=0 && end>=0 && end-begin>=0);
        for(int i =begin; i<=end;i++){
            for(int j = 0; j<sz;j++){
                if(this->arr[j].yearPublished()== i){
                    findList.append(this->arr[j]);
                }
            }
        }
        print_notempty(findList);
    }

    bool isSubstring(const string &s1, const string &s2){
        int length1 = s1.size();
        int length2 = s2.size();
        if(length1<length2){
            return false;
        }
        for(int i = 0; i<=length1-length2;i++){
            int curr = i;
            string s="";
            for(int j = 0;j<length2;j++){
                s +=s1[curr];
                curr++;
            }
            if(s==s2){
                return true;
            }
        } 
        return false;
    }

    void findBySubstring(const string &s){
        Database findList;
        for(int i = 0; i<sz;i++){
            if(isSubstring(this->arr[i].song(),s)){
                findList.append(this->arr[i]);
            }
        }
        print_notempty(findList);
    }

    void alpha_order(){

    }

    void printList(const Database& data){
        for(int i = 0; i<data.sz;i++){
            cout<<"Song: "<<data.arr[i].song()<<
            ",\t"<<data.arr[i].artistFirstName()<<" "<<
            data.arr[i].artistLastName()<<",\t"<<
            data.arr[i].yearPublished()<<"\n";
        } 
    }

    void print_notempty(const Database& data){
        if(data.size()!=0){
            printList(data);
        }
    }

};