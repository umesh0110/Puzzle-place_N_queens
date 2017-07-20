# Puzzle-place_N_queens
Puzzle of placing N queens in NxN chessboard without attacking.

N queen problem can be solved by using stacks and backtracking method. Placing N queens in the NxN chess board without conflicting requires a Stack of N size. Each element in the stack refers to the queen position in a particular column.
Sorting is used in this problem to sort the scores from players and display the high scores. 
Files are used to store previous scores.

Functions description :

queen():
	This function finds the solutions for n queens by using backtracking.each solution is stord in array a. 
	
place()
	This is called when the position of queens placed in the chessboard by the user is to be checked.

sort() :
 In this module, Sorting occurs between the scores taken from the file and present score, The resultant will be the top scores of the particular level.

bsearch():
	When the user place few queens and ask the program for remaining solutions,the solution nearer to the placed queens is searched in this function. Binary search is used in this.

drawString ():
Printing strings in the glut window needs this function.

displaymenu():
	Display function calls this function in the initial or when mode is 0.It displays the levels, user have to select level using mouse.

displaysols():
	Display function calls this when user click get solutions.it displays few number of queens and user have to select the required queens.Then it displays the solutions required.

displayboard():
	Display function calls this function when chessboard is to be printed.

displayregd():
	Display function displays the final scores, high scores and your rating based on time.

display():
	This function is rendered whenever the display is changed, glutPostRedisplay is used to call this function. Based on the mode required, display function calls the other  functions.	

reshape():
	when the size of the glutwindow are changed the graphics inside the function are also reshaped. 

mouse ():
	when user press the left click or right click this function is called. Positions of the mouse pointer are taken, and required changes are made.

keyboard():
	When user press the keys in the keyboard this function is called. Based on the key pressed required changes are made.

opef():
 This module helps in opening scores.dat file and input the previous scores for comparison with present score . 

closf(): 
This module helps in opening scores.dat file and add the updated scores to the file .



INSTRUCTIONS

•	Include the open GL libraries .

•	If already included , open Project-N_queen_problem.cpp.

•	Compile and run the file, Follow the instructions given in the game.


