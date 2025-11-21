/************************************************************************************************
Program.......: Math Tutor V5
Programmers...: Suna Aregay, Jesse McLaughlin
Date..........: November 16th, 2025
Section.......: Section 3 – 12:00 pm
GitHub Repo...: https://github.com/suna2km/Math_TutorV5
Description...: The purpose of this program is to:
                    - Display a fun welcome banner with funny math jokes
                    - Ask for the user's name and greet them
                    - Use random generation to produce a math problem for the user to solve
                    - Give the user 3 attempts to answer the question correctly
                    - Asks if the user wishes to continue after each question
                    - If the user answers 3 questions correctly they level up to harder problems
                    - If the user answers 3 questions incorrectly they level down to simpler problems if applicable
                    - Validates that all answers are numeric and if user enters a valid wish to continue
                    - Gives a summary report that displays the level, questions and attempts when the user quits the game
                    - Displays the summary totals including the average in the report
*************************************************************************************************/
#include <cstdlib>   // used to add random numbers
#include <ctime>     //to allow for the use of the time() function for random seeding
#include <iostream>  //used to allow for input and output to the console
#include <windows.h> //to allow the console output to be set to UTF-8 for better ascii art support
#include <vector>    //to store lists of questions and related data
#include <string>    //for string datatypes

#include "mathtutor.h" // Math Tutor Functions

using namespace std; //so fully-qualified statements aren't needed for cout's and cin's



//Begin main function of the program
int main() {

    vector<vector<int>> allQuestions; //stores the 2D vector called questions

    //other necessary variables for program operation
    string userName = "?";  //stores user's name
    string userInput = "?"; //for asking if the user wishes to continue

    int totalCorrect = 0;   //keeps track of how many questions the user got correct
    int totalIncorrect = 0; //keeps track of how many question the user got incorrect
    int mathLevel = 1;      //current difficulty level

    SetConsoleOutputCP(CP_UTF8); //sets the console output code page to UTF-8 for better ascii art support
    bool isCorrect = false; //did the user answer the current question correctly

    // use the system time clock for seeding, which in turn allows for pseudorandom number generation
    srand(time(0));

    // Welcome the user
    DisplayGameIntro();
    userName = GetName();


    // perform operations for creating and asking math questions once
    // continue operations while the user wishes to continue with the program
    do {

        vector<int> currentQuestion = GenerateRandomQuestion(mathLevel);

       isCorrect = GiveThreeAttempts(userName, currentQuestion);

        //used for leveling up or down
        if (isCorrect) {
            totalCorrect ++;
        } else {
            totalIncorrect ++;
        }

        // Checks if level needs to be increased/decreased
        CheckForLevelChange(totalCorrect, totalIncorrect, mathLevel);

        allQuestions.push_back(currentQuestion); //stores the completed row into the 2D vector of all questions

        getline(cin, userInput); // clears the new line from the input buffer

        userInput = AskToPlayAgain(userName);

    } while (userInput == "yes" || userInput == "y");
    //end of user's wish to continue with the program

    DisplaySummaryReport(allQuestions);

        //say goodbye to the user
        cout << "Thanks for playing the silly simple math tutor " << userName << "!" << endl;

        //end program by returning 0
        return 0;
}

