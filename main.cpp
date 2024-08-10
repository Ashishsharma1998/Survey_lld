#include<iostream>
#include "Survey.hpp"
#include "User.hpp"
#include "Question.hpp"
#include "Option.hpp"

using namespace std;


int main(){
   
   //survey1
   Survey *survey1 = new Survey();
   survey1->registerUser("john","123456",true);
   User *admin = survey1->login("john","123456");

   Option *op1 = new Option(1,4);
   Option *op2 = new Option(2,6);
   Option *op3 = new Option(3,8);

   Question *question1 = new Question(1,0,"what is your feedback1?",{op1,op2,op3});
   
   survey1->setQuestion(question1,admin->getUserId());

   survey1->registerUser("Ashish","123",false);
   survey1->registerUser("Raghav","123",false);

   User *user1 = survey1->login("Ashish","123");
   User *user2 = survey1->login("Raghav","123");

   survey1->chooseOption(question1->getQuestionId(),op2,user1->getUserId());
   survey1->chooseOption(question1->getQuestionId(),op3,user2->getUserId());

   double ratings1 = survey1->getAverageRatingsOfQuestion(1);

   cout<<"ratings of question 1 "<<ratings1<<"\n";

   cout<<"rating of question 1 "<<question1->getRatings()<<"\n";

   survey1->updateQuestion(question1->getQuestionId(),"feedback please?",admin->getUserId());

   cout<<question1->getQuestionContent()<<"\n";

   //survey2 
   Survey *survey2 = new Survey();

   survey2->registerUser("john cena","123456",true);
   User *admin2 = survey2->login("john cena","123456");

   Option *op4 = new Option(1,4);
   Option *op5 = new Option(2,5);
   Option *op6 = new Option(3,8);

   Question *question2 = new Question(1,0,"what is your feedback2?",{op4,op5,op6});
   
   survey2->setQuestion(question2,admin2->getUserId());

   survey2->registerUser("Harsh","123",false);
   survey2->registerUser("Raghav","123",false);

   User *user3 = survey2->login("Harsh","123");
   User *user4 = survey2->login("Raghav","123");

   survey2->chooseOption(question2->getQuestionId(),op4,user3->getUserId());
   survey2->chooseOption(question2->getQuestionId(),op5,user4->getUserId());

   double ratings2 = survey2->getAverageRatingsOfQuestion(1);

   cout<<"ratings of question 2 "<<ratings2<<"\n";

   
   return 0; 
}