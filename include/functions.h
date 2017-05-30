/*****************************************************************
 * Homework 4 solution checks if symbols are balanced in an
 * expression using a stack then use a stack and queue to check 
 * if a generic vector is a palindrome
 *
 * @author Evan Kiel
 * @version 5/30/2017
 * *****************************************************************/

#ifndef __H_FUNCTIONS_
#define __H_FUNCTIONS_

/** Required includes for vectors strings stacks and queue */
#include <string>
#include <vector>
#include <stack>
#include <queue>


/** function to check if the symbols in an expression are balanced */
bool balanced(std::string expression){
	std::stack<char> balance;
	char trap =(char) L'▰'; //store the symbols being checked
	char tri =(char) L'▲';
	char circle =(char) L'◯';
	for(size_t x = 0; x<expression.length(); x++){
		/** check if one of the symbols is present*/
		if(expression[x]==trap
		   ||expression[x]==tri||expression[x]==circle){
			/** check if the stack is empty*/
			if(!balance.empty()){
				/** check if the symbol doesnt matches the top*/
				if(balance.top() != expression[x])
					balance.push(expression[x]);
				else
					balance.pop();
			}		
			else
				balance.push(expression[x]);
		}
	}
	return(balance.empty());
}

/*********************************************************
 * fucntion to check if a generic vector is a palindrome
 * https://stackoverflow.com/questions/29500782/stack
 * -and-queue-palindrome-program
***********************************************************/
template <typename T>
bool palindrome(std::vector<T> v){
	if ( v.empty() ) return false;

	/** fill stack and queue with data from vector */
        std::stack<T> 
            s( std::stack<T>::container_type( v.begin(), v.end() ) );
        std::queue<T> 
            q( std::queue<T>::container_type( v.begin(), v.end() ) );

	/** if front and back match pop them off until empty 
 	* including the middle which could be the same location*/
        while ( !s.empty() && s.top() == q.front() )
        {
            s.pop();
            q.pop();
        }
	
        return s.empty();
}

#endif
