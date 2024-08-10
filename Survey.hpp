#pragma once

#include<iostream>
#include "Question.hpp"
#include "Option.hpp"
#include "User.hpp"
#include<map>
#include<vector>

class Survey{
  private:

    std::map<int,Question*> questions;
    std::map<int,std::vector<Option*>> pickedOptions; //questinid:->{options}
    std::map<int,User*> users;

   public:
   
   Survey(){
        std::cout<<"New survey has been instantiated\n";
    }
   
      
    void registerUser(std::string username,std::string password,bool isAdmin){
       User *user = new User(generateId(),username,password,isAdmin);
       users[user->getUserId()]=user;
    }  

   User *login(std::string username,std::string password){
        for(auto it:users){
          if(it.second->getUsername()==username && it.second->getPassword()==password){
            return it.second;
          }
        }
        return nullptr;
   } 

    void setQuestion(Question *question,int userId){
       User *user = users[userId];
       if(!user->isUserAdmin()){
          std::cout<<"you are not admin\n";
          return;
       }
       questions[question->getQuestionId()]=question;
    }

    void deleteQuestion(int questionId,int userId){
       User *user = users[userId];
       if(!user->isUserAdmin()){
          std::cout<<"you are not admin\n";
          return;
       }
       questions.erase(questionId);  
    }

    void updateQuestion(int questionId,std::string content,int userId){
    User *user = users[userId];
    if (!user->isUserAdmin()) {
        std::cout << "You are not an admin\n";
        return;
    }

    // Check if the questionId exists in the map
    auto it = questions.find(questionId);
    if (it == questions.end()) {
        std::cout << "Question with ID " << questionId << " does not exist\n";
        return;
    }

    Question *q = it->second;
    if (q) {
        q->updateQuestion(content);
    } else {
        std::cout << "Error: Question pointer is null\n";
    }
    }
       
  
    std::vector<Option*> getAllOptionsOfQustions(int questionId){
        Question *q = questions[questionId];
        return q->getAllOptions();
    }

    void chooseOption(int questionId,Option *opt,int userId){
       User *user = users[userId];
       if(user->isUserAdmin()){
          std::cout<<"you are admin\n";
          return;
       }
      pickedOptions[questionId].push_back(opt);   
    }


    double getAverageRatingsOfQuestion(int questionId){
        std::vector<Option*> ops = pickedOptions[questionId];
        Question *question = questions[questionId];
        int sz = ops.size();
        if(sz==0){
         std::cout<<"user haven't choose any options for this question\n";
         return 0;
        }
        int sum=0;
        for(Option* op:ops){
            sum+=op->getOptionWeight();
        }
        
        double rate = sum/sz;
        question->setRatings(rate);
        return rate;
     }


      int generateId(){
      return rand()%99999999;
      }
 
};



