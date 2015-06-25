
### We redefined natural programming.

## Overview
***
LimeStone-Interpreter is an open-sourced, completely free interpreter for the LimeStone Scripting Language. It provides an interpreting mode that allows you to interpret any code written in the limestone language.  
Limestone is a set of grammar module enables you to code in natural language(see example code at the bottom). We also introduced lazy programming to this language.

## Limestone traits
***
- Easy syntax
- Light interpreter
- Natural Programmings supported
- procedures oriented programming

## Lazy Coding
***
> There are three great virtues of a programmer; Laziness, Impatience and Hubris.   
> Larry Wall. 
we are introducing lazy programming to the Limestone. Following traits are applied in interpreting:  
- Inside-declared variables. This includes if, loop and function code block, programmers can invoke these special variable without declaring them every time.  
- Updatable variable: This declaration will set the variables to updatable, which means they will get updated when involing them in the code. We will use an algorithm to keep this quick.

## Support
***
Any support to Altoria.Pendragon@outlook.com, and you can report bugs just by opening an issue.

## Sample code
***
<code>
# Our reign, of course, was built on sand and stones.

Define a[10010] as struct:
	x, y, power, checked
.

# Firstly we need to get nodes and lines of the graph.
Read n, l;
Print: To describe a graph, enter start, end, power for each line.
Loop from 1 to l:
	Read: a[index]->x, a[index]->y, a[index]->power.
.

Sort: in a, from 1 to l, by a[sort]->power in increase.

# Now, weve got a node list from least to most.
# Its time to get the minimal spanning tree.
Loop from 1 to l:
	P <= get-root in a[index]->x;
	Q <= get-root in a[index]->y;
	If p equal than q: # In the same group, ignoring.
		Print: in $p and $q, attribute $a[index]->power is ignored.
	.
	If p not equal than q: # Add into same group.
		Connect p with q;
	.
.

function connect $a with $b:
	root[get-root in a] <= get-root in b;
.

function get-root in $a:
	Loop while a not equal than root[a]:
		a <= root[a];
	.
	return a;
.
</code>
