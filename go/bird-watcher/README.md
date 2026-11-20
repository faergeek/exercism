# Bird Watcher

Welcome to Bird Watcher on Exercism's Go Track.
If you need help running the tests or submitting your code, check out `HELP.md`.
If you get stuck on the exercise, check out `HINTS.md`, but try and solve it without using those first :)

## Introduction

## For Loops

A `for` statement repeats a block of code.
Its first line controls how often the block repeats:

```go
for init; condition; post {
    // loop body
}
```

- The **init** statement runs once before the first iteration. It's common to declare and initialize a counter variable used by the loop.
- The **condition** is a Boolean expression evaluated before each iteration. The loop stops when this evaluates to `false`.
- The **post** statement runs after each completed iteration. It can be used to update a counter.

Do not surround `init; condition; post` with parentheses.
However, the braces surrounding the loop body are always required.

This loop starts `i` at `1`, prints the current value of `i`, increases it for the next iteration, and stops when `i` reaches `10`:

```go
for i := 1; i < 10; i++ {
    fmt.Println(i)
}
```

## Instructions

You are an avid bird watcher that keeps track of how many birds have visited your garden.
Usually you use a tally in a notebook to count the birds, but to better work with your data, you've digitalized the bird counts for the past weeks.

## 1. Determine the total number of birds that you counted so far

Let us start analyzing the data by getting a high level view.
Find out how many birds you counted in total since you started your logs.

Implement a function `TotalBirdCount` that accepts a slice of `int`s that contains the bird count per day.
It should return the total number of birds that you counted.

```go
birdsPerDay := []int{2, 5, 0, 7, 4, 1, 3, 0, 2, 5, 0, 1, 3, 1}
TotalBirdCount(birdsPerDay)
// => 34
```

## 2. Calculate the number of visiting birds in a specific week

Now that you got a general feel for your bird count numbers, you want to make a more fine-grained analysis.

Implement a function `BirdsInWeek` that accepts a slice of bird counts per day and a week number.

It returns the total number of birds that you counted in that specific week.
You can assume weeks are always tracked completely.

```go
birdsPerDay := []int{2, 5, 0, 7, 4, 1, 3, 0, 2, 5, 0, 1, 3, 1}
BirdsInWeek(birdsPerDay, 2)
// => 12
```

## 3. Fix a counting mistake

You realized that all the time you were trying to keep track of the birds, there was one bird that was hiding in a far corner of the garden.

You figured out that this bird always spent every second day in your garden.

You do not know exactly where it was in between those days but definitely not in your garden.

Your bird watcher intuition also tells you that the bird was in your garden on the first day that you tracked in your list.

Given this new information, write a function `FixBirdCountLog` that takes a slice of birds counted per day as an argument and returns the slice after correcting the counting mistake.

```go
birdsPerDay := []int{2, 5, 0, 7, 4, 1}
FixBirdCountLog(birdsPerDay)
// => [3 5 1 7 5 1]
```

## Source

### Created by

- @sachinmk27

### Contributed to by

- @andrerfcsantos