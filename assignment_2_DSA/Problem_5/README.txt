=============
OBSERVATIONS:
=============
From the graph we see that the average depth of the Binary Search Tree increases quite steeply when N is in the 
range 0 to about 40 then the slope(in terms of avg depth wrt to N) of the graph reduces a bit when N is in the range of 
41 to about 92 and the slope(in terms of avg depth wrt to N) of the graph further reduces when N is in the range 93 to 1000.

We also notice that the slope(in terms of avg depth wrt to N) of the graph appears to be constant (i.e the slant is uniform) 
in the ranges:
     1) 0 to 40
     2) 41 to 92
     3) 93 to 1000
    
Also the slope(in terms of N wrt m ) of the graph is almost a straight line meaning that the avg depth of a given Tree
with N nodes remains fairly constant with m (number of repitions). This is verified by looking at output.txt:

|==========================================================|
| No.OfNodes|   N = 10     N = 50     N = 100    N = 1000  |                   
|  m = 10   |  4.900000 | 9.700000 | 12.100000 | 20.200001 |
|  m = 50   |  4.860000 | 9.820000 | 12.260000 | 21.320000 |
|  m = 100  |  4.720000 | 9.510000 | 12.480000 | 21.209999 |
|  m = 1000 |  4.615000 | 9.928000 | 12.296000 | 20.943001 |
|==========================================================|

Here we can see that there is a very small variation for avgdepth for a given N with respect to m, and this variation
increases as N increases.

============
EXPLANATION:
============
Thus we can conclude that the average height of the binary trees that we found is consistent with the formula:
avg height of a tree with N nodes = O(3logN) = O(logN)
 
hence avg height of a binary tree with N nodes is O(logN)

Proof:
for N = 10 we get 3logN = 9.96 
for N = 50 we get 3log N = 16.93
for N = 100 we get 3log N = 19.93
for N = 1000 we get 3log N = 29.89

for N = 10 we get log N = 3.321
for N = 50 we get log N = 5.643
for N = 100 we get log N = 6.64
for N = 1000 we get log N = 9.9657

===========
CONCLUSION:
===========
Here we can see that the O(3logN) estimates start to become closer to the observed value of N as N increases, particularly for N = 1000
similarly the O(logN) estimates are closer to the observed values for N = 10 but the gap starts increasing for larger values of N.
The reason for this can be attributed to the fact tha(log(N+1)) - 1 is the calculated minimum height of a BST with N nodes
whereas N-1 is the maximum height of a BST with N nodes. Hence the minimum height estimates are closer to the observed estimates
for smaller values of N. And for larger values of N the observed estimates lie closer to the values calculated by using the constant term 3 in O(3logN).

Hence all in all the avg height of the binary tree lies in the range O(logN) <= avg_height <= O(3logN).
Hence it can be concluded that the avg height of a tree with N nodes is of the form O(logN).
In some cases the avg height for N = 10 has reached values 8 and 9 for m = 100 and m = 1000, however this was pretty rare.

