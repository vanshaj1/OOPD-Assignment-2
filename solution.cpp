//******************************************************Question 2****************************************************
#include <iostream>
// #include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <ctime>
#include <typeinfo>
#include<exception>
#define INF (unsigned)!((int)0)


using namespace std;

//********************************************************Open Source************************************************* cite:- https://stackoverflow.com/a/25385766 //
// const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
{
    return ltrim(rtrim(s, t), t);
}

//************************************************************************************************************************//




class user;
class book;
class magzine;
class journal;
class library;

class Item{
 public:
    virtual void setIdentifier(int no,string LibraryName) = 0;
    virtual string getIdentifier() = 0;
    virtual int getUserIdOfTheBorrower(int copy) = 0;
};


class user{
    int uid;
    string name;
    int type;
    string *bookBorrowed;
    string *journalBorrowed;
    string *magzineBorrowed;
    int borrowedBookLength = 0;
    int borrowedJournalLength = 0;
    int borrowedMagzineLength = 0;
    string *issuedDate = new string[0];
    string *returnDate = new string[0];
    public:
     user(){
        bookBorrowed = new string[0];
        journalBorrowed = new string[0];
        magzineBorrowed = new string[0];
     }
     void addDetails(int uid,string name,int type){
        this->uid = uid;
        this->name = name;
        this->type = type;
     }
     int getUserId(){
        return uid;
     }
     string getName(){
        return name;
     }
     int getType(){
        return type;
     }
     void setIssueDate(string issue_temp){
        int len = borrowedBookLength-1;
        string *newIssueArray = new string[len+1];
        for(int i = 0 ;i < len;i++){
            newIssueArray[i] = issuedDate[i];
        }
        newIssueArray[len] = issue_temp;
        issuedDate = newIssueArray;
     }
     void setReturnDate(string return_temp){
        int len = borrowedBookLength-1;
        string *newReturnArray = new string[len+1];
        for(int i = 0 ;i < len;i++){
            newReturnArray[i] = returnDate[i];
        }
        newReturnArray[len] = return_temp;
        returnDate = newReturnArray;
     }
     void borrowBooks(string identifier){
        int len = borrowedBookLength;
        string *newArray = new string[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = bookBorrowed[i];
        }
        newArray[len] = identifier;
        bookBorrowed = newArray;
        borrowedBookLength++;
        
     }
     void borrowMagzines(string identifier){
        int len = borrowedMagzineLength;
        string *newArray = new string[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = magzineBorrowed[i];
        }
        newArray[len] = identifier;
        magzineBorrowed = newArray;
        borrowedMagzineLength++;
        
     }
     void borrowJournals(string identifier){
        int len = borrowedJournalLength;
        string *newArray = new string[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = journalBorrowed[i];
        }
        newArray[len] = identifier;
        journalBorrowed = newArray;
        borrowedJournalLength++;
        
     }
     bool check(int uid){
        if(this->uid == uid){
            return true;
        }
        return false;
     }
     friend class library;
    
};

