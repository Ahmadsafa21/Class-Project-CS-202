#include <cstring>
#include <string>

//  Ahmed Safa  
//  The purpose of this file is to support the hierarchy  
//  I'm creating and support my abstract base class

using namespace std;



class generalConcept
{
    public:
        generalConcept();
        virtual ~generalConcept();
        generalConcept(const generalConcept &from);


        virtual void display(const int &num) = 0;

        virtual void changeDifficulty(const int &newDif)= 0;
        virtual void edit(const string &question)= 0;
        virtual void more_practice(bool &morePractice)= 0;
        virtual void setQuestion(string &question)= 0;
        virtual string getQuestion() = 0;

    protected:

        char * general_name;

};


class exam_prep:public generalConcept
{
    public:

        exam_prep();
        ~exam_prep();
        exam_prep(const string &question, const int &difficulty);
        exam_prep(const exam_prep &from);
        
        void display(const int &num);

        void changeDifficulty(const int &newDif);
        void edit(const string &question);
        void more_practice(bool &morePractice);
        void setQuestion(string &question);
        string getQuestion();




    protected:

        char * question_type;
        string sample_question;
        int difficulty;
        bool more;
};


class practice:public generalConcept
{
    public:
        practice();
        practice(const string &question, const string &prototype, const int &dif);



        void display(const int &num);

        void changeDifficulty(const int &newDif);
        void edit(const string &question);
        void more_practice(bool &morePractice);
        void setQuestion(string &question);
        string getQuestion();
        

    protected:
        string question;
        string prototype;
        int difficulty;
        bool more;


};


class master_practice:public generalConcept
{

    public:
        master_practice();
        master_practice(const string &practice_topic);
        
        void display(const int &num);

        void changeDifficulty(const int &newDif);
        void edit(const string &topic);
        void more_practice(bool &morePractice);
        void setQuestion(string &topic);
        void completed();
        string getQuestion();


    protected:
        string practice_topic;
        int question_count = 1;
        bool more;
        bool complete;
};






