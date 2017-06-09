class MyQueue {
public:
	/*amotized O(1) solution */
	stack<int> input, output;
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int rv = peek();
		output.pop();
		return rv;
	}

	/** Get the front element. */
	int peek() {
		if (output.empty())
			for (; !input.empty(); input.pop()) output.push(input.top());
		return output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return input.empty() && output.empty();
	}

	// /*AC 20170607 1248*/
	//     stack<int> s;
	//     /** Initialize your data structure here. */
	//     MyQueue() {

	//     }

	//     /** Push element x to the back of queue. */
	//     void push(int x) {
	//         s.push(x);
	//     }

	//     /** Removes the element from in front of queue and returns that element. */
	//     int pop() {
	//         stack<int> tmp;
	//         for (; !s.empty(); s.pop()) tmp.push(s.top());
	//         int rv = tmp.top();
	//         for(tmp.pop(); !tmp.empty(); tmp.pop()) s.push(tmp.top());
	//         return rv;
	//     }

	//     /** Get the front element. */
	//     int peek() {
	//         stack<int> tmp;
	//         for (; !s.empty(); s.pop()) tmp.push(s.top());
	//         int rv = tmp.top();
	//         for(; !tmp.empty(); tmp.pop()) s.push(tmp.top());
	//         return rv;
	//     }

	//     /** Returns whether the queue is empty. */
	//     bool empty() {
	//         return s.empty();
	//     }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
