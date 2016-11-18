========================================================================
    CONSOLE APPLICATION : Lab_2 Project Overview
========================================================================

Jordan Wheeler		444332		Lab 2		j.wheeler@wustl.edu

In this lab, we did encountre a few notable errors outside of general syntax errors.
The first was a runtime failure that had to do with my copy constructor for the 
Hand class attempting to use the size of an empty array as an iterator limit. The second
had to do with the return type of my insert operator from a deck to a hand, which 
I initially couldnt figure it out , but in order to be ablle to "add" multiple things in the 
insertion line, it also has to return a refrence to a hand variable.

The program works in a series of different situations. The program should
be passed a text file and (optionally) a '-shuffle' argument, which will then shuffle 
the deck that it constructs from a valid file. In any of the cases where the arguments 
are passed incorectly, (i.e. no arguments are passsed, too many arguments are passed...)
the program returns a usage message to assist the user in loading the program.

In the case where a valid text file is passed, the file reads in all of the valid
card definition strings to a Deck object, and then shuffles it if the '-shuffle'
argument was detected. If there are enough cards to fill 9 five card hands, then they
are filled from the back of the deck. Otherwise, the user is notified that there are not
enough cards in the deck to continue, and the program terminates. 

From here, we simply print out the 9 hands in order lexically and by rank.



