#include "concepts.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;


generalConcept::generalConcept(const generalConcept &source)
{
    
}


generalConcept::generalConcept():
    general_name{nullptr}
{
}

generalConcept::~generalConcept()
{
    if (general_name)
        delete [] general_name;
}


exam_prep::exam_prep():
    question_type{nullptr},
    sample_question{"Empty"},
    difficulty{0},
    more{false}
{
}
exam_prep::~exam_prep()
{
    if (question_type)
        delete [] question_type;
}

exam_prep::exam_prep(const string &question, const int &difficulty):
    sample_question{question},
    difficulty{difficulty},
    more{false}
{
    question_type = new char [strlen("MCQ")+1];
    strcpy(question_type, "MCQ");
}

exam_prep::exam_prep(const exam_prep &from):
    generalConcept(from),
    question_type{new char [strlen(from.question_type)+1]},
    sample_question{from.sample_question},
    difficulty{from.difficulty}
{
    strcpy(question_type, from.question_type);
}

void exam_prep::display(const int &num)
{
    cout << endl << num << "-Question: " << sample_question << endl;
    cout << "Difficulty: " << difficulty << "/10" << endl;
    cout << "Question Type: " << question_type<< endl;
    if (more)
    {
        cout << "This question needs more practice" << endl;
    }
}

void exam_prep::changeDifficulty(const int &newDif)
{
    difficulty = newDif;
    cout << "The difficulty has been changed to " << difficulty << "/10" << endl;
    
}

void exam_prep::edit(const string &question)
{
    sample_question = question;
    cout << "The question now is: " << sample_question << endl;
}

void exam_prep::more_practice(bool &morePractice)
{
    more = morePractice;
    if(morePractice)
        cout << "This question needs more practice" << endl;
}

void exam_prep::setQuestion(string &question)
{
    sample_question = question;
}

string exam_prep::getQuestion()
{
    return sample_question;
}
practice::practice():
    question{"Empty"},
    prototype{"Empty"},
    difficulty{0},
    more{false}
{
}
practice::practice(const string &question, const string &prototype, const int &dif):
    question{question},
    prototype{prototype},
    difficulty{dif},
    more{false}
{
}

void practice::display(const int &num)
{
    cout << endl << num << "-Question: " << question << endl;
    cout << "Prototype: " << prototype << endl;
    cout << "Difficulty: " << difficulty << "/10" << endl;
    if (more)
    {
        cout << "This question needs more practice" << endl;
    }
}

void practice::changeDifficulty(const int &newDif)
{
    difficulty = newDif;
    cout << "The difficulty has been change to " << difficulty << "/10" << endl;
}


void practice::edit(const string &question)
{
    this->question = question;
    cout << "The questions now is: " << this->question << endl;
}

void practice::more_practice(bool &morePractice)
{
    more = morePractice;
    if (morePractice)
        cout << "Question has been marked for more practice" << endl;
}

void practice::setQuestion(string &question)
{
    this->question = question;
}

string practice::getQuestion()
{
    return question;
}


master_practice::master_practice():
    practice_topic{"empty"},
    question_count{0},
    more{false},
    complete{false}
{
}

master_practice::master_practice(const string &practice_topic):
    practice_topic{practice_topic},
    more{false},
    complete{false}
{
}

void master_practice::display(const int &num)
{
        cout << "Topic "<< num <<": " << practice_topic << endl;
        if (more)
        {
            cout << "This question needs more practice" << endl;
        }
        if (complete)
        {
            cout << "This question has been completed!" << endl;
        }
}

void master_practice::changeDifficulty(const int &newDif)
{

}

void master_practice::edit(const string &topic)
{
    practice_topic = topic;
    cout << "The topic now is: " << practice_topic << endl;
}

void master_practice::more_practice(bool &morePractice)
{
    more = morePractice;
    if (morePractice)
        cout << "Question has been marked for more practice" << endl;
}

void master_practice::setQuestion(string &topic)
{
    practice_topic = topic;
}
void master_practice::completed()
{
    cout << "Question will be marked as completed"<< endl;
    complete = true;
}

string master_practice::getQuestion()
{
    return practice_topic;
}




    











