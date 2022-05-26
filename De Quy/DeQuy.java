public class DeQuy {
    public static void print(int a[],int idx){
        if(idx < 0 || idx >= a.length){
            return;
        }
        System.out.println(a[idx]);
        print(a,idx+1);
    }
    public static void main(String[] args) {
        int a[] = {1,2,3,4,5,6,7,8,9};
        print(a,0);
    }
}
