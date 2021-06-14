# CS50-pset4-Filter

## My immplentation of image filters can be found in helpers.c file. They include:
- grayscale FLAG -g 
- sepia FLAG -s
- reflect (horizontal mirror) FLAG -r
- blur (box blur) FLAG -b

#### To run the program, first compile it:

$ make filter

#### Then input input and output image files, with one of the 4 filters e.g.:

$ ./filter -g images/yard.bmp out.bmp

$ ./filter -s images/yard.bmp out.bmp

$ ./filter -r images/yard.bmp out.bmp

$ ./filter -b images/yard.bmp out.bmp


### Some of my own notes, while watching Week4 lecture [video](https://cs50.harvard.edu/x/2021/weeks/4/)

In C: A string has same address as address of its first char (since we already know its ending @ \0 or bx0000-0000 or 0x00 or null)![image](https://user-images.githubusercontent.com/58123635/121841558-90295080-ccac-11eb-8afa-0a32dc4e310e.png)

NOTE: string comparison: s1 == s2 (actually comparing address pointer. This is the same as &s1 == &s2)![image](https://user-images.githubusercontent.com/58123635/121841667-c8309380-ccac-11eb-8742-e6b911dc48eb.png)

In C, we can allocate memory, with malloc (from <stdlib.h>).
Dont forget: NULL checking, and free (return memory space) after use.![image](https://user-images.githubusercontent.com/58123635/121841700-e1394480-ccac-11eb-85ab-83665d7e8697.png)

MEMORY SPACE:
	• malloc: allocate space in heap
functions: work with space in stack![image](https://user-images.githubusercontent.com/58123635/121841736-f3b37e00-ccac-11eb-9b06-75b1c69b5db0.png)

- Origin of "StackOverflow": we attempt calling functions so many time (in recursion), that it overflows into the heap.
Buffer overflow: overflow allocated array, or allocated memory (from using malloc) e.g. buffer in Netflix/Zoom/Youtube (videos)![image](https://user-images.githubusercontent.com/58123635/121841821-1e053b80-ccad-11eb-8022-bd7af460790e.png)
