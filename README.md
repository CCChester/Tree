# Tree

For this problem, the classes that make up the program are implemented using the class
keyword. In this problem you will apply the Iterator pattern to create an iterator over binary
search trees. A test harness main.cc is provided. Do not modify this file. When you have
successfully completed this program, the \print" command p will display the contents of the
binary search tree t in sorted order. Note that the provided Tree class stores information
in each node about whether the node is a left child, a right child, or the root. Use this
information to help you navigate the tree. Iteration must run in time O(L(x)) where L(x) is
the length of the shortest path in the tree from x to x's successor node. In particular, you
must perform the minimal amount of traversal in moving from a node to its successor.
You may assume that all input is valid.
