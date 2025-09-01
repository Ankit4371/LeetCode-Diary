
// Choose the class where adding student will result in max gain
// Max Heap by gain
// T.C. O(N + SlogK)



class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            double gainA = (double)(a[0] + 1) / (a[1] + 1) - (double)a[0] / a[1];
            double gainB = (double)(b[0] + 1) / (b[1] + 1) - (double)b[0] / b[1];
            return Double.compare(gainB, gainA); // Max-heap by gain
        });
        // O(N + SlogN)
        for(int i = 0 ; i < classes.length; i++){
            pq.add(new int[]{classes[i][0], classes[i][1]});
        }
        // SlogN
        while(extraStudents > 0){
            int[] top = pq.poll();
            pq.add(new int[] {top[0]+1, top[1]+1});
            extraStudents--;
        }
        double ans = 0.0;
        while(!pq.isEmpty()){
            int[] top = pq.poll();
            double passRatio = (double)top[0]/top[1];
            System.out.println(passRatio);
            ans += passRatio;
        }
        return ans/classes.length;
    }
}
