#include <string.h>
#include <stdio.h>
#include <specstrings.h>


using namespace std;

void main()
{
char text[20], newText[20];
gets(text);
strcpy(newText,text);
for(int i = 0;i < strlen(text); i++)
if(text[i] =='A')
text[i] = text[i]+2;
puts(text);

}