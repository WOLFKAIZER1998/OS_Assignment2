# OS_Assignment2

This program simulates a lottery scheduler for processes in an operating system. Each process is assigned a certain number of tickets, and the scheduler selects the next process to run based on a lottery system. The more tickets a process has, the higher its chances of being selected to run next.The lottery scheduling algorithm works by generating a random "winning" ticket. It then iterates over the processes, adding up their tickets until it reaches or surpasses the winning ticket number. The process whose tickets pushed the total to or beyond the winning number is selected to run next.

In the program, the random number generator used is the rand() function from the C++ standard library. This is then seeded with the current time to make sure that there are different sequences of random numbers each time the program runs.

