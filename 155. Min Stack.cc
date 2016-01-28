class MinStack {
private:
stack<int>minStack;
stack<int>myStack;
public:
    void push(int x) {
        myStack.push(x);
        if(minStack.empty() || getMin()>=x)//node store all value <= current min
            minStack.push(x);
    }

    void pop() {
        if(myStack.top()==minStack.top())//popped value is also min
            minStack.pop();
        myStack.pop();
    }

    int top() {
        if(myStack.empty())return -1;
        return myStack.top();
    }

    int getMin() {
        if(minStack.empty())return -1;
        return minStack.top();
    }
};