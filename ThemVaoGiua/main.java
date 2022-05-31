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


    public static Node addHead(Node nodeHead,int value){
        Node newNode=new Node(value);
        if(nodeHead!=null){
            newNode.next=nodeHead;
        }
        return newNode;
    }

    public static Node addMidNode(Node nodeHead,int value,int index){
        if(index==0) return addHead(nodeHead,value);
        Node newNode=new Node(value);
        int idx=0;
        Node curNode=nodeHead;

        while(curNode!=null){
            idx++;
            if(idx==index){
                newNode.next=curNode.next;
                curNode.next=newNode;
                break;
            }
            curNode=curNode.next;
        }
        return nodeHead;
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
        n1=addMidNode(n1,100,2);
        PrintNode(n1);
    }
}

