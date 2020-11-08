# Mini-tasks-program
A program containing various tasks including a math game, a binary,hexa and denary number conversion tool as well as a UPC code generator and checker. 

Menu System:
A top-level menu system allowing the user to select various applications and checking for invalid input which return a message and redisplay the menu. Inlcude code to launch each function and also to exit the application.

Keep Counting:
A Math quiz which uses the last result given to ask further questions. This incudes addition, subtraction or questions with a range of both. The time taken for the whole quiz and/or to solve the number of questions correctly until one is wrong is then displayed. 

Number Conversion Tool:
A tool to convert numbers from denary to binary and to hexa, all made from scratch. All 3 can be converted from each of them to the others. Then it displays the result.

UPC Generator and Checker: 
Two programs made to generate a UPC code of a smaller size than normal. It takes a 6 digit number and generates the 7th digit using the following rules:
- Add the digits in the odd-numbered positions together (working left to right where the 1st position is the left-most digit and excluding the check digit) and multiply by three
- Add the digits in the even-numbered positions to the result.
- Take the remainder of the result when divided by 10 (modulo). 
     - If the remainder is equal to 0 then use 0 as the check digit
     - If the remainder is not equal to 0 then subtract the remainder from 10 to derive the check digit
     
     
All these various programs were made for my 1st assignment back in my 1st year of my bachelor's degree. It is written in C++ and demonstrates the use of various vasic principles such as Functional programming, function prototyping, switch statements, if and elses, etc.

