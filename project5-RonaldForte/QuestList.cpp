/* 
Ronald A Forte Jr.
Ronald.ForteJr63@myhunter.cuny.edu
Due 11/10/23
Project 5
*/

#include "QuestList.hpp"
#include <fstream>
#include <sstream>
#include <cmath> //for floor function

/**
    Default Constructor
*/
//QuestList default constructor
QuestList::QuestList() : DoublyLinkedList<Quest*>() {}
/**
    @param: a reference to string name of an input file
    @pre: Formatting of the csv file is as follows:
        Title: A string
        Description: A string
        Completion Status: 0 (False) or 1 (True)
        Experience Points: A non negative integer
        Dependencies: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
        Subquests: A list of Quest titles of the form [QUEST1];[QUEST2], where each quest is separated by a semicolon. The value may be NONE.
    Notes:
        - The first line of the input file is a header and should be ignored.
        - The dependencies and subquests are separated by a semicolon and may be NONE.
        - The dependencies and subquests may be in any order.
        - If any of the dependencies or subquests are not in the list, they should be created as new quests with the following information:
            - Title: The title of the quest
            - Description: "NOT DISCOVERED"
            - Completion Status: False
            - Experience Points: 0
            - Dependencies: An empty vector
            - Subquests: An empty vector
        - However, if you eventually encounter a quest that matches one of the "NOT DISCOVERED" quests while parsing the file, you should update all the quest details.
        Hint: update as needed using addQuest()
        

    @post: Each line of the input file corresponds to a quest to be added to the list. No duplicates are allowed.

*/

//QuestList param constructor
QuestList::QuestList(const std::string& file) : DoublyLinkedList<Quest*> (){
        std::ifstream read(file);
        if(!read.is_open()){
            std::cout << "Try again, File couldn't open.";
        }
        std::string firstline; //we dont care about the first line in csv
        getline(read, firstline);
        
        std::string questTitle, descrip, depends, squest;
        int exp;
        bool complete;
        std::vector<Quest*> dependvect = {};
        std::vector<Quest*> subvect = {};


        std::string longline = "";
        while(getline(read, longline)){
            std::istringstream str(longline); //parsing the long line :,)
            std::string conversion;
            getline(str, questTitle, ','); //Holding the QuestTitle
            getline(str, descrip, ',');

            getline(str, conversion, ',');
            complete = stoi(conversion);

            getline(str, conversion, ',');
            exp = stoi(conversion);

            getline(str, depends, ',');
            std::vector<Quest*> dependvect;
            std::string empt = "";
            std::istringstream depparse(depends);

            while(getline(depparse, empt, ';')){
                if(empt != "NONE"){
                    if(getPosOf(empt) != -1){
                    Node<Quest*> *lmao = getPointerTo(getPosOf(empt));
                    dependvect.push_back(lmao -> getItem());
                }
                else{
                    Quest* submit = new Quest;
                    submit -> title_ = empt;
                    submit -> description_ = "NOT DISCOVERED";
                    submit -> completed_ = false;
                    submit -> experience_points_ = 0;
                    submit -> dependencies_ = {};
                    submit -> subquests_ = {};
                    addQuest(submit);
                    dependvect.push_back(submit);
                }
            }
                

            }
            //for subq
            getline(str, squest, ',');
            std::vector<Quest*> subvect;
            std::string empstr = "";
            std::istringstream subparse(squest);

            while(getline(subparse, empstr, ';')){
                if(empstr != "NONE"){
                    if(getPosOf(empstr) != -1){
                        Node<Quest*> *lmao4sub = getPointerTo(getPosOf(empstr));
                        subvect.push_back(lmao4sub -> getItem());
                    }
                    else{
                        Quest* submit = new Quest;
                        submit -> title_= empstr;
                        submit -> description_ = "NOT DISCOVERED";
                        submit -> completed_ = false;
                        submit -> experience_points_ = 0;
                        submit -> dependencies_ = {};
                        submit -> subquests_ = {};
                        addQuest(submit);
                        subvect.push_back(submit);
                    }
                }
            }
            addQuest(questTitle, descrip, complete, exp, dependvect, subvect);
        }
        //(const std::string& title, const std::string& description, const bool& completed, const int& exp, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquest)
        /*std::string questTitle, descrip, depends, squest;
        int exp;
        bool complete*/
}

/**
    @param: A string reference to a quest title
    @return: The integer position of the given quest if it is in the QuestList, -1 if not found.
*/
int QuestList::getPosOf(const std::string& title)const{
    Node<Quest*> *head = first_;
    int temp = 0;
    while(head != nullptr){
        if(head -> getItem() -> title_ == title){
            return temp;
        }else{
            temp++;
            head = head -> getNext();
        }  

    }
    return -1; //meaning it was not found in list
}

/**
    @param: A string reference to a quest title
    @return: True if the quest with the given title is already in the QuestList
*/
bool QuestList::contains(const std::string& title)const{
    return getPosOf(title) != -1; //return only if it is in the list
}

