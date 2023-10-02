# Commands To build the file
  * using Makefile
    * -> make : It will create both debug file and optimized binary files
    * -> make debug : It will create debug binary file 
    * -> make optimized : It will create optimized binary file 

# Commands to run file 
   * ./< Name of any binary > 

# Input Formats
   * For Books input Information 
      * title
      * isbn
      * isbn13
      * author1
      * author2
      * author3
      * author4
      * author5
      * identifier
     * -> Enter Details as plain string without using ""
   * For Magzine input Information 
      * publication
      * identifier
     * -> Enter publication using "" around input string
   * For Journal input Information
      * name
      * identifier
     * -> Enter name using "" around input string
    
# Used Libraries provided by C++ inbuilt
   *  iostream
   *  fstream
   *  sstream
   *  string
   *  cmath

# used some open source solutions for some functions (all these soltions are also commented in code as open source with citations)
   * cite:- https://stackoverflow.com/a/25385766 // :- used to Trim string when taking string from csv
      * ->  inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
      * ->  {
      * ->     s.erase(s.find_last_not_of(t) + 1);
      * ->     return s;
      * ->  }
      * -> 
      * ->  // trim from beginning of string (left)
      * ->  inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
      * ->  {
      * ->     s.erase(0, s.find_first_not_of(t));
      * ->     return s;
      * ->  }
      * -> 
      * ->  // trim from both ends of string (right then left)
      * ->  inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
      * ->  {
      * ->     return ltrim(rtrim(s, t), t);
      * ->  }
   * cite: https://stackoverflow.com/a/997988 :- used for getting current time and date
      * -> std::time_t t = std::time(0);   // get time now
      * -> std::tm* now = std::localtime(&t);
   * cite:- https://stackoverflow.com/a/14265607 :- used for splitting the string 
      * ->  string token;
      * ->  while(identifier.length() != 0 && i < 3){
      * ->      token = identifier.substr(0,identifier.find_first_of("/"));
      * ->      identifier = identifier.substr(identifier.find_first_of("/") + 1);
      * ->      temp_Idt[i] = token;
      * ->      i++;
      * ->  } 
   

   