# CS50-pset4-Filter

My immplentation of image filters can be found in helpers.c file. They include:
- grayscale FLAG -g 
- sepia FLAG -s
- reflect (horizontal mirror) FLAG -r
- blur (box blur) FLAG -b

To run the program, first compile it:

$ make filter

Then input input and output image files, with one of the 4 filters e.g.:

$ ./filter -g images/yard.bmp out.bmp

$ ./filter -s images/yard.bmp out.bmp

$ ./filter -r images/yard.bmp out.bmp

$ ./filter -b images/yard.bmp out.bmp


