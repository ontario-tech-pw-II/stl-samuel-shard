// Student class is implemented based on string and does not need any changes

#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    //Check for correct number of command line arguments
    if (argc != 2){
        cout << "Error, must provide 1 argument: student-grade input file.\n";
        cout << "Exiting program.\n";
        return 0;
    }

    //Create input file stream, from command argument 1
    ifstream fin(argv[1]);
    //check file can be opened
    if (fin.fail()){
        cerr << "Cannot open the input file.\n";
        cout << "Exiting program.\n";
        return 0;
    }else{
        cout << "Reading " << argv[1] << endl;
    }

    //Read through file and count occurrences of search string
    string word;
    
    //input file alternates between student name and student grade
    //wordOrGrade even means name, wordOrGrade odd means grade
    int wordOrGrade = 0;

    //store current name
    string tempName;

    //create set to store all students that have 1 or more grades below 50
    set<string> lowGrade;

    //read in words
    while(fin >> word){
        //cout << word << "/"; //for testing
        //if line is student name
        if (wordOrGrade % 2 == 0){
            //store student name in temp variable
            tempName = word;

        }//else line is student grade
        else{
            //cout << "Student grade " << word[0]-48 << word[1]-48;
            //if grade is less than 50
            if(int(word[0])-48 < 5){
                //cout << "\t" << tempName << " has failing grade."; // for testing purposes
                //store name in set
                lowGrade.insert(tempName);
            }
            //cout << endl;
        }
        wordOrGrade++;
    }

    //declare iterator to access and output students with low grades
    set<string>::iterator p;
    cout << "Set of students with 1 or more grades below 50:\n";
    for(p = lowGrade.begin(); p!= lowGrade.end(); p++){
        cout << *p << endl;
    }
    fin.close();
    return 0;
}
/*Q: For part 2 of the GitHub Activity, how can there be 3 Johns?  
I thought each key in a map had to be unique.
A: For the first time you just insert. 
For the 2n’d and 3'd you update the count.*/