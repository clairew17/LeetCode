// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<int>left;
    int read(char *buf, int n) {
        int len = 0;
        
        //read remaining data from last time call
        while(left.size()>0)
        {
            buf[len++]=left.front();left.pop();
            if(len==n)return len;
        }
        int c;
        //read from file 
        while(len<n)
        {
            c = read4(buf+len);
            len += c;
            if(c<4)break;
        }
        
        //buffer data exceeding n in to queue
        for(int i=n;i<len;i++)
        {
            left.push(buf[i]);
        }
        
        
        //add delimiter
        int e = min(len, n);
        buf[e] = '\0';
        return e;
    }
};