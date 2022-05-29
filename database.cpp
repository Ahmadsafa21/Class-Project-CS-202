#include "database.h"
#include <iostream>




node::node():
    next{nullptr},
    prev{nullptr},
    base_pointer{nullptr}
{
}


node::node(const node &from):
    next{from.next},
    prev{from.prev},
    base_pointer{from.base_pointer}
{
}
node::~node()
{
    delete base_pointer;
}


node *& node::getNext()
{
    return next;
}

void node::setNext(node * next)
{
    this->next = next;
}

node *& node::getPrev()
{
    return prev;
}

void node::setPrev(node * previous)
{
    this->prev = previous;
}

generalConcept *& node::getBase()
{
    return base_pointer;
}

void node::setBase(generalConcept * base_pointer)
{
    this->base_pointer = base_pointer;
}


arr_dll::arr_dll():
    Qpractice_num{1},
    QexamPrep_num{1},
    QmasterTopic_num{1},
    temp{0}
{
    doubly_array = new node*[3];

    doubly_array[0] = new node;
    doubly_array[1] = new node;
    doubly_array[2] = new node;

}

arr_dll::~arr_dll()
{
    remove_all();
    delete doubly_array[0];
    delete doubly_array[1];
    delete doubly_array[2];
    delete [] doubly_array;
}

arr_dll::arr_dll(const arr_dll &source)
{

}

void arr_dll::insert(const int &index, const string &question, const int &dif, const string &prototype)
{
    if (index == 1)
    {
        insert_exam(question, doubly_array[0]->getNext(), dif);
        doubly_array[0]->getNext()->getPrev() = nullptr;
    }
    if (index == 2)
    {
        insert_practice(question, doubly_array[1]->getNext(), dif , prototype);
        doubly_array[1]->getNext()->getPrev() = nullptr;
    }

    if (index == 3)
    {
        insert_masterTopic(question, doubly_array[2]->getNext() );
        doubly_array[2]->getNext()->getPrev() = nullptr;
    }
}

void arr_dll::insert_exam(const string &question, node *& curr, const int &dif)
{
    if (!curr)
    {
        curr = new node;
        curr->setBase(new exam_prep(question, dif));
        curr->setNext(nullptr);
        return;
    }

    insert_exam(question, curr->getNext(), dif);
    curr->getNext()->getPrev() = curr;

}
void arr_dll::insert_practice(const string &question, node *& curr, const int &dif, const string &prototype)
{
    if (!curr)
    {
        curr = new node;
        curr->setBase(new practice(question, prototype, dif));
        curr->setNext(nullptr);
        return;
    }
    insert_practice(question, curr->getNext(), dif, prototype);
    curr->getNext()->getPrev() = curr;
}

void arr_dll::insert_masterTopic(const string &topic, node *& curr)
{
    if (!curr)
    {
        curr = new node;
        curr->setBase(new master_practice(topic));
        curr->setNext(nullptr);
        return;
    }
    insert_masterTopic(topic, curr->getNext() );
    curr->getNext()->getPrev() = curr;
}

void arr_dll::remove(const int &index, const string &question)
{
    if (index ==1)
        remove(doubly_array[0]->getNext(), question);
    if (index ==2)
        remove(doubly_array[1]->getNext(), question);
    if (index ==3)
        remove(doubly_array[2]->getNext(), question);
}


void arr_dll::remove(node *& curr, const string &question)
{
    if (curr->getBase()->getQuestion() == question)
    {
        node * hold_next = curr->getNext();
        delete curr;
        curr = hold_next;
        return;
    }
    remove(curr->getNext(), question);
    curr->getNext()->getPrev() = curr;
}

void arr_dll::display()
{
    if(doubly_array[0]->getNext() )
    {
        cout << "\n1- Exam prepartion questions: " << endl;
        _display(doubly_array[0]->getNext(), QexamPrep_num);
    }
    if(doubly_array[1]->getNext() )
    {
        cout << "\n2- Practice questions: " << endl;
        _display(doubly_array[1]->getNext() , Qpractice_num);
    }
    if(doubly_array[2]->getNext() )
    {
        cout << "\n3- Topics to work on after term is over: " << endl;
        _display(doubly_array[2]->getNext() ,QmasterTopic_num);
    }
    QexamPrep_num = 1;
    Qpractice_num = 1;
    QmasterTopic_num = 1;
}

void arr_dll::_display(node * curr, int &num)
{
    if (!curr)
        return;

    curr->getBase()->display(num);

    _display(curr->getNext(), ++num);
}

bool arr_dll::find(const int &num, const int &nodeNum, const char &userOption, const string &question, const int &newDif)
{
    bool tempBool;
    temp  = 0;
    if (num == '1')
        tempBool = _find(doubly_array[0]->getNext(), num, nodeNum, userOption, temp, question, newDif);
    if (num == '2')
        tempBool = _find(doubly_array[1]->getNext(), num, nodeNum, userOption, temp, question, newDif);
    if (num == '3')
        tempBool = _find(doubly_array[2]->getNext(), num, nodeNum, userOption, temp, question, newDif);

    tempBool = true;
    return tempBool;
}

bool arr_dll::_find(node *& curr, const int &userNum, const int &nodeNum, const char &userOption, int &temp, const string &question, const int &newDif)
{
    bool found = false;
    if (temp == nodeNum)
    {
        return true;
    }
    found = _find(curr->getNext(), userNum, nodeNum, userOption, ++temp, question, newDif);

    if (found)
    {
        if (userOption == '1')
        {
            curr->getBase()->edit(question);
            found = false;
        }
        if (userOption == '2')
        {
            curr->getBase()->more_practice(found);
            found = false;
        }
        if (userOption == '3' && userNum =='3')
        {
            master_practice * ptr = dynamic_cast<master_practice*>(curr->getBase());
            if (ptr)
                ptr->completed();
            found = false;
        }
        else if (userOption == '3')
        {
            curr->getBase()->changeDifficulty(newDif);
            found = false;
        }
    }
    return found;
}

void arr_dll::remove_all()
{
    if (doubly_array[0])
        _remove_all(doubly_array[0]->getNext() );
    if (doubly_array[1] )
        _remove_all(doubly_array[1]->getNext() );
    if (doubly_array[2])
        _remove_all(doubly_array[2]->getNext() );
}

void arr_dll::_remove_all(node *& curr)
{
    if (curr == nullptr)
        return;
    node * nextNode = curr->getNext();
    delete curr;
    curr = nextNode;

    _remove_all(curr);
}










