#include "Menu.h"
#include <iostream>
#include "Database.h"
#include "Song.h"
using namespace std;

template<typename menu>

void print(const menu list1){
    menu list  = list1;
}


int main(){
    
    menu songlist;
    songlist.menuList();
    Database list;
    list = songlist.database();
    
    //cout<<songlist.database().size();
    //cout<<songlist.database().capacity();
    // arr.printList(arr);

    // Song song{"rolling in the deep", "Adele","qwe", 2006};
    // Song song1{"the deep","steven","asd", 2012};
    // Song song2{"aaaa","bbbb", "asd", 2006};
    // Song song3{"bb","bbbb", "wes", 2012};
    // Song song4{"dd","eeee", "qwe", 2008};
     

    // // // // //song.print();
    
    // Database arr;
    // arr.append(song);
    // arr.append(song1);
    // arr.append(song2);
    // arr.append(song3);
    // arr.append(song4);
    // arr.alpha_order();
    // arr.printList(arr);
    // arr.findByName("qwe");

    //menu<Database> LIST;
    //Database data = LIST.database();
    //arr.findByyear(2006);
    //arr.findByyear(2008,2012);
    //arr.findBySubstring("deep");
    // cout<<arr.size()<<endl;
    // cout<<arr.capacity()<<endl;

    //menu songlist;

    //songlist.menuList();
    //Database list = arr.findBySongName("Rolling in the deep");
    //list.printList(list);
    //cout<<list.size()<<endl;
    //cout<<song.artistName()<<endl;
     

    return 0;


}