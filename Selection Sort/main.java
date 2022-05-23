import java.util.*;
public class main{
    //sx tang
    public static void SelectionSort(int[] a) {
        for(int i = 0; i < a.length-1; i++){
            int min_idx=i;
            for(int j=i+1; j < a.length; j++){
                if(a[j]<a[min_idx]){
                    min_idx=j;
                }
            }
            if(i!=min_idx){
                int tmp=a[min_idx];
                a[min_idx]=a[i];
                a[i]=tmp;
            }
        }
    }
    public static void main(String[] args) {
        int[] a={10,2,-1,9,5,7,};
        System.out.println(Arrays.toString(a));
        SelectionSort(a);
        System.out.println(Arrays.toString(a));
    }
}