class MinStack {
	/*pushing current min and the value when min changes..*/
	/*AC 20170615 1634 */
public:
	/** initialize your data structure here. */
	stack<int> s;
	long min;

	MinStack() {
		min = INT_MAX;
	}

	void push(int x) {
		if (x <= min) {
			s.push(min);
			min = x;
		}
		s.push(x);
	}

	void pop() {
		if (s.top() == min) {
			s.pop();
			min = s.top();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min;
	}


	/*using one stack here*/
	/*be careful of overflow by the substraction */
	// public:
	//     /** initialize your data structure here. */
	//     stack<long> s;
	//     long min;

	//     MinStack() {
	//         min = INT_MAX;
	//     }

	//     void push(int x) {
	//         s.push((long)x - min);
	//         if (x < min) min = x;
	//     }

	//     void pop() {
	//         if (s.top() < 0) min -= s.top();
	//         s.pop();
	//     }

	//     int top() {
	//         if (s.top() < 0) return min;
	//         return s.top() + min;
	//     }

	//     int getMin() {
	//         return min;
	//     }

	// public:
	//     /** initialize your data structure here. */
	//     stack<int> s;
	//     stack<int> mins;
	//     MinStack() {

	//     }

	//     void push(int x) {
	//         s.push(x);
	//         if
	//             (mins.empty() || mins.top() > x) mins.push(x);
	//         else
	//             mins.push(mins.top());
	//     }

	//     void pop() {
	//         s.pop();
	//         mins.pop();
	//     }

	//     int top() {
	//         return s.top();
	//     }

	//     int getMin() {
	//         return mins.top();
	//     }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
