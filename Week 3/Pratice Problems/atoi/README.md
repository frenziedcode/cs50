# Recursive atoi

## Learning Goals

Deepen an understanding of strings
Practice creating recursive functions

## Background

Imagine that you travel back in time to the 1970’s, when the C programming language was first created. You are hired as a programmer to come up with a way to convert strings to ints. (You may have used a function just like this in Week 2, called atoi). You want to be thorough in your development process and plan to try several approaches before deciding on the most efficient.

In this problem, you will start with a simple implementation of atoi that handles positive ints using loops. You want to rework this into an implementation that uses recursion. Recusive functions can be memory intensive and are not always the best solution, but there are some problems in which using recursion can provide a simpler and more elegant solution.

## Getting Started

1. Log into `cs50.dev` using your GitHub account.
2. Click inside the terminal window and execute `cd`.
3. Execute wget `https://cdn.cs50.net/2022/fall/labs/3/atoi.zip` followed by Enter in order to download a zip called atoi.zip in your codespace. Take care not to overlook the space between wget and the following URL, or any other character for that matter!
4. Now execute unzip `atoi.zip` to create a folder called `atoi`.
5. You no longer need the ZIP file, so you can execute `rm atoi.zip` and respond with “y” followed by Enter at the prompt.

## Implementation Details

In the recursive version of convert, start with the last char and convert it into an integer value. Then shorten the string, removing the last char, and then recursively call convert using the shortened string as input, where the next char will be processed.

## Thought Question

Why do you need a base case whenever you create a recursive function?

## How to Test Your Code

Your program should behave per the examples below.

`atoi/ $ ./atoi
Enter a positive integer: 3432
3432`

`atoi/ $ ./atoi
Enter a positive integer: 98765
98765`

No `check50` for this one!

To evaluate that the style of your code, type in the following at the `$` prompt.

`style50 atoi.c`

## How to Submit

No need to submit! This is an optional practice problem.
