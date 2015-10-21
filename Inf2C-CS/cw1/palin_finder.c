// ==========================================================================
// Palindrome Finder
// ==========================================================================
// Prints the palindromes in an input sentence.
//
// Inf2C-CS Coursework 1. Task B 
// OUTLINE code, to be completed as part of coursework.

// Boris Grot, Rakesh Kumar
//  12 Oct 2015

//---------------------------------------------------------------------------
// C definitions for SPIM system calls
//---------------------------------------------------------------------------
#include <stdio.h>

int read_char() { return getchar(); }
void read_string(char* s, int size) { fgets(s, size, stdin); }

void print_char(int c)     { putchar(c); }   
void print_string(char* s) { printf("%s", s); }


int isPalin(char word[],int nr)
{
    int i=0,j=nr-2;
    if(j==0) return 0;
    while(i<=j)
    {
        if(word[i]!=word[j]&&(word[i]-32!=word[j])&&(word[i]!=word[j]-32)) return 0;
        i++;
        j--;

    }
    return 1;

}

int is_delimiting_char(char ch)
{
  if(ch == ' ')			//White space
    return 1;
  else if(ch == ',')		//Comma
    return 1;
  else if(ch == '.')		//Period
    return 1;
  else if(ch == '!')		//Exclamation
    return 1;
  else if(ch == '?')		//Question mark
    return 1;
  else if(ch == '_')		//Underscore
    return 1;
  else if(ch == '-')		//Hyphen
    return 1;
  else if(ch == '(')		//Opening parentheses
    return 1;
  else if(ch == ')')		//Closing parentheses
    return 1;
  else if(ch == '\n')		//Newline (the input ends with it)
    return 1;
  else
    return 0;
}

//---------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------

// TO BE COMPLETED

//---------------------------------------------------------------------------
// MAIN function
//---------------------------------------------------------------------------


int main (int argc, char** argv) {
  
  char input_sentence[100];
  int i=0,j,k;
  char current_char;
    
  char word[20];
  int char_index, delimiting_char;
  
  /////////////////////////////////////////////    
        

  
  /////////////////////////////////////////////
  
  /* Infinite loop 
   * Asks for input sentence and prints the palindromes in it
   * Terminated by user (e.g. CTRL+C)
   */
  int found=0;
  while(1) {
    
    i=0;       
        
    print_char('\n'); 
    
    print_string("input: ");

    /* Read the input sentence. 
     * It is just a sequence of character terminated by a new line (\n) character.
     */
  
    do {           
      current_char=read_char();
      input_sentence[i]=current_char;
      i++;
    } while (current_char != '\n');
          
    /////////////////////////////////////////////     
    
       
    print_string("output:\n");          
    char_index=0;
    // TO BE COMPLETED 
    
    /////////////////////////////////////////////
    found =0;

    for(k=0; k<i; k++)  {		
    current_char = input_sentence[k];
    delimiting_char = is_delimiting_char(current_char);

    if(delimiting_char) {
      if (char_index > 0) {			//Avoids printing a blank line in case of consecutive delimiting characters.
        word[char_index++] = '\n';
 		                               //Puts an newline character so the next word in printed in a new line.
        if(isPalin(word,char_index)){
        found=1;
        for(j=0; j<char_index; j++)  {    
          print_char(word[j]);  
        }
        }
        char_index = 0;
      }
    }
    else {
      word[char_index++] = current_char;
    }
  }

   if(found==0) print_string("No palindrome found.\n");
  }

  return 0;
}


//---------------------------------------------------------------------------
// End of file
//---------------------------------------------------------------------------
