# garbage, for now

## Aim

For those working in modern "Internet" companies, or "AI" companies if you are reading this several years from now. I aim to:

- **Teach:** Try to develop a fast-learning process to help others grasp programming as quickly as possible. Focuses on speedrun so it does not guarantee insightful knowledge and is by no means comprehensive. However, some interesting stuff would be provided marked optional.
- **Teach Myself:** Should be able to review or preview many important topics in our industry.
- **Improve:** Since we are working in a fast-changing industry, the ability of fast-learning, or revolutionizing ourselves, is the most valuable asset in ourselves. Hopefully, a system of fast-learning could be established within this project.

## Method

Pick any topic you want. But I would recommend (with bias :P):
- For data scientists or anyone who wishes to learn AI (Trending): `Python` -> `Big Data` -> `Machine Learning`
- For those who want to build a website: `LNMP`
- For those who want to have some fun and see immediate feedback: `Frontend`
- For students or those who wish to find jobs: `Java` -> `LeetCode`
- For architects: `PowerPoint`
- For architects who want to write some code besides powerpoints: `C++` -> `Search Engine`/`Distributed Systems`

## Basic

### Java

Grasp Java Programming in a few days with [a simple online tutorial](https://beginnersbook.com/java-tutorial-for-beginners-with-examples/).

-   Installation

    Download JDK (I would recommend Java SE Development Kit 8) from the Oracle website.

-   [Fundamentals](https://beginnersbook.com/2013/05/jvm/)

    Java Development Kit > Java Runtime Environment > Java Virtual Machine

    .java -> `$javac ` -> .class -> `$java `

-   [Data types](https://beginnersbook.com/2017/08/data-types-in-java/)

    -   `byte`, `short`, `int`, `long`: 1, 2, 4, 8 byte(s) length integer
    -   `float` and `double`: 4, 8 byte(s) length decimal(6/7 decimal digits, 15 decimal digits). Always suffix float value with the "f" else compiler will consider it as double
        ```java
        double num1 = 22.4;
        float num2 = 22.4f;
        ```
    -   `char`: 2 bytes length 
    -   `boolean`: `true` and `false` with lowercase initials
    -   Non-primitive: Arrays and Strings

-   "Unique" Grammer

    -   Enhanced for loop:
        ```java
        String arr[]={"hi","hello","bye"};
        for (String str : arr) {
             System.out.println(str);
        }
        ```

    -   do-while loop

-   Object-Oriented Programming
    -   `this.`
    -   Inheritance: With `extends`. **Multiple inheritance is not allowed** in Java.
        ```java
        class A extends B
        {
        }
        ```
    -   Polymorphism: Apart from **method overriding**, Java allowed **method overloading** within a class using different method signature (same method name, different parameters).
        ```java
        class DisplayOverloading
        {
            public void disp(char c)
            {
                 System.out.println(c);
            }
            public void disp(char c, int num)
            {
                 System.out.println(c + " "+num);
            }
        }
        ```

    -   Abstract Method: Method with only signature no body (declared but not defined) or declared using the abstract keyword.
        ```java
        abstract public void playInstrument();
        ```
        - The class that inherits **must provide the implementation of all the abstract methods of parent class else declare the subclass as abstract**.
        - These methods cannot be abstract: Constructors, Static methods, Private methods, Methods that are declared "final".

    -   Abstract Class: An abstract class outlines the methods but not necessarily implements all the methods.
        ```java
        abstract class A{
            abstract void myMethod();
            void anotherMethod(){
                 //Does something
            }
        }
        ```
        - **Cannot be instantiated.**
        - A class derived from the abstract base class must implement those methods that are not implemented(means they are abstract) in the abstract class.

    -   Interface: With `interface`.
        ```java
        Interface Interface1 
        {
            String a;
            void b();
        }
        //...
        class ClassName extends Superclass implements Interface1, Interface2
        ```
        
        - Can contain only constants and abstract methods.
        - Cannot be instantiated.
        - Can only be implemented by classes or extended by other interfaces.
        - Java does not support Multiple Inheritance, however a class can implement more than one interfaces.
        - All methods in an interface are implicitly public and abstract. Using the keyword abstract before each method is optional.
        - An interface may contain final variables.
        - When a class implements an interface it has to give the definition of all the abstract methods of interface, else it can be declared as abstract class.
        - An interface reference can point to objects of its implementing classes.

    -   Access Specifiers: `public`/`private`/`protected`/Default(Package Level scope)
