# Ft_Printf:
In this project , I m trying to mimic the behaviors of the famous C function which is Printf.

I used for the power of variadic function that let enter a variable of argument into a function call

### used functions:

write, va_start, va_arg, va_copy and va_end

### implemented conversions:

• %c Prints a single character.

• %s Prints a string (as defined by the common C convention).

• %p The void * pointer argument has to be printed in hexadecimal format.

• %d Prints a decimal (base 10) number.

• %i Prints an integer in base 10.

• %u Prints an unsigned decimal (base 10) number.

• %x Prints a number in hexadecimal (base 16) lowercase format.

• %X Prints a number in hexadecimal (base 16) uppercase format.

• %% Prints a percent sign.

### bonus part

here I tried to Manage the following flags: ’# +’ (Yes, one of them is a space)

## using makefile:
to compile all the medatory functions into object files then archive them to a libftprintf.a static library use the command:
> make

or you can use:
> make all

for the bonus part use:
> make bonus

to delete the object files you can use:
>make clean

and to the delete the object files and the library you can use:
> make fclean 

rebuilding the library will be done if you use:
> make re
