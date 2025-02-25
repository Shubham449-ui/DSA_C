class Solution {
    // Function to return the minimum cost of connecting the ropes.
    public int minCost(int[] arr) {
        PriorityQueue<Integer>pq = new PriorityQueue<>();
        for(int i = 0;i<arr.length;i++)
        {
            pq.add(arr[i]);
        }
        int cost = 0;
        while(pq.size()>1)
        {
            int min = pq.remove();
            int min2 = pq.remove();
            cost = cost + min + min2;
            pq.add(min + min2);
        }
        return cost;
    }
}
