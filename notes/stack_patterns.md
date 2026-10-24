


# Stack Patterns

## 1. Introduction
A stack follows the LIFO principle: Last In, First Out.

## 2. Common Operations
- push(): Insert an element
- pop(): Remove the top element
- top(): Access the top element
- empty(): Check whether the stack is empty
- size(): Return the number of elements

## 3. C++ Implementation
```cpp
stack<int> st;

st.push(10);
st.push(20);

cout << st.top();

st.pop();
