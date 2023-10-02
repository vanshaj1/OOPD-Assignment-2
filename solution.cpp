//*******************************************************Question1****************************************************
#include <iostream>
// #include <conio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <ctime>
#include <typeinfo>


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
    
};

class book{
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
        void setIdentifier(int no){
            identifier = "B/" + to_string(no);
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
                return -1;
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
            if(this->original_title == title && this->isbn == isbn && this->isbn13 == isbn13 && this->author1 == author1 && this->author2 == author2 && this->author3 == author3 && this->author4 == author4 && this->author5 == author5 && this->identifier == identifier){
                return true;
            }
            return false;
        }
        void borrow(user *User){
            if(books_remaining == 0){
                cout<<"no copies are left please come later";
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
        }

};


class magzine{
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

        }
        void setIdentifier(int no){
            identifier = "M/"+ to_string(no);
        }
        string getIdentifier(){
            return identifier;
        }
        int getUserIdOfTheBorrower(int copy){
            int len = borrowedByIdLength;
            if(copy >= len){
                return -1;
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

};

class journal{
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
     void setIdentifier(int no){
            identifier = "J/"+to_string(no);
    }
    string getIdentifier(){
        return identifier;
    }
    int getUserIdOfTheBorrower(int copy){
        int len = borrowedByIdLength;
        if(copy >= len){
            return -1;
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
};





class library{
    book *uniquebooks = new book[0];
    journal *journals = new journal[0];
    magzine *magzines = new magzine[0];
    user *users = new user[0];
    int noOfUsers = 0;
    int noOfBooks = 0;
    int noOfMagzines = 0;
    int noOfJournals = 0;
    public:
     void addBook(string book_id,string goodreads_book_id,string best_book_id,string work_id,int books_count,string isbn,string isbn13,string author1,string author2,string author3,string author4,string author5, string original_publication_year,string original_title,string title,string language_code,string average_rating,string ratings_count,string work_ratings_count,string work_text_reviews_count,string ratings_1,string ratings_2,string ratings_3,string ratings_4,string ratings_5,string image_url,string small_image_url){
        book newBook;
        newBook.addDetails(book_id,goodreads_book_id,best_book_id,work_id,books_count,isbn,isbn13,author1,author2,author3,author4,author5,original_publication_year,original_title,title,language_code,average_rating,ratings_count,work_ratings_count,work_text_reviews_count,ratings_1,ratings_2,ratings_3,ratings_4,ratings_5,image_url,small_image_url);
        newBook.setIdentifier(noOfBooks);
        
        // if(uniquebooks == nullptr){
        //     uniquebooks = &newBook;
        // }else{
        //     book *temp = uniquebooks;
        //     while(temp->next != nullptr){
        //         *temp = *temp->next;
        //     }
        //     temp->next = &newBook;
        // }
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
        newJournal.setIdentifier(noOfJournals);
        
        // if(journals == nullptr){
        //      journals = &newJournal;
        // }else{
        //     journal *temp = journals;
        //     while(temp->next != nullptr){
        //         temp = temp->next;
        //     }
        //     temp->next = &newJournal;
        // }
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
        newMagzine.setIdentifier(noOfMagzines);
        noOfMagzines++;
        // if(magzines == nullptr){
        //      magzines = &newMagzine;
        // }else{
        //     magzine *temp = magzines;
        //     while(temp->next != nullptr){
        //         temp = temp->next;
        //     }
        //     temp->next = &newMagzine;
             
        // }
            magzine *newArray = new magzine[noOfMagzines];
            for(int i = 0 ;i < noOfMagzines-1;i++){
                newArray[i] = magzines[i];
            }
            newArray[noOfMagzines-1] = newMagzine;
            magzines = newArray;

     }
     void addUser(string name,int type){
        user newUser;
        
        newUser.addDetails(this->noOfUsers,name,type);
        // if(users == nullptr){
        //      users = &newUser;
        // }else{
        //      users->next = &newUser;
        // }
          
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
     void getLocationOfBooks(string title,string isbn,string isbn13,string author1, string author2, string author3 ,string author4, string author5,string identifier){
        book *temp = find(title,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
        if(temp == nullptr){
            cout << "Item is not present";
        }else{
            
            string temp_Idt[3];
            int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
            string token;
            while(identifier.length() != 0 && i < 3){
                token = identifier.substr(0,identifier.find_first_of("/"));
                identifier = identifier.substr(identifier.find_first_of("/") + 1);
                temp_Idt[i] = token;
                i++;
            } 
            /*************************************************************/
            // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
            string fstoi = temp_Idt[2]+"";
            int bno = stoi(fstoi);
            int uid = temp->getUserIdOfTheBorrower(bno);
            if(uid == -1){
                cout << "Book belongs to section : " << temp_Idt[0] << " shelf : " << temp_Idt[1] << " and drawer : " <<temp_Idt[2]<<endl;
            }else{
                cout<<"This book is borrowed by user with id "<<uid<<"\n";
                cout<<"Items issue Date :- "<<temp->getIssueDateOfTheBook(bno)<<endl;
                cout<<"Items return Date :- "<<temp->getReturnDateOfTheBook(bno)<<endl;

            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday<<endl;
        }
     }
     void getLocationOfJournals(string branch,string name,string identifier){
        journal *temp = find(branch,name,identifier);
        if(temp == nullptr){
            cout << "Item is not present";
        }else{
            
            string temp_Idt[3];
            int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
            string token;
            while(identifier.length() != 0 && i < 3){
                token = identifier.substr(0,identifier.find_first_of("/"));
                identifier = identifier.substr(identifier.find_first_of("/") + 1);
                temp_Idt[i] = token;
                i++;
            } 
            /*************************************************************/
            // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
            string fstoi = temp_Idt[2]+"";
            int bno = stoi(fstoi);
            int uid = temp->getUserIdOfTheBorrower(bno);
            if(uid == -1){
                cout << "Jounal belongs to section : " << temp_Idt[0] << "virtual shelf : " << temp_Idt[1] << " and virtual drawer : " <<temp_Idt[2]<<endl;
            }else{
                cout<<"This journal is borrowed by user with id "<<uid<<"\n"; 
                cout<<"Items issue Date :- "<<temp->getIssueDateOfTheJournal(bno)<<endl;
            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday<<endl;
        }
     }
     void getLocationOfMagzines(string publication,string identifier){
        magzine *temp = find(publication,identifier);
        if(temp == nullptr){
            cout << "Item is not present";
        }else{
            
            string temp_Idt[3];
            int i = 0;
            //*********************Open source stack overflow************* cite:- https://stackoverflow.com/a/14265607
            string token;
            while(identifier.length() != 0 && i < 3){
                token = identifier.substr(0,identifier.find_first_of("/"));
                identifier = identifier.substr(identifier.find_first_of("/") + 1);
                temp_Idt[i] = token;
                i++;
            } 
            /*************************************************************/
            // cout<<temp_Idt[0]<<temp_Idt[1]<<typeid(temp_Idt[2]).name();
            string fstoi = temp_Idt[2]+"";
            int bno = stoi(fstoi);
            int uid = temp->getUserIdOfTheBorrower(bno);
            if(uid == -1){
                cout << "Magzine belongs to Virtual section : " << temp_Idt[0] << " Virtual shelf : " << temp_Idt[1] << " and Virtual drawer : " <<temp_Idt[2]<<endl;
            }else{
                cout<<"This magzine is borrowed by user with id "<<uid<<"\n"; 
                cout<<"Items issue Date :- "<<temp->getIssueDateOfTheMagzine(bno)<<endl;
            }
            //********************************Open Source*********************** cite: https://stackoverflow.com/a/997988
            std::time_t t = std::time(0);   // get time now
            std::tm* now = std::localtime(&t);
            //******************************************************************
            cout<<"Requested for Item Location on :- "<<now->tm_year + 1900<<'-'<<now->tm_mon + 1<<'-'<<now->tm_mday;
        }
     }
    book * find(string title,string isbn,string isbn13,string author1, string author2 , string author3, string author4, string author5,string identifier){
        // book *temp = uniquebooks;
        // while(temp  != nullptr){
        //     if(temp->check(title,isbn,isbn13,author1, author2, author3, author4, author5,identifier)){
        //         return temp;
        //     }
        //     *temp  = *temp->next;
        // }
        
        int len = noOfBooks;  // working on  <-----------------------
        for(int i = 0 ;i < len;i++){
            if(uniquebooks[i].check(title,isbn,isbn13,author1, author2, author3, author4, author5,identifier)){
                return &uniquebooks[i];
            }
        }
        return nullptr;
     }
    journal * find(string branch,string name,string identifier){
        // journal *temp = journals;
        // while(temp  != nullptr){
        //     if(temp ->check(branch,name,identifier)){
        //         return temp;
        //     }
        //     *temp  = *temp->next;
        // }
        int len = noOfJournals;  // working on  <-----------------------
        for(int i = 0 ;i < len;i++){
            if(journals[i].check(name,identifier)){
                return &journals[i];
            }
        }
        return nullptr;
     }
    magzine * find(string publication,string identifier){
        // magzine *temp = magzines;
        // while(temp  != nullptr){
        //     if(temp ->check(publication,identifier)){
        //         return temp;
        //     }
        //     *temp  = *temp->next;
        // }
        // int len = sizeof(magzines)/sizeof(magzines[0]);  // working on  <-----------------------
        // cout<<"THe length"<<len;
        for(int i = 0 ;i < noOfMagzines;i++){
            if(magzines[i].check(publication,identifier)){
                return &magzines[i];
            }
        }
        return nullptr;
     }
     user * find(int uid){
        // user *temp = users;
        // while(temp  != nullptr){
        //     if(temp ->check(uid)){
        //         return temp;
        //     }
        //     *temp  = *temp->next;
        // }
        // int len = sizeof(users)/sizeof(users[0]);  // working on  <-----------------------
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
};



void readingJournal(library *Library,string nameofFile){
    string line;
    ifstream file(nameofFile);

    while(getline(file,line)){
        
        stringstream s(line);
        string res = "";
        string word; 
        while(getline(s,word,',')){
            res += word;
        }
        res = '"'+res+'"';
        cout<<res;
        Library->addJournals(res);
    }
}

void readingMagzines(library *Library,string nameofFile){
    string line;
    ifstream file(nameofFile);

    getline(file,line);
    while(getline(file,line)){
        
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
}

void readingBooks(library *Library,string nameofFile){
    string line;
    ifstream file(nameofFile);
    
    getline(file,line);
    while(getline(file,line)){
        
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
}

int main(){
    library Library;
    readingBooks(&Library,"books.csv");
    readingMagzines(&Library,"publications_rank.csv");
    readingJournal(&Library,"journals.csv");
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
                    book *Book = Library.find(title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
                    if(Book == nullptr){
                        cout<<"This Book is not available with us \n ";
                    }else{
                        string name;
                        int uid;
                        cout<<"we are having the book but for borrowing please provide us details about you :- \n";
                        cout<<"Enter name: ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter user id:- ";
                        cin>>uid;
                        user *User = Library.find(uid);
                        if(User == nullptr){
                            cout<<"Your are not registered with us, Kindly register yourself first \n";
                        }else{
                            // User->borrowBooks(Book->getIdentifier());
                            Book->borrow(User);
                        }

                    }
                }else if(item == 'J'){
                    string branch, name, identifier;
                    cout<<"Enter details of the Journal to borrow\n";
                    cout<< "Enter name:- ";
                    cin.ignore();
                    getline(cin,name);
                    cout<<"Enter identifier:- ";
                    cin>> identifier;
                    journal *Journal = Library.find(" ",name,identifier);
                    if(Journal == nullptr){
                        cout<<"This Journal is not available with us \n ";
                    }else{
                        string name1;
                        int uid;
                        cout<<"we are having the book but for borrowing please provide us details about you :- \n";
                        cout<<"Enter name: ";
                        cin.ignore();
                        getline(cin,name1);
                        cout<<"Enter user id:- ";
                        cin>>uid;
                        user *User = Library.find(uid);
                        if(User == nullptr){
                            cout<<"Your are not registered with us, Kindly register yourself first \n";
                        }else{
                            // User->borrowJournals(Journal->getIdentifier());
                            Journal->borrow(User);
                        }
                    }

                }else if(item == 'M'){
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
                    }else{
                        string name;
                        int uid;
                        cout<<"we are having the book but for borrowing please provide us details about you :- \n";
                        cout<<"Enter name: ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter user id:- ";
                        cin>>uid;
                        user *User = Library.find(uid);
                        if(User == nullptr){
                            cout<<"\nYour are not registered with us, Kindly register yourself first ";
                        }else{
                            // User->borrowMagzines(Magzine->getIdentifier());
                            Magzine->borrow(User);
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
                        Library.getLocationOfBooks(title ,isbn,isbn13,author1,author2,author3,author4,author5,identifier);
                    }else if(item == 'M'){
                        string publication,identifier;
                        cout<<"Enter details of the Magzine to get Location\n";
                        cout<<"Enter publications:- ";
                        cin.ignore();
                        getline(cin,publication);
                        cout<< "Enter identifier- ";
                        cin >> identifier;
                        Library.getLocationOfMagzines(publication,identifier);
                    }else if(item == 'J'){
                        string branch, name, identifier;
                        cout<<"Enter details of the Journal to get Location\n";
                        cout<< "Enter name:- ";
                        cin.ignore();
                        getline(cin,name);
                        cout<<"Enter identifier:- ";
                        cin>> identifier;
                        Library.getLocationOfJournals(" ",name,identifier);
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
                    int type;
                     
                    cout<<"For registration please provide you details as follows: \n";
                    cout<<"Enter your name: ";
                    cin.ignore();
                    getline(cin,name);
                    cout<<"Enter your user type 0 for student and 1 for professor: ";
                    cin>>type;
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