class book:public Item{
    string book_id;
    string goodreads_book_id;
    string best_book_id;
    string work_id;
    int books_count;
    int books_remaining;
    string isbn;
    string isbn13;
    string author1;
    string author2;
    string author3;
    string author4;
    string author5;
    string original_publication_year;
    string original_title;
    string title;
    string language_code;
    string average_rating;
    string ratings_count;
    string work_ratings_count;
    string work_text_reviews_count;
    string ratings_1;
    string ratings_2;
    string ratings_3;
    string ratings_4;
    string ratings_5;
    string image_url;
    string small_image_url;
    int *borrowedById = new int[0];
    int borrowedByIdLength = 0;
    string *issuedDate = new string[0];
    string *returnDate = new string[0];
    int returnTime[2] ={1,6};
    string identifier;
    string location;
    public:
        book *next;
        void addDetails(string book_id,string goodreads_book_id,string best_book_id,string work_id,int books_count,string isbn,string isbn13,string author1,string author2, string author3, string author4, string author5, string original_publication_year,string original_title,string title,string language_code,string average_rating,string ratings_count,string work_ratings_count,string work_text_reviews_count,string ratings_1,string ratings_2,string ratings_3,string ratings_4,string ratings_5,string image_url,string small_image_url){
            this->book_id = book_id;
            this->goodreads_book_id = goodreads_book_id;
            this->best_book_id = best_book_id;
            this->work_id = work_id;
            this->books_count = books_count;
            this->isbn = isbn;
            this->isbn13 = isbn13;
            this->author1 = author1;
            this->author2 = author2;
            this->author3 = author3;
            this->author4 = author4;
            this->author5 = author5;
            this->original_publication_year = original_publication_year; 
            this->original_title = original_title;
            this->title = title;
            this->language_code = language_code;
            this->average_rating = average_rating;
            this->ratings_count = ratings_count;
            this->work_ratings_count = work_ratings_count;
            this->work_text_reviews_count = work_text_reviews_count;
            this->ratings_1 = ratings_1;
            this->ratings_2 = ratings_2;
            this->ratings_3 = ratings_3;
            this->ratings_4 = ratings_4;
            this->ratings_5 = ratings_5;
            this->image_url = image_url;
            this->small_image_url = small_image_url;
            books_remaining = books_count;

        }
        void setIdentifier(int no,string LibraryName){
            identifier = LibraryName+"/B/" + to_string(no);
            // cout<<identifier<<endl;
        }
        string getIdentifier(){
            return identifier;
        }
        int getRemainigBooks(){
            return books_remaining;
        }
        int getCountOfTotalBooks(){
            return books_count;
        }
        int getUserIdOfTheBorrower(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return INF;
            }else{
                return borrowedById[copy];
            }
        }
        string getIssueDateOfTheBook(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return " ";
            }else{
                return issuedDate[copy];
            }
        }
        string getReturnDateOfTheBook(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return " ";
            }else{
                return returnDate[copy];
            }
        }
        void increaseBookCountByOne(){
            books_count += 1;
            books_remaining += 1;
        }
        bool check(string title,string isbn,string isbn13,string author1,string author2, string author3, string author4, string author5,string identifier){
            if(this->original_title == title && this->isbn == isbn && this->isbn13 == isbn13 && this->author1 == author1 && this->author2 == author2 && this->author3 == author3 && this->author4 == author4 && this->author5 == author5  && this->identifier == identifier){
                // cout<<(this->original_title== title) << (this->isbn == isbn) << (this->isbn13 == isbn13) << (this->author1 == author1) << (this->author2 == author2) << (this->author3 == author3) << (this->author4 == author4) << (this->author5 == author5) << (this->identifier == identifier);
                return true;
            }
            // cout<<(this->identifier == identifier)<<endl;
            // cout<<this->original_title<<  "" << title << this->isbn <<  " " << isbn << this->isbn13 <<  " " << isbn13 << this->author1 <<  " " << author1 << this->author2 <<  " " <<author2 << this->author3 <<  " " << author3 << this->author4 <<  " " << author4 << this->author5 <<  " " << author5 << this->identifier <<  " " << identifier<<endl;
            return false;
        }
        int borrow(user *User){
            if(books_remaining == 0){
                cout<<"no copies are left please come later";
                return 0;
                //call to borrow from another library
            }else{
                books_remaining--;
                int len = borrowedByIdLength;
                string copy_identifier = identifier +"/"+to_string(len);
                User->borrowBooks(copy_identifier);
                int *newArray = new int[len+1];
                for(int i = 0 ;i < len;i++){
                    newArray[i] = borrowedById[i];
                }
                newArray[len] = User->getUserId();
                delete borrowedById;
                borrowedById = newArray;
                borrowedByIdLength++;
                
                //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
                std::time_t t = std::time(0);   // get time now
                std::tm* now = std::localtime(&t);
                //******************************************************************
                int issued_year = now->tm_year + 1900;
                int issued_month = now->tm_mon + 1;
                int issued_day = now->tm_mday;
                int type = User->getType();
                int return_Month = returnTime[type];
                return_Month = return_Month + issued_month;
                int return_year = issued_year;
                int return_day = issued_day;
                if(return_Month > 12){
                    return_year++;
                }
                return_Month = return_Month % 12;
                
                string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day);
                string return_temp = to_string(return_year) + "-"+to_string(return_Month)+"-"+to_string(return_day); 

                User->setIssueDate(issue_temp);
                User->setReturnDate(return_temp);

                string *newIssueArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newIssueArray[i] = issuedDate[i];
                }
                newIssueArray[len] = issue_temp;
                issuedDate = newIssueArray;

                string *newReturnArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newReturnArray[i] = returnDate[i];
                }
                newReturnArray[len] = return_temp;
                returnDate = newReturnArray;

                cout<<"Book Borrowed Details:- \n";
                cout<<"User with user id:- "<<User->getUserId()<<endl;
                cout<<"Book Borrowed identifier is :- "<<copy_identifier<<endl;
                cout<<"Issue Date is:- "<<issued_year<<'-'<<issued_month<<'-'<<issued_day<<endl;
                cout<<"Return Date is:- "<<return_year<<'-'<<return_Month<<'-'<<return_day<<endl;
            }
            return 1;
        }
        int borrow(user *User,string libraryName){
            if(books_remaining == 0){
                // cout<<"no copies are left please come later";
                //call to borrow from another library
                return 0;
            }else{
                books_remaining--;
                int len = borrowedByIdLength;
                string copy_identifier = identifier +"/"+to_string(len);
                User->borrowBooks(copy_identifier);
                int *newArray = new int[len+1];
                for(int i = 0 ;i < len;i++){
                    newArray[i] = borrowedById[i];
                }
                newArray[len] = -User->getUserId();
                delete borrowedById;
                borrowedById = newArray;
                borrowedByIdLength++;
                
                //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
                std::time_t t = std::time(0);   // get time now
                std::tm* now = std::localtime(&t);
                //******************************************************************
                int issued_year = now->tm_year + 1900;
                int issued_month = now->tm_mon + 1;
                int issued_day = now->tm_mday;
                int type = User->getType();
                issued_day += 7;
                if(issued_month % 2 == 1 && issued_month <= 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                }else if(issued_month == 2 && issued_year % 4 == 0 && issued_day > 29){
                    issued_day = issued_day % 29;
                    issued_month += 1;
                }else if(issued_month == 2 && issued_year % 4 != 0 && issued_day > 28){
                    issued_day = issued_day % 28;
                    issued_month += 1;
                }else if(issued_month % 2 == 0 && issued_month <= 7 && issued_day > 30){
                    issued_day = issued_day % 30;
                    issued_month += 1;
                }else if(issued_month % 2 == 0 && issued_month > 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                    if(issued_month > 12){
                        issued_year++;
                        issued_month = issued_month % 12;
                    }
                }else if(issued_month % 2 == 1 && issued_month > 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                    if(issued_month > 12){
                        issued_year++;
                        issued_month = issued_month % 12;
                    }
                }

                int return_Month = returnTime[type];
                return_Month = return_Month + issued_month;
                int return_year = issued_year;
                int return_day = issued_day;
                if(return_Month > 12){
                    return_year++;
                }
                return_Month = return_Month % 12;
                
                string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day);
                string return_temp = to_string(return_year) + "-"+to_string(return_Month)+"-"+to_string(return_day); 

                User->setIssueDate(issue_temp);
                User->setReturnDate(return_temp);

                string *newIssueArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newIssueArray[i] = issuedDate[i];
                }
                newIssueArray[len] = issue_temp;
                issuedDate = newIssueArray;

                string *newReturnArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newReturnArray[i] = returnDate[i];
                }
                newReturnArray[len] = return_temp;
                returnDate = newReturnArray;

                cout<<"Book Borrowed Details:- \n";
                cout<<"User with user id:- "<<User->getUserId()<<endl;
                cout<<"Book Borrowed identifier is :- "<<copy_identifier<<endl;
                cout<<"Issue Date is:- "<<issued_year<<'-'<<issued_month<<'-'<<issued_day<<endl;
                cout<<"Return Date is:- "<<return_year<<'-'<<return_Month<<'-'<<return_day<<endl;
            }
            return 1;
        }
    friend class library;
};


