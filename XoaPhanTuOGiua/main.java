public class main{
    public static class Node{
        Node next;
        int value;
        public Node(int value) {
            this.value = value;
        }
    }
    public static void PrintNode(Node nodeHead){
        if(nodeHead!=null){
            Node tmp=nodeHead;
            while(tmp!=null){
                System.out.print(tmp.value);
                tmp=tmp.next;
                if(tmp!=null){
                    System.out.print("->");
                }
            }
        }
    }
    public static Node DeleteFirst(Node node){
        if(node!=null){
            return node.next;
        }
        return node;
    }
    public static Node removeAtIndex(Node headNode, int index) {
        if(headNode == null || index < 0)
            return null;

        if(index == 0)
            return DeleteFirst(headNode);

        Node currNode = headNode;
        Node prevNode = null;
        int count = 0;
        boolean bIsFound = false;
        while(currNode != null){
            if(count == index){
                // Remove currNode
                bIsFound = true;
                break;
            }
            prevNode = currNode;
            currNode = currNode.next;
            count++;
        }

        // Remove curr
        if(bIsFound){
            if(prevNode == null){ // Current Node is Last Node
                return null;
            }else{
                if(currNode != null){
                    prevNode.next = currNode.next;
                }
            }
        }
        return headNode;
        
    }



    public static void main(String[] args) {
        Node n1 = new Node(1);
        Node n2 = new Node(2);
        Node n3 = new Node(3);
        Node n4 = new Node(4);
        Node n5 = new Node(5);
        n1.next=n2;
        n2.next=n3;
        n3.next=n4;
        n4.next=n5;
        PrintNode(n1);
        System.out.println();
        n1=removeAtIndex(n1,2);
        PrintNode(n1);
    }
}

