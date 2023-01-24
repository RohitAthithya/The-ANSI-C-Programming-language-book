#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
/* count lines, words, and characters in input */
#define CTRL(x) (x & 0x1f)
main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF && c != CTRL('d')) 
    {
        ++nc;//we consider even the blank spaces or the tab space or the new line character to be a character
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else 
            if (state == OUT) 
            {
                state = IN;
                ++nw;
            }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

//check how the program can fail
/*

type the fololowing:
1. single characters => even these are counted a words for no reason lol
2. special characters or tokens => ' , ; , , \ , -  like that
3. Semantic definition of word, some special cases:

4. cat-walk => 1 word or 2?
5. small word: "a b c d" => has 4 words!
6. biiiiiig words: "a fooooooooo<aMILLIONLETTERS>ooooooo a" has 3 words
boundary conditions:
.
10.Texts bigger than 2GB
11.Words which contain a dash but no whitespace.
12. Non-ascii words.
13.Files in some different encoding (if your program supports that)
14.Characters which are surrounded by whitespace but do not contain any word characters (e.g. "hello - world")
15.Texts without any words => \n\b\n\b\n\b\b\b\b^D
16.Texts with all words on a single line =>hello this is uncle da bacha boi
s*/
/* the authors want to convey that there can be deficiencies in any code,
    there may be time when your code satisfies all boundary condtions except a few!

    may be even nobody would have thought about a scenario/situation like that

    once a great person said : "There often exists bogus input" you may some day be expected to somehow deal with it in a 
    in a similar situation
*/
// refer this too: 
// https://stackoverflow.com/questions/5717411/how-to-test-word-count-program-if-there-is-any-uncovered-bugs

