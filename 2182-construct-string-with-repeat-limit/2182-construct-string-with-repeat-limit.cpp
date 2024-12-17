class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
	unordered_map<char, int> freq;
	for (const char& c : s)
		freq[c]++;
	priority_queue<pair<char, int>> pq;
	for (const auto& it : freq)
		pq.push( { it.first, it.second } );
	string res;
	while (pq.size() >= 2) {
		auto [firstCh, firstFreq] = pq.top();
		pq.pop();
		auto [secondCh, secondFreq] = pq.top();
		pq.pop();

		if (res.size() > 0 && res.back() == firstCh) {
			int toAppend = min(repeatLimit - 1, firstFreq);
			res.append(toAppend, firstCh);
			firstFreq -= toAppend;
		} else {
			res.append(min(repeatLimit, firstFreq), firstCh);
			firstFreq -= repeatLimit;
		}
		if (firstFreq > 0)
			pq.push( { firstCh, firstFreq } );

		res.append(1, secondCh);
		secondFreq--;
		if (secondFreq > 0)
			pq.push( { secondCh, secondFreq } );
	}
	if (pq.size() > 0) {
		auto [ch, cnt] = pq.top();
		if (res.empty() || res.back() != ch)
			res.append(min(repeatLimit, cnt), ch);
		else
			res.append(min(repeatLimit - 1, cnt), ch);
	}
	return res;
}
};