/**
    @pre: The given quest is not already in the QuestList
    @param:  A pointer to a Quest object
    @post:  Inserts the given quest pointer into the QuestList. Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
            If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
           
    @return: True if the quest was added successfully, False otherwise
*/
bool QuestList::addQuest(Quest* adding){
    if (contains(adding -> title_)) {
        if (getPointerTo(getPosOf(adding -> title_)) -> getItem() -> description_ != "NOT DISCOVERED") {
            return false;
        }
        else {
            getPointerTo(getPosOf(adding -> title_)) -> getItem() -> description_ = adding -> description_;
            getPointerTo(getPosOf(adding -> title_)) -> getItem() -> completed_ = adding -> completed_;
            getPointerTo(getPosOf(adding -> title_)) -> getItem() -> experience_points_ = adding -> experience_points_;
            getPointerTo(getPosOf(adding -> title_)) -> getItem() -> dependencies_ = adding -> dependencies_;
            getPointerTo(getPosOf(adding -> title_)) -> getItem() -> subquests_ = adding -> subquests_;
            
            return true;
        }
    }
    else {
        if (insert(getLength(), adding)) { //for adding depends
            for (auto i: adding -> dependencies_) { //T.A. said use this. Research how it works
                if (!contains(i -> title_)) {
                    addQuest(i); //adding dependd
                }
            }
            for (auto j: adding -> subquests_) { //for adding subquest
                if (!contains(j -> title_)) {
                    addQuest(j); //adding subquest
                }
            }
            return true;
            } else {
                return false;
            }
        }
}

/**
    @param:  A reference to string representing the quest title
    @param:  A reference to string representing the quest description
    @param:  A reference to boolean representing if the quest is completed
    @param:  An reference to int representing experience points the quest rewards upon completion 
    @param:  A reference to vector of Quest pointers representing the quest's dependencies
    @param:  A reference to vector of Quest pointers representing the quest's subquests
    @post:   Creates a new Quest object and inserts a pointer to it into the QuestList. 
             If the quest is already in the list but is marked as "NOT DISCOVERED", update its details. (This happens when a quest has been added to the list through a dependency or subquest list)
             Each of its dependencies and subquests are also added to the QuestList IF not already in the list.
             

    @return: True if the quest was added successfully

*/
bool QuestList::addQuest(const std::string& title, const std::string& description, const bool& completed, const int& exp, const std::vector<Quest*>& dependencies, const std::vector<Quest*>& subquest){
    Quest* quest = new Quest(title, description, completed, exp, dependencies, subquest); //making new quest to add
    return addQuest(quest);
}

/**
    @param:  A Quest pointer
    @return: A boolean indicating if all the given quest's dependencies are completed
*/
bool QuestList::dependenciesComplete(Quest* depcomp){
    for(int i = 0; i < depcomp -> dependencies_.size(); i++){
        if(!(depcomp -> dependencies_[i] -> completed_)){
            return false;
        }
    }
    return true;
}

/**
    @param: A Quest pointer
    @return: A boolean if the given quest is available.
    Note: For a quest to be available, it must not be completed, and its dependencies must be complete.
*/
bool QuestList::questAvailable(Quest* avail){
    if(!dependenciesComplete(avail) || avail -> completed_){
        return false;
    }
    return true;
}

/**
    @param: A Quest pointer
    @post: Prints the quest title and completion status
    The output should be of the form:
    [Quest Title]: [Complete / Not Complete]
    [Quest Description]\n\n
*/
void QuestList::printQuest(Quest* printq){
    std::string temp = "";

    if(printq -> completed_ == true){
        temp= "Complete";
    }
    else{
        temp = "Not Complete";
    }
    std::cout << printq -> title_ << ": " << temp << "\n" << printq -> description_ << "\n\n";
}
        
/**
    @param: A string reference to a quest title
    @post:  Prints a list of quests that must to be completed before the given quest can be started (incomplete dependencies).
            If any of the quest's incomplete dependencies have an incomplete dependency, recursively print the quests that need to be done in order, indenting incomplete quests. 
            The indentation for incomplete quests is 2 spaces: "  "    
            The format of the list should be of the following forms for each different case:

            Query: [Quest Title]
            No such quest.
    
            Query: [Quest Title]
            Quest Complete
    
            Query: [Quest Title]
            Ready: [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
              [Quest Title]
            
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Quest Title]
    
            Query: [Quest Title]
            Ready: [Dependency0]
            Ready: [Dependency1]
              [Dependency2]
              [Quest Title]
              
     If the given quest title is not found in the list, print "No such quest."
*/
void QuestList::questQuery(const std::string& title){
    std::cout << "Query: " << title << "\n";
    
    if (!contains(title)){
        std::cout << "No such quest.\n";
        return;
    }
    
    Quest* quest = getPointerTo(getPosOf(title)) -> getItem();

    if(quest -> completed_){
        std::cout << "Quest Complete\n";
        return;

    } else {
        QueryHelp(quest);
    }
}

//Helper
void QuestList::QueryHelp(Quest* queery){
    if (queery -> dependencies_.empty() || dependenciesComplete(queery)){
        std::cout << "Ready: " << queery -> title_<< "\n";
        return; //if true then stop helping :)
    }
    for (int i =0; i < queery -> dependencies_.size(); i++){
        if (!(queery -> dependencies_[i] -> completed_)){
            QueryHelp(queery -> dependencies_[i]); //recursvive pls be right
        }
    }

    std::cout << "  " << queery -> title_ << "\n";
}