class magzine:public Item{
    string publication;
    string rank;
    string totalPaid;
    string wordRate;
    string daysToBePaid;
    string paymentDifficulty;
    string rank_totalPaid;
    string rank_wordRate;
    string rank_daysToBePaid;
    string rank_paymentDifficulty;
    int *borrowedById = new int[0];
    int borrowedByIdLength = 0;
    string *issuedDate = new string[0];
    string identifier;
    public: 
    magzine *next;
    void addDetails(string publication,
                    string rank,
                    string totalPaid,
                    string wordRate,
                    string daysToBePaid,
                    string paymentDifficulty,
                    string rank_totalPaid,
                    string rank_wordRate,
                    string rank_daysToBePaid,
                    string rank_paymentDifficulty){
            this->publication = publication;
            this->rank = rank;
            this->totalPaid = totalPaid;
            this->wordRate = wordRate; 
            this->daysToBePaid = daysToBePaid;
            this->paymentDifficulty = paymentDifficulty;
            this->rank_totalPaid = rank_totalPaid;
            this->rank_wordRate = rank_wordRate;
            this->rank_daysToBePaid = rank_daysToBePaid;
            this->rank_paymentDifficulty = rank_paymentDifficulty;
            // cout<<publication;

        }
        void setIdentifier(int no,string LibraryName){
            identifier = LibraryName+"/"+"M/"+ to_string(no);
        }
        string getIdentifier(){
            return identifier;
        }
        string getPublication(){
            return publication;
        }
        int getUserIdOfTheBorrower(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return INF;
            }else{
                return borrowedById[copy];
            }
        }
        string getIssueDateOfTheMagzine(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return " ";
            }else{
                return issuedDate[copy];
            }
        }
        bool check(string publication,string identifier){
            if(this->publication == publication && this->identifier == identifier){
                return true;
            }
            return false;
        }
        void borrow(user *User){
            
            // int len = sizeof(borrowedById)/sizeof(borrowedById[0]);
            int len = borrowedByIdLength;
            string copy_identifier = identifier +"/"+to_string(len);
            User->borrowMagzines(copy_identifier);
            int *newArray = new int[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = borrowedById[i];
            }
            newArray[len] = User->getUserId();
            delete borrowedById;
            borrowedById = newArray;
            borrowedByIdLength++;

            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
                std::time_t t = std::time(0);   // get time now
                std::tm* now = std::localtime(&t);
                //******************************************************************
                int issued_year = now->tm_year + 1900;
                int issued_month = now->tm_mon + 1;
                int issued_day = now->tm_mday;
                
                string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day); 

                string *newIssueArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newIssueArray[i] = issuedDate[i];
                }
                newIssueArray[len] = issue_temp;
                issuedDate = newIssueArray;


                cout<<"magzine Borrowed Details:- \n";
                cout<<"User with user id:- "<<User->getUserId()<<endl;
                cout<<"Magzine Borrowed identifier is :- "<<copy_identifier<<endl;
                cout<<"Issue Date is:- "<<issue_temp<<endl;
        }
        void borrow(user *User,string libraryName){

            int len = borrowedByIdLength;
            string copy_identifier = identifier +"/"+to_string(len);
            User->borrowMagzines(copy_identifier);
            int *newArray = new int[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = borrowedById[i];
            }
            newArray[len] = -User->getUserId();
            delete borrowedById;
            borrowedById = newArray;
            borrowedByIdLength++;

            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
                std::time_t t = std::time(0);   // get time now
                std::tm* now = std::localtime(&t);
                //******************************************************************
                int issued_year = now->tm_year + 1900;
                int issued_month = now->tm_mon + 1;
                int issued_day = now->tm_mday;
                issued_day += 7;
                if(issued_month % 2 == 1 && issued_month <= 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                }else if(issued_month == 2 && issued_year % 4 == 0 && issued_day > 29){
                    issued_day = issued_day % 29;
                    issued_month += 1;
                }else if(issued_month == 2 && issued_year % 4 != 0 && issued_day > 28){
                    issued_day = issued_day % 28;
                    issued_month += 1;
                }else if(issued_month % 2 == 0 && issued_month <= 7 && issued_day > 30){
                    issued_day = issued_day % 30;
                    issued_month += 1;
                }else if(issued_month % 2 == 0 && issued_month > 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                    if(issued_month > 12){
                        issued_year++;
                        issued_month = issued_month % 12;
                    }
                }else if(issued_month % 2 == 1 && issued_month > 7 && issued_day > 31){
                    issued_day = issued_day % 31;
                    issued_month += 1;
                    if(issued_month > 12){
                        issued_year++;
                        issued_month = issued_month % 12;
                    }
                }
                
                string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day); 

                string *newIssueArray = new string[len+1];
                for(int i = 0 ;i < len;i++){
                    newIssueArray[i] = issuedDate[i];
                }
                newIssueArray[len] = issue_temp;
                issuedDate = newIssueArray;


                cout<<"magzine Borrowed Details:- \n";
                cout<<"User with user id:- "<<User->getUserId()<<endl;
                cout<<"Magzine Borrowed identifier is :- "<<copy_identifier<<endl;
                cout<<"Issue Date is:- "<<issue_temp<<endl;
        }
        friend class library;

};

class journal:public Item{
    string name;
    int *borrowedById = new int[0];
    int borrowedByIdLength = 0;
    string *issuedDate = new string[0];
    string identifier;
    public:
    journal *next;
     void addDetails(string name){
        this->name = name;
     }
     void setIdentifier(int no,string LibraryName){
            identifier = LibraryName +"/"+"J/"+to_string(no);
    }
    string getIdentifier(){
        return identifier;
    }
    int getUserIdOfTheBorrower(int copy){
        int len = borrowedByIdLength;
        if(copy >= len){
            return INF;
        }else{
            return borrowedById[copy];
        }
    }
    string getIssueDateOfTheJournal(int copy){
        int len = borrowedByIdLength;
        if(copy >= len){
            return " ";
        }else{
            return issuedDate[copy];
        }
    }
    bool check(string name,string identifier){
        if(this->name == name && this->identifier == identifier){
            return true;
        }
        return false;
    }
    void borrow(user *User){
            
            int len = borrowedByIdLength;
            string copy_identifier = identifier +"/"+to_string(len);
            User->borrowJournals(copy_identifier);
            int *newArray = new int[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = borrowedById[i];
            }
            newArray[len] = User->getUserId();
            delete borrowedById;
            borrowedById = newArray;
            borrowedByIdLength++;
            
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            int issued_year = now->tm_year + 1900;
            int issued_month = now->tm_mon + 1;
            int issued_day = now->tm_mday;
            
            string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day); 

            string *newIssueArray = new string[len+1];
            for(int i = 0 ;i < len;i++){
                newIssueArray[i] = issuedDate[i];
            }
            newIssueArray[len] = issue_temp;
            issuedDate = newIssueArray;

            cout<<"journal Borrowed Details:- \n";
            cout<<"User with user id:- "<<User->getUserId()<<endl;
            cout<<"journal Borrowed identifier is :- "<<copy_identifier<<endl;
            cout<<"Issue Date is:- "<<issue_temp<<endl;
    }
    void borrow(user *User,string libraryName){
            
            int len = borrowedByIdLength;
            string copy_identifier = identifier +"/"+to_string(len);
            User->borrowJournals(copy_identifier);
            int *newArray = new int[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = borrowedById[i];
            }
            newArray[len] = -User->getUserId();
            delete borrowedById;
            borrowedById = newArray;
            borrowedByIdLength++;
            
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            int issued_year = now->tm_year + 1900;
            int issued_month = now->tm_mon + 1;
            int issued_day = now->tm_mday;
            issued_day += 7;
            if(issued_month % 2 == 1 && issued_month <= 7 && issued_day > 31){
                issued_day = issued_day % 31;
                issued_month += 1;
            }else if(issued_month == 2 && issued_year % 4 == 0 && issued_day > 29){
                issued_day = issued_day % 29;
                issued_month += 1;
            }else if(issued_month == 2 && issued_year % 4 != 0 && issued_day > 28){
                issued_day = issued_day % 28;
                issued_month += 1;
            }else if(issued_month % 2 == 0 && issued_month <= 7 && issued_day > 30){
                issued_day = issued_day % 30;
                issued_month += 1;
            }else if(issued_month % 2 == 0 && issued_month > 7 && issued_day > 31){
                issued_day = issued_day % 31;
                issued_month += 1;
                if(issued_month > 12){
                    issued_year++;
                    issued_month = issued_month % 12;
                }
            }else if(issued_month % 2 == 1 && issued_month > 7 && issued_day > 31){
                issued_day = issued_day % 31;
                issued_month += 1;
                if(issued_month > 12){
                    issued_year++;
                    issued_month = issued_month % 12;
                }
            }
            string issue_temp = to_string(issued_year) + "-"+to_string(issued_month)+"-"+to_string(issued_day); 

            string *newIssueArray = new string[len+1];
            for(int i = 0 ;i < len;i++){
                newIssueArray[i] = issuedDate[i];
            }
            newIssueArray[len] = issue_temp;
            issuedDate = newIssueArray;

            cout<<"journal Borrowed Details:- \n";
            cout<<"User with user id:- "<<User->getUserId()<<endl;
            cout<<"journal Borrowed identifier is :- "<<copy_identifier<<endl;
            cout<<"Issue Date is:- "<<issue_temp<<endl;
    }
};


