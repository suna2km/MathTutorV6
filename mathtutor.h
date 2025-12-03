//
// Created by Jemcla01 on 11/14/2025.
//
/************************************************************************************************
Program.......: Math Tutor V5
Programmers...: Suna Aregay, Kage Peterson
Date..........: December 5th, 2025
Section.......: Section 3 – 12:00 pm
GitHub Repo...: https://github.com/suna2km/MathTutorV6
Description...: This file contains all the prototypes for the functions that the main function calls.
*************************************************************************************************/
#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <string> // for string data types
#include <vector> // for storing the questions in a 2D vector

using namespace std;

void DisplayGameIntro();
string GetName();
int LoadPreviousGame(string userName, vector<vector<int>>& allQuestions);
vector<int> GenerateRandomQuestion(int mathLevel);
int GetUserAnswer();
bool GiveThreeAttempts(string userName, vector<int> &currentQuestion);
void CheckForLevelChange (int &totalCorrect, int & totalIncorrect, int &mathLevel);
string YesNoQuestion(string question);
void DisplaySummaryReport(const vector<vector<int>> &allQuestions);
void SaveCurrentGame(string userName, const vector<vector<int>>& allQuestions);

#endif