struct LRUListNode {
	int key;
	int value;
	LRUListNode* next;
	LRUListNode* pre;
	LRUListNode(int k, int v){key = k; value = v; next = nullptr; pre = nullptr;}
};

class LRUCache {
	int c;
	int s;
	unordered_map<int, LRUListNode*> m;
	LRUListNode *lru;
	LRUListNode *fru;
public:
	/*20171108 0451*/
	/*         0523*/
	/*AC       0601 initialize all variables!! */
	LRUCache(int capacity) {
		assert (capacity > 0);
		c = capacity;
		s = 0;
		lru = fru = nullptr;
	}

	int get(int key) {
		if (!m.count(key)) return -1;

		LRUListNode *curr = m[key];
		if (!curr->next) {
			assert(fru == curr);
			return curr->value;
		}

		if (!curr->pre) {
			assert(curr == lru);
			lru = curr->next;
			curr->next->pre = curr->pre;
		} else {
			curr->pre->next = curr->next;
			curr->next->pre = curr->pre;
		}

		curr->next = fru->next;
		fru->next = curr;
		curr->pre = fru;
		fru = curr;

		return curr->value;
	}

	void put(int key, int value) {
		// printf("put %d->%d\n", key, value);
		int v = get(key);
		if (v == value) return;
		if (v != -1) {
			LRUListNode *curr = m[key];
			curr->value = value;
			return;
		}
		LRUListNode *curr = new LRUListNode(key, value);

		if (!lru) {
			lru = fru = curr;
			s++;
			m[key] = curr;
			return;
		}

		fru->next = curr;
		curr->pre = fru;
		fru = curr;
		m[key] = curr;

		// printf("s=%d c=%d\n", s, c);
		if (s < c) {
			s++;
			return;
		}

		// printf("lru->key = %d\n", lru->key);
		m.erase(lru->key);
		LRUListNode *tmp = lru;
		lru = tmp->next;
		lru->pre = nullptr;
		delete tmp;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
