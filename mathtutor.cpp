//
// Created by Jemcla01 on 11/14/2025.
//
/************************************************************************************************
Program.......: Math Tutor V5
Programmers...: Suna Aregay, Jesse McLaughlin
Date..........: November 16th, 2025
Section.......: Section 3 – 12:00 pm
GitHub Repo...: https://github.com/suna2km/Math_TutorV5
Description...: This file contains all the functions that the main function calls.
*************************************************************************************************/
#include <cctype>   //for lowercasing yes/no input
#include <cstdlib>  //for srand and rand
#include <iomanip>  //for report column alignment
#include <iostream> //for cout and cin
#include <limits>   //for invalid numeric inputs
#include <string>   //for string datatypes
#include <vector>   //for storing the question in a 2D vector

using namespace std;

//constant variables
const int MAX_ATTEMPTS = 3; // gives user 3 attempts per question
const int LEVEL_RANGE_CHANGE = 10; //for the amount to change when leveling up or down

/*****************************************************
     * Display the program intro and jokes.
*****************************************************/
void DisplayGameIntro() {
    //output an ascii art title using a raw string literal to ignore escape sequences
    //output some funny math jokes
    cout << R"(
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ~___  ___      _   _       _____     _             ~
        ~|  \/  |     | | | |     |_   _|   | |            ~
        ~| .  . | __ _| |_| |__     | |_   _| |_ ___  _ __ ~
        ~| |\/| |/ _` | __| '_ \    | | | | | __/ _ \| '__|~
        ~| |  | | (_| | |_| | | |   | | |_| | || (_) | |   ~
        ~\_|  |_/\__,_|\__|_| |_|   \_/\__,_|\__\___/|_|   ~
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << endl;
    cout << "**************************************************************************************\n"
            "*   Welcome to the Silly Simple Math Tutor                                           *\n"
            "*   Fun Math facts:                                                                  *\n"
            "*       - Without Geometry, life is pointless                                        *\n"
            "*       - Why was the = sign so humble? Because it knew it wasn't > or < anyone else *\n"
            "*       - Parallel lines have so much in common. It's too bad they'll never meet     *\n"
            "**************************************************************************************\n";

    return;

} //end of DisplayGameIntro function

/*****************************************************
 * Prompt the user for their name and welcome the user
 * Returns the user's name
 *****************************************************/
string GetName() {
    string userName = "?";

    //ask for the user's name and store the response
    cout << "What is your name? ";
    getline(cin, userName);

    //Greet the user using their entered username
    cout << "Welcome " << userName << " to the Silly Simple Math Tutor!" << endl;

    return userName;

} //end of GetName function

/***************************************************************
 * Loop until a numeric value is entered
 * returns the user's answer
 ***************************************************************/
int GetUserAnswer() {
    int userAnswer = 0;
    // Validate the user's answer by looping until numeric data is entered
    while (!(cin >> userAnswer)) {
        cin.clear(); // clear the cin error flag
        // need to include the limits library to use numeric_limits
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); //ignore the max input, up to '\n'
        cout << "\tInvalid input!" << endl;
        cout << "\tPlease enter a number: ";
    } // end of get userAnswer while loop

    return userAnswer;

} //end of GetUserAnswer function

/***************************************************************
 * For loop to give the user three attempts
 * receives the currrentQuestion vector storing the current question's data and user's name
 * returns true if user answers correctly otherwise, false
 ***************************************************************/
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion) {

    int userAnswer = 0;
    bool isCorrect = false;

    int mathLevel = currentQuestion.at(0);
    int leftNumber = currentQuestion.at(1);
    char mathSymbol = static_cast<char>(currentQuestion.at(2));
    int rightNumber = currentQuestion.at(3);
    int correctAnswer = currentQuestion.at(4);

    cout << endl;

    //use the random left number, right number, and math symbol to ask the user a math question
    //give the user three attempts to answer correctly while informing them what level they are on
    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        cout << "[Level #" << mathLevel << "] " << userName << ", what is "
                << leftNumber << " " << mathSymbol << " " << rightNumber << " = ";

        // Get User Answer
        userAnswer = GetUserAnswer();

        //if user's answer is correct, increment their totalCorrect answers by 1, display "congrats" and break out
        if (userAnswer == correctAnswer) {
            currentQuestion.push_back(i); //adding a value to row for when we add the summary
            cout << "\tCongratulations! You answered correctly!" << endl;
            cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
            cout << "\t\t\t\t*happy tail wags*" << endl;
            isCorrect = true;
            break; //exit loop on correct answer
        } else {
            //if the user answered incorrectly and has no attempts left, display "sorry"" and the correct answer
            //also increment the user's totalIncorrect answers by 1
            if (i >= MAX_ATTEMPTS) {
                currentQuestion.push_back(0);
                cout << "\tSorry! You answered incorrectly..." << endl;
                cout << "\tThe correct answer was " << correctAnswer << "." << endl;
                cout << R"(
                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V)" << endl;
                cout << "\t\t\t\t*sad puppy noises*" << endl;
            }
            //if the user answered incorrectly with attempts still remaining, display "sorry" and remaining attempts
            else {
                cout << "\tSorry! You answered incorrectly..." << endl;
                cout << "\t";
                cout << "\tYou have " << MAX_ATTEMPTS - i << " attempt(s) remaining" << endl;
            }
        }
    } //end of user's attempts at answering a question

    return isCorrect;

} //end of GiveThreeAttempts function

/***************************************************************
 * asks the user if they want to continue playing
 * returns the user input
 ***************************************************************/
string YesNoQuestion(string question) {
    string userInput = "?";
    //ask whether the user wishes to continue
    while (true) {
        cout << "\nDo you want to continue? (y= yes | n=no) ";
        getline(cin, userInput); // clears the new line from the input buffer
        for (int i = 0; i < userInput.size(); i++) //cast all characters to lower case
            userInput.at(i) = tolower(userInput.at(i));
        //if the user entered a valid value, break from the loop
        if (userInput == "y" || userInput == "yes" ||
            userInput == "n" || userInput == "no")
            break;
        //if the user entered an invalid value, output the result & allow loop to continue
        else {
            cout << "\tInvalid input, please try again...";
        }
    } //end validating if user wishes to continue

    return userInput;

} //end of AskToPlayAgain function

/***************************************************************
 * display summary report by receiving the 2D vector that strores all questions
 ***************************************************************/
void DisplaySummaryReport(const vector<vector<int> > &allQuestions) {
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 0;
    int leftNumber = 0;
    char mathSymbol = '?';
    int rightNumber = 0;
    int correctAnswer = 0;
    int numAttempts = 0;

    //summary report asci art
    cout << "========================================" << endl;
    cout << "             " << "Summary Report" << endl;
    cout << "========================================" << endl;
    cout << "Level      Questions           Attempts " << endl;
    cout << "=====  =================      ==========" << endl;

    // resets total Correct and Incorrect values for use again
    totalCorrect = 0;
    totalIncorrect = 0;

    //loop through the 2D vector to display all questions
    for (int i = 0; i < allQuestions.size(); i++) {
        //give the proper value in the correct position
        mathLevel = allQuestions.at(i).at(0);
        leftNumber = allQuestions.at(i).at(1);
        mathSymbol = static_cast<char>(allQuestions.at(i).at(2));
        rightNumber = allQuestions.at(i).at(3);
        correctAnswer = allQuestions.at(i).at(4);
        numAttempts = allQuestions.at(i).at(5);

        cout << " " << setw(2) << right << mathLevel //displays the vector using the order we just set
                << "     " << setw(3) << right << leftNumber
                << " " << mathSymbol
                << " " << setw(3) << left << rightNumber << "="
                << "  " << setw(3) << correctAnswer;

        if (numAttempts != 0) {
            //displays the number of attempts that they used
            cout << "    " << setw(9) << right << numAttempts << " " << endl;
            totalCorrect++;
        } else {
            //if all attempts are used, displays that they got the answer incorrect
            cout << "       " << setw(9) << right << "Incorrect" << endl;
            totalIncorrect++;
        }
    }
    cout << endl; //does the math to figure out the total questions and the average you got correct
    cout << "Total Questions: " << right << (totalCorrect + totalIncorrect) << endl;
    cout << "Total Correct  : " << right << totalCorrect << endl;
    cout << "Total Incorrect: " << right << totalIncorrect << endl;
    cout << "Average Correct: " << right << (totalCorrect * 100) / (totalCorrect + totalIncorrect) << "%" << endl;
    cout << endl;

    return;

} //end of DisplaySummaryReport function

/***************************************************************
 * generate each random question
 * receives mathLevel to set left and right number ranges
 * returns current questions data as a int vector
 * ************************************************************/
vector<int> GenerateRandomQuestion(int mathLevel) {

    //for the different math operations used
    enum MathType { MT_ADDITION = 1, MT_SUBTRACTION = 2, MT_MULTIPLICATION = 3, MT_DIVISION = 4 };
    MathType mathType = MT_ADDITION; //stores the random MathType enum generated for the current question

    int correctAnswer = 0; //for storing the correct answer to each math question
    char mathSymbol = '?'; //stores the math operation symbols
    int userAnswer = 0; //for the answer to the question
    int tempNumber = 0; //for swapping the left and right numbers to prevent negative answers
    int leftNumber = 0; //stores the operand on the left side of the math symbol
    int rightNumber = 0; //stores the operand on the right side of the math symbol
    int totalCorrect = 0; //keeps track of how many questions the user got correct
    int totalIncorrect = 0; //keeps track of how many question the user got incorrect
    int currentRange = LEVEL_RANGE_CHANGE; //current range for random numbers

    //generate a random number between 1 and the current level's range for right and left numbers
    leftNumber = (rand() % currentRange) + 1;
    rightNumber = (rand() % currentRange) + 1;

    //generate a random number between 1-4
    //use the random number generated to randomly select a math type from the MathType enumeration.
    //Store the result cast to a MathType enumeration object
    mathType = static_cast<MathType>(rand() % 4 + 1);

    //set the math symbol based on the random MathType enumeration that was generated using a switch statement
    switch (mathType) {
        case MT_ADDITION:
            mathSymbol = '+';
            correctAnswer = leftNumber + rightNumber;
            break;
        case MT_SUBTRACTION:
            mathSymbol = '-';
            //larger number on the left to avoid negative numbers
            if (leftNumber < rightNumber) {
                tempNumber = leftNumber; //storing smaller num in temp
                leftNumber = rightNumber; //put larger num in leftNumber
                rightNumber = tempNumber; //storing smaller num in rightNumber
            }
            correctAnswer = leftNumber - rightNumber;
            break;
        case MT_MULTIPLICATION:
            mathSymbol = '*';
            correctAnswer = leftNumber * rightNumber;
            break;
        case MT_DIVISION:
            mathSymbol = '/';
            //To avoid fractional answers, treat correctAnswer as the intended result
            correctAnswer = leftNumber;
            leftNumber *= rightNumber; //to make leftNumber evenly divisible
            break;
        default: //error message
            //displayed if math type is outside the valid values 1-4
            cout << "Invalid math type: " << mathType << endl;
            cout << "Please report this error to Suna Aregay or Ben Stearns" << endl;
            cout << "Error code -1";
            exit(-1);

            // creates a new vector to record one question’s data
            // this will be stored in a 2D vector for the summary report
    } // end of switch

    return {mathLevel, leftNumber, mathSymbol, rightNumber, correctAnswer};

} //end of GenerateRandomQuestion function

/*********************************************************************
 * Checks For level change and increments or decrements currentRange
 *********************************************************************/
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel) {

    //constant variable
    const int LEVEL_RANGE_CHANGE = 10; //for the amount to change when leveling up or down
    int currentRange = LEVEL_RANGE_CHANGE; //current range for random numbers

    //check whether the user got 3 questions answered correctly
    //if so, increase their math level, range of random numbers generated, and reset totalCorrect/Incorrect to 0
    //output that they've leveled up and what their new level and range of numbers are
    if (totalCorrect == 3) {
        mathLevel++;
        totalCorrect = 0;
        totalIncorrect = 0;
        currentRange = mathLevel * LEVEL_RANGE_CHANGE;
        cout << "\tCongrats, you have leveled up!" << endl;
        cout << "\tYour current level is now " << mathLevel << " with numbers ranging from 1-" << currentRange <<
                endl;
    }
    //check whether user got 3 questions incorrect and their current mathLevel is greater than level 1
    //if so, decrease their math level, range of random numbers generated, and reset totalCorrect/Incorrect to 0
    //output that they've leveled down, their new math level and new range of random numbers
    if (totalIncorrect == 3 && mathLevel > 1) {
        mathLevel--;
        totalCorrect = 0;
        totalIncorrect = 0;
        currentRange = mathLevel * LEVEL_RANGE_CHANGE;
        cout << "\tSorry, you answered too many questions incorrectly and leveled down" << endl;
        cout << "\tYour current level is now " << mathLevel << " with numbers ranging from 1-" << currentRange <<
                endl;
    }

    return;

} //end of CheckForLevelChange function
