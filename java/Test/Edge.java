public class Edge {
    private final Node neighbor;
    private final int weight;

    public Edge(Node target, int weight) {
        this.neighbor = target;
        this.weight = weight;

    }

    public int getWeight() {
        return weight;
    }

    public Node getNeighbor() {
        return neighbor;
    }
}
