class Trie:
    def __init__(self):
        self._d = {}
        self._index = 0
    
    def add_word(self, word):
        d = self._d

        for char in word:
            if char not in d:
                d[char] = {}
            d = d[char]

        if '$' in d:
            return d['$']
        result = d['$'] = self._index
        self._index += 1
        return result    

    def find_pair_words(self, word_1, word_2):
        d_1 = self._d
        d_2 = self._d

        length = 0

        for a, b in zip(word_1, word_2):
            if a not in d_1:
                return
            if b not in d_2:
                return
            
            d_1 = d_1[a]
            d_2 = d_2[b]
            length += 1

            if '$' in d_1 and '$' in d_2:
                yield d_1['$'], d_2['$'], length
        

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        trie = Trie()
        
        triplets = defaultdict(list)
        for u, v, w in zip(original, changed, cost):
            length = len(u)
            uu = trie.add_word(reversed(u))
            vv = trie.add_word(reversed(v))
            triplets[length].append((uu, vv, w))

        inf = float('inf')

        def get_dist(triplet):
            dist = {}
            for u, v, w in triplet:
                dist[(u, v)] = min(dist.get((u, v), inf), w)

            unique_original = set(t[0] for t in triplet)
            unique_changed = set(t[1] for t in triplet)
            unique = unique_original & unique_changed

            for c in unique:
                for a in unique_original:
                    for b in unique_changed:
                        if a != b and dist.get((a, b), inf) > dist.get((a, c), inf) + dist.get((c, b), inf):
                            dist[(a, b)] = dist[(a, c)] + dist[(c, b)]
            
            return dist
        
        dist = {}
        for triplet in triplets.values():
            dist.update(get_dist(triplet))

        n = len(source)
        dp = {-1: 0}

        for i in range(n):
            current = dp[i - 1] if source[i] == target[i] else inf
            for uu, vv, length in trie.find_pair_words(
                word_1=(source[j] for j in range(i, -1, -1)),
                word_2=(target[j] for j in range(i, -1, -1)),
            ):
                d = dist.get((uu, vv), inf)
                current = min(current, d + dp[i - length])

            dp[i] = current
        
        result = dp[n - 1]
        if result == inf:
            return -1
        return result