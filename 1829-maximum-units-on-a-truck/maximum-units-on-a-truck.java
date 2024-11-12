class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a,b)-> Integer.compare(b[1],a[1]));
        int n = boxTypes.length;
        int ans = 0;
        int i=0;
        while(truckSize>0 && i<n){
            int boxes = boxTypes[i][0];
            int units = boxTypes[i][1];
            if(boxes<=truckSize){
                ans += boxes * units;
                truckSize -= boxes;
            }
            else {
                ans += truckSize * units;
                truckSize = 0;
            }
            i++;
        }
        return ans;
    }
}