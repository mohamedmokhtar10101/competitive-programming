# codeforces-Burglar-and-Matches
 B. Burglar and Matches solution implemented with c++
 
 
the idea of the solution is about the priority of taking matchesBox , to get the maximum you should take the 

matchesBoxes in any container that have the maximum matches in each matchesBox ,it's straitforward

sort them such that the first one is the matchesBox that has the biggest number of matches


if i can carry all matches box i will take them all if i can carry less than them i will take what i can carry ,else if i can carry more than that i will go to the next matchesbox that has the second biggest number of matches and take what i can carry that's all


example

n	m

7	3

matchesBox	matches

  5		10
  
  2		5
  
  3		6
  
  
sort them in ascening order depending on the matchesBox's capacity(number of matches)
it will be

matchesBox	matches

  5		10	container
  
  3		6	container
  
  2		5	container
  
  my capactiy n=7 iterate through all containers  carried matchesBox sumN=0 
  
  first iteration 
  
  matchesBox	matches
  
  5	10		5 is less than my capacity then take all of them (5 matchesBox ,10 matchesBox in each one)
  
 after 1 iteration 
 
 sumN =5  and  sum = 5*10 =50 (sum of all carried matches)
 
 second iteration
 
 matchesBox	matches
 
  3		6                3 is  more than what i need(i need just 2 i carried 5 and my capacity is 7 then i need to cary  
  
  just   2)
  
                                                                                                                            
                                                                                                                              
 after 2 iterations
 
 sumN =7  and  sum = 50 + 2*6 = 62 (sum of all carried matches)
 
 
Output

62












I hope you got it =D
