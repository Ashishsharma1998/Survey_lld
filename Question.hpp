#pragma once

#include "Option.hpp"
#include<vector>
#include<string>


class Question{
 private:
  int id;
  double ratings;
  std::string content;
  std::vector<Option*> options;
 public:
  Question(int id,double ratings,std::string content,std::vector<Option*> options){
     this->id=id;
     this->ratings=ratings;
     this->content=content;
     this->options=options;
   } 

   int getQuestionId(){
    return this->id;
   }
   
   void setRatings(double rate){
     this->ratings=rate;
   }
   int getRatings(){
    return this->ratings;
   }

   void updateQuestion(std::string content){
      this->content=content;
   }
    
   std::string getQuestionContent(){
      return this->content;  
   } 

   std::vector<Option*> getAllOptions(){
    return this->options;
   }
};
