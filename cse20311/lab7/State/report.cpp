From the user's perspective the user has to input a number from the menu
to choose an option he wants. He can display all states with all their info, display states inaugurated 
in a year, display state with biggest population, display all the information of a state.

From the coder's perspective I created a class with its interface and its implementation with all the 
set functions inside the class  and all the get functions inside the class. In the main function 
I had a while loop for the menu that would only exit if the numeber 5 was input. The program would request
the user to input an option from to 1 to 4 and then do the function. If the function required more information,
like for example the year of the states inaugurated the same year, the program would request the additional 
information with a cin>>. 

I evaluated the program for correct results by trying out different input names. I discovered that I could not 
request the user to input the name of a state name with a space in like "New Jersey" because it did not work.
I changed it to request a state abbreviation.
