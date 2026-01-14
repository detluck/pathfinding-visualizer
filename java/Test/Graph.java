import java.util.*;

public class Graph {
    private final Map<String, Node> nodes = new HashMap<>();

    public Graph(){}

    public void addEdge(String node1Name, String node2Name, int weight){
        Node node1 = nodes.computeIfAbsent(node1Name, Node::new);
        Node node2 = nodes.computeIfAbsent(node2Name, Node::new);

        node1.addNeighbor(new Edge(node2, weight));

        node2.addNeighbor(new Edge(node1, weight));
    }

    public List<Node> getShortestPath(String startNodeName, String endNodeName){
        Node startNode = nodes.get(startNodeName);
        Node endNode = nodes.get(endNodeName);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        Set<Node> visited = new HashSet<>();
        startNode.setDistance(0);
        pq.add(startNode);

        while(!pq.isEmpty()){
            Node currentNode = pq.poll();
            if(visited.contains(currentNode)){
                continue;
            }
            if(currentNode.getName().equals(endNode.getName())){
                return getPath(endNode);
            }

            List<Edge> neighbors = currentNode.getNeighbors();
            for (Edge edge : neighbors) {
                Node neighbor = edge.getNeighbor();
                int newDistance = edge.getWeight() + currentNode.getDistance();
                if(newDistance < neighbor.getDistance()) {
                    neighbor.setParent(currentNode);
                    neighbor.setDistance(newDistance);
                    pq.add(neighbor);
                }
            }
            visited.add(currentNode);
        }
        return null;
    }

    public List<Node> getPath(Node endNodde){
        List<Node> result = new ArrayList<>();
        for(Node node = endNodde ; node != null; node = node.getParent()){
            result.add(node);
        }
        Collections.reverse(result);
        return result;
    }


    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.addEdge("A", "B",5);
        graph.addEdge("A", "C", 10);
        graph.addEdge("B", "D", 2);
        graph.addEdge("C", "D", 5);
        List<Node> result = graph.getShortestPath("A", "D");
        System.out.println(result);
    }
}
