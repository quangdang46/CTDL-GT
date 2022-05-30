import java.util.Arrays;

public class main{
    public static void QuickSort(int a[],int l,int r){
        if(l>=r) return;
        int key=a[(l+r)/2];
        int m=getIndex(a,l,r,key);
        QuickSort(a,l,m-1);
        QuickSort(a,m,r);
    }
    public static int getIndex(int a[],int l,int r,int key){
        while(l<=r){
            while(a[l]<key){
                l++;
            }
            while(a[r]>key){
                r--;
            }
            if(l<=r){
                int tmp=a[l];
                a[l]=a[r];
                a[r]=tmp;
                l++;
                r--;
            }
        }
        return l;
    }
    public static void main(String[] args) {
        int[] a=new int[]{-1,4,5,22,-2,-4};
        QuickSort(a,0,a.length-1);
        System.out.println(Arrays.toString(a));
    }
}