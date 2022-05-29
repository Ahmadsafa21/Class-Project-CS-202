#include "database.h"
//  Ahmed Safa
//  The purpose of this file is to make a user interface   



class interface
{

    public:
        interface();
        void buildQuestions();
        void getUserInput();
        bool userDecision();



    protected:
        arr_dll ARR_dll;
        char input;
        char category;
        int node_num;
        int userNewDif;
        string userQuestion;
};
