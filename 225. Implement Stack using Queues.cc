class Stack {
private:
    queue<int>q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q.empty())return;
        int n = q.size();
        for(int i=0;i<n;i++){
            int x = q.front();q.pop();
            if(i<n-1)q.push(x);
        }
        
    }

    // Get the top element.
    int top() {
       if(q.empty())return -1;
       int n = q.size();
       int x = -1;
       for(int i=0;i<n;i++){
           x = q.front();
           q.pop();
           q.push(x);
       }
       return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};