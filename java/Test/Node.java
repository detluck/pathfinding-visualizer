import java.util.ArrayList;
import java.util.List;

public class Node implements Comparable<Node> {
    private final String name;
    private int distance = Integer.MAX_VALUE;
    private Node parent;
    private final List<Edge> neighbors = new ArrayList<>();

    public Node(String name){
        this.name = name;
        this.parent = null;
    }

    public String getName() {
        return name;
    }

    public List<Edge> getNeighbors() {
        return neighbors;
    }
    
    public void addNeighbor(Edge edge){
        neighbors.add(edge);
    }

    public Node getParent() {
        return parent;
    }

    public void setParent(Node parent) {
        this.parent = parent;
    }

    public void setDistance(int distance) {
        this.distance = distance;
    }

    public int getDistance() {
        return distance;
    }

    @Override
    public int compareTo(Node o) {
        return this.distance - o.distance;
    }

    @Override
    public String toString() {
        return String.format("->%s, %d", name, distance);
    }
}
