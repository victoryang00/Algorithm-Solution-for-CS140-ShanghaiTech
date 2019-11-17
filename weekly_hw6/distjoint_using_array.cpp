class DisjointSet {  
    int[] parents;

    public DisjointSet(final int  N) {
        this.parents = new int[N];
        for(int i = 0;i<N;i++){
            parents[i] = i;
        }
    }

    int find(int i){
        if(parents[i]==i){
            return i;
        }else{
            return find(parents[i]);
        }
    }

    void union(int x,int y){
        int rootx = find(x);
        int rooty = find(y);
        if(rootx!=rooty){
            parents[rootx]=rooty;
        }
    }

    @Override
    public String toString() {
        StringBuffer buffer = new StringBuffer();
        for(int i = 0;i<parents.length;i++){
            if(i!=parents[i]){
                buffer.append(String.format("[%s->%s]",i,parents[i]));
            }else{
                buffer.append(String.format("[%s-> ]",i));
            }
        }
        return buffer.toString();
    }
}