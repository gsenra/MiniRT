# MiniRT
A basic raytracer made as a student project at 42 São Paulo.

# Work History

August 14th 2020 - Started building the basic functions and structures to open a file, parse its content and process the information accordingly.

August 17th 2020 - Cleaned up the Makefile a little bit, so that .o files will go on their own folder and it keeps Libft as it's own submodule so it can be updated/modified easily. Doing some more work on the file parsing structure, and managed to get information from a file and put it on a struct to use later, plus some very basic error returns for invalid file structures.

August 18th 2020 - Integrated file parsing functions with MiniLibX functions to use information contained on a file to set the resolution of an output window.

August 19th 2020 - Restructuring some functions to comply with The Norme. Integrated get_next_line to libft.

August 20th 2020 - Wrote the functions needed to parse ambient lighting parameters from an input file, and right now what they do is set the color of the output window. Having trouble with The Norme because of error messages being too long, and functions having more than 25 lines. We need to figure out a more succint way to write error messages. Also, we need to code our own ASCII-to-Float function, since we are forbidden to use the one from stdlib.h.

September 3rd 2020 - Created a system to handle error messages in a more convenient way, allowing us to store the messages themselves on an external file. Norme is still being troublesome.

September 4th 2020 - Finally fixed the code so it complies with The Norme, though the end result is a bit jumbled. Will add comments later. Wrote an AtoF function to replace the one from stdlib.h that we were forbidden to use. Also added some additional error verification, and we are now starting to write the code to handle the information regarding cameras, lights and polygons.

September 5th 2020 - Developed the functions to handle parameters regarding cameras, and all the error handling related to this task. Starting to work on integrating a camera linked list to our main scene struct. Having some trouble with pointers.

September 6th 2020 - Linked list holding values for cameras works correctly, and we're able to de-allocate it properly after using it. We also corrected all memory leaks up to this point, and made all our relevant code compliant with The Norme. We made a mistake interpreting the subject in regard to the ambient light input parameters, and must correct it in the near future.

September 8th 2020 - Streamlined functions regarding ambient light parsing and wrote functions regarding scene light parsing. Re-structured the library to make it more readable. Integrated our AtoF to libft.

September 10th 2020 - Sphere and plane parsing work, and the functions are already Norme compliant. Fixed some other minor issues with the file parsing structure, now allowing the program to read the file if you skip lines between parameters, which was a requisite in the subject.

September 11th 2020 - File parser is now finished. Tested it for memory leaks and NOrme compliance, and everything seems to be working accordingly. Now we can move to the actual raytracing part.
