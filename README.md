<!-- 
https://github.com/lifeparticle/Markdown-Cheatsheet
https://youtu.be/eVGEea7adDM?si=cz1Fbqxr9VgioIEh
-->

# Math Tutor V6

<b>Table of Content</b>
- [Summary](#summary)
- [Console Output Example](#console-output-examples)
- [Maintainers](#maintainers)

## Summary
Welcome to Math Tutor Version 6!

This is a fun program to test your math skills with some randomly generated math questions.
Do super well and you can level up to harder problems!
Be careful though. Get too many wrong and you might level down. Give it a try
and see how you did with the summary report it gives you at the end!

Here's a list of what this program does:
- Displays a fun welcome banner with funny math jokes
- Asks for your name so it knows who you are!
- Uses random generation to produce a math problem for you to solve
- You get 3 attempts to answer the question correctly
- After each question, you get the choice of whether to continue playing
- If you get 3 questions correct you level up to harder problems!
- But if you run out of your 3 attempts first then you level down to simpler problems (Level 1 is the lowest)
- Validates all answers are numeric and whether you give a valid response to continue playing (upper or lower case is fine!)
- Gives a summary report that displays the level, questions and attempts when the user quits the game
- Displays the summary totals including the average in the report
- (new) Allows the user to save and load their session using a file

## Loading Previous Game Console Output Examples
```
Welcome suna to the Silly Simple Math Tutor!
Looks like you've played this game before.

suna, Do you want to load your previous game? (y=yes | n=no)y

Loading previous game...please wait.
Successfully loaded 5 questions from mathtutor.txt

[Level #2] suna, what is 63 / 9 =7

        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*

suna, Do you want to continue? (y=yes | n=no)y


[Level #2] suna, what is 45 / 5 =9

        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*

suna, Do you want to continue? (y=yes | n=no)n

========================================
             Summary Report
========================================
Level      Questions           Attempts
=====  =================      ==========
  1       1 + 7  =  8              1
  1       8 / 2  =  4              1
  1      48 / 6  =  8              1
  2      10 - 2  =  8              1
  2       3 + 6  =  9         Incorrect
  2      63 / 9  =  7              1
  2      45 / 5  =  9              1

Total Questions: 7
Total Correct  : 6
Total Incorrect: 1
Average Correct: 85%

suna, Would you like to save your progress? (y=yes | n=no)
```
## Saving Progress Console Output Example
```
suna, Do you want to continue? (y=yes | n=no)n

========================================
             Summary Report
========================================
Level      Questions           Attempts
=====  =================      ==========
  1       1 + 7  =  8              1
  1       8 / 2  =  4              1
  1      48 / 6  =  8              1
  2      10 - 2  =  8              1
  2       3 + 6  =  9         Incorrect
  2      63 / 9  =  7              1
  2      45 / 5  =  9              1

Total Questions: 7
Total Correct  : 6
Total Incorrect: 1
Average Correct: 85%

suna, Would you like to save your progress? (y=yes | n=no)sure

        Invalid input, please try again...
suna, Would you like to save your progress? (y=yes | n=no)y

Please wait while we save your progress
Successfully saved your progress!
Added 7 questions to mathtutor.txt

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                 Goodbye!
Thanks for playing the silly simple math tutor suna!

Process finished with exit code 0
```


## Maintainers
[@suna2km](https://github.com/suna2km) Suna Aregay  
[@KagePeterson](https://github.com/KagePeterson) Kage Peterson

[Back to Top](#math-tutor-v6)
