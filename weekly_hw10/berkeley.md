# Question5 Merged Median

#

When combining multiple lists into an output, the `merge` step of merge sort comes to mind immediately — take items off the top of $k$ sorted sublists and combine them into a single output. This requires $k$ comparisons for each item in $n$, so  overall we require $O(k \cdot n)$ operations. If $k$ is small, this is essentially linear in $ N$. 

Code for that process in Python:

```python
def TryMerge(k, n, a, b):
 
    # construct a list of k arrays of n random elements 
    # in the range of a to b
    lists = GetListOfSortedArrays(k, n, a, b)
 
    # pass them in to Merge and report the output
    return Merge(lists)
 
def GetListOfSortedArrays(k, n, a, b):
    lists = list()
    for i in range(k):
        l = []
        for j in range(n):
            l.append(random.randint(a, b))
        l.sort()
        lists.append(l)
    return lists
 
def Merge(lists):
 
    # maintain dictionary of k pointers to the next item in each array
    pointers = {}
    for k in range (len(lists)):
        pointers[k] = 0 # init all pointers to the start of their list
 
    output = []
    while len(pointers) > 0:
        # look at the top item in each list
        min = None
        p = None
        for k in pointers.keys():
            val = lists[k][pointers[k]]
            if min == None or val < min:
                min = val
                p = k
 
        # add the item to the output and increment the pointer
        output.append(min)
        pointers[p] = pointers[p] + 1
 
        # if the pointer is past the last item the list, remove 
	# the pointer
        if pointers[p] >= len(lists[p]):
            del(pointers[p])
 
    return output
```


And some output:

```bash
TryMerge( 5, 5, 1, 100)

Original: [[ 13, 63, 69, 72, 96], [ 2, 5, 7, 51, 92], [ 1, 12, 12, 33, 69], 
	   [ 10, 12, 29, 44, 99], [ 8, 19, 19, 25, 80]]

Result:   [ 1, 2, 5, 7, 8, 10, 12, 12, 12, 13, 19, 19, 25, 29, 33, 44, 51, 
		63, 69, 69, 72, 80, 92, 96, 99]
```

If, on the other hand, $k$ is large (for example, approaching the size of $n$) then the operation 
tends to $O(n^2)$ or greater, which is bad.

Instead, assuming there is enough space to store an additional copy of each element, it is 
possible that inserting all the items into a heap and then pulling them off one at a time 
could be quicker. Each heap insert requires $O(\log n)$ time, so building the entire heap 
should require $O(n lg n)$ time. However there is a method called ``bubble down'' that will 
actually create a heap from an array in roughly linear-time. Doing that would then allow 
us to get the list in $O(n)$ time even for large $k$. 

Here is the Python code approximating that solution:

```python
def TryHeap(k, n, a, b):

    # construct a list of k arrays of n random elements 
    # in the range of a to b
    lists = GetListOfSortedArrays(k, n, a, b)
     
    # return sorted version using a heap
    return HeapSort(lists)

def HeapSort(lists):

    # put the items into contiguous storage
    input = []
    for l in lists:
        input.extend(l)
    count = len(input)
     
    # heapify (using python's built in library, which does bubble down 
    # heapification in near linear-time)
    heapq.heapify(input)
     
    # pull min value into output until heap is empty
    output = []
    for i in range(count):
        output.append(heapq.heappop(input))
    return output
```

This also correctly sorts the input lists.

Of these two approaches, which one performs better on the same input? 
We can add timing decorators to the function like so:

```python
import time
def print_timing(func):
    def wrapper(*arg):
        t1 = time.time()
        res = func(*arg)
        t2 = time.time()
        editor.AddText("\n" + func.func_name 
		+ " took " + str((t2-t1)*1000.0) + " ms\n")
        return res
    return wrapper
```

We then add a decorator to each function:

```python
@print_timing
def TryHeap(k, n, a, b):
    ...
```

The timings thus obtained tell us about the function's performance in 
different situations. As we might expect, with a small $k$, 
the merge version beats the heap version: 

```bash
>> TryMerge( 2, 1000000, 1, 10000)
TryMerge took 12014.9998665 ms

>> TryHeap( 2, 1000000, 1, 10000)
TryHeap took 13969.0001011 ms
However, with a larger k, the heap version is faster (about five times as fast in one implementation):

>> TryMerge( 100, 3000, 1, 10000)
TryMerge took 10780.9998989 ms

>> TryHeap( 100, 3000, 1, 10000)
TryHeap took 2062.99996376 ms
```

Doubling $k$ roughly quadruples the time (which is consistent with 
the assertion that the performance is $O(n^2)$ as $k$ approaches $n$). By 
comparison, doubling $k$ in the heap version is (expectedly) a linear doubling:

```bash
>> TryMerge( 200, 3000, 1, 10000)
TryMerge took 38062. 0000362 ms

>> TryHeap( 200, 3000, 1, 10000)
TryHeap took 4266. 00003242 ms
```