# FoodPanda Management System
![foodpanda](https://user-images.githubusercontent.com/87219816/178435552-6b655490-57cc-409f-9a9d-67eab3f911ae.jpg)

## Description
The proposed project is about the **CRUD (Create, Read, Update, delete)** based Food-Panda Management system in which customers can get orders from the nearby Food-Panda store. The store has a main-branch in **F7** and sub-branches in different sectors. The customers can buy products from the store by first selecting the product category. The available product categories in the stores include **Chicken-Burger** (Rs. 200), **Andy-wala Burger** (Rs.150), **Small-Sized-Pizza** (Rs. 400), **Large-Sized-Pizza** (Rs.750), **Fries** (Rs. 100), **One-Liter-Coke** (Rs. 120) and **Shuwarma** (Rs.150).

Once the user selects the required product category, the system will check that whether the selected product category stock is available at the shop. If the stock for the selected category is available, the user will be directed to products screen. In case the stock is unavailable for that category, user will be referred to the nearest store where the selected product category is available. 

The available products are shown to user to buy the desired product. The details of the product
include **Order Id**, **Order name**, **Order price**, **Customer name**, **Customer Mobile number**.

## List of Data Structures Used:
Four major data structures is used in the project to implement:
- 1. Linkedlist
- 2. AVL Trees
- 3. Stack
- 4. Graphs
- 5. Arrays

### 1. Linkedlist
Linkedlist is used for the storage of orders. Orders are purchased, checked, updated, cancelled and delivered using linkedlist.  

### 2. AVL Trees
AVL Trees are used as a storage of delivered orders. It is used to store the history of all the orders that have been delivered. It helps in checking how much sale is done for a day.

### 3. Stack
Stack is used to store the feedbacks of the customers. Program takes the feedback from the customer (when his orders are delivered) and store it in the stack. When the user checks the feedback, it displays orders from the stack on the basic of **LIFO (Last-In-First-Out)**.

### 4. Graphs
Graphs are used to store the information of customers destinations that are chosen from different sectors. The main shop (source) of the graph is **F7** and user can get his order in **I9**, **I8**, **H8**, **H6**, **I10**, and **F8**. Dijistra's algorithm is used to calculate the **shortest path** between the source and the destination.

### 5. Arrays
Different arrays of different data types are used in the program. For example, an array of type string is used to store all the **sectors**, an **2D array** of type int is used to **implement graph** and an array of string type is used to store **feedbacks** in the stack.  

## Screenshots
![Capture](https://user-images.githubusercontent.com/87219816/178435646-fef89f49-0de0-468e-9ade-305674778fff.PNG)
![Capture1](https://user-images.githubusercontent.com/87219816/178435673-34f4cf7f-0e98-40bc-958b-b7dc4852fad4.PNG)
![Capture2](https://user-images.githubusercontent.com/87219816/178435712-49b38a55-958a-4c28-b0da-7a8cd311c543.PNG)
![Capture3](https://user-images.githubusercontent.com/87219816/178435723-56f15288-0ba6-445f-a341-aa9757e3074b.PNG)
![Capture4](https://user-images.githubusercontent.com/87219816/178435989-c2d8deb9-bf4f-4636-b679-5b64761d7c1b.PNG)

