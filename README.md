Introduction
The Beal Conjecture is an unsolved problem in number theory. It was discovered by Andrew Beal while attempting to generalise Fermat's Last Theorem and stated that if Ax + By = Cz, where A, B, C, x, y, z are positive integers with x, y, z >2, then A, B, C have a common prime factor.
Example
23 + 23 = 24
Evaluation: 23 = 8, 23 = 8, 24 = 16; 8 + 8 = 16
This equation satisfies the Beal Conjecture because A, B, and C share a common prime factor, 2.
Beal Number Total (BNT)
The Beal Number Total (BNT) is A + B + C + x + y + z.
Example BNT 1: For the equation 23 + 23 = 24, the BNT is 2 + 2 + 2 + 3 + 3 + 4 = 16.
Example BNT 2: For the equation 33 + 63 = 35; the BNT is 3 + 3 + 6 + 3 + 3 + 5 = 23.
Guidance
Always consider efficiency of timeliness and space in your algorithms.
If you believe that a solution to a question is an empty set (∅), then state this.
Questions
Question 1:
Write a C++ program to find the first five distinct, lowest BNTs that satisfy the Beal Conjecture. Your program should have a command-line interface for user interaction. Show and evaluate the equations that derive these BNTs.
Question 2:
Extend your program to find the first five distinct BNTs that are prime numbers.
Question 3:
Further extend your program to find BNTs where A, B, and C are within the range of 3 to 20, and x, y, and z are within the scope of 3 to 15. Show and evaluate the equations that derive these BNTs.
Question 4:
Develop your program further to write and read outputs to file. This will allow students to check each others’ solutions are correct regarding the preceding three questions. The file format should be plain text with the following layout: 
BNT: Equation (newline)
// There may be multiple equations that can derive the BNT, so these can be on multiple lines
For our previous examples   the file format should be: 
16: 2, 3, 2, 3, 2, 4
23: 3, 3, 6, 3, 3, 5
Question 5:
Extend your program to find the first ten distinct BNTs that are composite numbers.
Question 6:
Extend your program to find the BNTs that are square numbers between 1000 and 100000.
Question 7:
Extend your program to generate an ASCII represented histogram of BNT occurrences between a minimum and a maximum value as specified by a user.
Question 8:
Find the highest BNT you can and display it with the equations that derive it. However, A, B, and C must all be greater than 2 for this task.
