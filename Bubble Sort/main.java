import java.util.*;
public class main{
    public static void BubbleSort(int[] a){
        for(int i=0; i<a.length; i++){
            boolean isSort= false;
            for(int j=0; j<a.length-i-1; j++){
                if(a[j]>a[j+1]){
                    isSort=true;
                    int tmp = a[j];
                    a[j] = a[j+1];
                    a[j+1]=tmp;
                }
            }
            if(!isSort) break;
        }
    }
    public static void main(String[] args) {
        int [] a= { 1, 0, 3, -1, 5};
        System.out.println(Arrays.toString(a));
        BubbleSort(a);
        System.out.println(Arrays.toString(a));
    }
}