public class main{
    public static class Node {
        Node next;
        int value;
        Node(int value) {
            this.value = value;
        }
    }

    public static Node ChenVaoDau(Node nodeHead,int value) {
        Node newNode = new Node(value);
        if(nodeHead != null){
            newNode.next = nodeHead;
        }
        return newNode;
    }
    public static void printNode(Node node) {
        if(node==null){
            System.out.println("null");
        }else{
            Node tmp = node;
            while(tmp!=null) {
                System.out.print(tmp.value);
                tmp = tmp.next;
                if(tmp!=null) {
                    System.out.print("->");
                }
            }

        }
    }

    public static void main(String[] args) {

        Node n1=new Node(1);
        Node n2=new Node(2);
        Node n3=new Node(3);
        Node n4=new Node(4);
        Node n5=new Node(5);
        n1.next=n2;
        n2.next=n3;
        n3.next=n4;
        n4.next=n5;
        printNode(n1);
        Node n6=ChenVaoDau(n1,6);
        System.out.println();
        printNode(n6);
        
    }

}