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
- Allows the user to save and load their session using a file

## Console Output Examples
```
``` Load Previous Game Output Example

        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        ~___  ___      _   _       _____     _             ~
        ~|  \/  |     | | | |     |_   _|   | |            ~
        ~| .  . | __ _| |_| |__     | |_   _| |_ ___  _ __ ~
        ~| |\/| |/ _` | __| '_ \    | | | | | __/ _ \| '__|~
        ~| |  | | (_| | |_| | | |   | | |_| | || (_) | |   ~
        ~\_|  |_/\__,_|\__|_| |_|   \_/\__,_|\__\___/|_|   ~
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
**************************************************************************************
*   Welcome to the Silly Simple Math Tutor                                           *
*   Fun Math facts:                                                                  *
*       - Without Geometry, life is pointless                                        *
*       - Why was the = sign so humble? Because it knew it wasn't > or < anyone else *
*       - Parallel lines have so much in common. It's too bad they'll never meet     *
**************************************************************************************
What is your name?suna

Welcome suna to the Silly Simple Math Tutor!
Looks like you've played this game before.

suna, Do you want to load your previous game? (y=yes | n=no)y

Loading previous game...please wait.
Successfully loaded 14 questions from mathtutor.txt
[Level #3] suna, what is 8 + 3 =11

        Congratulations! You answered correctly!

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                *happy tail wags*

suna, Do you want to continue? (y=yes | n=no)y


[Level #3] suna, what is 8 + 10 =2

        Sorry! You answered incorrectly...
                You have 2 attempt(s) remaining
[Level #3] suna, what is 8 + 10 =3

        Sorry! You answered incorrectly...
                You have 1 attempt(s) remaining
[Level #3] suna, what is 8 + 10 =6

        Sorry! You answered incorrectly...
        The correct answer was 18.

                                 /^ ^\
                                / 0 0 \
                                V\ ⁀ /V
                                 /   \
                                 |    \
                                 || (__V
                                *sad puppy noises*

suna, Do you want to continue? (y=yes | n=no)n

========================================
             Summary Report
========================================
Level      Questions           Attempts
=====  =================      ==========
  1       5 * 7  =  35             1
  1      10 * 2  =  20        Incorrect
  1      32 / 4  =  8              3
  1       6 - 5  =  1              1
  1       7 * 4  =  28             1
  1       2 / 2  =  1              1
  2       6 - 3  =  3         Incorrect
  2       6 - 4  =  2              1
  2       7 - 4  =  3              1
  2       3 + 6  =  9              1
  2       3 + 7  =  10             1
  2      27 / 9  =  3              1
  3       6 + 3  =  9              2
  3       5 + 9  =  14        Incorrect
  3       8 + 3  =  11             1
  3       8 + 10 =  18        Incorrect

Total Questions: 16
Total Correct  : 12
Total Incorrect: 4
Average Correct: 75%

```
``` Saving Progress Console Output Example
suna, Would you like to save your progress? (y=yes | n=no)y

Please wait while we save your progress
Successfully saved your progress!
Added 16 questions to mathtutor.txt

                                 /^ ^\
                                / 0 0 \
                                V\ ‿ /V
                                 /   \
                                 |    \
                                 || (__V
                                 Goodbye!
Thanks for playing the silly simple math tutor suna!

```


## Maintainers
[@suna2km](https://github.com/suna2km) Suna Aregay  
[@KagePeterson](https://github.com/KagePeterson) Kage Peterson

[Back to Top](#math-tutor-v6)
