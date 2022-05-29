#include "concepts.h"
//  Ahmed Safa              
//  The purpose of this code is to support my data structure 


class node // Node for ARR
{
    public:
        node();
        ~node();
        node(const node &from);

        node *& getNext();
        void setNext(node * next);

        node *& getPrev();
        void setPrev(node * previous);
        
        generalConcept *& getBase();
        void setBase(generalConcept * base_pointer);

    protected:
        node * next;
        node * prev;
        generalConcept * base_pointer;
};


class arr_dll //Array of doubly linked lists
{
    public:
        arr_dll();
        ~arr_dll();
        arr_dll(const arr_dll &source);


        void insert(const int &index, const string &question, const int &dif, const string &prototype);
        void remove(const int &index, const string &question);
        void display();
        bool find(const int &num, const int &nodeNum, const char &userOption, const string &question, const int &newDif);
        void remove_all();


    protected:
        node ** doubly_array;
        int Qpractice_num;
        int QexamPrep_num;
        int QmasterTopic_num;
        int temp;

        //recursive
        void insert_exam(const string &question, node *& curr, const int &dif);
        void insert_practice(const string &question, node *& curr, const int &dif, const string &prototype);
        void insert_masterTopic(const string &topic, node *& curr);
        void remove(node *& curr, const string &question);
        void _display(node * curr, int &num);
        bool _find(node *& curr, const int &userNum, const int &nodeNum, const char &userOption, int &temp, const string &question, const int &newDif);
        void _remove_all(node *& curr);

        
};

