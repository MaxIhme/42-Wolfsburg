# 42 Wolfsburg Software Engineering School
### https://42wolfsburg.de/
### A Repo with all the 42 Projects I already did 

## Libft
Reprogramming some basic C functions like atoi, memcpy, strchr and many more.

## get next line

Gets a file descriptor (for example to a textfile) and returns a pointer to allocated memory with a whole line in it. Everytime the function get's called it returns the next line until the file ends.

## ft_printf
Reprogramming the function printf with the conversions %c (char), %s (string), %p (pointer), %d (decimal), %i (integer), %u (unsigned), %x (hexadecimal lowercase), %X (hexadecimal uppercase) and %% (%)

## Born2beroot
Installing a debian system in VirtualBox, configuration of a firewall, administration of users and groups, changing password policy, configuring sudo, writing a monitoring bash script -> see dir Born2beroot 

## push_swap
Implementing sorting algorythms. We were allowed to use 2 imaginary stacks. The comands we were alloed to use to sort the numbers were: sa, sb-> swap the first two numbers of stack a/b; ss -> sa and sb in one; pa, pb -> push the first number in b to a/ in a to b; ra, rb -> rotate a: shift up all elements of a, the first one becomes the last one. similar with rb; rr -> ra and rb at the same time; rra,rrb -> reverse rotate a: shift down all elements of a. The last element becomes the first one. Similar with rb; rrr -> rra and rrb at the same time. We had to sort the numbers in a restricted number of commands that I wrote above.

## so_long
Implementing a little 2D game with Tiles, Collectibles and an Exit. It reads a textfile as a map and chechs it if it's valid, then starts the game.

## minitalk
Write two programs that communicate with signals SIGUSR1 and SIGUSR2. It was implemented via bit transmittion with these two Signals. 

## Memory leaks

We fail if we have any memory leaks, segfaults or compilation errors.

## Norm

All code has to fit the 42 Norm wich mainly says how to write clean, simple and understandable code, i.e. only 5 functions per File, with each 25 Lines per function. No "for", "do...while", "switch", "case" or "goto". Only 4 parameters hand over to a function, max. 5 Variables per function and many more rules does the norm include.
