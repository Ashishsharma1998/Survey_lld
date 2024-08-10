#pragma once

class Option{
  private:
   int id;
   int weight;
  public:
    Option(int id,int weight){
        this->id=id;
        this->weight=weight;
    } 
   int getOptionId(){
    return this->id;
   } 

   int getOptionWeight(){
    return this->weight;
   }
};