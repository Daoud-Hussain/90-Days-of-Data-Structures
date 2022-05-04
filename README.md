# Data Structures and Algorithms in C++

![Data-Structure-and-Algorithms](https://socialify.git.ci/Daoud-Hussain/Data-Structure-and-Algorithms//image?description=1&font=Raleway&forks=1&issues=1&language=1&name=1&pattern=Floating%20Cogs&pulls=1&stargazers=1&theme=Dark)

## Introduction
C++ is a **cross-platform** language that can be used to create high-performance applications. It was developed by **Bjarne Stroustrup**, as an extension to the **C** language. It gives programmers a high level of control over system resources and memory. It is an **object-oriented** programming language which gives a clear structure to programs and allows code to be reused, lowering development costs.
## Why use C++?
C++ is a **middle-level language** rendering it the advantage of programming low-level (drivers, kernels) and even higher-level applications (games, GUI, desktop apps etc.). The basic syntax and code structure of both **C** and **C++** are the same. 
You should use C++ because it is: 

-  Portable
-  Machine independant
-  User-friendly
-  Faster in Speed
-  Has Rich libraries support

## LinkedList
Like arrays, Linked List is a **linear data structure**. Unlike arrays, linked list elements are not stored at a **contiguous location**; the elements are linked using pointers. 
### Why LinkedList??
    Arrays can be used to store linear data of similar types, but arrays have the following limitations:
     ●  The size of the arrays is fixed.
     ●  Inserting a new element in an array is expensive.

    It provides following advantages over arrays: 
     ●  Dynamic size 
     ●  Ease of insertion/deletion
    
### Types of LinkedList
There are **three** common types of Linked List.

- Singly Linked List
- Doubly Linked List
- Circular Linked List

Before exprssing all the types, let's understand some important terms used in Linkedlists
     
    Node - Each element in a linked list is called a node. A single node contains data and a pointer to the next node which helps in maintaining the structure of the list.
    
    Head - The first node of the linked list is called the head. It represents the starting point of the whole list.
    
    Tail - The last node of the linked list is called the Tail. It is the ending point of the whole list.
    
    Link − Each link of a linked list can store a data called an element.
    
    Next − Each link of a linked list contains a link to the next link called Next.
    
    
### Singly-Linkedlist:

A singly linked list is a type of linked list that is **Unidirectional**, that is, it can be traversed in only one direction from head to the last node (tail).

#### Declaring a Singly Linkedlist
The syntax to declare a singly linkedlist in C++ is given by: 
    
    struct LinkedList{
        int data;
        struct LinkedList *next;
     };
 

 ### Doubly-Linkedlist:

Doubly Linked List is a variation of Linked list in which navigation is possible in **both ways**, either forward and backward easily as compared to Single Linked List.

#### Declaring a Doubly Linkedlist
The syntax to declare a doubly linkedlist in C++ is given by: 
    
    struct DoublyLinkedList{
        int data;
        DoublyLinkedList* next; 
        DoublyLinkedList* prev; 
    };
 
### Circular-Linkedlist:

Circular linked list is a linked list where all nodes are connected to form a **Circle**. There is **no NULL** at the end. A circular linked list can be a singly circular linked list or doubly circular linked list.

#### Declaring a Circular Linkedlist
The syntax to declare a ciruclar linkedlist in C++ is given by: 
    
    struct CircularLinkedList 
    { 
        int data; 
        struct CircularLinkedList *next; 
    };
 
 
## Stack
A stack is a **Linear data structure** that follows the principle of **Last In First Out (LIFO)**. This means the **last** element inserted inside the stack is removed **first**. It is an **Abstract Data Type (ADT)**, commonly used in most programming languages. It is named stack as it behaves like a real-world stack (i.e Allows operations at one end only).

### How stack Works?
Being an abstract data type with a **bounded (predefined) capacity**. It allows adding and removing elements in a particular order. Every time an element is added, it goes on the **top** of the stack and the only element that can be removed is the element that is at the top of the stack.


### Basic Operations on Stack
There are some basic operations that allow us to perform different actions on a stack.

    Push - Add an element to the top of a stack
    Pop - Remove an element from the top of a stack
    IsEmpty - Check if the stack is empty
    IsFull - Check if the stack is full
    Peek - Get the value of the top element without removing it
    
#### Declaring a Stack
The syntax to declare a stack in C++ is given by: 
    
    struct Stack(int s){
        int top = -1;
        int size = s;
        int *arr = new int[size];
     };
  
## Queue
A Queue is a **Linear structure** which follows a particular order in which the operations works on an order called **First In First Out (FIFO)**. A good example of a queue is any queue of consumers for a resource where the consumer that came **first is served first**. The difference between stacks and queues is in removing. In a stack, we remove the item the most **recently added**; in a queue, we remove the item the **least recently added**.

### How Queue Works?
Queue operations work as follows:
In queue, we have two pointers FRONT and REAR. FRONT track the first element of the queue while REAR track the last element of the queue. Initially, set value of FRONT and REAR to -1 and then update accordingly (that is, increment for enqueu and decrement for dequeue).

### Basic Operations on Queue
A queue is an object (an abstract data structure - ADT) that allows the following operations:

    Enqueue - Add an element to the end of the queue
    Dequeue - Remove an element from the front of the queue
    IsEmpty - Check if the queue is empty
    IsFull - Check if the queue is full
    Peek - Get the value of the front of the queue without removing it

#### Declaring a Queue
The syntax to declare a queue in C++ is given by: 
    
    struct Queue(int s){
        int front = -1;
        int rear = -1;
        int size = 10;
        int *arr = new int[size];
     };
     
 
## Trees
A tree is a **Non-linear hierarchical** data structure that consists of nodes connected by edges. It consists of a central node, structural nodes, and sub nodes, which are connected via edges. A tree has the following properties:

- The tree has one node called root. The tree originates from this, and hence it does not have any parent.
- Each node has one parent only but can have multiple children.
- Each node is connected to its children via edge.

### Basic Terminology In Tree Data Structure:

    Parent Node: The node which is a predecessor of a node is called the parent node of that node.
    Child Node: The node which is the immediate successor of a node is called the child node of that node.
    Root Node: The topmost node of a tree or the node which does not have any parent node is called the root node. 
    Degree of a Node: The total count of subtrees attached to that node is called the degree of the node. 
    Leaf Node or External Node: The nodes which do not have any child nodes are called leaf nodes. 
    Ancestor of a Node: Any predecessor nodes on the path of the root to that node are called Ancestors of that node. 
    Descendant: Any successor node on the path from the leaf node to that node. 
    Sibling: Children of the same parent node are called siblings. 
    Height of a node: The number of edges on the longest path from that node to a leaf. 
    Internal node: A node with at least one child is called Internal Node.
    Neighbour of a Node: Parent or child nodes of that node are called neighbors of that node.
    Subtree: Any node of the tree along with its descendant
### Types of Trees
Types of trees depend on the number of children a node has. There are two major tree types:

**i- General Tree:** <br> 
A tree in which there is no restriction on the number of children a node has, is called a General tree. <br> <br>
**ii- Binary Tree:** <br>In a Binary tree, every node can have at most 2 children, left and right. Binary tree is furthur divided into following types: 
- **Full Binary Tree:** <br>  If every node in a tree has either 0 or 2 children, then the tree is called a full tree. The tree in the above diagram is not a full binary tree as node C has only the right child.
- **Perfect Binary tree:** <br>It is a binary tree in which all interior nodes have two children and all leaves have the same depth or same level.
- **Balanced Tree:** <br>If the height of the left and right subtree at any node differs at most by 1, then the tree is called a balanced tree.
- **Binary Search Tree:** <br>It is a binary tree with binary search property. Binary search property states that the value or key of the left node is less than its parent and value or key of right node is greater than its parent. And this is true for all nodes. 

### Declaring a Tree
The code to write a tree node would be similar to what is given below. It has a data part and references to its left and right child nodes.

    struct Tree {
       int data;   
       Tree *leftChild;
       Tree *rightChild;
    };