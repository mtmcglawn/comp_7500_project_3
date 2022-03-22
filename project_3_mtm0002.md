# Project 3

Matthew Tyler McGlawn

3/21/2022

## 1. Design

The idea that I had for my design was to separate each function into it's own file and use shared memory to pass data between.
The idea was that this would allow for better scalability in the future as well as less cohesion.
I created 2 structs that allow for the data to be shared with each other.
The first contains data that is shared amongst the threads - I called this ThreadData.
It contains the mutex and the thread locks as well as data that needs to be manipulated by both threads.
The second contains data that is shared amongst the different commands, which I referred to as CommandData.
CommandData contains information such as location in the job queue and data required to be printed when aubatch is "quit".

## 2. Performance metrics

Unfortunately I was unable to complete the project to a point that would allow me to gain any metrics.
I ran into a race condition (or possibly a shared memory issue) and have spent the last 5 days (estimated 30-40 hours) trying to resolve it.

## 3. Difficulties

The main difficulty that I ran into was the race condition that still hinders me.
I'm assuming it stems from the way that I manage my data (shared memory), but I am still unsure.
My goal is to keep working on it for the next few days, or at least until I can no longer receive partial credit.
Another difficulty to me was trying to wrap my head around the project pdf instructions (they seemed somewhat vague and thrown together in my opinion).

## 4. Sample Running

Sample Input
```
$ ./aubatch
```
