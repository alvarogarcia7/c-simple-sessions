# Pending exercises

## [max_serial] Find the maximum element

Difficulty: 1 out of 5

Given an array of elements, find the maximum element in there.

## [ubst] Unbalanced Binary Search Tree

Difficulty: 2 out of 5

Create a data structure to hold an unbalanced binary search tree (UBST). Simplification: only make the data structure hold `int`s

More information: 

  * [unbalanced binary search tree](https://www.quora.com/What-is-an-unbalanced-binary-tree-and-what-are-its-uses)
  * [binary tree at wikipedia](https://en.wikipedia.org/wiki/Binary_tree)

### Extra 1: Hold any type

Difficulty: 3 out of 5

Expand the session to hold any data type, so the UBST can hold any type inside (e.g., long, bool, struct).

### Extra 2: Information about levels up and down

Difficulty: 2 out of 5

Expand the session so I can check how many levels up or down are available, from a node.

Example: In tree 1 -> 2, after finding node 2:

  * Levels above: 1
  * Levels below: 0

This operation should have cost `O(1)`

### Extra 3: Allow repeated elements

Difficulty: 2 out of 5

The `add` function will also be used to add another copy of the same element.

The `remove` function will be used to remove elements.

When `find`, also return the number of copies that are available in the tree.

## [ubst_search] Searching in an Unbalanced Binary Search Tree

Prerequisites: ubst

Difficulty: 2 out of 5

Given an UBST, find whether the element given is in the tree. This should be done in an efficient way (cost: `O(log n)`)

Signature: `bool bst_contains(ubst* ubst, int needle);`

## [quicksort] Quicksort Algorithm

Difficulty: 3 out of 5

Implement the [Quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm, for integers.

Calculate the best-case, worst-case performance, both in time complexity and in space complexity

### Extra 1: Hold any type

Difficulty: 3 out of 5

Expand the session, making the algorithm able to sort any data type.

## [wardrobe] Wardrobe combinations

Difficulty: 2 out of 5

Imagine you have just moved into your new apartment, and then you notice that you still need a new wardrobe for your dressing room. Regrettably, you won’t find a wardrobe that fits exactly to the size of your wall. But fortunately, the Swedish furniture dealer of your choice offers you the opportunity to build your own, customized wardrobe by combining individual wardrobe elements.

The wardrobe elements are available in the following sizes: 50cm, 75cm, 100cm, and 120cm. The wall on which the wardrobe elements are placed has a total length of 250cm. With which combinations of wardrobe elements can you make the most of the space?

Write a function that returns all combinations of wardrobe elements that exactly fill the wall.

([Source](https://kata-log.rocks/configure-wardrobe-kata))

### Extra 1: Cheapest combination

Here is the price list for the available wardrobe elements:

  * 50cm => 59 USD
  * 75cm => 62 USD
  * 100cm => 90 USD
  * 120cm => 111 USD

Write a second function that checks which of the resulting combinations is the cheapest one.

# Legend used

Naming of the session

  * Sessions follow this naming: `[session_key] Session title`
  * session_key is unique in this document
  * Session title is a small description

Difficulty: 1 being easier than 5. Problems graded 5 or "*" require extra preparation