class borrowedTo{
    public:
    user * User;
    string LibraryName;
    Item *item;
    string type;
};
class borrowedFrom{
    public:
    string LibraryName;
    Item *item;
    string type;
};


class library{
    book *uniquebooks = new book[0];
    journal *journals = new journal[0];
    magzine *magzines = new magzine[0];
    user *users = new user[0];
    borrowedTo *Lent = new borrowedTo[0];
    borrowedFrom *borrowed = new borrowedFrom[0];
    string LibraryName = "";
    int noOfItemsBorrowedFrom = 0;
    int noOfitemsBorrowedTo = 0;
    int noOfUsers = 0;
    int noOfBooks = 0;
    int noOfMagzines = 0;
    int noOfJournals = 0;
    public:
    library(){

    }
    library(string name){
        this->LibraryName = name;
    }
    void setnoOfBooks(int no){
        this->noOfBooks = no; 
    }
    void setnoOfMagzines(int no){
        this->noOfMagzines = no; 
    }
    void setnoOfJournals(int no){
        this->noOfJournals = no; 
    }
     void addBook(string book_id,string goodreads_book_id,string best_book_id,string work_id,int books_count,string isbn,string isbn13,string author1,string author2,string author3,string author4,string author5, string original_publication_year,string original_title,string title,string language_code,string average_rating,string ratings_count,string work_ratings_count,string work_text_reviews_count,string ratings_1,string ratings_2,string ratings_3,string ratings_4,string ratings_5,string image_url,string small_image_url){
        book newBook;
        newBook.addDetails(book_id,goodreads_book_id,best_book_id,work_id,books_count,isbn,isbn13,author1,author2,author3,author4,author5,original_publication_year,original_title,title,language_code,average_rating,ratings_count,work_ratings_count,work_text_reviews_count,ratings_1,ratings_2,ratings_3,ratings_4,ratings_5,image_url,small_image_url);
        newBook.setIdentifier(noOfBooks,LibraryName);
            int len = noOfBooks;
            book *newArray = new book[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = uniquebooks[i];
            }
            newArray[len] = newBook;
            uniquebooks = newArray;
            noOfBooks++;
     }
     void addJournals(string name){
        journal newJournal;
        newJournal.addDetails(name);
        newJournal.setIdentifier(noOfJournals,LibraryName);
            int len = noOfJournals;
            journal *newArray = new journal[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = journals[i];
            }
            newArray[len] = newJournal;
            journals = newArray;
            noOfJournals++;
     }
     void addMagzines(string publication,
                      string rank,
                      string totalPaid,
                      string wordRate,
                      string daysToBePaid,
                      string paymentDifficulty,
                      string rank_totalPaid,
                      string rank_wordRate,
                      string rank_daysToBePaid,
                      string rank_paymentDifficulty){
        magzine newMagzine;
        newMagzine.addDetails(publication,rank,totalPaid,wordRate,daysToBePaid,paymentDifficulty,rank_totalPaid,rank_wordRate,rank_daysToBePaid,rank_paymentDifficulty);
        newMagzine.setIdentifier(noOfMagzines,LibraryName);
        noOfMagzines++;
        
            magzine *newArray = new magzine[noOfMagzines];
            for(int i = 0 ;i < noOfMagzines-1;i++){
                newArray[i] = magzines[i];
            }
            newArray[noOfMagzines-1] = newMagzine;
            magzines = newArray;

     }
     void addUser(string name,int type){
        //  cout<<"I am here";
        user newUser;
        
        newUser.addDetails(this->noOfUsers,name,type);
        
          
            int len = noOfUsers;
            user *newArray = new user[len+1];
            for(int i = 0 ;i < len;i++){
                newArray[i] = users[i];
            }
            newArray[len] = newUser;
            users = newArray;
        cout<<"User Registered Successfully and your user id is:- "<<noOfUsers;
            noOfUsers++;
     }
     int getUserIdOfTheBorrowerOfAnotherLibrary(string identifier,string LibraryName,string type,int no){
        // cout<<"I am user id of borrower";
        int len = noOfItemsBorrowedFrom;
        // cout<<len<<endl;
        for(int i = 0 ;i < len;i++){
            // cout<<"I am in Loop userid wala"<<endl;
             borrowedFrom temp = borrowed[i];
             if(temp.LibraryName == LibraryName && temp.item->getIdentifier() == identifier){
                int uid = temp.item->getUserIdOfTheBorrower(no);
                if(uid == INF){
                    return -1;
                }else{
                    if(uid < 0){
                        return (-(uid));
                    }else{
                        return -1;
                    }
                }
             }
        }
        return -1;
     }
     string getIssueDateofTheItemBorrowedByAnotherLibrary(int uid,int bno){
         user &User = users[uid];
         return User.issuedDate[bno];
     }
     string getreturnDateofTheItemBorrowedByAnotherLibrary(int uid , int bno){
         user &User = users[uid];
         return User.returnDate[bno];
     }
     bool getLocationOfBooks(string title,string isbn,string isbn13,string author1, string author2, string author3 ,string author4, string author5,string identifier,library *Library){
        string temp_Idt[4];
        int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
        string token;
        while(identifier.length() != 0 && i < 4){
            token = identifier.substr(0,identifier.find_first_of("/"));
            identifier = identifier.substr(identifier.find_first_of("/") + 1);
            temp_Idt[i] = token;
            i++;
        } 
        /*************************************************************/
        // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
        string fstoi = temp_Idt[3];
        int bno;
        try{
            bno = stoi(fstoi);
        }catch(exception& e){
            cout<<"Identifier drawer or copy id is not valid"<<endl;
            return 0;
        }
        string indt = temp_Idt[0]+"/"+temp_Idt[1]+"/"+ temp_Idt[2];
        book *temp = find(title,isbn,isbn13,author1,author2,author3,author4,author5,indt);
        if(temp == nullptr){
            // book *tal = Library->find(title,isbn,isbn13,author1,author2,author3,author4,author5,indt);
            // if(tal != nullptr){
            //     int uid = getUserIdOfTheBorrowerOfAnotherLibrary(indt,temp_Idt[0],"B",bno);
            //     if(uid == -1 || noOfItemsBorrowedFrom == 0){
            //         cout << "Book belongs to section "<<temp_Idt[1]<<"of  : " << temp_Idt[0] << "shelf : " << temp_Idt[2]<<"we can't give you more information because this is other library"<<endl;
            //     }else{
            //         cout<<"This Book is borrowed by user with id "<<uid<<"\n"; 
            //         cout<<"Items issue Date :- "<<getIssueDateofTheItemBorrowedByAnotherLibrary(uid,bno)<<endl;
            //         cout<<"Items return Date :- "<<getreturnDateofTheItemBorrowedByAnotherLibrary(uid,bno)<<endl;
            //     }
            //      //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            //     std::time_t t = std::time(0);   // get time now
            //     std::tm* now = std::localtime(&t);
            //     //******************************************************************
            //     cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday;
            //     return true;
            // }
           
            cout << "Item is not present with and at "<<temp_Idt[0];
            return false;
        }else{
            
            int uid = temp->getUserIdOfTheBorrower(bno);
            
            if(uid == INF){
                cout << "Book belongs to section : " << temp_Idt[1] <<" Of "<<temp_Idt[0]<< " shelf : " << temp_Idt[2] << " and drawer : " <<temp_Idt[3]<<endl;
            }else{
                if(temp_Idt[0] != "IIITD"){
                    cout<<"This Book is borrowed by user with id "<<-(uid)<<" "<<"from IIITD"<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheBook(bno)<<endl;
                }else{
                    cout<<"This Book is borrowed by user with id "<<uid<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheBook(bno)<<endl;
                }
            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday<<endl;
            return true;
        }
     }
     bool getLocationOfJournals(string branch,string name,string identifier,library *Library){
        string temp_Idt[4];
        int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
        string token;
        while(identifier.length() != 0 && i < 4){
            token = identifier.substr(0,identifier.find_first_of("/"));
            identifier = identifier.substr(identifier.find_first_of("/") + 1);
            temp_Idt[i] = token;
            i++;
        } 
        /*************************************************************/
        // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
        string fstoi = temp_Idt[3];
        int bno;
        try{
            bno = stoi(fstoi);
        }catch(exception& e){
            cout<<"Identifier drawer or copy id is not valid"<<endl;
            return 0;
        }
        string indt = temp_Idt[0]+"/"+temp_Idt[1] +"/"+temp_Idt[2];
        journal *temp = find(branch,name,indt);
        if(temp == nullptr){

            // journal *tal = Library->find(branch,name,indt);
            // if(tal != nullptr){
            //     int uid = getUserIdOfTheBorrowerOfAnotherLibrary(indt,temp_Idt[0],"J",bno);
            //     if(uid == -1 || noOfItemsBorrowedFrom == 0){
            //         cout << "Journal belongs to Virtual section "<<temp_Idt[1]<<"of  : " << temp_Idt[0] << " Virtual shelf : " << temp_Idt[2]<<"we can't give you more information because this is other library"<<endl;
            //     }else{
            //         cout<<"This journal is borrowed by user with id "<<uid<<"\n"; 
            //         cout<<"Items issue Date :- "<<getIssueDateofTheItemBorrowedByAnotherLibrary(uid,bno)<<endl;
            //     }
            //      //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            //     std::time_t t = std::time(0);   // get time now
            //     std::tm* now = std::localtime(&t);
            //     //******************************************************************
            //     cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday;
            //     return true;
            // }
           
            cout << "Item is not present with and at "<<temp_Idt[0];
            return false;
        }else{
            
            int uid = temp->getUserIdOfTheBorrower(bno);
            
            if(uid == INF){
                cout << "Journal belongs to Virtual section : " << temp_Idt[1] <<" Of "<<temp_Idt[0]<< " Virtual shelf : " << temp_Idt[2] << " and Virtual drawer : " <<temp_Idt[3]<<endl;
            }else{
                if(temp_Idt[0] != "IIITD"){
                    cout<<"This Journal is borrowed by user with id "<<-(uid)<<" "<<"from IIITD"<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheJournal(bno)<<endl;
                }else{
                    cout<<"This Journal is borrowed by user with id "<<uid<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheJournal(bno)<<endl;
                }
            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday<<endl;
            return true;
        }
     }
     bool getLocationOfMagzines(string publication,string identifier,library *Library){
        string temp_Idt[4];
        int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
        string token;
        while(identifier.length() != 0 && i < 4){
            token = identifier.substr(0,identifier.find_first_of("/"));
            identifier = identifier.substr(identifier.find_first_of("/") + 1);
            temp_Idt[i] = token;
            i++;
        } 
        /*************************************************************/
        // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
        string fstoi = temp_Idt[3];
        int bno;
        try{
            bno = stoi(fstoi);
        }catch(exception& e){
            cout<<"Identifier drawer or copy id is not valid"<<endl;
            return 0;
        }
        string indt = temp_Idt[0]+"/"+temp_Idt[1] +"/"+temp_Idt[2];
        // cout<<"\n"<<temp_Idt[1]<<endl;
        magzine *temp = find(publication,indt);
        if(temp == nullptr){
            
            // magzine *tal = Library->find(publication,indt);
            // if(tal != nullptr){
            //     int uid = getUserIdOfTheBorrowerOfAnotherLibrary(indt,temp_Idt[0],"M",bno);
            //     if(uid == -1 || noOfItemsBorrowedFrom == 0){
            //         cout << "Magzine belongs to Virtual section "<<temp_Idt[1]<<"of  : " << temp_Idt[0] << " Virtual shelf : " << temp_Idt[2]<<"we can't give you more information because this is other library"<<endl;
            //     }else{
            //         cout<<"This magzine is borrowed by user with id "<<uid<<"\n"; 
            //         cout<<"Items issue Date :- "<<getIssueDateofTheItemBorrowedByAnotherLibrary(uid,bno)<<endl;
            //     }
            //      //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            //     std::time_t t = std::time(0);   // get time now
            //     std::tm* now = std::localtime(&t);
            //     //******************************************************************
            //     cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday;
            //     return true;
            // }
           
            cout << "Item is not present with and at "<<temp_Idt[0];
            return false;
        }else{
            
            int uid = temp->getUserIdOfTheBorrower(bno);
            
            if(uid == INF){
                cout << "Magzine belongs to Virtual section : " << temp_Idt[1] <<" Of "<<temp_Idt[0]<< " Virtual shelf : " << temp_Idt[2] << " and Virtual drawer : " <<temp_Idt[3]<<endl;
            }else{
                if(temp_Idt[0] != "IIITD"){
                    cout<<"This magzine is borrowed by user with id "<<-(uid)<<" "<<"from IIITD"<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheMagzine(bno)<<endl;
                }else{
                    cout<<"This magzine is borrowed by user with id "<<uid<<"\n"; 
                    cout<<"Items issue Date :- "<<temp->getIssueDateOfTheMagzine(bno)<<endl;
                }
            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday;
            return true;
        }
     }
    book * find(string title,string isbn,string isbn13,string author1, string author2 , string author3, string author4, string author5,string identifier){
        int len = noOfBooks;  // working on  <-----------------------
        for(int i = 0 ;i < len;i++){
            if(uniquebooks[i].check(title,isbn,isbn13,author1, author2, author3, author4, author5,identifier)){
                return &uniquebooks[i];
            }
        }
        return nullptr;
     }
    journal * find(string branch,string name,string identifier){
        int len = noOfJournals;  // working on  <-----------------------
        for(int i = 0 ;i < len;i++){
            if(journals[i].check(name,identifier)){
                return &journals[i];
            }
        }
        return nullptr;
     }
    magzine * find(string publication,string identifier){
        for(int i = 0 ;i < noOfMagzines;i++){
            if(magzines[i].check(publication,identifier)){
                return &magzines[i];
            }
        }
        return nullptr;
     }
     user * find(int uid){
        for(int i = 0 ;i < noOfUsers;i++){
            if(users[i].check(uid)){
                return &users[i];
            }
        }
        return nullptr;
     }
     void purchase(string title,string isbn,string isbn13,string author1,string author2,string author3,string author4,string author5,string identifier){
        book *temp = find(title,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
        if(temp == nullptr){
            cout << "Item is not present , Library can only purchase the item that are present in library \n";
        }else{
            temp->increaseBookCountByOne();
            cout<<"\n Book purchased successfully \n";
        }
     }

     int getNoofBooks(){
        return noOfBooks;
     }
     int getNoofJournals(){
        return noOfJournals;
     }
     int getNoofMagzines(){
        return noOfMagzines;
     }
     //find in another library  return library object
    // Item * find_In_Another_Library(library * Library,string title ,string isbn,string isbn13,string author1,string author2,string author3,string author4,string author5,string identifier){
    //     book * Book = Library->find(title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
    //     return Book;
    // }
    // Item * find_In_Another_Library(library * Library,string publication,string identifier){
    //     magzine * Magzine = Library->find(publication,identifier);
    //     return Magzine;
    // }
    // Item * find_In_Another_Library(library * Library,string branch,string name,string identifier){
    //     journal * Journal = Library->find(" ",name,identifier);
    //     return Journal;
    // }
    void setborrowedTo(borrowedTo &brt){
        int len = noOfitemsBorrowedTo;
        borrowedTo *newArray = new borrowedTo[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = Lent[i];
        }
        newArray[len] = brt;
        Lent = newArray;
        noOfitemsBorrowedTo++;

    }
    int borrowBookFromAnotherLibrary(user * User,book * item,library &Library,string LibraryName){
        int res = item->borrow(User,LibraryName);
        if(res == 0){
            return 0;
        }
        borrowedFrom brf;
        brf.item = item;
        brf.LibraryName = LibraryName;
        brf.type = "B";

        int len = noOfItemsBorrowedFrom;
        borrowedFrom *newArray = new borrowedFrom[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = borrowed[i];
        }
        newArray[len] = brf;
        borrowed = newArray;
        noOfItemsBorrowedFrom++;

        borrowedTo brt;
        brt.item = item;
        brt.LibraryName = "IIITD";
        brt.User = User;
        brt.type = "B";

        Library.setborrowedTo(brt);
        return 1;
        
    }
    void borrowJournalFromAnotherLibrary(user * User,journal * item,library &Library,string LibraryName){
        item->borrow(User,LibraryName);
        
        borrowedFrom brf;
        brf.item = item;
        brf.LibraryName = LibraryName;
        brf.type = "J";

        int len = noOfItemsBorrowedFrom;
        borrowedFrom *newArray = new borrowedFrom[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = borrowed[i];
        }
        newArray[len] = brf;
        borrowed = newArray;
        noOfItemsBorrowedFrom++;

        borrowedTo brt;
        brt.item = item;
        brt.LibraryName = "IIITD";
        brt.User = User;
        brt.type = "J";

        Library.setborrowedTo(brt);
        
    }
    void borrowMagzineFromAnotherLibrary(user * User,magzine * item,library &Library,string LibraryName){
        item->borrow(User,LibraryName);
        borrowedFrom brf;
        brf.item = item;
        brf.LibraryName = LibraryName;
        brf.type = "M";

        int len = noOfItemsBorrowedFrom;
        borrowedFrom *newArray = new borrowedFrom[len+1];
        for(int i = 0 ;i < len;i++){
            newArray[i] = borrowed[i];
        }
        newArray[len] = brf;
        borrowed = newArray;
        noOfItemsBorrowedFrom++;

        borrowedTo brt;
        brt.item = item;
        brt.LibraryName = "IIITD";
        brt.User = User;
        brt.type = "M";

        Library.setborrowedTo(brt);
        
    }

     //borrow from another library and lent to user with 7 days of delay passing that object as pararmeter  
     //kept location of the borrowed book
     //Location of item
     //( optional )  possible return also fixed
};



void readingJournal(library *Library,string nameofFile,int sidx,int eidx){
    int i = 0;
    string line;
    ifstream file(nameofFile);
    while(getline(file,line)){  
        if(i >= sidx && i <= eidx){
            stringstream s(line);
            string res = "";
            string word; 
            while(getline(s,word,',')){
                res += word;
            }
            res = '"'+res+'"';
            // cout<<res;
            Library->addJournals(res);
        }
        i++;
    }
}

void readingMagzines(library *Library,string nameofFile,int sidx,int eidx){
    string line;
    ifstream file(nameofFile);
    int idx = 0;
    getline(file,line);
    while(getline(file,line)){
        if(idx >= sidx && idx <= eidx){
            stringstream s(line);
            string res[10];
            string word;
            int i=0;
            while(getline(s,word,',')){
                res[i] = word;
                i++;
            }
            Library->addMagzines(res[0],res[1],res[2],res[3],res[4],res[5],res[6],res[7],res[8],res[9]);
        }   
        idx++;

    }
}

void readingBooks(library *Library,string nameofFile,int sidx,int eidx){
    // cout<<"I am in readingBooks";
    string line;
    ifstream file(nameofFile);
    int idx = 0;
    getline(file,line);
    while(getline(file,line)){
        if(idx >= sidx && idx <= eidx){
            stringstream s(line);
            string res[27];
            string word;
            int i = 0;
            while(getline(s,word,',') && i < 27){
                word = trim(word);
                word = (word[0] == '"') ? word.substr(1,word.length()-1) : word;
                word = (word[word.length()-1] == '"') ? word.substr(0,word.length()-1) : word;
                if(i > 7 && i <= 11){
                    if(word[0] > '9'){
                        //nothing
                    }else{
                        i = 12;
                    }
                }
                if(i == 6){
                    double temp =  stod(word);
                    word = to_string(temp);
                    word = word.substr(0,word.find("."));
                }
                res[i] = word;
                i++;
            }
            // cout<<authors[0]<<" , "<<authors[1]<<"\n";
            // cout<<res[7]<<" , "<<res[6]<<"\n";
            Library->addBook(res[0],res[1],res[2],res[3],stoi(res[4]),res[5],res[6],res[7],res[8],res[9],res[10],res[11],res[12],res[13],res[14],res[15],res[16],res[17],res[18],res[19],res[20],res[21],res[22],res[23],res[24],res[25],res[26]);
        }
         idx++;   
    }
}

//****************************************Open Source Check Integer or string**********************************
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
//**************************************************************************************************************




int main(){
    library Library("IIITD");
    library DTU("DTU");
    library IITD("IITD");

    //***********************************IIITD Library***************************************
    readingBooks(&Library,"books.csv",0,40);
    readingMagzines(&Library,"publications_rank.csv",0,40);
    readingJournal(&Library,"journals.csv",0,45);
    //***************************************************************************************
    //***************************************DTU*********************************************
    readingBooks(&DTU,"books.csv",0,80);
    readingMagzines(&DTU,"publications_rank.csv",0,70);
    readingJournal(&DTU,"journals.csv",0,80);
    //***************************************************************************************
    //***************************************IITD********************************************
    readingBooks(&IITD,"books.csv",0,98);
    readingMagzines(&IITD,"publications_rank.csv",0,79);
    readingJournal(&IITD,"journals.csv",0,98);
    //***************************************************************************************

    while(true){
        cout<<"Enter one of the following options:- \n";
        cout<<" 0 - Borrow \n 1 - find Book Location \n 2 - New User Registartion \n 3 - Purchase new Book \n 4 - Exit \n";
        char choice;
        cin>>choice;
        switch (choice)
        {
        case '0':
            {   cout<<"What do you want borrow B - books , J - journals , M - magzines: \n";
                char item;
                cin>>item;
                if(item == 'B'){
                    string name;
                    string suid;
                    
                    cout<<"Enter name: ";
                    cin.ignore();
                    getline(cin,name);

                    if(check_number(name) == true){
                        cout<<"Not valid Name try again";
                        return 0;
                    }

                    cout<<"Enter user id:- ";
                    cin>>suid;

                    if(check_number(suid) == false){
                        cout<<"Not valid User id try again";
                        return 0;
                    }
                    

                    int uid = stoi(suid);
                    user *User = Library.find(uid);
                    if(User == nullptr){
                        cout<<"Your are not registered with us, Kindly register yourself first \n";
                        
                    }else{
                                string title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier;
                                cout<<"Enter details of the book to borrow\n";
                                cout<<"Enter title:- ";
                                cin.ignore();
                                getline(cin,title);
                                cout<< "Enter isbn:- ";
                                cin >> isbn;
                                cout<<"Enter isbn13:- ";
                                cin>>isbn13;
                                cout<<"Enter author1:- ";
                                cin.ignore();
                                getline(cin,author1);
                                cout<<"Enter author2:- ";
                                cin.ignore();
                                getline(cin,author2);
                                cout<<"Enter author3:- ";
                                cin.ignore();
                                getline(cin,author3);
                                cout<<"Enter author4:- ";
                                cin.ignore();
                                getline(cin,author4);
                                cout<<"Enter author5:- ";
                                cin.ignore();
                                getline(cin,author5);
                                cout<<"Enter Identifier:- ";
                                cin>>identifier;
                                    
                                // User->borrowBooks(Book->getIdentifier());
                                book *Book = Library.find(title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
                                if(Book != nullptr){
                                    int res = Book->borrow(User);
                                    if(res == 0){
                                        cout<<"Book is not available in our library please we are contacting others.....\n";
                                    }else{
                                            cout<<"Book borrowed from IIITD"<<endl;
                                            goto option;
                                    }
                                }
                                 try{
                                     identifier = identifier.substr(identifier.find_first_of('/'));
                                    }catch(exception& e){
                                        cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                                        return 0;
                                    }
                                // cout<<identifier;
                                string DTUIdentifier = "DTU"+identifier;
                                book *Book1 = DTU.find(title ,isbn,isbn13,author1,author2,author3,author4,author5,DTUIdentifier);
                                if(Book1 != nullptr){
                                    int l1 = Library.borrowBookFromAnotherLibrary(User,Book1,DTU,"DTU");
                                    if(l1 == 0){
                                        cout<<"No copies are available of this on our and DTU we are trying with IITD please wait..."<<endl;
                                    }else{
                                            cout<<"Book borrowed from DTU in colloboration with IIITD"<<endl;
                                            goto option;
                                        }
                                }
                                string IITDIdentifier = "IITD"+identifier;
                                book *Book2 = IITD.find(title ,isbn,isbn13,author1,author2,author3,author4,author5,IITDIdentifier);
                                if(Book2 != nullptr){
                                    int l2 = Library.borrowBookFromAnotherLibrary(User,Book2,IITD,"IITD");
                                    if(l2 == 0){
                                        cout<<"No copies are available of this on our, DTU and IITD Library please come later "<<endl;
                                    }else{
                                        cout<<"Book borrowed from IITD in colloboration with IIITD"<<endl;
                                        goto option;
                                    }
                                }

                                cout<<"Book is not available any where please come later"<<endl;
                                

                    }
                    
                }else if(item == 'J'){

                    string name;
                    string suid;
                    
                    cout<<"Enter name: ";
                    cin.ignore();
                    getline(cin,name);

                    if(check_number(name) == true){
                        cout<<"Not valid Name try again";
                        return 0;
                    }

                    cout<<"Enter user id:- ";
                    cin>>suid;

                    if(check_number(suid) == false){
                        cout<<"Not valid User id try again";
                        return 0;
                    }
                    
                    
                    int uid = stoi(suid);
                    user *User = Library.find(uid);
                    if(User == nullptr){
                        cout<<"Your are not registered with us, Kindly register yourself first \n";
                    }else{
                        string branch, name, identifier;
                        cout<<"Enter details of the Journal to borrow\n";
                        cout<< "Enter name:- ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter identifier:- ";
                        cin>> identifier;
                        journal *Journal = Library.find("",name,identifier);
                        if(Journal == nullptr){
                            cout<<"This Journal is not available with us \n ";
                             try{
                                identifier = identifier.substr(identifier.find_first_of('/'));
                            }catch(exception& e){
                                cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                                return 0;
                            }
                            string DTUIdentifier = "DTU"+identifier;
                            journal *Book1 = DTU.find("",name,DTUIdentifier);
                            if(Book1 != nullptr){
                                Library.borrowJournalFromAnotherLibrary(User,Book1,DTU,"DTU");
                                cout<<"journal Borrowed from DTU with colloboration with IIITd"<<endl;
                            }else{
                                string IITDIdentifier = "IITD"+identifier;
                                journal *Book2 = IITD.find("",name,IITDIdentifier);
                                if(Book2 != nullptr){
                                    Library.borrowJournalFromAnotherLibrary(User,Book2,IITD,"IITD");
                                    cout<<"Journal Borrowed from IITD with colloboration with IIITd"<<endl;
                                }else{
                                    cout<<"Journal not available with us and our colloborartors please come later"<<endl;
                                }
                            
                            }
                        }else{
                                // User->borrowJournals(Journal->getIdentifier());
                                Journal->borrow(User);
                        }
                    }

                }else if(item == 'M'){

                    string name;
                    string suid;
                    
                    cout<<"Enter name: ";
                    cin.ignore();
                    getline(cin,name);

                    if(check_number(name) == true){
                        cout<<"Not valid Name try again";
                        return 0;
                    }

                    cout<<"Enter user id:- ";
                    cin>>suid;

                    if(check_number(suid) == false){
                        cout<<"Not valid User id try again";
                        return 0;
                    }
                    
                    
                    int uid = stoi(suid);
                    user *User = Library.find(uid);
                    if(User == nullptr){
                        cout<<"\nYour are not registered with us, Kindly register yourself first ";
                    }else{
                        string publication,identifier;
                        cout<<"Enter details of the Journal to borrow\n";
                        cout<<"Enter publications:- ";
                        cin.ignore();
                        getline(cin,publication);
                        cout<< "Enter identifier- ";
                        cin >> identifier;
                        magzine *Magzine= Library.find(publication,identifier);
                        // cout<<Magzine<<"Magzine add";
                        if(Magzine == nullptr){
                            cout<<"This Magzine is not available with us \n ";
                             try{
                                identifier = identifier.substr(identifier.find_first_of('/'));
                            }catch(exception& e){
                                cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                                return 0;
                            }
                            // cout<<identifier;
                            string DTUIdentifier = "DTU"+identifier;
                            magzine *Book1 = DTU.find(publication,DTUIdentifier);
                            if(Book1 != nullptr){
                                Library.borrowMagzineFromAnotherLibrary(User,Book1,DTU,"DTU");
                                cout<<"Magzine Borrowed from DTU with colloboration with IIITd"<<endl;
                            }else{
                                try{
                                    identifier = identifier.substr(identifier.find_first_of('/'));
                                }catch(exception& e){
                                    cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                                    return 0;
                                }
                                // cout<<identifier;
                                string IITDIdentifier = "IITD"+identifier;
                                magzine *Book2 = IITD.find(publication,IITDIdentifier);
                                if(Book2 != nullptr){
                                    Library.borrowMagzineFromAnotherLibrary(User,Book2,IITD,"IITD");
                                    cout<<"Magzine Borrowed from IITD with colloboration with IIITd"<<endl;
                                }else{
                                    cout<<"Magzine not available with us and our colloborartors please come later"<<endl;
                                }
                            
                            }
                        }else{
                                // User->borrowMagzines(Magzine->getIdentifier());
                                Magzine->borrow(User);
                        }
                    }
                }
               option:  cout<<"\nDo you wanted to continue with further options y/n: \n";
                        char option;
                        cin >> option;
                        if(option == 'n'){
                            return 0;
                        }
                break;
            }
        case '1':
                {   cout<<"What do you want borrow B - books , J - journals , M - magzines: \n";
                    char item;
                    cin>>item;
                    if(item == 'B'){
                        string title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier;
                        cout<<"Enter details of the book to get Location of it: \n";
                        cout<<"Enter title:- ";
                        cin.ignore();
                        getline(cin,title);
                        cout<< "Enter isbn:- ";
                        cin >> isbn;
                        cout<<"Enter isbn13:- ";
                        cin>>isbn13;
                        cout<<"Enter author1:- ";
                        cin.ignore();
                        getline(cin,author1);
                        cout<<"Enter author2:- ";
                        cin.ignore();
                        getline(cin,author2);
                        cout<<"Enter author3:- ";
                        cin.ignore();
                        getline(cin,author3);
                        cout<<"Enter author4:- ";
                        cin.ignore();
                        getline(cin,author4);
                        cout<<"Enter author5:- ";
                        cin.ignore();
                        getline(cin,author5);
                        cout<<"Enter Identifier:- ";
                        cin>>identifier;




                        try{
                            identifier = identifier.substr(identifier.find_first_of('/'));
                        }catch(exception& e){
                            cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                            return 0;
                        }
                        
                        // cout<<identifier;
                        string IIITDIdentifier = "IIITD"+identifier;
                        if(Library.getLocationOfBooks(title ,isbn,isbn13,author1,author2,author3,author4,author5,IIITDIdentifier,&Library) == false){
                            string DTUIdentifier = "DTU"+identifier;
                            if(DTU.getLocationOfBooks(title ,isbn,isbn13,author1,author2,author3,author4,author5,DTUIdentifier,&DTU) == false){
                                string IITDIdentifier = "IITD"+identifier;
                                IITD.getLocationOfBooks(title ,isbn,isbn13,author1,author2,author3,author4,author5,IITDIdentifier,&IITD);
                            }
                        }
                    }else if(item == 'M'){
                        string publication,identifier;
                        cout<<"Enter details of the Magzine to get Location\n";
                        cout<<"Enter publications:- ";
                        cin.ignore();
                        getline(cin,publication);
                        cout<< "Enter identifier- ";
                        cin >> identifier;
                         try{
                            identifier = identifier.substr(identifier.find_first_of('/'));
                        }catch(exception& e){
                            cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                            return 0;
                        }
                        // cout<<identifier;
                        string IIITDIdentifier = "IIITD"+identifier;
                        if(Library.getLocationOfMagzines(publication,IIITDIdentifier,&Library) == false){
                            string DTUIdentifier = "DTU"+identifier;
                            if(DTU.getLocationOfMagzines(publication,DTUIdentifier,&DTU) == false){
                                 string IITDIdentifier = "IITD"+identifier;
                                IITD.getLocationOfMagzines(publication,IITDIdentifier,&IITD);
                            }
                        }
                    }else if(item == 'J'){
                        string branch, name, identifier;
                        cout<<"Enter details of the Journal to get Location\n";
                        cout<< "Enter name:- ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter identifier:- ";
                        cin>> identifier;
                         try{
                            identifier = identifier.substr(identifier.find_first_of('/'));
                        }catch(exception& e){
                            cout<<"Identifer is not valid should be informat of CLG/TYPE/SHELF/DRAWER"<<endl;
                            return 0;
                        }
                        // cout<<identifier;
                        string IIITDIdentifier = "IIITD"+identifier;
                        if(Library.getLocationOfJournals("",name,IIITDIdentifier,&Library) == false){
                            string DTUIdentifier = "DTU"+identifier;
                            if(DTU.getLocationOfJournals("",name,DTUIdentifier,&DTU) == false){
                                string IITDIdentifier = "IITD"+identifier;
                                IITD.getLocationOfJournals("",name,IITDIdentifier,&IITD);
                            }
                        }
                    }
                    cout<<"\nDo you wanted to continue with further options y/n: \n";
                    char option;
                    cin >> option;
                    if(option == 'n'){
                        return 0; 
                    }
                    break;
                }
        case '2':
                {   string name;
                    string stype;
                    int type;
                     
                    cout<<"For registration please provide you details as follows: \n";
                    cout<<"Enter your name: ";
                    cin.ignore();
                    getline(cin,name);

                    if(check_number(name) == true){
                        cout<<"Not valid Name try again";
                        return 0;
                    }

                    cout<<"Enter your user type 0 for student and 1 for professor: ";
                    cin>>stype;

                     if(check_number(stype) == false){
                        cout<<"Not valid Type try again";
                        return 0;
                    }

                    type = stoi(stype);

                    if(type != 0 && type != 1){
                        cout<<"Not a valid Type try again";
                        return 0;
                    }

                    Library.addUser(name,type);
                    cout<<"\nDo you wanted to continue with further options y/n: ";
                    char option;
                    cin >> option;
                    if(option == 'n'){
                        return 0;
                    }
                    break;

                }
        case '3':
                {   string title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier;
                    cout<<"Enter details of the book to purchase it: \n";
                    cout<<"Enter title:- ";
                    cin.ignore();
                    getline(cin,title);
                    cout<< "Enter isbn:- ";
                    cin >> isbn;
                    cout<<"Enter isbn13:- ";
                    cin>>isbn13;
                    cout<<"Enter author1:- ";
                    cin.ignore();
                    getline(cin,author1);
                     cout<<"Enter author2:- ";
                    cin.ignore();
                    getline(cin,author2);
                     cout<<"Enter author3:- ";
                    cin.ignore();
                    getline(cin,author3);
                     cout<<"Enter author4:- ";
                     cin.ignore();
                    getline(cin,author4);
                     cout<<"Enter author5:- ";
                     cin.ignore();
                    getline(cin,author5);
                    cout<<"Enter Identifier:- ";
                    cin>>identifier;
                    Library.purchase(title,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
                    cout<<"\nDo you wanted to continue with further options y/n: \n";
                    char option;
                    cin >> option;
                    if(option == 'n'){
                        return 0;
                    }
                    break;
                }
        case '4':
                {   
                    return 0; 
                }
        default:
                {
                    cout<<"Do you wanted to continue with further options y/n: \n";
                    char option;
                    cin >> option;
                    if(option == 'n'){
                        return 0;
                    }
                    break;
                }
        }
    }
    
    return 0;
}