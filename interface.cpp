#include "interface.h"
#include <iostream>

using namespace std;

interface::interface():
    input{0},
    category{0},
    node_num{0},
    userNewDif{0},
    userQuestion{"empty"}
{
}

void interface::buildQuestions()
{

    ARR_dll.insert(1, "Define what a copy constructor does", 6, "");
    ARR_dll.insert(1, "What are the advantages of having a hierarchy?", 5 ,"");
    ARR_dll.insert(1, "What is RTTI ?", 4, "");

    ARR_dll.insert(2, "Count the even numbers in a CLL/LLL/DLL and return their sum", 3, "int count_num(node *& curr)" );
    ARR_dll.insert(2, "Find the largest number and print it out in a CLL/LLL/DLL", 5, "bool largest_found(node *& curr)" );
    ARR_dll.insert(2, "Return the sum of all unique data in a CLL/LLL/DLL", 7, "int unique_sum(node *& curr, int &unique)");

    ARR_dll.insert(3, "Recursion", 0, "");
    ARR_dll.insert(3, "Binary search trees", 0, "");
    ARR_dll.insert(3, "Dynamic Binding", 0, "" );

    ARR_dll.display();
}


void interface::getUserInput()
{
    try
    {
        while (category != 'q')
        {
            cout << "\nWhich category do you want to modify? (1/2/3) or 'q' to exit" << endl;
            cout << "1 for exam preparation" << endl;
            cout << "2 for programming problems" << endl;
            cout << "3 for topics to work on after the term is over" << endl;
            cout << "----> ";
            cin >> category;

            if(category == 'q')
                throw category;
            else 
            {
                if (category != '1' && category != '2' && category != '3' )
                    throw category;
            }

            cout << "Which question would you like to modify? " << endl; 
            cout << "Enter (1/2/3): " ;
            cin.clear();
            cin >> node_num;
            if (node_num != 1 && node_num != 2 && node_num != 3)
                throw node_num;

            cout << "\nPick one of the options or 'q' to exit\n" << endl;

            if (category == '3')
            {
                cout << "1- Edit a question" << endl;
                cout << "2- Mark topic for more practice" << endl;
                cout << "3- Mark topic as completed" << endl;
            }
            else
            {
                cout << "1- Edit a question" << endl;
                cout << "2- Mark question for more practice" << endl;
                cout << "3- Rate the difficulty" << endl;
            }
            cout << "----> ";
            cin >> input;
            cin.clear();
            cin.ignore();
            if (input == 'q')
                throw input;

            if (input != '1' && input != '2' && input != '3')
                throw input;

            if (userDecision() )
                ARR_dll.display();
        }
    }

    
        catch(char &invalid)
        {
            if (invalid == 'q')
            {
                cout << "Quitting successfully" << endl;
//                exit(0);
            }
            else
            {
                cout << "Wrong input exception handler called" << endl;
//                exit(0);
            }
        }
        catch(...)
        {
            cout << "Wrong input character excepting handler called" << endl;
//            exit(0);
        }
}

bool interface::userDecision()
{
    if (input == '1')
    {
        cout << "Please enter the new question you want: ";
        getline(cin, userQuestion);
    }
    if (input == '3' && category == '3')
    {
//        cout << "Question will be marked as completed" << endl;
    }
    else if (input == '3' && category != '3')
    {
        cout << "Enter the difficulty: ";
        cin >> userNewDif;
    }

    return ARR_dll.find(category, node_num, input, userQuestion, userNewDif );
}










