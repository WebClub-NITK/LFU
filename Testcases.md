# Hello!

* Following are the few test cases which you should use to test your code. Feel free to add other corner cases if not
already covered.

* Please use the following test cases to test your code using Testing Frameworks/Testing Tools like CPPUNIT for C++ or JUnit for Java, please use appropriate tool for your programming language.


### Naming
* AddValue (Value) : Insert Value into the Cache.
* LookUpValue (Value) : Check if Value is there and increment Frequency.
* EvictFromCache () : Remove least Frequent Element.
* PrintLFU () : Print the Elements in LFU. Format = Frequency: List of Elements.




Test Case 1
-----------------------------
1) AddValue (5)
2) AddValue (4)
3) AddValue (3)
4) AddValue (4)
5) LookUpValue (5)
6) PrintLFU ()

> Count 1: 3

> Count 2: 4,5

7) EvictFromCache ()
8) PrintLFU ()

> Count 2: 4, 5


9) EvictFromCache ()
10) PrintLFU ()

>	'Nothing or simply Return'





Test Case 2
-----------------------------
1) EvictFromCache ()
2) LookUpValue (1)
3) AddValue (1)
4) PrintLFU ()

>	Count 2: 1


5) AddValue (2)
6) PrintLFU ()

>	Count 1: 2

> Count 2: 1






Test Case 3
-----------------------------
1) AddValue (1)
2) AddValue (1)
3) AddValue (1)
4) AddValue (2)
5) AddValue (2)
6) AddValue (3)
7) PrintLFU ()

>	Count 1: 3

>	Count 2: 2

>	Count 3: 1

8) EvictFromCache ()
9) PrintLFU ()

>	Count 2: 2

> Count 3: 1


10) AddValue (2)
11) PrintLFU ()
 
>	Count 3: 1, 2

12) EvictFromCache()
13) PrintLFU ()

>	Count 3: 1

>   OR

>	Count 3: 2
>(Depends on Implementation.)

