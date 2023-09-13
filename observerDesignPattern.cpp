/****************************************************************
*   Problem: Observer Design pattern                             *
*   Author:  https://github.com/anonymousAlpha-96               *
*   Date:    26.Aug.23                                          *
*****************************************************************/



#include <iostream>
#include <list>

using namespace std;

class Isubscriber{

    public:
    virtual void notify(string msg)=0;
};

class User:public Isubscriber{
    private:
    int userID;
    public:
    User(int id)
    {
        userID = id;
    }
    void notify(string msg){
        cout<<"User : "<<userID<<" recived new notification : "<<msg<<endl;
    }
};

class Group{
    private:
    list<Isubscriber*> users;
    public:
    void subscribe(Isubscriber* user)
    {
        users.push_back(user);
    }
    void unsubscribe(Isubscriber* user)
    {
        users.remove(user);
    }
    void notify(string msg)
    {
        for(auto user: users)
        {
            user->notify(msg);
        }
    }

};

int main()
{
    Group* group = new Group;
    

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);
    
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("last msg from version 12.0!");

    group->unsubscribe(user1);

    group->notify("first msg from version 13.0!");

    return 0;
}