/**
    @return: An integer sum of all the experience gained
    Note: This should only include experience from completed quests 
*/
int QuestList::calculateGainedExperience(){
    Node<Quest*> *uno = first_; //first node in linked list
    int exp = 0;
    while(uno != nullptr){ //iterates the linkedlist
        if(uno -> getItem() -> completed_){
            exp += uno -> getItem() -> experience_points_; //exp++
        }
        uno = uno -> getNext(); //iterate to next node
    }
    return exp;
}
        
/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that can be gained from completing the main quest AND all its subquests.
    Note: Also consider the potential experience if a subquest itself has subquests.
*/ 
int QuestList::calculateProjectedExperience(Quest* domquest){
    int expsum = 0;
    expsum += domquest -> experience_points_; //adding to dominant quest
    for(int i =0; i < domquest -> subquests_.size(); i++){
        expsum += calculateProjectedExperience(domquest -> subquests_[i]); //recursive
    }
    return expsum;
}

/**
    @param: A quest pointer to a main quest
    @return: An integer sum of all the experience that has already been gained by completing the given quest's subquests.
    Note: Also consider the experience gained if a completed subquest itself has subquests.  
*/
int QuestList::calculatePathwayExperience(Quest* domquest){ //kinda the same as calculate projected
    int exppathsum = 0;

    if(domquest -> completed_){
        exppathsum += domquest -> experience_points_;
    }
    for(int i =0; i < domquest -> subquests_.size(); i++){
       exppathsum += calculatePathwayExperience(domquest -> subquests_[i]);
    }
    return exppathsum;
}

/**
    @param: A string reference to a filter with a default value of "NONE".
    @post: With default filter "NONE": Print out every quest in the list.
           With filter "COMPLETE":   Only print out the completed quests in the list.
           With filter "INCOMPLETE": Only print out the incomplete quests in the list.
           With filter "AVAILABLE":  Only print out the available quests in the list.
           If an invalid filter is passed, print "Invalid Filter\n"
    Printing quests should be of the form:
    [Quest title]: [Complete / Not Complete]  
    [Quest description]\n
*/
void QuestList::questHistory(const std::string& filter){ //I have no idea what's happening here. T.A. helped but didnt explain T-T
    if (filter != "NONE" && filter != "COMPLETE" && filter != "INCOMPLETE" && filter != "AVAILABLE") {
        std::cout << "Invalid Filter\n";

    } else {
        Node<Quest*> *uno = first_;
        while (uno != nullptr) {
            if (filter == "NONE") {
                printQuest(uno -> getItem());

            } else if (filter == "COMPLETE") {
                if (uno -> getItem() -> completed_) {
                    printQuest(uno -> getItem());
                }

            } else if (filter == "INCOMPLETE") {
                if (!(uno -> getItem() -> completed_)) {
                    printQuest(uno -> getItem());
                }

            } else if (filter == "AVAILABLE") {
                if (questAvailable(uno -> getItem())) { 
                    printQuest(uno -> getItem());
                }
            }
            uno = uno -> getNext();
        }
    }
}

/**
    @param: A quest pointer to a main quest
    @post:  Outputs subquest pathway. Print quest names with two spaces ("  ") of indentation for each subquest, recursively.
            Also print the percentage of experience gained in this pathway, rounded down to the lower integer.
            The format should be of the form:
            [Main Quest] ([Pathway XP] / [Projected XP]% Complete)
                [Subquest0]: [Complete / Not Complete]
                    [Sub-Subquest01]: [Complete / Not Complete]
                        [Sub-Subquest011]: [Complete / Not Complete]
                    [Subquest02]: [Complete / Not Complete]
            Hint: You can write a helper function to print the subquests recursively. If the given quest is already marked as completed, you can assume that all of its subquests are also completed.
*/
void QuestList::printQuestDetails(Quest* domquest) {
    double pathway = calculatePathwayExperience(domquest); //makes doobley
    double projected = calculateProjectedExperience(domquest); 

    std::cout << domquest -> title_ << " (" <<  int((pathway / projected) * 100) << '%' << " Complete)" << std::endl;  // prints out the quest name and the percentage of it's completion

    if (domquest -> completed_) { 
        return;
    }

    QuestDetailHelp(domquest, 2); 

}

//Helper funct
void QuestList::QuestDetailHelp(Quest* subq, int indent) { //for subquest
    std::string temp = "";

    for (int i = 0; i < indent; i++){ //indent comes up
        temp += " ";
    }

    for (int i = 0; i< subq -> subquests_.size(); i++) {  

        QuestDetailHelp(subq -> subquests_[i], indent + 2); 

        if (subq -> subquests_[i] -> completed_) {
            std::cout << temp << subq -> subquests_[i] -> title_ << ": Complete" << "\n";
        } else {
            std::cout << temp << subq -> subquests_[i] -> title_ << ": Not Complete" << "\n";
        }
    }
}
