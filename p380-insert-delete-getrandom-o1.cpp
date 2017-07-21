class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (d.count(val)) return false;
		d[val] = v.size();
		v.push_back(val);
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (!d.count(val)) return false;
		int idx = d[val], victim = v.back();
		swap(v[idx], v.back());
		v.pop_back();
		d[victim] = idx;
		d.erase(val); // ?
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int randidx = rand() % v.size();
		printf("%d %lu\n", randidx, time(NULL));
		return v[randidx];
	}

private:
	vector<int> v;
	unordered_map<int, int> d;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
