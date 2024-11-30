class Solution {
    List<Integer> circuit;
    public int[][] validArrangement(int[][] pairs) {
        Map<Integer,List<Integer>> map = new HashMap<>();
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, Integer> outDegree = new HashMap<>();
        int res[][] = new int[pairs.length][2];

        for (int[] pair : pairs) 
        {
            if (map.containsKey(pair[0])) {
                List<Integer> l = map.get(pair[0]);
                l.add(pair[1]);
            } else {
                map.put(pair[0], new ArrayList<>(Arrays.asList(pair[1])));
            }
        }   

        for (int[] pair : pairs) {
            int u = pair[0];
            int v = pair[1];
            outDegree.put(u, outDegree.getOrDefault(u, 0) + 1);
            inDegree.put(v, inDegree.getOrDefault(v, 0) + 1);
            inDegree.putIfAbsent(u, 0);
            outDegree.putIfAbsent(v, 0);
        }

        int src =  pairs[0][0];
        for(int e:inDegree.keySet())
        {
            if(outDegree.get(e)-inDegree.get(e)==1)
                src = e;
        }

        circuit=new ArrayList();
        dfs(map, src);
        Collections.reverse(circuit);
        for(int i=1;i<circuit.size(); i++){
            res[i-1][0]=circuit.get(i-1);
            res[i-1][1]=circuit.get(i);
        }

        return res;    
    }

    void dfs(Map<Integer, List<Integer>> graph, int u){
        while(graph.containsKey(u) && !graph.get(u).isEmpty()){
            int v=graph.get(u).remove(0);
            dfs(graph, v);
        }
        circuit.add(u);
    }
}