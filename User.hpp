#pragma once

#include<string>
#include<set>

class User{
  private:
    int id;
    std::string username;
    std::string password;
    bool isAdmin;

  public:
    User(int id, std::string username, std::string password,bool isAdmin){
       this->id=id;
       this->username=username;
       this->password=password;
       this->isAdmin=isAdmin;
    }  
    
    int getUserId(){
        return id;
    } 

    bool isUserAdmin(){
      return isAdmin;
    }

    std::string getUsername(){
      return username;
    }

    std::string getPassword(){
      return password;
    }

};